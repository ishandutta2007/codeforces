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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int n,m,cur[MX];
bool away[MX];
int pos[MX], en[MX];
 
template<int SZ> struct LCA {
    const int MAXK = 32-__builtin_clz(SZ);
    
    int N, R = 1; // vertices from 1 to N, R = root
    vi adj[SZ];
    int par[32-__builtin_clz(SZ)][SZ], depth[SZ];
    
    void addEdge(int u, int v) {
        adj[u].pb(v), adj[v].pb(u);
    }
    
    int co = 0;
    void dfs(int u, int prev) {
        par[0][u] = prev;
        depth[u] = depth[prev]+1;
        pos[u] = co ++;
        for (int v: adj[u]) if (v != prev) dfs(v, u);
        en[u] = co-1;
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
        return depth[u]+depth[v]-2*depth[lca(u,v)];
    }
};
 
LCA<MX> L;
 
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    FOR(i,2,n+1) {
        int x; cin >> x;
        L.addEdge(i,x);
    }
    L.init(n);
    FOR(i,1,n+1) cin >> cur[i];
    // answer: # of i such that cur[i] < 0 && away[i] == 0
}
 
struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = 
            chrono::steady_clock::now()
            .time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
// template<class K, class V> using um = unordered_map<K, V, chash>;
template<class K, class V> using um = gp_hash_table<K, V, chash>;
 
/*template<class K, class V> V get(ht<K,V>& u, K x) {
    return u.find(x) == end(u) ? 0 : u[x];
}*/
 
um<int,int> u;
 
int par[MX], cadd[MX], cans;
um<int,int> val[MX];
 
void fill(int x, bool b = 0) {
    for (int X = L.par[0][x]; X != par[x]; X = L.par[0][X]) {
        if (b == 0) {
            if (!away[X]) val[x][cur[X]] ++;
        } else {
            cur[X] += cadd[x];
        }
    }
}
 
void genTree(vi x) {
    FOR(i,1,n+1) {
        val[i].clear();
        par[i] = cadd[i] = 0;
    }
    sort(all(x),[](int a, int b) { return pos[a] < pos[b]; });
    vi st;
    for (int i: x) {
        if (sz(st) && st.back() == i) continue;
        while (sz(st) && en[st.back()] < pos[i]) st.pop_back();
        if (sz(st)) {
            par[i] = st.back();
            // cout << "OOPS " << i << " " << par[i] << " " << L.par[0][i] << "\n";
            fill(i);
        }
        st.pb(i);
    }
    // exit(0);
}
 
int get(um<int,int>& u, int x) {
    if (u.find(x) == u.end()) return 0;
	return u[x];
}
 
void process(int x) {
    if (x > 0) {
        away[x] = 1; if (cur[x] < 0) cans --;
        while (x) {
            cadd[x] --; cur[x] --;
            if (cur[x] == -1 && !away[x]) cans ++;
            cans += get(val[x],-1-cadd[x]); 
            x = par[x];
        }
    } else {
        x = abs(x);
        away[x] = 0; if (cur[x] < 0) cans ++;
        while (x) {
            cadd[x] ++; cur[x] ++;
            if (cur[x] == 0 && !away[x]) cans --;
            cans -= get(val[x],-cadd[x]);
            x = par[x];
        }
    }
}
 
void fixStuff() {
    FOR(i,1,n+1) if (par[i]) fill(i,1);
}
 
void solve(vi todo) {
    vi tmp; for (int i: todo) tmp.pb(abs(i)); tmp.pb(1);
    sort(all(tmp),[](int a, int b) { return pos[a] < pos[b]; }); 
    vi ne; F0R(i,sz(tmp)-1) ne.pb(L.lca(tmp[i],tmp[i+1]));
    tmp.insert(tmp.end(),all(ne));
    genTree(tmp);
    
    for (int i: todo) {
        process(i);
        cout << cans << " ";
    }
    
    fixStuff();
}
 
int main() {
    init();
    vi todo;
    F0R(i,m) {
        int q; cin >> q;
        todo.pb(q);
        if (sz(todo) >= 300) { // 
            solve(todo);
            todo.clear();
        }
    }
    solve(todo);
}
 
/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/