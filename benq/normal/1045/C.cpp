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
const int MX = 200001;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
        setIn(s+".in");
        setOut(s+".out");
    }
}


template<int SZ> struct BCC {
    int N;
    vi adj[SZ];
    vector<vpi> fin;
    
    void addEdge(int u, int v) { adj[u].pb(v), adj[v].pb(u); }
    
    int ti = 0, disc[SZ], low[SZ], comp[SZ], par[SZ];
    vpi st;

    void BCCutil(int u, bool root = 0) {
        disc[u] = low[u] = ti++;
        int child = 0;
        
        for (int i: adj[u]) if (i != par[u]) 
            if (disc[i] == -1) {
                child ++; par[i] = u;
                st.pb({u,i});
                BCCutil(i);
                low[u] = min(low[u],low[i]);
                
                if ((root && child > 1) || (!root && disc[u] <= low[i])) { // articulation point!
                    vpi tmp;
                    while (st.back() != mp(u,i)) tmp.pb(st.back()), st.pop_back();
                    tmp.pb(st.back()), st.pop_back();
                    fin.pb(tmp);
                }
            } else if (disc[i] < disc[u]) {
                low[u] = min(low[u],disc[i]);
                st.pb({u,i});
            }
    }
    
    void bcc(int _N) {
        N = _N;
        FOR(i,1,N+1) par[i] = disc[i] = low[i] = -1;
        FOR(i,1,N+1) if (disc[i] == -1) {
            BCCutil(i,1);
            if (sz(st)) fin.pb(st);
            st.clear();
        }
    }
};

template<int SZ> struct LCA {
    const int MAXK = 32-__builtin_clz(SZ);
    
    int N, R = 1; // vertices from 1 to N, R = root
    vi adj[SZ];
    int par[32-__builtin_clz(SZ)][SZ], depth[SZ], sum[SZ];
    
    void addEdge(int u, int v) {
        adj[u].pb(v), adj[v].pb(u);
    }
    
    void dfs(int u, int prev){
        par[0][u] = prev;
        sum[u] += sum[par[0][u]];
        depth[u] = depth[prev]+1;
        for (int v: adj[u]) if (v != prev) dfs(v, u);
    }
    
    void init(int _N) {
    	N = _N;
        dfs(R, 0);
        FOR(k,1,MAXK) FOR(i,1,N+1)
            par[k][i] = par[k-1][par[k-1][i]];
    }
    
    int lca(int u, int v){
        if (depth[u] < depth[v]) swap(u,v);
        
        F0Rd(k,MAXK) if (depth[u] >= depth[v]+(1<<k))  u = par[k][u];
        F0Rd(k,MAXK) if (par[k][u] != par[k][v]) u = par[k][u], v = par[k][v];
        
        if(u != v) u = par[0][u], v = par[0][v];
        return u;
    }
    
    int dist(int u, int v) {
        int L = lca(u,v);
        return sum[u]+sum[v]-sum[L]-sum[par[0][L]];
    }
};

LCA<MX> L;
BCC<MX> B;

int N,M,Q;

int main() {
    io();
    cin >> N >> M >> Q;
    F0R(i,M) {
        int a,b; cin >> a >> b;
        B.addEdge(a,b);
    }
    B.bcc(N);
    F0R(i,sz(B.fin)) {
        auto a = B.fin[i];
        set<int> S;
        for (auto t: a) S.insert(t.f), S.insert(t.s);
        for (int j: S) L.addEdge(j,i+1+N);
        L.sum[i+1+N] = 1;
    }
    L.init(N+sz(B.fin));
    F0R(i,Q) {
        int a,b; cin >> a >> b;
        cout << L.dist(a,b) << "\n";
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/