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
const int MX = 200010;

vpi ed;
pi d[MX];

template<int SZ> struct LCA {
    const int MAXK = 32-__builtin_clz(SZ);
    
    int N, R = 1; // vertices from 1 to N, R = root
    vi edges[SZ];
    int parK[32-__builtin_clz(SZ)][SZ], pathK[32-__builtin_clz(SZ)][SZ], depth[SZ];
    
    void addEdge(int u, int v) {
        edges[u].pb(v), edges[v].pb(u);
    }
    
    void dfs(int u, int prev){
        parK[0][u] = prev;
        depth[u] = depth[prev]+1;
        for (int v: edges[u]) if (v != prev) dfs(v, u);
    }
    
    void construct() {
        dfs(R, 0);
        FOR(k,1,MAXK) FOR(i,1,N+1)
            parK[k][i] = parK[k-1][parK[k-1][i]];
    }
    
    int lca(int u, int v){
        if (depth[u] < depth[v]) swap(u,v);
        
        F0Rd(k,MAXK) if (depth[u] >= depth[v]+(1<<k))  u = parK[k][u];
        F0Rd(k,MAXK) if (parK[k][u] != parK[k][v]) u = parK[k][u], v = parK[k][v];
        
        if(u != v) u = parK[0][u], v = parK[0][v];
        return u;
    }
    
    pi get(int u, int v) {
        int ans = 0;
        F0Rd(k,MAXK) if (depth[v] < depth[pathK[k][u]]) {
            ans ^= 1<<k;
            u = pathK[k][u];
        }
        if (depth[pathK[0][u]] > depth[v]) return {MOD,MOD};
        return {ans,u};
    }
    
    int dist(int u, int v) {
        return depth[u]+depth[v]-2*depth[lca(u,v)];
    }
};


LCA<MX> L;
int n, ans[MX], tmp[MX], q;
bool ok[MX];
vi adj[MX];
vector<pair<pi,int>> ad[MX], del[MX];

int bet(int x, int y) {
    if (L.depth[x] < L.depth[y]) return x;
    return y;
}

void genPath() {
    int m; cin >> m;
    FOR(i,1,L.N+1) L.pathK[0][i] = i;
    F0R(i,m) {
        int a,b; cin >> a >> b;
        ed.pb({a,b});
        int c = L.lca(a,b);
        
        L.pathK[0][a] = bet(c,L.pathK[0][a]);
        L.pathK[0][b] = bet(c,L.pathK[0][b]);
    }
    
    FORd(i,2,L.N+1) L.pathK[0][L.parK[0][i]] = bet(L.pathK[0][L.parK[0][i]],L.pathK[0][i]);
    FOR(k,1,L.MAXK) FOR(i,1,L.N+1)
        L.pathK[k][i] = L.pathK[k-1][L.pathK[k-1][i]];
}

template<class T, int SZ> struct Seg {
    T seg[2*SZ], MN = 0;
    
    Seg() {
        memset(seg,0,sizeof seg);
    }
    
    T comb(T a, T b) { return a+b; } // easily change this to min or max
    
    void upd(int p, T value) {  // set value at position p
        for (seg[p += SZ] += value; p > 1; p >>= 1)
            seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]); // non-commutative operations
    }
    
    void build() {
        F0Rd(i,SZ) seg[i] = comb(seg[2*i],seg[2*i+1]);
    }
    
    T query(int l, int r) {  // sum on interval [l, r]
        T res1 = MN, res2 = MN; r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) res1 = comb(res1,seg[l++]);
            if (r&1) res2 = comb(seg[--r],res2);
        }
        return comb(res1,res2);
    }
};

Seg<int,1<<18> B;

void finish() {
    for (auto a: ed) adj[max(d[a.f].f,d[a.s].f)].pb(min(d[a.f].f,d[a.s].f));
    // if no direct path add one 
    F0R(i,L.N+1) {
        for (auto z: ad[i]) tmp[z.s] -= B.query(z.f.f,z.f.s);
        for (auto z: del[i]) tmp[z.s] += B.query(z.f.f,z.f.s);
        
        for (int j: adj[i]) B.upd(j,1);
    }
    F0R(i,q) if (ok[i]) ans[i] += (tmp[i] == 0);
}

int co = 0;

void dfs(int x) {
    d[x].f = co++;
    for (int i: L.edges[x]) if (i != L.parK[0][x]) dfs(i);
    d[x].s = co-1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> L.N;
    FOR(i,2,L.N+1) {
        int x; cin >> x;
        L.addEdge(x,i);
    }
    L.construct();
    genPath();
    
    dfs(1);
    cin >> q;
    F0R(i,q) {
        int u,v; cin >> u >> v;
        int c = L.lca(u,v);
        pi U = L.get(u,c), V = L.get(v,c);
        //cout << u << " " << v << " " << c << " " << U.f << " " << U.s << " " << V.f << " " << V.s << "\n";
        //cout << L.pathK[0][u] << " " << L.pathK[0][v] << "\n";
        if (U.f+V.f >= MOD) ans[i] = -1;
        else {
            ans[i] = U.f+V.f+1;
            pi x = d[U.s], y = d[V.s];
            if (x > y) swap(x,y);
            if (x.s < y.f) {
                ok[i] = 1;
                ad[y.f].pb({x,i});
                del[y.s+1].pb({x,i});
            }
        }
    }
    
    finish();
    F0R(i,q) cout << ans[i] << "\n";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)