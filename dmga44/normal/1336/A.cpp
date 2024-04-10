#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005

vector<int> g[MAXN],vs;
int level[MAXN],sons[MAXN],mk[MAXN];

void dfs(int u)
{
    mk[u]=1;
    sons[u]=1;
    for(auto y : g[u])
        if(!mk[y])
        {
            level[y]=level[u]+1;
            dfs(y);
            sons[u]+=sons[y];
        }

    vs.push_back(level[u]-sons[u]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k,u,v;
    cin >> n >> k;;
    for(int i=0;i<n-1;i++)
    {
        cin  >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    level[0]=1;
    dfs(0);

    sort(all(vs));

    ll res=0;
    for(int i=0;i<k;i++)
        res+=vs[n-1-i];
    db(res)

    return 0;
}