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
#define MAXN 300005

vector<pii> g[MAXN];
bool mk[MAXN];
int cant[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m,u,v;
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
            cin >> u >> v;
            g[u].push_back(pii(v,i+1));
            g[v].push_back(pii(u,i+1));
            cant[u]++;
            cant[v]++;
        }
        priority_queue<pii,vector<pii>,less<pii> > pq;
        for(int i=1;i<=3*n;i++)
            pq.push(pii(cant[i],i));

        vector<int> mat,ind;
        while(!pq.empty())
        {
            int u=pq.top().second;
            pq.pop();
            if(mk[u])
                continue;
            bool ok=0;
            for(auto y : g[u])
                if(!mk[y.first])
                {
                    mk[y.first]=1;
                    mk[u]=1;
                    mat.push_back(y.second);
                    ok=1;
                    break;
                }
            if(!ok)
                ind.push_back(u);
        }

        if(mat.size()>=n)
        {
            db("Matching")
            for(int i=0;i<n;i++)
                cout << mat[i] << ' ';
            cout << '\n';
        }
        else if(ind.size()>=n)
        {
            db("IndSet")
            for(int i=0;i<n;i++)
                cout << ind[i] << ' ';
            cout << '\n';
        }

        for(int i=0;i<=3*n+1;i++)
        {
            g[i].clear();
            cant[i]=0;
            mk[i]=0;
        }

//        dinic<int> g(6*n+2);
//        for(int i=1;i<=3*n;i++)
//        {
//            g.add_edge(0,(2*i)-1,1);
//            g.add_edge((2*i),6*n+1,1);
//        }
//        map<pii,int> ma;
//        for(int i=0;i<m;i++)
//        {
//            cin >> u >> v;
//            ma[pii(u,v)]=i+1;
//            ma[pii(v,u)]=i+1;
//            g.add_edge(u*2-1,2*v,1);
//            g.add_edge(2*v-1,2*u,1);
//        }
//
//        int x=g.max_flow(0,6*n+1);
//
//        if(x>=2*n)
//        {
//            db("Matching")
//            map<pii,bool> mi;
//            int cont=n;
//            for(int i=1;i<6*n+1;i++)
//                for(auto y : g.adj[i])
//                {
//                    int dst=y.dst;
//                    int iu=(i+1)/2;
//                    int iv=(dst+1)/2;
//                    if(dst!=0 && dst!=6*n+1 && y.flow==1 && !mi[pii(iu,iv)] && cont)
//                    {
//                        cont--;
//                        cout << ma[pii(iu,iv)] << ' ';
//                        mi[pii(iu,iv)]=1;
//                        mi[pii(iv,iu)]=1;
//                    }
//                }
//            cout << '\n';
//        }
//        else
//        {
//            db("IndSet")
//            int cont=n;
//            for(int i=1;i<=3*n;i++)
//            {
//                bool ok=0;
//                for(auto y : g.adj[2*i-1])
//                    ok|=y.flow;
//                for(auto y : g.adj[2*i])
//                    ok|=y.flow;
//                if(!ok && cont)
//                {
//                    cout << i << ' ';
//                    cont--;
//                }
//            }
//            cout << '\n';
//        }
    }

    return 0;
}