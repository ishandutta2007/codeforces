#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

const int mod = 1000000007;
const int maxn = 1e6 + 10;
int f[maxn], dp[maxn][20];
int main() {
  for (int i = 2; i < maxn; ++i)
    if (f[i] == 0) {
      for (int j = i; j < maxn; j += i)
        f[j] = i;
    }
  REP(i, 20) dp[0][i] = i == 0 ? 1 : 2;
  for (int i = 1; i < maxn; ++i) {
    REP(j, 20) dp[i][j] = j == 0 ? 1 : (dp[i - 1][j] + dp[i][j - 1]) % mod;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int r, n;
    scanf("%d%d", &r, &n);
    LL ans = 1;
    while (n > 1) {
      int t = f[n];
      int c = 0;
      while (n % t == 0) {
        n /= t;
        ++c;
      }
      ans = ans * dp[r][c] % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}