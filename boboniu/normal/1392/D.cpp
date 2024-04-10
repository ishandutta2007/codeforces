#include <bits/stdc++.h>
using namespace std;
#define maxN 222222

int n;
long long k;
char s[maxN];
int dp[maxN];
int main() {
  int tc;
  scanf("%d", &tc);
  for (int T = 0; T < tc; T++) {
    scanf("%d", &n);
    scanf("%s", s);
    int ans = n + 1;
    for (int c = 0; c < 5; c++) {
      dp[0] = 0;
      for (int i = 1; i <= n; i++)
        dp[i] = n + 1;
      for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 2] + (s[i - 2] != 'R') + (s[i - 1] != 'L');
        if (i >= 3)
          dp[i] = min(dp[i], dp[i - 3] + (s[i - 3] != 'R') + (s[i - 2] != 'L') +
                                 (s[i - 1] != 'L'));
        if (i >= 3)
          dp[i] = min(dp[i], dp[i - 3] + (s[i - 3] != 'R') + (s[i - 2] != 'R') +
                                 (s[i - 1] != 'L'));
        if (i >= 4)
          dp[i] = min(dp[i], dp[i - 4] + (s[i - 4] != 'R') + (s[i - 3] != 'R') +
                                 (s[i - 2] != 'L') + (s[i - 1] != 'L'));
      }
      ans = min(ans, dp[n]);
      rotate(s, s + 1, s + n);
    }
    printf("%d\n", ans);
  }
}