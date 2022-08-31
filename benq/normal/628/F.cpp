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

 
struct Edge {
    int v;
    ll flow, C;
    int rev;
};
 
template<int SZ> struct Dinic {
    int level[SZ], start[SZ];
    vector<Edge> adj[SZ]; 
     
    void addEdge(int u, int v, ll C) {
        Edge a{v, 0, C, sz(adj[v])};
        Edge b{u, 0, 0, sz(adj[u])};
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

Dinic<21000> D;

int n,b,q;
vpi v;

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> b >> q;
    v.pb({b,n});
    v.pb({0,0});
    F0R(i,q) {
        int x,y; cin >> x >> y;
        v.pb({x,y});
    }
    sort(all(v)); v.erase(unique(all(v)),v.end());
    F0R(i,sz(v)-1) 
        if (v[i].s > v[i+1].s || (v[i].f == v[i+1].f && v[i].s != v[i+1].s)) {
            cout << "unfair";
            exit(0);
        }
}

int main() {
    init();
    F0R(i,sz(v)-1) {
        D.addEdge(0,b+1+i,v[i+1].s-v[i].s);
        FOR(j,v[i].f+1,v[i+1].f+1) D.addEdge(b+1+i,j,1);
    }
    FOR(i,1,b+1) D.addEdge(i,20100+(i%5),1);
    F0R(i,5) D.addEdge(20100+i,20105,n/5);
    
    if (D.maxFlow(0,20105) == n) {
        cout << "fair";
        exit(0);
    }
    cout << "unfair";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/