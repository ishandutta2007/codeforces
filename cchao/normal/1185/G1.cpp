#include <bits/stdc++.h>
using namespace std;

int n, s;
int t[22], g[22];

constexpr int mod = 1e9 + 7;
uint64_t dp[1 << 15][3] = {};

int sum[1 << 15] = {};

int main() {
  scanf("%d%d", &n, &s);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &t[i], &g[i]);
    g[i]--;
  }
  uint64_t ans = 0;
  for (int i = 1; i < (1 << n); ++i) {
    if (__builtin_popcount(i) == 1) {
      int j = 0;
      while (~i & (1 << j)) j++;
      dp[i][g[j]] = 1;
    } else {
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) {
          for (int k = 0; k < 3; ++k) {
            if (k != g[j]) {
              dp[i][g[j]] += dp[i ^ (1 << j)][k];
            }
          }
        }
      }
      dp[i][0] %= mod;
      dp[i][1] %= mod;
      dp[i][2] %= mod;
    }
    int sum = 0;
    for (int j = 0; j < n; ++j)
      if (i & (1 << j))
        sum += t[j];
    if (sum == s)
      ans = (ans + dp[i][0] + dp[i][1] + dp[i][2]) % mod;
  }
  cout << ans << endl;
  return 0;
}