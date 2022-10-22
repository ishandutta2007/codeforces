#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 200005

vector<pii> edge;
int cant[MAXN],bad[MAXN],res[MAXN],p[MAXN],r,mk[MAXN];
vector<pii> g[MAXN];

void dfs(int u)
{
    mk[u]=1;
    int cont=0;
    for(auto y : g[u])
    {
        int v=y.first;
        int id=y.second;
        if(!mk[v])
        {
            if(cont==p[u])
                cont++;
            if(!bad[u])
            {
                p[v]=cont;
                res[id]=cont;
            }
            else
            {
                p[v]=0;
                res[id]=0;
            }
            cont++;
            dfs(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k,u,v;
    cin >> n >> k;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        edge.push_back(pii(u,v));
        cant[u]++;
        cant[v]++;
        g[u].push_back(pii(v,i));
        g[v].push_back(pii(u,i));
    }

    vector<pii> vv;
    for(int i=0;i<n;i++)
        vv.push_back(pii(cant[i],i));

    sort(vv.rbegin(),vv.rend());

    for(int i=0;i<k;i++)
        bad[vv[i].second]=1;

    r=vv[k].first;

    p[0]=-1;
    dfs(0);

    db(r)
    for(int i=0;i<n-1;i++)
        cout << res[i]+1 << ' ';
    cout << '\n';

    return 0;
}