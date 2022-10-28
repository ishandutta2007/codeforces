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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif
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
    int n,h,m;
    cin>>n>>h>>m;
    Dinic<ll> flow(n*h+n+m+10,0,n*h+n+m+2);
    int s = 0,t = n * h + n + m + 2;
    int cur = 1;
    vector<vector<int>> H(n+1,vector<int>(h+1,0));
    for(int i=1;i<=n;++i)
        for(int j=0;j<=h;++j)
            H[i][j] = cur++;
    int ans = n * h * h;
    for(int i=1;i<=n;++i)
        flow.add_edge(s,H[i][0],1e12);
    for(int i=1;i<=n;++i)
    {
        for(int j=h;j>=1;--j)
            flow.add_edge(H[i][j],H[i][j-1],1e12);
        for(int j=0;j<=h-1;++j)
        {
            flow.add_edge(H[i][j],H[i][j+1],h*h - (j)*(j));
        }
    }
    --cur;
    assert(cur == n * (h + 1));
    for(int i=1;i<=m;++i)
    {
        int l,r,x,c;
        cin>>l>>r>>x>>c;
        ++x;
        flow.add_edge(i+cur,t,c);
        for(int j=l;j<=r;++j)
            if(x <= h)
                flow.add_edge(H[j][x],i+cur,1e12);
        assert(i+cur < t);
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