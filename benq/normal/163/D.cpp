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
    
    // friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend void pr(const modular& a) { pr(a.val); }
    friend void re(modular& a) { ll x; re(x); a = modular(x); }
   
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

map<ll,array<ll,4>> ans;
int t;

ll po(ll a, int b) {
	if (b == 0) return 1;
	ll x = po(a*a,b/2); if (b&1) x *= a;
	return x;
}

void dfs(vpl& v, ll prod, int ind, vl& ret) {
	if (ind == sz(v)) {
		ret.pb(prod);
		return;
	}
	F0R(i,v[ind].s+1) {
		dfs(v,prod,ind+1,ret);
		prod *= v[ind].f;
	}
}

array<ll,4> get(ll a, ll b, ll c) {
	assert(a <= b && b <= c);
	return {a*b+b*c+c*a,a,b,c};
}

bool dumb = 0;

vl merge(const vl& a, const vl& b, ll z) {
	vl ret;
	int ib = 0;
	F0R(i,sz(a)) {
		while (ib < sz(b) && b[ib]*z < a[i]) {
			ret.pb(b[ib]*z);
			ib ++;
		}
		ret.pb(a[i]);
	}
	while (ib < sz(b)) {
		ret.pb(b[ib]*z);
		ib ++;
	}
	return ret;
}

vl nex(vl cur, pl t) {
	if (t.s == 1) return merge(cur,cur,t.f);
	t.s ++;
	vector<vl> tmp = {cur};
	for (int i = 1; (1<<i) <= t.s; i++) tmp.pb(merge(tmp.back(),tmp.back(),po(t.f,1<<(i-1))));
	// return cur;
	vl ans;
	F0R(i,sz(tmp)) if (t.s&(1<<i)) {
		t.s ^= 1<<i;
		ans = merge(ans,tmp[i],po(t.f,t.s));
	}
	return ans;
}

vl genSorted(vpl v) {
	vl cur = {1};
	trav(t,v) cur = nex(cur,t);
	return cur;
}

array<ll,4> solve(vpl v) {
	vl ret = genSorted(v); ll V = ret.back();
	// ps("HUH",v,ret);
	if (dumb) return {0,0,0,0};
	array<ll,4> mn = {LLONG_MAX,0,0,0};
	int ind = 0;
	F0Rd(i,sz(ret)) {
		ll A = ret[i]; if (A > 1e6 || A*A*A > V) continue;
		while (ind < sz(ret) && (ld)A*ret[ind]*ret[ind] <= V) ind ++;
		ll lo = 2*A*sqrt((double)V/A)+V/A; if (lo >= mn[0]) break;
		ll X = sqrt(V/A); int it = ind;
		while (it) {
			ll Z = ret[--it]; if (Z < A) break;
			if (V/A+A*Z+(double)V/Z >= mn[0]) break;
			if (V/A % Z == 0) {
				ckmin(mn,get(A,Z,V/A/Z));
				break;
			}
		}
	}
	return {2*mn[0],mn[1],mn[2],mn[3]};
}

int main() {
    setIO(); re(t);
    F0R(i,t) {
    	int k; re(k);
    	// if (i == 0 && k == 10) dumb = 1;
    	vpl v(k); re(v);
    	ll prod = 1;
    	trav(t,v) F0R(i,t.s) prod *= t.f;
    	// ps("HA",prod);
    	if (!ans.count(prod)) ans[prod] = solve(v);
    	array<ll,4> zz = ans[prod];
    	F0R(i,4) pr(zz[i],' ');
    	ps();
    }
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/