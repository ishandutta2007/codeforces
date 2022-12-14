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
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 200005;
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
    friend modular inv(const modular& a) { return invGeneral(a.val,MOD); } 
    // inv is equivalent to return exp(b,b.mod-2) if prime
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

void fin(int x) {
    ps(x); exit(0);
}

template<int SZ> struct TreeDiameter {
    struct Edge { 
        int a,b,w; 
        int other(int x) { return a+b-x; }
    };
    vector<Edge> ed;
    vi adj[SZ];
    void addEdge(int a, int b) { // can adjust to allow diameter w/ weights
        adj[a].pb(sz(ed)), adj[b].pb(sz(ed));
        ed.pb({a,b,1});
    }

    int par[SZ];
    ll dist[SZ];
    void dfs(int x) {
        trav(i,adj[x]) {
            int y = ed[i].other(x);
            if (y != par[x]) {
                par[y] = x; dist[y] = dist[x]+ed[i].w;
                dfs(y);
            }
        }
    }
    void genDist(int x) {
        par[x] = -1; dist[x] = 0; dfs(x);
    }

    int n; vi center; int dia;
    void init(int _n) {
        n = _n; genDist(1);
        int bes = 1; FOR(i,1,n+1) if (dist[i] > dist[bes]) bes = i; // bes is now one endpoint of a diameter
        genDist(bes); center.pb(bes);
        FOR(i,1,n+1) if (dist[i] > dist[bes]) bes = i;
        dia = dist[bes]; center.pb(bes);
    }
};

TreeDiameter<MX> T;
int n;
vi rec;

bool ok() {
    trav(t,rec) if (t == -MOD) return 0;
    return 1;
}

void solve(int x, int p = 0, int depth = 0) {
    int child = 0;
    trav(t,T.adj[x]) {
        int y = T.ed[t].other(x); if (y == p) continue;
        solve(y,x,depth+1);
        child ++;
    }
    while (sz(rec) <= depth) rec.pb(MOD);
    if (rec[depth] != MOD && rec[depth] != child) rec[depth] = -MOD;
    else rec[depth] = child;
}

bool ok(vi v) {
    trav(t,v) if (t > 1) return 0;
    return 1;
}

int lst(int x, int p) {
    trav(t,T.adj[x]) {
	    int y = T.ed[t].other(x);
        if (y != p) return lst(y,x);
    }
    return x;
}

int main() {
	setIO(); re(n);
	F0R(i,n-1) {
	    int a,b; re(a,b);
	    T.addEdge(a,b);
	}
	T.init(n); 
	if (T.dia%2 == 0) {
	    int tmp = T.center[1]; F0R(i,T.dia/2) tmp = T.par[tmp];
	    bool bad = 0;
	    map<vi,vi> m;
	    trav(t,T.adj[tmp]) {
	        int x = T.ed[t].other(tmp);
	        rec.clear(); solve(x,tmp); // ps(rec); 
	        if (!ok()) {
	            bad = 1;
	            break;
	        }
	        m[rec].pb(x);
	    }
	    if (!bad) {
	        if (sz(m) == 1) fin(tmp);
	        if (sz(m) == 2) trav(t,m) if (sz(t.s) == 1 && ok(t.f)) fin(lst(t.s[0],tmp));
	    }
	}
	// ps("??",T.center);
	F0R(i,2) {
	    rec.clear(); solve(T.center[i]);
    	if (ok()) fin(T.center[i]);
	}
	fin(-1);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/