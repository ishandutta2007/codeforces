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
#define MAXN 100005

vector<int> g[MAXN];
int res[MAXN],mk[MAXN],p[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,u,v;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    priority_queue<int,vector<int>,greater<int> > pq;
    pq.push(1);
    p[1]=1;
    int cont=0;
    while(!pq.empty())
    {
        int u=pq.top();
        pq.pop();
        if(!mk[u])
        {
            res[cont]=u;
            cont++;
            mk[u]=1;
        }
        for(auto v : g[u])
            if(!p[v])
            {
                pq.push(v);
                p[v]=1;
            }
    }

    for(int i=0;i<n;i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}