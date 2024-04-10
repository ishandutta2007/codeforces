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
const int MX = 300001;

ll n,q,a[MX];
vpi adj[MX];
ll ansChild[MX], ansFromPar[MX], ansToPar[MX], edgePar[MX];

template<int SZ> struct LCA {
    const int MAXK = 32-__builtin_clz(SZ);
    
    int N, R = 1; // vertices from 1 to N, R = root
    int par[32-__builtin_clz(SZ)][SZ], depth[SZ];
    ll A[MX], B[MX];
    
    void dfs(int u, int prev){
        par[0][u] = prev;
        depth[u] = depth[prev]+1;
        A[u] += A[prev];
        for (auto v: adj[u]) if (v.f != prev) dfs(v.f, u);
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
    
    void dfs0(int cur, int pre) {
        ansChild[cur] = a[cur];
        for (pi i: adj[cur]) if (i.f != pre) {
            dfs0(i.f,cur);
            edgePar[i.f] = i.s;
            ansFromPar[i.f] = max(0LL,ansChild[i.f]-2*i.s);
            ansChild[cur] += ansFromPar[i.f];
        }
    }
    
    void dfs1(int cur, int pre) {
        for (pi i: adj[cur]) if (i.f != pre) {
            ansToPar[i.f] = max(ansToPar[cur]+ansChild[cur]-ansFromPar[i.f]-2*i.s,0LL);
            dfs1(i.f,cur);
        }
    }
    
    void gen() {
        dfs0(1,0);
        dfs1(1,0);
        
        FOR(i,1,n+1) {
            A[i] = ansChild[i]-ansFromPar[i]-edgePar[i];
            B[i] = ansFromPar[i]+ansToPar[i]+edgePar[i];
        }
            
        init(n);
    }
    
    ll query(int u, int v) {
        int x = lca(u,v);
        return A[u]+A[v]-A[x]-A[par[0][x]]+B[x];
    }
};

LCA<MX> L;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

int main() {
    io();
    cin >> n >> q;
    FOR(i,1,n+1) cin >> a[i];
    F0R(i,n-1) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].pb({v,w}), adj[v].pb({u,w});
    }
    L.gen();
    F0R(i,q) {
        int u,v; cin >> u >> v;
        cout << L.query(u,v) << "\n";
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/