#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef long double ld;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>,
    rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 200005

ll res,sons[MAXN],dp[MAXN],mk[MAXN],n;
vector<ll> g[MAXN];

void dfs(int u)
{
    mk[u]=1;
    sons[u]=1;
    for(auto v : g[u])
        if(!mk[v])
        {
            dfs(v);
            sons[u]+=sons[v];
            dp[u]+=dp[v];
        }
    dp[u]+=sons[u];
}

void dfs1(int u)
{
    mk[u]=1;
    res=max(res,dp[u]);
    for(auto v : g[u])
        if(!mk[v])
        {
            dp[v]=(dp[u]-sons[v]+(n-sons[v]));
            dfs1(v);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int u,v;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);
    for(int i=0;i<n;i++)
        mk[i]=0;

    dfs1(0);

    db(res)

    return 0;
}