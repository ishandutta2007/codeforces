#include<bits/stdc++.h>
using namespace std;
#define MAX 500000
typedef long long int LL;
LL t,n,dp[MAX];
LL F(LL y)
{
    return max(y,-y);
}
int main()
{

    while(scanf("%I64d%I64d",&t,&n)==2)
    {
        for(LL i=0;i<t;i++)
            scanf("%I64d",&dp[i]);
        sort(dp,dp+t);
//        for(LL i=0;i<t;i++)cout<<dp[i]<<"  ";puts("");
        if(t==1)puts("0");
        else if(t==2)printf("%I64d\n",min(F(dp[0]-n),F(dp[1]-n)));
        else
        {
            LL a1,a2,a3,a4;
            a1=F(n-dp[0])+F(dp[0]-dp[t-2]);
            a2=F(n-dp[t-1])+F(dp[t-1]-dp[1]);
            a3=F(n-dp[t-2])+F(dp[t-2]-dp[0]);
            a4=F(n-dp[1])+F(dp[t-1]-dp[1]);
            LL ans=min(a1,a2);
            ans=min(ans,min(a3,a4));
            printf("%I64d\n",ans);
        }
    }
    return 0;
}