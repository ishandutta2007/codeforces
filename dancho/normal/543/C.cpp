#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m;
char s[32][32];
int a[32][32];

int mag[32][32];
int mx[32][32];
int sm[32][32];
int re[32][32];

int dp[21][1 << 20];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  memset(mag, 0, sizeof(mag));
  memset(mx, 0, sizeof(mag));
  memset(sm, 0, sizeof(mag));
  for (int j = 0; j < m; ++j) {
    for (int c = 0; c < 26; ++c) {
      for (int i = 0; i < n; ++i) {
        if (s[i][j] == 'a' + c) {
          mag[j][c] |= (1 << i);
          mx[j][c] = max(mx[j][c], a[i][j]);
          sm[j][c] += a[i][j];
        }
      }
      re[j][c] = sm[j][c] - mx[j][c];
    }
  }
  memset(dp, 63, sizeof(dp));
  dp[m][(1 << n) - 1] = 0;
  for (int j = m - 1; j >= 0; --j) {
    for (int ma = (1 << n) - 1; ma >= 0; --ma) {
      dp[j][ma] = dp[j + 1][ma];
      for (int i = 0; i < n; ++i) {
        if (!(ma & (1 << i))) {
          dp[j][ma] = min(dp[j][ma], a[i][j] + dp[j][ma | (1 << i)]);
          int c = s[i][j] - 'a';
          dp[j][ma] = min(dp[j][ma], re[j][c] + dp[j][ma | mag[j][c]]);
        }
      }
      // for (int c = 0; c < 26; ++c) {
      //   if ((ma | mag[j][c]) != ma) {
      //     dp[j][ma] = min(dp[j][ma], sm[j][c] - mx[j][c] + dp[j][ma | mag[j][c]]);
      //   }
      // }
    }
  }
  printf("%d\n", dp[0][0]);
  return 0;
}