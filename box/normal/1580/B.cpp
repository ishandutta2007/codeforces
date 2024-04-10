#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
// const int MOD = 1000000007;
int MOD;
int dp[105][105][105];
int C[105][105];
int fac[105];

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
  ull b, m;
  FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
  ull reduce(ull a) {
    ull q = (ull)((L(m) * a) >> 64);
    ull r = a - q * b; // can be proven that 0 <= r < 2*b
    return r >= b ? r - b : r;
  }
};
FastMod F(2);

// k: number good
// m: number max

int dfs(int n, int m, int k) {
  if (n == 0)
    return (k == 0);
  if (k == 0 && (m > n || m == 0))
    return fac[n];
  if (k > n || m > n || m == 0)
    return 0;
  if (n == 1 && m == 1 && k == 1)
    return 1;
  if (dp[n][m][k] != -1)
    return dp[n][m][k];
  dp[n][m][k] = 0;
  int Rk = k;
  if (m == 1)
    Rk--;
  if (Rk == -1)
    return 0;
  for (int i = 0; i < n; i++)
    for (int x = 0; x <= Rk; x++) {
      ll a = dfs(i, m - 1, x);
      ll b = dfs(n - i - 1, m - 1, Rk - x);
      // cout << n << ' ' << m << ' ' << k << ' ' << i << ' ' << x << ' ' << a
      //  << ' ' << b << ' ' << C[n - 1][i] << endl;
      dp[n][m][k] = F.reduce(dp[n][m][k] + F.reduce(a * b) * C[n - 1][i]);
    }
  // cout << dp[n][m][k] << endl;
  return dp[n][m][k];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  int n, m, k;
  cin >> n >> m >> k >> MOD;
  F = FastMod(MOD);
  fac[0] = 1;
  for (int i = 1; i <= 100; i++)
    fac[i] = 1ll * i * fac[i - 1] % MOD;
  C[0][0] = 1;
  for (int i = 1; i <= 100; i++)
    for (int j = 0; j <= i; j++) {
      C[i][j] = C[i - 1][j];
      if (j)
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  cout << dfs(n, m, k) << endl;
}