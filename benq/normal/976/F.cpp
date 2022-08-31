#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
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

struct Edge {
    int v;
    ll flow, C;
    int rev,id;
};

template<int SZ> struct Dinic {
    int level[SZ], start[SZ];
    vector<Edge> adj[SZ]; 
     
    void addEdge(int u, int v, ll C, int id = -1) {
        Edge a{v, 0, C, sz(adj[v]),id};
        Edge b{u, 0, 0, sz(adj[u]),id};
        adj[u].pb(a), adj[v].pb(b); 
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
     
        return total;
    } 
};

int n1,n2,m;
vpi edge;
Dinic<4002> P = Dinic<4002>();
int deg[4002];
bool ok[4002];

void solve(int x) {
    P.maxFlow(0,n1+n2+1);
    F0R(i,n1+n2+2) deg[i] = 0;
    F0R(i,4002) ok[i] = 0;
    vi ans;
    FOR(i,1,n1+1)  for (auto& a: P.adj[i]) if (i != 0 && a.flow > 0) {
        deg[i] ++;
        deg[a.v] ++;
        ok[a.id] = 1;
        ans.pb(a.id);
    }
    F0R(i,sz(edge)) if (!ok[i+1] && min(deg[edge[i].f],deg[edge[i].s]) < x) {
        ok[i+1] = 1;
        ans.pb(i+1);
        deg[edge[i].f] ++;
        deg[edge[i].s] ++;
    }
    
    cout << sz(ans) << " ";
    for (int i: ans) cout << i << " ";
    cout << "\n";
    for (auto& a: P.adj[0]) if (a.v <= n1) a.C ++;
    FOR(i,n1+1,n1+n2+1) for (auto& a: P.adj[i]) if (a.v == n1+n2+1) a.C ++; 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n1 >> n2 >> m;
    FOR(i,1,n1+1) P.addEdge(0,i,0);
    FOR(i,n1,n1+n2+1) P.addEdge(i,n1+n2+1,0);
    F0R(i,m) {
        int a,b; cin >> a >> b;
        edge.pb({a,n1+b});
        P.addEdge(a,n1+b,1,i+1);
        deg[a] ++, deg[b+n1] ++;
    }
    int mx = MOD;
    FOR(i,1,n1+n2+1) mx = min(mx,deg[i]);
    F0R(i,mx+1) solve(i);
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)