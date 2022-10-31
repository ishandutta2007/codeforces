#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1<<17;

vector <int> V;
char s[MAX];
int dp[3][2][MAX];

int main()
{
  int n;

  scanf("%d %s", &n, s);
  
  dp[0][0][0] = dp[0][1][0] = 0;
  for (int i=0; i<n; i++) {
    int c = s[i] - '0';
    dp[0][c][i+1] = max(dp[0][c][i+1], dp[0][c][i]);
    dp[0][c][i+1] = max(dp[0][c][i+1], dp[0][1^c][i] + 1);
    dp[0][1^c][i+1] = max(dp[0][1^c][i+1], dp[0][1^c][i]);

    dp[2][c][i+1] = max(dp[2][c][i+1], max(dp[1][c][i], dp[2][c][i]));
    dp[2][c][i+1] = max(dp[2][c][i+1], max(dp[1][1^c][i] + 1, dp[2][1^c][i] + 1));
    dp[2][1^c][i+1] = max(dp[2][1^c][i+1], max(dp[2][1^c][i], dp[1][1^c][i]));

    c ^= 1;
    dp[1][c][i+1] = max(dp[1][c][i+1], max(dp[1][c][i], max(dp[0][1^c][i] + 1, dp[1][1^c][i] + 1)));
    dp[1][1^c][i+1] = max(dp[1][1^c][i+1], max(dp[0][1^c][i], dp[1][1^c][i]));
  }

  int ret=0;
  for (int i=1; i<3; i++)
    for (int j=0; j<2; j++)
      ret = max(ret, dp[i][j][n]);

  printf("%d\n", ret);
  
  return 0;
}