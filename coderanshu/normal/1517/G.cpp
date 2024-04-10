#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

template<typename flow_t = long long>
struct Dinic {
    struct FlowEdge 
    {
        int v, u;
        flow_t cap, flow = 0;
        FlowEdge(int v, int u, flow_t cap) : v(v), u(u), cap(cap) {}
    };
    const flow_t flow_inf = numeric_limits<flow_t>::max()/2;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    // s -> source
    // t -> sink
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) 
    {
        adj.resize(n+1);
        level.resize(n+1);
        ptr.resize(n+1);
    }

    void add_edge(int v, int u, flow_t cap) 
    {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() 
    {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    flow_t dfs(int v, flow_t pushed) 
    {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            flow_t tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    flow_t flow() 
    {
        flow_t f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (flow_t pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
// .add_edge(u,v,cap);u->v
// .flow() == maxFlow

int _runtimeTerror_()
{
    int n;
    cin>>n;
    Dinic<ll> flow(2*n+2,0,2*n+1);
    vector<ll> x(n+1),y(n+1),w(n+1);
    auto get = [&](int i,int j)
    {
        if(j%2 == 0)
        {
            if(i%2 == 0)
                return 1;
            return 0;
        }
        if(i%2 == 0)
            return 2;
        return 3;
    };
    ll ans = 0;
    for(int i=1;i<=n;++i)
    {
        cin>>x[i]>>y[i]>>w[i];
        ans += w[i];
        flow.add_edge(n+i,i,w[i]);
        if(get(x[i],y[i]) == 0)
            flow.add_edge(0,n+i,1e13);
        if(get(x[i],y[i]) == 3)
            flow.add_edge(i,2*n+1,1e13);
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(i == j)
                continue;
            if(get(x[j],y[j]) == 1 + get(x[i],y[i]) && (abs(x[i]-x[j]) + abs(y[i]-y[j]) == 1))
                flow.add_edge(i,n+j,1e13);
        }
    }
    ans -= flow.flow();
    cout<<ans<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}