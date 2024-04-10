#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 3e5+5, MOD = 1e9+7;
long long dp[MAXN][10];
int arr[MAXN];
int main() {
    int n,m,k; long long ans = 0;
    scanf("%d %d %d",&n,&m,&k);
    for (int i = 1; i <= n; i++) {
      scanf ("%d",&arr[i]);
        for (int j = 0; j < m; j++) {
          if (i < m && (j > i || j == 0)) continue;
          if (j == (1%m)) dp[i][j] = dp[i-1][m==1?0:j-1] - k + arr[i];
          else if (!j) dp[i][j] = dp[i-1][m-1] + arr[i];
          else dp[i][j] = dp[i-1][j-1] + arr[i];
          ans = max(ans,dp[i][j]);
       }
       dp[i][1%m] = max(dp[i][1%m],(ll)arr[i]-k);
       ans = max(ans,dp[i][1%m]);
    }
    printf ("%lld\n",ans);
}