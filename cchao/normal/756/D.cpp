#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, dp[5010][5010];
char s[5010];

int main() {
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; ++i)
    dp[0][i] = 1;
  int nxt[26];
  for (int i = 1; i <= n; ++i) {
    for (int &x : nxt) x = n;
    for (int j = n - 1; j >= 0; --j) {
      int c = s[j] - 'a';
      dp[i][j] = dp[i][j+1] - dp[i-1][nxt[c]] + dp[i-1][j];
      if (dp[i][j] < 0) dp[i][j] += mod;
      if (dp[i][j] >= mod) dp[i][j] -= mod;
      nxt[c] = j;
    }
  }
  printf("%d\n", dp[n][0]);
  return 0;
}