#include <bits/stdc++.h>

using namespace std;

const int N=2000;

int a,n,m;
bool need[N+5];
int dp[N+5][N+5],cost[N+5];
int bst[N+5],cine[N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            dp[i][j]=(1<<30);
    cin>>a>>n>>m;
    for(int i=0;i<=a;i++)
        bst[i]=(1<<30),cine[i]=-1;
    for(int i=1;i<=n;i++)
    {
        int st,dr;
        cin>>st>>dr;
        for(int j=st;j<dr;j++)
            need[j]=1;
    }
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x>>cost[i];
        if(cost[i]<bst[x])
            bst[x]=cost[i],cine[x]=i;
    }
    dp[0][0]=0;
    for(int i=0;i<a;i++)
        for(int j=0;j<=m;j++)
        {
            if(dp[i][j]==(1<<30))continue;
            if(need[i]==0)
                dp[i+1][0]=min(dp[i+1][0],dp[i][j]);
            if(j!=0)
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+cost[j]);
            if(cine[i]!=-1)
                dp[i+1][cine[i]]=min(dp[i+1][cine[i]],dp[i][j]+bst[i]);
        }
    int ans=(1<<30);
    for(int i=0;i<=m;i++)
        ans=min(ans,dp[a][i]);
    if(ans==(1<<30))
        ans=-1;
    cout<<ans<<"\n";
    return 0;
}
/**
**/