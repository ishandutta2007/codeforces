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
#define MAXN 105
#define oo2 (ll(1e9+5))

int d[MAXN][MAXN],mk[MAXN];
vector<int> g[MAXN];
int ss[MAXN*10][3];

template<typename flow_type>
struct dinic
{
    struct edge
    {
        size_t src, dst, rev;
        flow_type flow, cap;
    };
    int n;
    vector<vector<edge>> adj;
    dinic(int n) : n(n), adj(n), level(n), q(n), it(n) {}
    void add_edge(size_t src, size_t dst, flow_type cap, flow_type rcap = 0)
    {
        adj[src].push_back({src, dst, adj[dst].size(), 0, cap});
        if (src == dst)
            adj[src].back().rev++;
        adj[dst].push_back({dst, src, adj[src].size() - 1, 0, rcap});
    }
    vector<int> level, q, it;
    bool bfs(int source, int sink)
    {
        fill(level.begin(), level.end(), -1);
        for (int qf = level[q[0] = sink] = 0, qb = 1; qf < qb; ++qf)
        {
            sink = q[qf];
            for (edge &e : adj[sink])
            {
                edge &r = adj[e.dst][e.rev];
                if (r.flow < r.cap && level[e.dst] == -1)
                    level[q[qb++] = e.dst] = 1 + level[sink];
            }
        }
        return level[source] != -1;
    }
    flow_type augment(int source, int sink, flow_type flow)
    {
        if (source == sink)
            return flow;
        for (; it[source] != adj[source].size(); ++it[source])
        {
            edge &e = adj[source][it[source]];
            if (e.flow < e.cap && level[e.dst] + 1 == level[source])
            {
                flow_type delta = augment(e.dst, sink,
                                          min(flow, e.cap - e.flow));
                if (delta > 0)
                {
                    e.flow += delta;
                    adj[e.dst][e.rev].flow -= delta;
                    return delta;
                }
            }
        }
        return 0;
    }
    flow_type max_flow(int source, int sink)
    {
        for (int u = 0; u < n; ++u)
            for (edge &e : adj[u])
                e.flow = 0;
        flow_type flow = 0;
        flow_type oo = numeric_limits<flow_type>::max();
        while (bfs(source, sink))
        {
            fill(it.begin(), it.end(), 0);
            for (flow_type f; (f = augment(source, sink, oo)) > 0;)
                flow += f;
        } // level[u] = -1 => source side of min cut
        return flow;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    ll n,m,u,v;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            d[i][j]=oo2;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
//        g[u].push_back(v);
//        g[v].push_back(u);
        d[u][v]=d[v][u]=1;
    }

    for(int i=0;i<n;i++)
        d[i][i]=0;

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<n;j++)
//            d[i][j]=oo2,mk[j]=0;
//        d[i][i]=0;
//        queue<int> q;
//        mk[i]=1;
//        for(q.push(i);!q.empty();q.pop())
//        {
//            u=q.front();
//            for(auto v : g[u])
//            {
//                if(!mk[v])
//                {
//                    mk[v]=1;
//                    d[i][v]=d[i][u]+1;
//                    q.push(v);
//                }
//            }
//        }
//    }

//    for(int i=0;i<n;i++,cout << '\n')
//        for(int j=0;j<n;j++)
//            cout << d[i][j] << ' ';

    ll s,b,k,h;
    cin >> s >> b >> k >> h;
    dinic<int> din(2+s+b);
    for(ll i=0;i<s;i++)
    {
//        din.add_edge(0,i+1,h);
        din.add_edge(0,i+1,1);
//        din.add_edge(i+1,s+b+1+i+1,h);
//        din.add_edge(s+b+i+2,s+b+1,oo2);
        cin >> ss[i][0] >> ss[i][1] >> ss[i][2];
        ss[i][0]--;
    }

    for(ll i=0;i<b;i++)
    {
        cin >> u >> v;
        u--;
        for(ll j=0;j<s;j++)
            if(d[u][ss[j][0]]<=ss[j][2] && v<=ss[j][1])
                din.add_edge(j+1,s+i+1,oo2);
        din.add_edge(s+i+1,s+b+1,1);
    }

    db(min((1ll*din.max_flow(0,s+b+1)*k),s*h))

    return 0;
}