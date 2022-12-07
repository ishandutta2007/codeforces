#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=50;
int n, m, sm[sz][sz], us[sz], bi=1, si;
void dfs(int v)
{
    si++;
    for(int a=0; a<n; a++)
    {
        if(sm[v][a])
        {
            if(us[a]==-1) us[a]=us[v]^1, dfs(a);
            else if(us[a]==us[v]) bi=0;
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    if(m==0)
    {
        cout<<0;
        return 0;
    }
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sm[u][v]=1, sm[v][u]=1;
    }
    for(int a=0; a<n; a++) us[a]=-1;
    int smq=0, bgq=0;
    for(int a=0; a<n; a++)
    {
        if(us[a]==-1)
        {
            us[a]=0, si=0, dfs(a);
            if(si==1) smq++;
            else bgq++;
        }
    }
    int q2=(bi) ? 1ll<<(smq+bgq) : 0, q1=(1ll<<(smq+1)), q11=(1ll<<(smq+bgq))-q1;
    int n1=n/2, n2=n-n1, sm11[n1], sm22[n2], sm12[n1];
    for(int a=0; a<n1; a++)
    {
        sm11[a]=0;
        for(int b=0; b<n1; b++) if(sm[a][b]) sm11[a]+=(1<<b);
        sm12[a]=0;
        for(int b=0; b<n2; b++) if(sm[a][b+n1]) sm12[a]+=(1<<b);
    }
    for(int a=0; a<n2; a++)
    {
        sm22[a]=0;
        for(int b=0; b<n2; b++) if(sm[a+n1][b+n1]) sm22[a]+=(1<<b);
    }
    int dp[1<<n1], dp2[1<<n2];
    dp2[0]=1;
    for(int mask=1; mask<(1<<n2); mask++)
    {
        int v=31-__builtin_clz(mask), pr=mask^(1<<v);
        if(dp2[pr] and (pr&sm22[v])==0) dp2[mask]=1;
        else dp2[mask]=0;
    }
    for(int i=0; i<n2; i++)
    {
        for(int mask=0; mask<(1<<n2); mask++)
        {
            if(mask&(1<<i)) dp2[mask]+=dp2[mask-(1<<i)];
        }
    }
    dp[0]=0;
    for(int mask=1; mask<(1<<n1); mask++)
    {
        int v=31-__builtin_clz(mask), pr=mask^(1<<v);
        if(dp[pr]!=-1 and (pr&sm11[v])==0) dp[mask]=dp[pr]|sm12[v];
        else dp[mask]=-1;
    }
    int q=0;
    for(int mask=0; mask<(1<<n1); mask++)
    {
        if(dp[mask]!=-1) q+=dp2[(1<<n2)-1-dp[mask]];
    }
    q*=2;
    q-=q2*2+q1;
    cout<<(1ll<<n)-q2-q1-q11-q;
}