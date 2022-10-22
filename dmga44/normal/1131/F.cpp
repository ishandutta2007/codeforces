#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<string,int> psi;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 150005

vector<pii> g[MAXN];
int res[MAXN],cont,d[MAXN],tf[MAXN][2],ant[MAXN];

int fin(int u)
{
    if(d[u]<0)
        return u;
    d[u]=fin(d[u]);
    return d[u];
}

void join(int u,int v)
{
    u=fin(u),v=fin(v);
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
    ant[tf[u][0]]=tf[v][1];
    tf[u][0]=tf[v][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,u,v;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        d[i]=-1;
        tf[i][0]=tf[i][1]=i;
        ant[i]=-1;
    }
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        join(u,v);
    }

    u=fin(1);

    while(u!=-1)
    {
        cout << u << ' ';
        u=ant[u];
    }
    cout << '\n';

    return 0;
}