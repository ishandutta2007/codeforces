#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

using L = uint64_t;
using P = pair<int, int>;
const int mod = 1e9 + 7;
L dp[55][55][55][3], fac[55]={1};
int n, T;
map<P, L> b[3];
int cnt[3] = {};

int main() {
  for (int i = 1; i <= 50; ++i) fac[i] = fac[i - 1] * i % mod;
  for (int i = 0; i <= 50; ++i) for (int j = 0; j <= 50; ++j) for (int k = 0; k <= 50; ++k) {
    for (int l = 0; l < 3; ++l) {
      if (array<int, 3>{i, j, k}[l] == 0) {}
      else if (i + j + k == 1) {
        dp[i][j][k][l] = 1;
      } else {
        L *a = l == 0 ? dp[i-1][j][k] : (l == 1 ? dp[i][j-1][k] : dp[i][j][k-1]);
        dp[i][j][k][l] = (a[0] + a[1] + a[2] - a[l]) % mod;
      }
    }
  }
  b[0][{0,0}] = 1; b[1] = b[2] = b[0];
  cin >> n >> T;
  for (int i  = 0, t, g; i < n; ++i) {
    cin >> t >> g;
    map<P, L> c;
    for (auto &x : b[g - 1]) if (x.F.F + t <= T) {
      c[{x.F.F + t, x.F.S + 1}] += x.S;
    }
    for (auto &x : c) {
      b[g - 1][x.F] += x.S;
      b[g - 1][x.F] %= mod;
    }
    cnt[g - 1]++;
  }
  L ans = 0;
  for (auto &x : b[0]) for (auto &y : b[1]) {
    int r = T - x.F.F - y.F.F;
    if (r < 0) break;
    for (int i = 0; i <= cnt[2]; ++i) if (b[2].count({r, i})) {
      L c1 = (dp[x.F.S][y.F.S][i][0] + dp[x.F.S][y.F.S][i][1] + dp[x.F.S][y.F.S][i][2]) % mod;
      L c2 = (fac[x.F.S] * fac[y.F.S] % mod) * fac[i] % mod;
      L c3 = (x.S * y.S % mod) * b[2][{r, i}] % mod;
      ans = (ans + (c1 * c2 % mod) * c3 % mod) % mod;
    }
  }
  cout << ans << endl;
  return 0;
}