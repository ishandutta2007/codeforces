#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int mod=1000000007;
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a.begin(),a.end());
    int dp[n+1][n+1][k+1];
    for(int o=0;o<=n;o++) for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[o][i][j]=0;
    dp[0][0][0]=1;
    for(int o=1;o<=n;o++)
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                int t=j+(a[o]-a[o-1])*i;
                if(t>k) break;
                if(i>0) dp[o][i][t]=(dp[o][i][t]+(1ll*i*dp[o-1][i][j])%mod)%mod; //add to an existing group but don't close it
                if(i>0) dp[o][i-1][t]=(dp[o][i-1][t]+(1ll*i*dp[o-1][i][j])%mod)%mod; //add to an existing group and close it
                if(i<n) dp[o][i+1][t]=(dp[o][i+1][t]+dp[o-1][i][j])%mod; //create a new group
                dp[o][i][t]=(dp[o][i][t]+dp[o-1][i][j])%mod; //create a new group and close it
            }
        }
    }
    int res=0;
    for(int j=0;j<=k;j++) res=(res+dp[n][0][j])%mod;
    printf("%d\n",res);
    return 0;
}