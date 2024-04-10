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

template<int SZ> struct DSU {
    int par[SZ], sz[SZ];
    DSU() {
        F0R(i,SZ) par[i] = i, sz[i] = 1;
    }
    
    int get(int x) { // path compression
    	if (par[x] != x) par[x] = get(par[x]);
    	return par[x];
    }
    
    bool unite(int x, int y) { // union-by-rank
    	x = get(x), y = get(y);
    	if (x == y) return 0;
    	if (sz[x] < sz[y]) swap(x,y);
    	sz[x] += sz[y], par[y] = x;
    	return 1;
    }
};


template<int SZ> struct BCC {
    int N, ti = 0;
    vi adj[SZ], ADJ[SZ];
    int disc[SZ], low[SZ], comp[SZ], par[SZ];
    vector<vpi> fin;
    vpi st;
    DSU<SZ> D;
    
    void addEdge(int u, int v) {
        adj[u].pb(v), adj[v].pb(u);
    }
    
    void BCCutil(int u, bool root = 0) {
        disc[u] = low[u] = ti++;
        int child = 0;
        
        for (int i: adj[u]) if (i != par[u]) {
            if (disc[i] == -1) {
                child ++; par[i] = u;
                st.pb({u,i});
                BCCutil(i);
                low[u] = min(low[u],low[i]);
                
                if (disc[u] < low[i]) { 
                    // bridge
                } else {
                    D.unite(u,i);
                }
            } else if (disc[i] < disc[u]) {
                low[u] = min(low[u],disc[i]);
                D.unite(u,i);
            }
        }
    }
    
    void bcc() {
        FOR(i,1,N+1) par[i] = disc[i] = low[i] = -1;
        FOR(i,1,N+1) if (disc[i] == -1) {
            BCCutil(i,1);
            if (sz(st)) fin.pb(st);
            st.clear();
        }
        FOR(i,1,N+1) for (int j: adj[i]) if (D.get(i) != D.get(j)) 
            ADJ[D.get(i)].pb(D.get(j));
    }
    
    pi dfs(int x, int p = 0) {
        vi dist = {0,0};
        int bes = 0;
        for (int i: ADJ[x]) if (i != p) {
            auto a = dfs(i,x);
            dist.pb(a.f+1);
            bes = max(bes,a.s);
        }
        sort(dist.rbegin(),dist.rend());
        bes = max(bes,dist[0]+dist[1]);
        return {dist[0],bes};
    }
    
    int solve() {
        FOR(i,1,N+1) if (D.get(i) == i) return dfs(i).s;
        exit(5);
    }
};

BCC<MX> B;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

int n,m;

int main() {
    io();
    cin >> n >> m;
    B.N = n;
    F0R(i,m) {
        int a,b; cin >> a >> b;
        B.addEdge(a,b);
    }
    B.bcc();
    cout << B.solve();
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/