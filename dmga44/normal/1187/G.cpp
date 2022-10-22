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

/*
    Minimum Cost Flow (Tomizawa, Edmonds-Karp)
    Complexity:
    O(F m log n), where F is the amount of maximum flow
    Tested:
    Codeforces [http://codeforces.com/problemset/problem/717/G]
*/
template<typename flow_type, typename cost_type>
struct min_cost_max_flow
{
    struct edge
    {
        size_t src, dst, rev;
        flow_type flow, cap;
        cost_type cost;
    };
    int n;
    vector<vector<edge>> adj;
    min_cost_max_flow(int n) : n(n), adj(n), potential(n), dist(n), back(n) {}
    void add_edge(size_t src, size_t dst, flow_type cap, cost_type cost)
    {
        adj[src].push_back({src, dst, adj[dst].size(), 0, cap, cost});
        if (src == dst)
            adj[src].back().rev++;
        adj[dst].push_back({dst, src, adj[src].size() - 1, 0, 0, -cost});
    }
    vector<cost_type> potential;
    inline cost_type rcost(const edge &e)
    {
        return e.cost + potential[e.src] - potential[e.dst];
    }

//    void bellman_ford(int source)
//    {
//        for (int k = 0; k < n; ++k)
//            for (int u = 0; u < n; ++u)
//                for (edge &e : adj[u])
//                    if (e.cap > 0 && rcost(e) < 0)
//                        potential[e.dst] += rcost(e);
//    }
    const cost_type oo = numeric_limits<cost_type>::max();
    vector<cost_type> dist;
    vector<edge * > back;
    cost_type dijkstra(int source, int sink)
    {
        fill(dist.begin(), dist.end(), oo);
        typedef pair<cost_type, int> node;
        priority_queue<node, vector<node>, greater<node>> pq;
        for (pq.push({dist[source] = 0, source}); !pq.empty();)
        {
            node p = pq.top();
            pq.pop();
            if (dist[p.second] < p.first)
                continue;
            if (p.second == sink)
                break;
            for (edge &e : adj[p.second])
                if (e.flow < e.cap &&
                        dist[e.dst] > dist[e.src] + rcost(e))
                {
                    back[e.dst] = &e;
                    pq.push({
                        dist[e.dst] = dist[e.src] + rcost(e),
                        e.dst
                    });
                }
        }
        return dist[sink];
    }
    pair<flow_type, cost_type> max_flow(int source, int sink)
    {
        flow_type flow = 0;
        cost_type cost = 0;
        for (int u = 0; u < n; ++u)
            for (edge &e : adj[u])
                e.flow = 0;
        potential.assign(n, 0);
        dist.assign(n, 0);
        back.assign(n, nullptr);
//        bellman_ford(source); // remove negative costs
        while (dijkstra(source, sink) < oo)
        {
            for (int u = 0; u < n; ++u)
            if (dist[u] < dist[sink])
                potential[u] += dist[u] - dist[sink];
            flow_type f = numeric_limits<flow_type>::max();
            for (edge * e = back[sink]; e; e = back[e->src])
                f = min(f, e->cap - e->flow);
            for (edge * e = back[sink]; e; e = back[e->src])
                e->flow += f, adj[e->dst][e->rev].flow -= f;
            flow += f;
            cost += f * (potential[sink] - potential[source]);
        }
        return {flow, cost};
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k,c,d,u,v;
    cin >> n >> m >> k >> c >> d;
    min_cost_max_flow<int,int> g((n+2)*102);
    for(int i=0;i<102;i++)
        g.add_edge((i*(n+2))+1,i*(n+2),100,(i*c));
    for(int i=0;i<101;i++)
        for(int j=0;j<n+1;j++)
            g.add_edge(j+(i*(n+2)),j+((i+1)*(n+2)),100,0);
    for(int i=0;i<k;i++)
    {
        cin >> u;
        g.add_edge(n+1,u,1,0);
    }

    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        for(int j=0;j<101;j++)
            for(int f=0;f<k;f++)
            {
                g.add_edge(u+(j*(n+2)),v+((j+1)*(n+2)),1,((2*f)+1)*d);
                g.add_edge(v+(j*(n+2)),u+((j+1)*(n+2)),1,((2*f)+1)*d);
            }
    }

    db(g.max_flow(n+1,(101*(n+2))).second)

    return 0;
}