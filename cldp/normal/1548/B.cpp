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

LL Gcd(LL a, LL b) {
  while (b > 0) {
    LL t = a % b;
    a = b;
    b = t;
  }
  return a;
}

const int MAXN = 200010;

LL x[MAXN];
LL f[MAXN][20];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i + 1 < n; ++i) {
      f[i][0] = abs(x[i + 1] - x[i]);
    }
    for (int j = 1; j < 20; ++j) {
      for (int i = 0; i + (1 << j) <= n - 1; ++i) {
        f[i][j] = Gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
      }
    }
    int ans = 1;
    for (int i = 0; i + 1 < n; ++i) {
      int t = i;
      LL gcd = 0;
      for (int j = 19; j >= 0; --j) {
        if (t + (1 << j) > n - 1) continue;
        LL temp = Gcd(gcd, f[t][j]);
        if (temp > 1) {
          gcd = temp;
          t += (1 << j);
        }
      }
      ans = max(ans, t - i + 1);
    }
    cout << ans << "\n";
  }
  return 0;
}