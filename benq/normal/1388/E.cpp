#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
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

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
ll half(ll x) { return fdiv(x,2); }

template<class T, class U> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = half(lo+hi);
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
template<class T, class U> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = half(lo+hi+1);
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
template<class T> void remDup(vector<T>& v) { 
	sort(all(v)); v.erase(unique(all(v)),end(v)); }

// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	#ifdef LOCAL
		return b ? "true" : "false"; 
	#else 
		return ts((int)b);
	#endif
}
template<class A> str ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { // containers with begin(), end()
	#ifdef LOCAL
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;

	#endif
}
template<class A, class B> str ts(pair<A,B> p) {
	#ifdef LOCAL
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}

// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
	pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) { 
	pr(h); if (sizeof...(t)) pr(" "); ps(t...); }

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif

// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(str s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

/**
 * Description: Operations with fractions
 * Source: https://martin-thoma.com/fractions-in-cpp/
 * Verification: TopCoder MinimizeAbsoluteDifferenceDiv1
 */

struct frac {
	ll n,d;
	frac(ll _n, ll _d) {
		n = _n, d = _d;
		ll g = __gcd(n,d); n /= g, d /= g;
		if (d < 0) n *= -1, d *= -1;
	}
	frac(ll _n) : frac(_n,1) {}
	frac() : frac(0) {}
	friend frac abs(frac F) { return frac(abs(F.n),F.d); }
	friend str ts(const frac& a) { return ts(a.n)+"/"+ts(a.d); }
 
	friend bool operator<(const frac& l, const frac& r) { return l.n*r.d < r.n*l.d; }
	friend bool operator==(const frac& l, const frac& r) { return l.n == r.n && l.d == r.d; }
	friend bool operator!=(const frac& l, const frac& r) { return !(l == r); }
 
	frac operator-() const { return frac(-n,d); }
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
};

int n;

typedef db T;
db fdiv(db a, db b) { return a/b; }

const T inf = LLONG_MAX; bool _Q;
struct Line { // a and b -> slope and y-intercept 
	mutable T a, b, lst; // lst can change
	T eval(T x) const { return a*x+b; }
	bool operator<(const Line& y) const { return _Q?lst<y.lst:a<y.a; }
	/// friend str ts(const Line& L) { return ts(vl{L.a,L.b,L.lst}); }
	T bet(const Line& y) const { assert(a <= y.a);
		return a == y.a ? (b >= y.b ? inf : -inf) : fdiv(b-y.b,y.a-a); }
};

struct LC : multiset<Line> {
	bool rem(iterator IT) { auto it = IT++; // update lst for it
		if (IT == end()) return it->lst = inf, 0;
		return (it->lst = it->bet(*IT)) >= IT->lst; }
	void add(T a, T b) { // y -> inserted pos
		auto z = insert({a,b,0}), y = z++, x = y; 
		while (rem(y)) erase(z++); /// remove stuff after insertion pos
		if (x != begin() && rem(--x)) erase(y), rem(x); /// remove inserted line
		while ((y = x) != begin() && (--x)->lst >= y->lst) erase(y), rem(x); /// remove stuff before insertion pos
	}
	T query(T p) { 
		assert(size()); _Q = 1; 
		T ret = lb({0,0,p})->eval(p); _Q = 0; return ret; }
};


LC A,B;
 
int main() {
	setIO(); re(n);
	vector<pair<frac,int>> v;
	vector<array<int,3>> seg(n); re(seg);
	F0R(i,n) F0R(j,n) if (seg[i][2] < seg[j][2]) {
		frac hi(seg[i][1]-seg[j][0],seg[j][2]-seg[i][2]);
		frac lo(seg[i][0]-seg[j][1],seg[j][2]-seg[i][2]);
		assert(lo < hi);
		v.pb({lo,1}); v.pb({hi,-1});
	}
	if (!sz(v)) {
		sort(all(seg));
		int mn = seg[0][0];
		trav(t,seg) swap(t[0],t[1]);
		sort(all(seg));
		ps(seg.bk[0]-mn);
		exit(0);
	}
	F0R(i,n) {
		A.add(seg[i][2],seg[i][1]); // 1,5 -> 5
		B.add(-seg[i][2],-seg[i][0]); //
	}
	sort(all(v));
	int cnt = 0;
	db ans = INF;
	trav(t,v) {
		dbg(t);
		bool ok = (cnt == 0);
		cnt += t.s;
		ok |= (cnt == 0);
		assert(cnt >= 0);
		if (ok) {
			db val = (db)t.f.n/t.f.d;
			dbg(val);
			db cur = A.query(val)+B.query(val);
			if (ckmin(ans,cur)) {
				// db lo = INF, hi = -INF;
				// trav(t,seg) {
				// 	//dbg("HA",lo,hi);
				// 	ckmin(lo,t[0]+t[2]*val);
				// 	ckmax(hi,t[1]+t[2]*val);
				// }
				// if (hi-lo != cur) {
				// 	ps(val,lo,hi,A.query(val),B.query(val));
				// 	exit(0);
				// }
				// // dbg("???",hi-lo,cur);
				// assert(hi-lo == cur);
			}
		}
	}
	cout << fixed << setprecision(9) << ans << "\n";
	// you should actually read the stuff at the bottom
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/