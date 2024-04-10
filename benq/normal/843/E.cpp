#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

bool saturated[1000];

template<int SZ> struct Dinic {
    struct Edge {
        int v;
        ll flow, C;
        int rev, id;
    };
 
    int level[SZ], start[SZ], vis[SZ];
    vector<Edge> adj[SZ]; 
     
    void addEdge(int u, int v, ll C, int id = -1) {
        Edge a{v, 0, C, sz(adj[v]), id};
        Edge b{u, 0, 0, sz(adj[u]), -1};
        adj[u].pb(a), adj[v].pb(b); 
    } 
     
    void dfs(int s) {
        if (vis[s]) return; 
        vis[s] = 1;
        for (auto a: adj[s]) if (a.flow < a.C) dfs(a.v);
    }
    
    bool bfs(int s, int t) {
        F0R(i,SZ) level[i] = -1;
        level[s] = 0;  
      
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto e: adj[u]) 
                if (level[e.v] < 0  && e.flow < e.C) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
        }
     
        return level[t] >= 0;
    }
      
    ll sendFlow(int u, ll flow, int t) {
        if (u == t) return flow;
      
        for (  ; start[u] < sz(adj[u]); start[u] ++) {
            Edge &e = adj[u][start[u]]; 
                                          
            if (level[e.v] == level[u]+1 && e.flow < e.C) {
                ll curr_flow = min(flow, e.C - e.flow);
                ll temp_flow = sendFlow(e.v, curr_flow, t);
    
                if (temp_flow > 0) {
                    e.flow += temp_flow;
                    adj[e.v][e.rev].flow -= temp_flow;
                    return temp_flow;
                }
            }
        }
      
        return 0;
    }
     
    ll maxFlow(int s, int t) {
        if (s == t) return -1;
        ll total = 0;  
      
        while (bfs(s, t)) {
            F0R(i,SZ) start[i] = 0;
            while (ll flow = sendFlow(s, INT_MAX, t)) total += flow;
        }
        
        dfs(s);
        F0R(i,SZ) for (auto a: adj[i]) if (vis[i] && !vis[a.v]) 
            if (a.id != -1) {
                saturated[a.id] = 1;
                // cout << a.id << "\n";
            }
     
        return total;
    } 
};

Dinic<101> D;

struct edge {
    int u, v, flow, cap, g;
};

edge stor[1000];

struct Flow2 {
    bool vis[101];
    vi adj[101];
    
    bool dfs(int a, int b) {
        if (vis[a]) return 0;
        vis[a] = 1; if (a == b) return 1;
        for (int i: adj[a]) {
            stor[i].flow ++, stor[i].cap ++;
            if (dfs(stor[i].v,b)) return 1;
            stor[i].flow --, stor[i].cap --;
        }
        return 0;
    }
    
    void sendFlow(int a, int b) {
        memset(vis,0,sizeof vis);
        dfs(a,b);
    }
};

Flow2 D2;

int n,m,s,t;
pi ans[1000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> s >> t;
    F0R(i,m) {
        int u,v,g; cin >> u >> v >> g;
        stor[i] = {u,v,0,0,g};
        if (g == 0) D.addEdge(u,v,MOD);
        else {
            D.addEdge(u,v,1,i);
            D.addEdge(v,u,MOD);
        }
    }
    
    cout << D.maxFlow(s,t) << "\n";
    // FOR(i,1,n+1) cout << D.vis[i] << " ";
    F0R(i,m) if (stor[i].g) D2.adj[stor[i].u].pb(i);
    F0R(i,m) {
        if (stor[i].g) {
            D2.sendFlow(s,stor[i].u);
            stor[i].flow ++, stor[i].cap ++;
            D2.sendFlow(stor[i].v,t);
            if (!saturated[i]) stor[i].cap ++;
        } 
    }
    F0R(i,m) {
        if (stor[i].g) cout << stor[i].flow << " " << stor[i].cap << "\n";
        else cout << "0 1\n";
    }
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/