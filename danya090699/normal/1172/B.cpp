#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, mod=998244353;
vector <int> sv[sz];
int n, dp[sz], fact[sz];
void dfs(int v, int pr)
{
    dp[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v), dp[v]=(1ll*dp[v]*dp[ne])%mod;
        }
    }
    int prq=sv[v].size();
    if(v) prq--;
    dp[v]=(1ll*dp[v]*fact[prq])%mod;
    if(v) dp[v]=(1ll*dp[v]*(prq+1))%mod;
    else dp[v]=(1ll*dp[v]*n)%mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    fact[0]=1;
    for(int a=1; a<=n; a++) fact[a]=(1ll*fact[a-1]*a)%mod;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, 0);
    cout<<dp[0];
}