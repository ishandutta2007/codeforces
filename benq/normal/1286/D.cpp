#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 

typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 
#define mp make_pair
#define f first
#define s second

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi; 
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back() 
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 998244353; // = (119<<23)+1
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = 4*atan((ld)1); 
const int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0}; 

template<class T> bool ckmin(T& a, const T& b) { 
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 
// change null_type for map
#define ook order_of_key
#define fbo find_by_order

void treeExample() {
	Tree<int> t, t2; t.insert(8);
	auto it = t.insert(10).f; assert(it == t.lb(9));
	assert(t.ook(10) == 1); assert(t.ook(11) == 2);
	assert(*t.fbo(0) == 8);
	t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}

namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);

	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); }
	template<class T, class... Ts> void re(T& t, Ts&... ts) { 
		re(t); re(ts...); 
	}

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
	template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
	template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
	
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
	
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
		pr(t); pr(ts...); 
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.f,", ",x.s,"}"); 
	}
	template<class T> void pr(const T& x) { 
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
		pr("}");
	}
	
	void ps() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
	}
	
	void pc() { pr("]\n"); } // debug w/ commas
	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
	}
	#define dbg(x...) pr("[",#x,"] = ["), pc(x);
}

using namespace output;

namespace io {
	void setIn(string s) { freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

struct mi {
	typedef decay<decltype(MOD)>::type T;
	T val; 
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(ll v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.val < b.val; }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }
	friend void pr(const mi& a) { pr(a.val); }
	friend ostream& operator<<(ostream& os, const mi& a) { 
		return os << a.val; }
   
	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) { 
		if ((val += m.val) >= MOD) val -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((val -= m.val) < 0) val += MOD; 
		return *this; }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }

	mi& operator*=(const mi& m) { 
		val = (ll)val*m.val%MOD; return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { 
		assert(!(a == 0)); return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

int n,x[MX],v[MX];
mi p[MX];

typedef array<array<mi,2>,2> T;

T operator+(const T& l, const T& r) {
	T z = T();
	F0R(i,2) F0R(j,2) F0R(k,2) z[i][k] += l[i][j]*r[j][k];
	return z;
}

mi i2 = mi(1)/2;
T ID;
T OK;

struct Seg { 
	T comb(T a, T b) { return a+b; } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T value) {	// set value at position p
		seg[p += n] = value;
		for (p /= 2; p; p /= 2) pull(p);
	}
	T query(int l, int r) {	 // sum on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

Seg S;

struct frac {
	ll n,d;
	frac() { n = 0, d = 1; }
	frac(ll _n, ll _d) {
		n = _n, d = _d;
		ll g = __gcd(n,d); n /= g, d /= g;
		if (d < 0) n *= -1, d *= -1;
	}
	frac(ll _n) : frac(_n,1) {}

	friend frac abs(frac F) { return frac(abs(F.n),F.d); }

	friend bool operator<(const frac& l, const frac& r) { return l.n*r.d < r.n*l.d; }
	friend bool operator==(const frac& l, const frac& r) { return l.n == r.n && l.d == r.d; }
	friend bool operator!=(const frac& l, const frac& r) { return !(l == r); }

	friend frac operator+(const frac& l, const frac& r) { return frac(l.n*r.d+r.n*l.d,l.d*r.d); }
	friend frac operator-(const frac& l, const frac& r) { return frac(l.n*r.d-r.n*l.d,l.d*r.d); }
	friend frac operator*(const frac& l, const frac& r) { return frac(l.n*r.n,l.d*r.d); }
	friend frac operator*(const frac& l, int r) { return l*frac(r,1); }
	friend frac operator*(int r, const frac& l) { return l*r; }
	friend frac operator/(const frac& l, const frac& r) { return l*frac(r.d,r.n); }
	friend frac operator/(const frac& l, const int& r) { return l/frac(r,1); }
	friend frac operator/(const int& l, const frac& r) { return frac(l,1)/r; }

	friend frac& operator+=(frac& l, const frac& r) { return l = l+r; }
	friend frac& operator-=(frac& l, const frac& r) { return l = l-r; }
	template<class T> friend frac& operator*=(frac& l, const T& r) { return l = l*r; }
	template<class T> friend frac& operator/=(frac& l, const T& r) { return l = l/r; }

	friend ostream& operator<<(ostream& strm, const frac& a) {
		strm << a.n;
		if (a.d != 1) strm << "/" << a.d;
		return strm;
	}
};

mi prob() {
	mi res = 0;
	F0R(i,2) F0R(j,2) {
		if (i == 1) res += p[0]*S.seg[1][i][j];
		else res += (1-p[0])*S.seg[1][i][j];
	}
	return res;
}

int main() {
	ID[0][0] = ID[1][1] = 1;
	F0R(i,2) F0R(j,2) OK[i][j] = mi(1)/2;
	ios_base::sync_with_stdio(0); cin.tie(0);
	re(n);
	F0R(i,n) {
		re(x[i],v[i],p[i]); p[i] /= 100;
	}
	// ps(1-p[0],p[0]);
	vector<pair<frac,pi>> vel;
	S.init(1<<17); // n = 1?
	F0R(i,n-1) {
		vel.pb({frac(x[i+1]-x[i],v[i+1]+v[i]),{i,0}});
		if (v[i] > v[i+1]) {
			vel.pb({frac(x[i+1]-x[i],v[i]-v[i+1]),{i,-1}});
		}
		if (v[i] < v[i+1]) {
			vel.pb({frac(x[i+1]-x[i],v[i+1]-v[i]),{i,1}});
		}
		T a = T();
		F0R(j,2) a[j][1] = p[i+1], a[j][0] = 1-p[i+1];
		S.upd(i,a);
	}
	sort(all(vel));
	mi ans = 0, lst = 0;
	trav(t,vel) {
		mi cur = mi(t.f.n)/t.f.d;
		// ps("HA",t.s,t.f.n,t.f.d,cur,prob());
		ans += (cur-lst)*prob(); lst = cur;
		if (t.s.s == 0) {
			auto a = S.seg[t.s.f+(1<<17)]; 
			/*ps("START",a);
			ps(S.seg[1]);
			ps(prob());
			ps();*/
			a[1][0] = 0;
			S.upd(t.s.f,a);
			/*ps("EN",a);
			ps(S.query(0,n-1));
			ps(S.query(0,n-2));
			ps(S.seg[1]);
			ps(prob());*/
		} else {
			auto a = S.seg[t.s.f+(1<<17)]; 
			if (t.s.s == -1) a[1][1] = 0;
			else a[0][0] = 0;
			S.upd(t.s.f,a);
		}
		// ps();
	}
// ps("??",prob());
	ans -= lst*prob();
	ps(ans);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/