#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=1e5+7;
long long dp[maxn][200][2];
int arr[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    memset(dp,0,sizeof(dp));
    if(arr[0]!=-1) dp[0][arr[0]][0]=1;
    else{
        for(int j=1;j<=200;j++)
        {
            dp[0][j][0]=1;
        }
    }
    long long sum[205][2];
    for(int i=1;i<n;i++)
    {
        memset(sum,0,sizeof(sum));
        for(int j=1;j<=200;j++)
        {
            sum[j][0]=(sum[j-1][0]+dp[i-1][j][0])%mod;
            sum[j][1]=(sum[j-1][1]+dp[i-1][j][1])%mod;
        }
        if(arr[i]==-1)
        {
            if(i==1)
            {
                for(int j=1;j<=200;j++)
                {
                    dp[i][j][0]=dp[i-1][j][0];
                    dp[i][j][1]=sum[j-1][0];
                }
                continue;
            }
            for(int j=1;j<=200;j++)
            {
                dp[i][j][0]=(sum[200][0]-sum[j-1][0]+dp[i-1][j][1]+mod)%mod;
                dp[i][j][1]=(sum[j-1][0]+sum[j-1][1])%mod;
                //cout<<i<<","<<j<<":"<<dp[i][j][0]<<","<<dp[i][j][1]<<endl;
            }
        }
        else{
            if(i==1)
            {
                dp[i][arr[i]][0]=dp[i-1][arr[i]][0];
                dp[i][arr[i]][1]=sum[arr[i]-1][0];
                continue;
            }
            dp[i][arr[i]][0]=(sum[200][0]-sum[arr[i]-1][0]+dp[i-1][arr[i]][1]+mod)%mod;
            dp[i][arr[i]][1]=(sum[arr[i]-1][0]+sum[arr[i]-1][1])%mod;
        }
    }
    long long ans=0;
    for(int j=1;j<=200;j++)
    {
        ans=(ans+dp[n-1][j][0])%mod;
    }
    printf("%lld\n",ans);
}