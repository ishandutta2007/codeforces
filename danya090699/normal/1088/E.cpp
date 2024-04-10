#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=3e5+10, inf=1e18;
vector <int> sv[sz];
int va[sz], dp[sz], be=-inf, su=0, k=0;
void dfs(int v, int pr)
{
    dp[v]=va[v];
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs(ne, v), dp[v]+=max(0ll, dp[ne]);
    }
    be=max(be, dp[v]);
}
void dfs2(int v, int pr)
{
    dp[v]=va[v];
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs2(ne, v);
            if(dp[ne]!=be) dp[v]+=max(0ll, dp[ne]);
        }
    }
    if(dp[v]==be) su+=be, k++;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++) scanf("%lld", &va[a]);
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, 0);
    dfs2(0, 0);
    cout<<su<<" "<<k;
}