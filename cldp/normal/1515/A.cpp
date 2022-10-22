#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n, k;
    cin >> n >> k;
    set<int> s;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      s.insert(a);
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      for (int a : s) {
        if (k == a) continue;
        ans.push_back(a);
        k -= a;
        s.erase(a);
        break;
      }
    }
    if (ans.size() == n) {
      cout << "YES" << '\n';
      for (int a : ans) cout << a << " ";
      cout << '\n';
    } else {
      cout << "NO\n";
    }

  }
  return 0;
}