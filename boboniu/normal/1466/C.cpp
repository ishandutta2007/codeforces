#include <bits/stdc++.h>
using namespace std;
#define maxN 423456

int tc;
int dp[maxN][2][2];
char s[maxN];
void solve() {
  scanf("%s", s + 2);
  int n = strlen(s + 2);
  for (int i = 2; i <= n + 1; i++) {
    for (int s1 = 0; s1 <= 1; s1++)
      for (int s2 = 0; s2 <= 1; s2++) {
        dp[i][s1][s2] = 1 << 30;
        for (int s3 = 0; s3 <= 1; s3++) {
          if (s1 == 1)
            dp[i][s1][s2] = min(dp[i][s1][s2], dp[i - 1][s2][s3] + 1);
          else {
            char p1 = (s2 == 0) ? s[i - 1] : 0;
            char p2 = (s3 == 0) ? s[i - 2] : 0;
            if (s[i] != p1 && s[i] != p2) {
              dp[i][s1][s2] = min(dp[i][s1][s2], dp[i - 1][s2][s3]);
            }
          }
        }
        //printf("%d %d %d %d\n", i, s1, s2, dp[i][s1][s2]);
      }
  }
  int ans = 1 << 30;
  for (int s1 = 0; s1 <= 1; s1++)
    for (int s2 = 0; s2 <= 1; s2++)
      ans = min(ans, dp[n + 1][s1][s2]);
  printf("%d\n", ans);
}

int main() {
  scanf("%d", &tc);
  for (int T = 0; T < tc; T++) {
    solve();
  }
}