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
int _runtimeTerror_()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<set<int>> g(n+1),rg(n+1);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].insert(y);
        rg[y].insert(x);
    }
    vector<ll> x(k+1),y(k+1);
    for(int i=1;i<=k;++i)
        cin>>x[i]>>y[i];

    vector<ll> costs;
    vector<ll> move;
    int left = -1,right = -1;
    auto get = [&](vector<set<int>> &g,bool rev)
    {
        left = right = -1;
        Dinic<ll> flow(2*n+3,0,2*n+1);
        for(int i=1;i<=n;++i)
        {
            flow.add_edge(0,i,1);
            flow.add_edge(i+n,2*n+1,1);
            for(auto j:g[i])
            {
                if(!rev)
                    flow.add_edge(i,j+n,1);
                else
                    flow.add_edge(j,i+n,1);
            }
        }
        auto u = flow.flow();
        for(int i=1;i<=n;++i)
        {
            if(left != -1)
                break;
            for(auto j:flow.adj[i])
            {
                if(flow.edges[j].flow == 1)
                {
                    left = i;
                    right = flow.edges[j].u - n;
                    break;
                }
            }
        }
        return u;
    };
    vector<int> want(k+1,0);
    for(int i=1;i<=k;++i)
    {   
        int uu = i;
        if(n - get(g,false) > i)
            costs.push_back(0),move.push_back(0),want[i] = 0;
        else
        {
            bool can = false;
            for(int i=1;i<=n;++i)
            {
                if(g[i].empty())
                    continue;
                auto u = g;
                g[i].clear();
                if(n - get(g,false) > uu)
                {
                    costs.push_back(1);
                    move.push_back(i);
                    can = true;
                    for(auto j:u[i])
                        rg[j].erase(i);
                    break;
                }
                g[i] = u[i];
            }
            if(can)
            {
                want[i] = 1;
                continue;
            }
            for(int i=1;i<=n;++i)
            {
                if(rg[i].empty())
                    continue;
                auto u = rg;
                rg[i].clear();
                if(n - get(rg,true) > uu)
                {
                    costs.push_back(1);
                    move.push_back(-i);
                    can = true;
                    for(auto j:u[i])
                        g[j].erase(i);
                    break;
                }
                rg[i] = u[i];
            }
            if(can)
            {
                want[i] = 1;
                continue;
            }
            for(auto j:g[left])
                rg[j].erase(left);
            g[left].clear();
            for(auto j:rg[right])
                g[j].erase(right);
            rg[right].clear();
            costs.push_back(1);
            costs.push_back(1);
            move.push_back(left);
            move.push_back(-right);
            want[i] = 2;
        }
    }
    for(int i=1;i<=k;++i)
        want[i] += want[i-1];
    vector<vector<ll>> dp(k+1,vector<ll>(2*n+1,-INF));
    dp[0][0] = 0;
    for(int i=1;i<=k;++i)
    {
        for(int j=0;j<=sz(costs);++j)
        {
            if(j < want[i])
            {
                dp[i][j] = -INF;
                continue;
            }
            for(int k=0;k<=j;++k)
                amax(dp[i][j],dp[i-1][j-k] + max(0ll,x[i] - k * y[i]));
        }
    }
    ll ans = -INF;
    int last = -1;
    for(int i=0;i<=2*n;++i)
    {
        if(dp[k][i] > ans)
            amax(ans,dp[k][i]),last = i;
    }
    vector<int> val;
    val.push_back(0);
    for(int i=k-1;i>=0;--i)
    {
        for(int j=0;j<=2*n;++j)
        {
            if(j <= last && dp[i][j] + max(0ll,x[i+1] - (last-j)*y[i+1])== ans)
            {
                int k = last - j;
                ans -= max(0ll,x[i+1] - k * y[i+1]);
                while(k--)
                {
                    val.push_back(move.back());
                    move.pop_back();
                }
                last = j;
            }
        }
        if(i)
            val.push_back(0);
    }
    cout<<sz(val)<<"\n";
    reverse(all(val));
    for(auto j:val)
        cout<<j<<" ";
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
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}