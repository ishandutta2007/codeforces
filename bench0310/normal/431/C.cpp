#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int mod=1000000007;
    int n,k,d;
    scanf("%d%d%d",&n,&k,&d);
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    dp[0][0]=1;
    for(int o=0;o<=n;o++)
    {
        for(int i=0;i<=1;i++)
        {
            for(int j=1;j<=k&&o+j<=n;j++)
            {
                dp[o+j][max(i,(int)(j>=d))]=(dp[o+j][max(i,(int)(j>=d))]+dp[o][i])%mod;
            }
        }
    }
    printf("%d\n",dp[n][1]);
    return 0;
}