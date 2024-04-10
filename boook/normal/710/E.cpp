#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define MAX 50000000
LL dp[MAX];
int main()
{
    LL n,x,y;
    while(scanf("%I64d%I64d%I64d",&n,&x,&y)==3)
    {
        dp[1]=x;
        for(int i=2;i<=n;i++)
        {
            if(i&1)
            {
                dp[i]=min(dp[i-1]+x,dp[i/2]+y+x);
                dp[i]=min(dp[i],dp[i/2+1]+y+x);
            }
            else
            {
                dp[i]=min(dp[i-1]+x,dp[i/2]+y);
            }
        }
        printf("%I64d\n",dp[n]);
    }
    return 0;
}