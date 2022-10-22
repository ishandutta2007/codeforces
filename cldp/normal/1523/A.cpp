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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using LL = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    m = min(n, m);
    for (int i = 0; i < m; ++i) {
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        if (s[j] == '1') ++cnt;
      }
      if (cnt == n) break;
      string t = s;
      if (s[1] == '1') t[0] = '1';
      if (s[n - 2] == '1') t[n - 1] = '1';
      for (int j = 1; j + 1 < n; ++j) {
        int tt = (s[j - 1] == '1') + (s[j + 1] == '1');
        if (tt == 1) t[j] = '1';
      }
      s = t;
    }
    cout << s << endl;
  }
  return 0;
}