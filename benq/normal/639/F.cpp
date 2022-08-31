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

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 300005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}

using namespace io;

template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    template<class U> modular(const U& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular exp(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { 
        auto i = invGeneral(a.val,MOD); assert(i != -1);
        return i;
    } // equivalent to return exp(b,MOD-2) if MOD is prime
    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;


template<int SZ> struct LCA {
    static const int BITS = 32-__builtin_clz(SZ);

    int N, R = 1; // vertices from 1 to N, R = root
    vi adj[SZ];
    int par[BITS][SZ], depth[SZ];

    // INITIALIZE

    void addEdge(int u, int v) { adj[u].pb(v), adj[v].pb(u); }

    void dfs(int u, int prev){
        par[0][u] = prev;
        depth[u] = depth[prev]+1;
        trav(v,adj[u]) if (v != prev) dfs(v, u);
    }

    void init(int _N) {
    	N = _N; 
        FOR(k,1,BITS) FOR(i,1,N+1) par[k][i] = par[k-1][par[k-1][i]];
    }

    // QUERY

    int getPar(int a, int b) {
        F0Rd(k,BITS) if (b&(1<<k)) a = par[k][a];
        return a;
    }

    int lca(int u, int v){
        if (depth[u] < depth[v]) swap(u,v);
        u = getPar(u,depth[u]-depth[v]);
        F0Rd(k,BITS) if (par[k][u] != par[k][v]) u = par[k][u], v = par[k][v];
        return u == v ? u : par[0][u];
    }

    int dist(int u, int v) {
        return depth[u]+depth[v]-2*depth[lca(u,v)];
    }
};

LCA<MX> L;

int n,m,q;
ll R = 0;

int rotate(int element) {
   element=(element+R)%n;

   if (element==0) {
       element=n;
   }

   return element;
}

template<int SZ> struct DSU {
    int par[SZ];

    DSU() {
        F0R(i,SZ) par[i] = i;
    }

    int get(int x) { // path compression
    	if (par[x] != x) par[x] = get(par[x]);
    	return par[x];
    }

    bool unite(int x, int y) { // union-by-rank
    	x = get(x), y = get(y);
    	if (x == y) return 0;
    	par[y] = x;
    	return 1;
    }
};

int depth[MX],par[MX];
DSU<MX> D,D2,D3,D4;
vi adj[MX];

void addEdge(int a, int b) {
    adj[a].pb(b), adj[b].pb(a);
}

void dfs(int a, int b) {
    depth[a] = depth[b]+1; par[a] = b;
    trav(t,adj[a]) if (t != b) dfs(t,a);
}

void ad(int a, int b) {
    while (1) {
        a = D2.get(a), b = D2.get(b); if (a == b) return;
        // ps("HUH",a,b,depth[a],depth[b]);
        if (depth[a] < depth[b]) swap(a,b);
        D2.unite(par[a],a);
    }
    // ps("BAD"); exit(0);
}

void AD(int a, int b) {
    // ps("??",a,b,D4.get(a),D4.get(b));
    while (1) {
        a = D4.get(a), b = D4.get(b); 
        // ps("OH",a,b,depth[a],depth[b]);
        if (a == b) return;
        // ps("HUH",a,b,depth[a],depth[b]);
        if (depth[a] < depth[b]) swap(a,b);
        D4.unite(par[a],a);
        // ps("UNITE",par[a],a);
    }
    // ps("BAD"); exit(0);
}

pi bound[MX];
int co = 0;

void genBound(int a, int b) {
    bound[a].f = ++co;
    trav(t,adj[a]) if (t != b) genBound(t,a);
    bound[a].s = co;
}

void init() {
    setIO(); re(n,m,q);
    vpi extra;
    F0R(i,m) {
        int a,b; re(a,b);
        if (D.unite(a,b)) addEdge(a,b);
        else extra.pb({a,b});
    }
    FOR(i,1,n+1) if (!depth[i]) dfs(i,0);
    trav(t,extra) ad(t.f,t.s);
    FOR(i,1,n+1) adj[i].clear();
    FOR(i,1,n+1) if (par[i] && D2.get(par[i]) != D2.get(i)) {
        int a = D2.get(par[i]), b = D2.get(i);
        addEdge(a,b);
        L.addEdge(a,b);
    }
    FOR(i,1,n+1) if (D2.get(i) == i && !bound[i].f) {
        // ps("HA",i);
        L.dfs(i,0);
        genBound(i,0);
    }
    L.init(n);
}

void resetAll(int co) {
    FOR(i,1,co+1) D3.par[i] = D4.par[i] = i;
    FOR(i,1,co+1) {
        depth[i] = 0;
        adj[i].clear();
    }
    // reset D3, D4, depth, adj
}

int key[MX];

int main() {
    init();
    FOR(i,1,n+1) {
        adj[i].clear();
        depth[i] = 0;
    }
    F0R(i,q) {
        int n,m; re(n,m);
        vi x(n); re(x); 
        vi v;
        trav(t,x) {
            t = D2.get(rotate(t));
            v.pb(t);
        }
        vpi ed(m); re(ed); 
        trav(t,ed) {
            t.f = D2.get(rotate(t.f)), t.s = D2.get(rotate(t.s));
            v.pb(t.f), v.pb(t.s);
        }
        v.erase(unique(all(v)),v.end());
        sort(all(v),[](int a, int b) { return bound[a].f < bound[b].f; });
        F0Rd(i,sz(v)-1) v.pb(L.lca(v[i],v[i+1]));
        sort(all(v),[](int a, int b) { return bound[a].f < bound[b].f; });
        v.erase(unique(all(v)),v.end());
        // ps("WUT",x,ed);
        /*ps("??",v);
        trav(t,v) ps(t,bound[t].f);
        exit(0);*/
        int co = 0; F0R(i,sz(v)) key[v[i]] = ++co;
        vi st; vpi cool;
        trav(t,v) {
            while (sz(st) && bound[st.back()].s < bound[t].f) st.pop_back();
            if (sz(st)) cool.pb({key[st.back()],key[t]});
            st.pb(t);
        }
        // ps("WUT",v,cool);
        trav(t,ed) cool.pb({key[t.f],key[t.s]});
        vpi extra;
        trav(t,cool) {
            if (D3.unite(t.f,t.s)) addEdge(t.f,t.s);
            else extra.pb(t);
        }
        FOR(i,1,co+1) if (!depth[i]) dfs(i,0);
        // ps("COOL",cool);
        trav(t,extra) AD(t.f,t.s);
        // ps("HA",co,cool,sz(extra)); exit(0);
        
        bool ok = 1;
        FOR(i,1,sz(x)) if (D4.get(key[x[i]]) != D4.get(key[x[0]])) ok = 0;
        if (ok) R += i+1;
        
        resetAll(co);
        if (ok) ps("YES");
        else ps("NO");
        // exit(0);
    }
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/