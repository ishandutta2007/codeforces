#include<bits/stdc++.h>
using namespace std;
int dp[5005][5005][3];
int h[5005];
const int INF=0x3f3f3f3f;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=n;i++)
        dp[i][0][2]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=ceil(i/2.0);j++)
        {
            dp[i][j][2]=min(dp[i-1][j][1],dp[i-1][j][2]);
            dp[i][j][1]=max(h[i]-h[i-1]+1,0)+dp[i-1][j][0];
            dp[i][j][0]=min(dp[i-1][j-1][1]>=INF?INF:dp[i-2][j-1][0]+max(0,h[i-1]-min(h[i-2],h[i])+1),dp[i-1][j-1][2]+max(0,h[i-1]-h[i]+1));
            //cout<<i<<","<<j<<":["<<dp[i][j][2]<<","<<dp[i][j][1]<<","<<dp[i][j][0]<<"]\n";
        }
    }
    for(int i=1;i<=ceil(n/2.0);i++)
    {
        int cur=0x3f3f3f3f;
        for(int j=0;j<3;j++)
            cur=min(cur,dp[n][i][j]);
        printf("%d ",cur);
    }
    puts("");
}