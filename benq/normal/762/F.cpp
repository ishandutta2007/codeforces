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
    modular(const ll& v) { 
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular pow(modular a, ll p) {
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<int SZ> struct CD {
    struct Edge { 
        int a,b,w; 
        int other(int x) { return a+b-x; }
    };
    vector<Edge> ed;
    vi adj[SZ];
    
    bool done[SZ];
    int sub[SZ], par[SZ];
    vl dist[SZ];
    pi cen[SZ];

    void addEdge(int a, int b, int w = 1) { 
        adj[a].pb(sz(ed)), adj[b].pb(sz(ed));
        ed.pb({a,b,w});
    }

    void dfs (int x) {
        sub[x] = 1;
        trav(i,adj[x]) {
            int y = ed[i].other(x);
            if (!done[y] && y != par[x]) {
                par[y] = x; dfs(y);
                sub[x] += sub[y];
            }
        }
    }

    void genDist(int p, int x) {
        trav(i,adj[x]) {
            int y = ed[i].other(x);
            if (!done[y] && y != p) {
                cen[y] = cen[x]; dist[y].pb(dist[x].back()+ed[i].w);
                genDist(x,y);
            }
        }
    }

    vi centroid(int x) {
        par[x] = -1;  dfs(x); 
        for (int sz = sub[x];;) {
            pi mx = {0,0};
            trav(i,adj[x]) {
                int y = ed[i].other(x);
                if (!done[y] && y != par[x]) ckmax(mx,{sub[y],y});
            }
            if (mx.f*2 <= sz) {
            	if (mx.f*2 == sz) return {x,mx.s};
            	return {x}; 
            }
            x = mx.s;
        }
    }

    void gen(int x, bool fst = 0) { // call init(1) to start
        done[x = centroid(x)] = 1; dist[x].pb(0); // exit(0);
        if (fst) cen[x].f = -1;
        int co = 0;
        trav(i,adj[x]) {
            int y = ed[i].other(x);
            if (!done[y]) {
                cen[y] = {x,co++}; dist[y].pb(ed[i].w);
                genDist(x,y);
            }
        }
        trav(i,adj[x]) {
            int y = ed[i].other(x);
            if (!done[y]) gen(y);
        }
    }
    
    void init() { gen(0,1); }
};

map<vi,int> m;
CD<13> C;
int S,T,des;
vi adj[1001], ADJ[13], c;
mi ans;

int genSub(int a, int b) {
	vi v;
	trav(t,ADJ[a]) if (t != b) {
		v.pb(genSub(t,a));
	}
	sort(all(v));
	if (!m.count(v)) {
		int z = sz(m);
		m[v] = z;
	}
	return m[v];
}

void init() {
    setIO(); re(S);
    F0R(i,S-1) {
    	int u,v; re(u,v);
    	adj[u].pb(v), adj[v].pb(u);
    }
    re(T);
    F0R(i,T-1) {
    	int a,b; re(a,b);
    	ADJ[a].pb(b), ADJ[b].pb(a);
    	C.addEdge(a,b);
    }
    c = C.centroid(1);
    des = genSub(c[0],0);
}

mi dp[1001][12];
mi tmp[1<<12];
int nex[12][1<<12][12];

void init(vi v, int ind) {
	F0R(i,1<<sz(v)) F0R(j,sz(m)) {
		int k = 0; while (k < sz(v) && (v[k] != j || (i&(1<<k)))) k ++;
		if (k < sz(v)) nex[ind][i][j] = i^(1<<k);
		else nex[ind][i][j] = -1;
	}
}

void dfs(int x, int y) {
	trav(t,adj[x]) if (t != y) dfs(t,x);
	trav(a,m) {
		F0R(i,1<<sz(a.f)) tmp[i] = 0;
		tmp[0] = 1;
		int b = sz(a.f); if (y && a.s == des) continue;
		/*if (!y && b > 6) {
			ps("HUH",a,b,T);
			FOR(i,1,T+1) ps(i,ADJ[i]);
			exit(0);
		}*/
		trav(t,adj[x]) if (t != y) 
			F0Rd(c,1<<b) if (tmp[c] != 0) F0R(d,sz(m)) 
				if (nex[a.s][c][d] != -1) tmp[nex[a.s][c][d]] += tmp[c]*dp[t][d];
		dp[x][a.s] = tmp[(1<<b)-1];
	}
	if (!y) ans += dp[x][des];
}

int main() { 
	init();
	trav(a,m) init(a.f,a.s);
	FOR(i,1,S+1) dfs(i,0);
	if (sz(c) > 1) if (genSub(c[0],c[1]) == genSub(c[1],c[0])) ans /= 2;
	ps(ans);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/