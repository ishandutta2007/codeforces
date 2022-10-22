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

const int MAXN = 11;

int x[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];
    bool flag = false;
    for (int i = 1; i < (1 << n); ++i) {
      int cnt = __builtin_popcount(i);
      for (int o = 0; o < (1 << cnt); ++o) {
        int ans = 0;
        int now = 0;
        for (int j = 0; j < n; ++j) {
          if (!(i >> j & 1)) continue;
          if (o >> now & 1) ans += x[j]; else ans -= x[j];
          ++now;
        }
        if (ans == 0) {
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    if (flag) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}