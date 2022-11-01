#include <bits/stdc++.h>

using namespace std;

int n, c[505];
int dp[505][505];

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    scanf("%d", c+i);
  }
  for(int i = 0; i<n; i++)
    dp[0][i] = 0;
  for(int i = 0; i<n; i++)
    dp[1][i] = 1;
  for(int i = 2; i<=n; i++) {
    int m = n-i;
    for(int j = 0; j<=m; j++) {
      dp[i][j] = i;
      for(int k = 1; k<i; k++)
        dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j+k]);
      for(int k = 1; k+k<=i+1; k++)
        if(c[j+k-1] == c[j+i-k])
          dp[i][j] = min(dp[i][j], ((i > k+k) ? dp[i-2*k][j+k] : 1));
        else
          break;
    }
  }
  cout << dp[n][0] << endl;
  return 0;
}