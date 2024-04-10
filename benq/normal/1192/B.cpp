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
const int MX = 100005;
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

ll depth[MX];
vi v;

array<ll,6> operator+(const array<ll,6>& l, const array<ll,6>& r) {
	array<ll,6> z;
	F0R(i,6) z[i] = max(l[i],r[i]);
	ckmax(z[1],l[0]+r[3]);
	ckmax(z[4],l[3]+r[5]);
	ckmax(z[2],l[0]+r[4]);
	ckmax(z[2],l[1]+r[5]);
	return z;
}

struct Seg {
	ll lazy[1<<19];
	array<ll,6> dat[1<<19];
	void pull(int ind) {
		dat[ind] = dat[2*ind]+dat[2*ind+1];
	}
	void build(int ind, int l, int r) {
		if (l == r) {
			ll d = depth[v[l]];
			// ps("HUH",l,v[l],d);
			dat[ind][0] = d;
			dat[ind][1] = -d;
			dat[ind][2] = 0;
			dat[ind][3] = -2*d;
			dat[ind][4] = -d;
			dat[ind][5] = d;
			// 00: d
			// 01: -d
			// 02: 0
			// 11: -2d
			// 12: -d
			// 22: d
			return;
		}
		int m = (l+r)/2;
		build(2*ind,l,m); build(2*ind+1,m+1,r);
		pull(ind);
	}
	void push(int ind, int l, int r) {
		if (!lazy[ind]) return;
		dat[ind][0] += lazy[ind];
		dat[ind][1] += -lazy[ind];
		dat[ind][3] += -2*lazy[ind];
		dat[ind][4] += -lazy[ind];
		dat[ind][5] += lazy[ind];
		if (l != r) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
		lazy[ind] = 0;
	}
	void upd(int lo, int hi, ll x, int ind, int l, int r) {
		push(ind,l,r);
		if (hi < l || r < lo) return;
		if (lo <= l && r <= hi) {
			lazy[ind] = x;
			push(ind,l,r);
			return;
		}
		int m = (l+r)/2;
		upd(lo,hi,x,2*ind,l,m);
		upd(lo,hi,x,2*ind+1,m+1,r);
		pull(ind);
	}
};

Seg S;
int n,q;
ll w,W[MX],last;
pi range[MX];
vpi adj[MX];

void dfs(int x, int y) {
	if (y != -1) range[y].f = sz(v);
	v.pb(x);
	trav(t,adj[x]) if (t.s != y) {
		depth[t.f] = depth[x]+W[t.s];
		dfs(t.f,t.s);
		v.pb(x);
	}
	range[y].s = sz(v)-1;
}

int main() {
    setIO(); re(n,q,w);
    F0R(i,n-1) {
    	int a,b; ll c; re(a,b,c);
    	W[i] = c;
    	adj[a].pb({b,i});
    	adj[b].pb({a,i});
    }
    dfs(1,-1);
    //ps(v);
    //F0R(i,n-1) ps(i,range[i]);
    S.build(1,0,sz(v)-1);
    //exit(0);
    // ps("HUH",S.dat[1][2]);
    F0R(i,q) {
    	int d; ll e; re(d,e);
    	d = (d+last)%(n-1);
    	e = (e+last)%w;
    	S.upd(range[d].f,range[d].s,e-W[d],1,0,sz(v)-1);
    	W[d] = e;
    	last = S.dat[1][2]; ps(last);
    }
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/