#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 505, INF = 0x3f3f3f3f;

int p[MAX];
int dp[MAX][MAX];

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=1; i<=n; i++)
    scanf("%d", &p[i]);

  memset(dp, INF, sizeof dp);
  
  for (int i=0; i<=n; i++) {
    if (p[i] == p[i+1] || i == n || !i)
      dp[i][i+1] = 1;
    else
      dp[i][i+1] = 2;
  }

  for (int i=0; i<=n+1; i++)
    for (int j=0; j<=n+1; j++)
      if (i > j)
        dp[i][j] = 0;

  for (int i=0; i<=n+1; i++)
    dp[i][i] = 1;
  dp[0][0] = dp[n+1][n+1] = 0;

  for (int raz=2; raz<n; raz++) {
    for (int l=0; l+raz<=n+1; l++) {
      int r = l + raz;
      if (p[l] == p[r])
        dp[l][r] = min(dp[l][r], dp[l+1][r-1]);
      
      for (int j=l; j<=r-1; j++)
        dp[l][r] = min(dp[l][r], dp[l][j] + dp[j+1][r]);
    }
  }

  printf("%d\n", dp[1][n]);

  return 0;
}