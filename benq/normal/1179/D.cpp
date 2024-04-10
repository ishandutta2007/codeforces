/*
ID: bqi3431
PROG: ~
LANG: C++11 
*/

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
const int MX = 500005;
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

int n, sz[MX], par[MX];

ll getsz(int a, int b) {
	if (!b) return n;
	if (a == par[b]) return n-sz[b];
	if (par[a] != b) {
		ps("WUT",a,b,par[a],par[b]);
		exit(0);
	}
	assert(par[a] == b); return sz[a];
}

ll sq(ll x) { return x*x; }

struct Edge { 
    int a,b,w; 
    int other(int x) { return a+b-x; }
};
vector<Edge> ed;
vi adj[MX];
ll ans = 0;
vpl v;

ll eval(pl a, ll b) {
	return a.f*b+a.s;
}

ll gre(ll a, ll b) {
	if (b < 0) a *= -1, b *= -1;
	// x > a/b 
	if (a%b == 0) return a/b+1;
	if (a>0) return a/b+1;
	return a/b;
}

ll bet(pl a, pl b) {
	// first x such that b.f*x+b.s > a.f*x+a.s
	// (b.f-a.f)*x > a.s-b.s
	assert(b.f >= a.f);
	if (b.f == a.f) {
		if (b.s > a.s) return -INF;
		return INF;
	}
	return gre(a.s-b.s,b.f-a.f);
}

ll query(int x) { // x is increasing
	while (sz(v) > 1 && eval(v.back(),x) < eval(v[sz(v)-2],x)) v.pop_back();
	if (!sz(v)) return -INF;
	return eval(v.back(),x);
}

void ins(pl t) {
	while (sz(v) > 1 && bet(t,v.back()) >= bet(v.back(),v[sz(v)-2])) v.pop_back();
	v.pb(t);
}

void finish(vpl dumb) {
	trav(t,dumb) t.s = 2*n*t.f-t.f*t.f-t.s;
	// ps(dumb); exit(0);
	sort(all(dumb));
	// ps(dumb);
	v.clear();
	trav(t,dumb) {
		ckmax(ans,query(t.f)+t.s);
		ins({-2*t.f,t.s});
	}
	// -2*c_1*c_2
}

template<int SZ> struct CD {
    bool done[SZ];
    int sub[SZ], par[SZ];

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
    
    int centroid(int x) {
        par[x] = -1;  dfs(x); 
        for (int sz = sub[x];;) {
            pi mx = {0,0};
            trav(i,adj[x]) {
                int y = ed[i].other(x);
                if (!done[y] && y != par[x]) ckmax(mx,{sub[y],y});
            }
            if (mx.f*2 <= sz) return x; 
            x = mx.s;
        }
    }

	ll getAns(int a, int b) {
		ll ret = getsz(a,b); ret *= ret;
		trav(i,adj[a]) {
			int c = ed[i].other(a);
			if (c == b || done[c]) continue;
			ckmin(ret,getAns(c,a)+sq(getsz(a,b)-getsz(c,a)));
		}
		return ret;
		// -getsz(c,a);
	}
	
    void gen(int x, bool fst = 0) { // call init(1) to start
        done[x = centroid(x)] = 1; 
        int co = 0;
        vpl dumb; dumb.pb({0,0});
        trav(i,adj[x]) {
            int y = ed[i].other(x);
            if (!done[y]) {
            	ll a = getAns(y,x);
            	dumb.pb({getsz(y,x),a});
            	// ps("HUH",x,y);
            }
        }
        // exit(0);
        finish(dumb); 
        trav(i,adj[x]) {
            int y = ed[i].other(x);
            if (!done[y] && 2*sub[y] >= n) gen(y);
        }
    }
    
    void init() { gen(1,1); }
};

CD<MX> C;

void dfs(int x) {
	sz[x] = 1;
	trav(i,adj[x]) {
		int t = ed[i].other(x);
		if (t != par[x]) {
			par[t] = x; dfs(t);
			sz[x] += sz[t];
		}
	}
}

int main() {
	setIO(); re(n);
	F0R(i,n-1) {
		int a,b; 
		a = i+1, b = i+2;
		re(a,b);
		C.addEdge(a,b);
	}
	dfs(1);
	C.init();
	ps(ans/2+((ll)n*n-n)/2);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/