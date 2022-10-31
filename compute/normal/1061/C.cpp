#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
const int mod=1e9+7;
int arr[maxn];
long long dp[maxn];
int main()
{
    int n;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=1;j*j<=arr[i];j++)
        {
            if(arr[i]%j==0)
            {
                dp[arr[i]/j]=(dp[arr[i]/j]+dp[arr[i]/j-1])%mod;
            }
        }
        for(int j=sqrt(arr[i])+1;j>0;j--)
        {
            if(j*j>=arr[i])
                continue;
            if(arr[i]%j==0)
            {
                dp[j]=(dp[j]+dp[j-1])%mod;
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+dp[i])%mod;
    cout<<ans<<endl;
}