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


namespace pairOp {
    template<class A, class B> pair<A,B> operator+(const pair<A,B>& l, const pair<A,B>& r) { return {l.f+r.f,l.s+r.s}; }
    template<class A, class B> pair<A,B> operator-(const pair<A,B>& l, const pair<A,B>& r) { return {l.f-r.f,l.s-r.s}; }
    template<class A, class B> pair<A,B> operator*(const pair<A,B>& l, const pair<A,B>& r) { return {l.f*r.f,l.s*r.s}; }
    template<class A, class B, class C> pair<A,B> operator*(const pair<A,B>& l, const C& r) { return {l.f*r,l.s*r}; }
    template<class A, class B, class C> pair<A,B> operator*(const C& r, const pair<A,B>& l) { return l*r; }
    template<class A, class B, class C> pair<A,B> operator/(const pair<A,B>& l, const C& r) { return {l.f/r,l.s/r}; }
    
    template<class A, class B> pair<A,B>& operator+=(pair<A,B>& l, const pair<A,B>& r) { return l = l+r; }
    template<class A, class B> pair<A,B>& operator-=(pair<A,B>& l, const pair<A,B>& r) { return l = l-r; }
    template<class A, class B> pair<A,B>& operator*=(pair<A,B>& l, const pair<A,B>& r) { return l = l*r; }
    template<class A, class B, class C> pair<A,B>& operator*=(pair<A,B>& l, const C& r) { return l = {l.f*r,l.s*r}; }
    template<class A, class B, class C> pair<A,B>& operator/=(pair<A,B>& l, const C& r) { return l = {l.f/r,l.s/r}; }
}

using namespace pairOp;

const int tmp = chrono::high_resolution_clock::now().time_since_epoch().count()%(MOD-1);

struct hsh {
    vpmi pows, ipows;
    pmi base = mp(948392576,tmp+1), invbase; // probably want to randomize base
    
    void init() {
        invbase = {1/base.f,1/base.s};
        pows.rsz(MX), ipows.rsz(MX);
        pows[0] = ipows[0] = {1,1};
        FOR(i,1,MX) pows[i] = pows[i-1]*base, ipows[i] = ipows[i-1]*invbase;
    }
};

hsh H;

typedef pair<pmi,int> T;

T operator+(const T& l, const T& r) {
	return {l.f+H.pows[l.s]*r.f,l.s+r.s};
}

int n;
vi adj[MX];
vector<pair<T,int>> v[MX]; // pre[MX], suf[MX];
T h1[MX], h2[MX];

map<T,int> m;

T adv(T x) {
	return {H.pows[1]*x.f+mp(mi(1),mi(1)),x.s+2};
}

void dfs(int x, int y) {
	trav(t,adj[x]) if (t != y) {
		dfs(t,x);
		v[x].pb({h1[t],t});
	}
	sort(all(v[x]));
	T cur = T();
	F0R(i,sz(v[x])) cur = cur+v[x][i].f;
	h1[x] = adv(cur);
	/*
	pre[x].rsz(sz(v[x]));
	suf[x].rsz(sz(v[x]));
	cur = T();
	F0Rd(i,sz(v[x])) {
		suf[x][i] = cur;
		cur = v[x][i]+cur;
	}*/
	// ps(x,h1[x]);
}

void dfs2(int x, int y) {
	if (y) v[x].pb({h2[x],y});
	sort(all(v[x]));
	vector<T> pre(sz(v[x])), suf(sz(v[x]));
	T cur = T();
	F0R(i,sz(v[x])) {
		pre[i] = cur;
		cur = cur+v[x][i].f;
	}
	cur = T();
	F0Rd(i,sz(v[x])) {
		suf[i] = cur;
		cur = v[x][i].f+cur;
	}
	F0R(i,sz(v[x])) if (v[x][i].s != y) {
		h2[v[x][i].s] = adv(pre[i]+suf[i]);
		dfs2(v[x][i].s,x);
	}
}

pi ans = {0,0};

void ad(T a, int b) {
	m[a] += b;
	if (!m[a]) m.erase(a);
}

void dfs3(int x, int y) {
	// ps("HUH",sz(m),x);
	ckmax(ans,{sz(m),x});
	trav(t,adj[x]) if (t != y) {
		ad(h1[t],-1); ad(h2[t],1);
		dfs3(t,x);
		ad(h1[t],1); ad(h2[t],-1);
	}
}

int main() {
	H.init();
    setIO(); re(n);
    F0R(i,n-1) {
    	int u,v; re(u,v);
    	adj[u].pb(v), adj[v].pb(u);
    }
    // ps("HUH",adj[1],adj[2],adj[3]);
    dfs(1,0); dfs2(1,0);
    FOR(i,2,n+1) m[h1[i]] ++;
    dfs3(1,0);
    ps(ans.s);
    // ps(sz(m));
} 

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/