#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
#define mod (ll)(1e9+7)
#define MAXN 100005

ll b[MAXN],res;
vector<int> g[MAXN];
vector<pii> s[MAXN];
bool mk[MAXN];

void dfs(int u)
{
    mk[u]=1;
    vector<pii> ns;
    for(auto y : s[u])
        ns.push_back(pii(__gcd(y.first,b[u]),y.second));
    ns.push_back(pii(b[u],1));

    s[u].clear();
    int ac=0;
    for(int i=0;i<ns.size();i++)
    {
        if(i && ns[i-1].first!=ns[i].first)
        {
            s[u].push_back(pii(ns[i-1].first,ac));
            ac=0;
        }
        ac+=ns[i].second;
    }
    s[u].push_back(pii(ns[ns.size()-1].first,ac));

    for(auto y : s[u])
        res=(res+(y.first*y.second))%mod;

    for(auto y : g[u])
        if(!mk[y])
        {
            for(auto v : s[u])
                s[y].push_back(v);
            dfs(y);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> b[i];
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

    db(res)

    return 0;
}