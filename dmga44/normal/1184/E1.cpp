#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef long double ld;
typedef pair<ld,int> pli;
typedef pair<pii,string> pps;
typedef pair<char,int> pci;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 100005

int d[MAXN];

int f(int u)
{
    if(d[u]<0)
        return u;
    d[u]=f(d[u]);
    return d[u];
}

void join(int u,int v)
{
    u=f(u),v=f(v);
    if(u==v)
        return ;
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<MAXN;i++)
        d[i]=-1;

    int n,m,u,v,w;
    cin >> n >> m;
    vector<pip> edges;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v >> w;
        u--,v--;
        if(!i)
            a=u,b=v;
        else
            edges.push_back(pip(w,pii(u,v)));
    }

    sort(edges.begin(),edges.end());

    int res=(1e9);
    for(auto y : edges)
    {
        join(y.second.first,y.second.second);
        if(f(a)==f(b))
        {
            db(y.first)
            return 0;
        }
    }
    db(res)

    return 0;
}