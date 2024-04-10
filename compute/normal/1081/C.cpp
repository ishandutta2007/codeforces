#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
const int mod=998244353;
long long dp[maxn][maxn];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    memset(dp,0,sizeof(dp));
    dp[1][0]=m;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j==0) dp[i][j]=dp[i-1][j];
            else dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]*(m-1))%mod;
        }
    }
    printf("%lld\n",dp[n][k]);

}