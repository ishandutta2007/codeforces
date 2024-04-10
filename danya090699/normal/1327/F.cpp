#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, m, an=1;
    cin>>n>>k>>m;
    int ot[m][3];
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<3; b++) scanf("%d", &ot[a][b]);
    }
    for(int i=0; i<k; i++)
    {
        int dp[n+2], q[n+2], ma[n+2];
        for(int a=0; a<=n+1; a++) q[a]=0, ma[a]=0;
        for(int a=0; a<m; a++)
        {
            int l=ot[a][0], r=ot[a][1], x=ot[a][2];
            if(x&(1<<i)) q[l]++, q[r+1]--;
            else ma[r]=max(ma[r], l);
        }
        for(int a=1; a<=n+1; a++) q[a]+=q[a-1], ma[a]=max(ma[a], ma[a-1]);
        dp[0]=1;
        for(int a=1; a<=n+1; a++)
        {
            if(q[a]) dp[a]=0;
            else
            {
                dp[a]=dp[a-1];
                if(ma[a-1])
                {
                    dp[a]-=dp[ma[a-1]-1];
                    if(dp[a]<0) dp[a]+=mod;
                }
            }
            dp[a]+=dp[a-1];
            if(dp[a]>=mod) dp[a]-=mod;
        }
        int cu=dp[n+1]-dp[n];
        if(cu<0) cu+=mod;
        an=1ll*an*cu%mod;
    }
    cout<<an;
}