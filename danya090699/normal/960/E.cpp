#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, mod=1e9+7;
int n, va[sz];
vector <int> sv[sz];
int dp[sz][2], si[sz], dp2[sz][2], an=0;
void dfs(int v, int pr)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v);
            dp[v][0]+=dp[ne][1], dp[v][1]+=dp[ne][0]+1, si[v]+=si[ne];
        }
    }
}
void dfs2(int v, int pr)
{
    int cu[2]={0, 0};
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dp2[ne][0]=dp2[v][1]+(dp[v][1]-dp[ne][0]-1);
            dp2[ne][1]=dp2[v][0]+(dp[v][0]-dp[ne][1])+1;

            int q[2]={dp[ne][1], dp[ne][0]+1};
            cu[0]=(cu[0]+1ll*q[0]*(n-si[ne]))%mod;
            cu[1]=(cu[1]+1ll*q[1]*(n-si[ne]))%mod;

            dfs2(ne, v);
        }
    }
    cu[0]=(cu[0]+1ll*dp2[v][0]*si[v])%mod;
    cu[1]=(cu[1]+1ll*dp2[v][1]*si[v])%mod;
    an=(an+1ll*cu[0]*va[v]+1ll*cu[1]*(mod-va[v])%mod)%mod;
    an=(an+1ll*n*va[v])%mod;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &va[a]);
        va[a]=(va[a]+mod)%mod;
    }
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, -1);
    dfs2(0, -1);
    cout<<an;
}