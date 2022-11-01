#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int mod=1000000007;
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    dp[1][0]=1;
    for(int o=1;o<=n;o++)
    {
        for(int i=0;i<k;i++)
        {
            for(int j=1;o*j<=n;j++)
            {
                dp[o*j][i+1]=(dp[o*j][i+1]+dp[o][i])%mod;
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++) res=(res+dp[i][k])%mod;
    printf("%d\n",res);
    return 0;
}