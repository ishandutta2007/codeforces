#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 505;
int MOD;

int Add(int a, int b)
{
  return (a + b) % MOD;
}

int dp[2][MAX][MAX], sum[MAX];
int p[MAX];

int main()
{
  int n, m, b;

  scanf("%d%d%d%d", &n, &m, &b, &MOD);

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  dp[0][0][0] = 1;
  int ind=0;

  for (int i=0; i<m; i++, ind ^= 1) {
    for (int j=0; j<n; j++)
      for (int k=0; k<=b; k++)
        dp[1^ind][j][k] = 0;

    for (int i=0; i<=b; i++)
      sum[i] = 0;
    
    for (int j=0; j<n; j++) {
      for (int k=0; k<=b; k++) {
        sum[k] = Add(sum[k], dp[ind][j][k]);
        if (p[j] + k <= b)
          dp[1^ind][j][p[j] + k] = Add(dp[1^ind][j][p[j] + k], sum[k]);
      }
    }
  }

  int rje=0;
  for (int i=0; i<n; i++)
    for (int j=0; j<=b; j++)
      rje = Add(rje, dp[ind][i][j]);
  
  printf("%d\n", rje);

  return 0;
}