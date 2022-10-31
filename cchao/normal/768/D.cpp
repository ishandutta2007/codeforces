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

double dp[10000][1010];
double a[10000];

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  dp[0][0] = 1.0;
  for (int i = 1; i < 10000; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] += dp[i-1][j] * (1.0 * j / n);
      dp[i][j] += dp[i-1][j-1] * (1.0 * (n - (j - 1)) / n);
    }
    a[i] = dp[i][n];
  }
  while (q--) {
    int p;
    scanf("%d", &p);
    double x = (p - 1e-8) / 2000.0;
    int ans = lower_bound(a, a + 10000, x) - a;
    printf("%d\n", ans);
  }
  return 0;
}