#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <climits>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v) {
  os << "[";
  for (int i : v) {
    os << i << " ";
  }
  os << "]";
  return os;
}

ostream& operator<<(ostream& os, const vector<vector<int>>& v) {
  os << "[";
  for (const vector<int>& i : v) {
    os << i;
  }
  os << "]";
  return os;
}

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> p;
        if (numRows == 0) return p;
        vector<int> curr{1};
        p.push_back(curr);
        // cout << "p is: " << p << endl;
        if (numRows == 1) return p;
        for (int i = 1; i < numRows; ++i) {
          curr.clear();
          curr.push_back(1);
          // middle numbers
          for (int prev = 1; prev < p[i-1].size(); ++prev) {
            curr.push_back(p[i-1][prev-1] + p[i-1][prev]);
          }
          // last numbers
          curr.push_back(1);
          // cout << "Adding curr: " << curr << endl;
          p.push_back(curr);
        }
        return p;
    }
};

void test1() {
  Solution S;
  cout << "l1? " << S.generate(1) << endl;
  cout << "l2? " << S.generate(2) << endl;
  cout << "l5? " << S.generate(5) << endl;
}

void test2() {
  Solution S;
}

void test3() {
  Solution S;
}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;
  
  return 0;
}
