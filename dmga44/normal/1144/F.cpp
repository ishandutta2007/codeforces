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

typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 200005

vector<pii> g[MAXN];
vector<pii> edges;
bool res[MAXN],ok=1,mk[MAXN];
int c[MAXN];

void dfs(int u)
{
    mk[u]=1;
    for(auto y : g[u])
    {
        int v=y.first;
        int p=y.second;
        if(!mk[v])
        {
            c[v]=(1-c[u]);
            dfs(v);
        }
        if(c[v]==c[u])
            ok=0;
        if(!c[u])
        {
            if(edges[p]==pii(u,v))
                res[p]=1;
        }
        else
            if(edges[p]==pii(v,u))
                res[p]=1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,u,v;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        edges.push_back(pii(u,v));
        g[u].push_back(pii(v,i));
        g[v].push_back(pii(u,i));
    }

    dfs(0);

    if(ok)
    {
        db("YES")
        for(int i=0;i<m;i++)
            cout << res[i];
        cout << '\n';
    }
    else
        db("NO")

    return 0;
}