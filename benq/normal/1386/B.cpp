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
#ifdef LOCAL // compile with -DLOCAL
	#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
	#define dbg(...) 0
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

typedef pl P;

int sgn(ll x) {
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}

__int128 cross(P a, P b) {
	return (__int128)a.f*b.s-(__int128)a.s*b.f;
}

/**
 * Description: Sorts points in ccw order about origin in the same way as
 	* \texttt{atan2}, which returns real in $(-\pi,\pi]$ so points on 
 	* negative $x$-axis come last.
 * Verification: https://codeforces.com/contest/1284/submission/68175790
 	* https://codeforces.com/contest/1284/submission/68207607 
 	* (don't use atan2, weird stuff happens!)
 */

int half(P x) { return x.s != 0 ? sgn(x.s) : -sgn(x.f); } // -1 if lower half, 0 if origin, 1 if upper half
bool angleCmp(P a, P b) { 
	int A = half(a), B = half(b);
	return A == B ? cross(a,b) > 0 : A < B; }

/** Usage: 
 	* vP v;
 	* sort(all(v),[](P a, P b) { return 
 		atan2(a.s,a.f) < atan2(b.s,b.f); });
 	* sort(all(v),angleCmp); // should give same result
*/

typedef array<ll,3> T;

T a;
int eq = 0, neg = 0;
vpl cat;

struct cmp {
	bool operator()(const pl& a, const pl& b) const {
		return angleCmp(a,b);
	};
};

map<pl,int,cmp> m;

T operator*(T a, ll b) {
	trav(t,a) t *= b;
	return a;
}
T operator-(T a, T b) {
	F0R(i,3) a[i] -= b[i];
	return a;
}

ll sum(T t) { return t[0]+t[1]+t[2]; }
// T nor(T a) {
// 	int g = __gcd(abs(a[0]),__gcd(abs(a[1]),abs(a[2])));
// 	F0R(i,3) a[i] /= g;
// 	return a;
// }

ll dot(T a, T b) {
	ll res = 0;
	F0R(i,3) res += a[i]*b[i];
	return res;
}

pl lst;

const pl ID = mp(0LL,0LL);

void ad(pl p, int x) {
	if (p == ID) {
		eq += x;
		return;
	}
	vpl cand = {lst,p};
	if (x == 1) {
		if (!m.count(p) && m.count({-p.f,-p.s})) neg ++;
		m[p] ++;
	} else {
		if (m[p] == 1 && m.count({-p.f,-p.s})) neg --;
		auto it = m.find(p);
		if (it == begin(m)) it = end(m);
		it --; cand.pb(it->f);
		m[p] --; if (!m[p]) m.erase(p);
	}
	lst = {0,0};
	auto bad = [&](pl a, pl b) {
		return a == b || cross(a,b) < 0;
	};
	trav(t,cand) {
		auto it = m.find(t); if (it == end(m)) continue;
		auto IT = next(it); if (IT == end(m)) IT = begin(m);
		if (bad(t,IT->f)) {
			// assert(lst == mp(0LL,0LL));
			lst = t;
		}
	}
}


int answer() {
	if (eq) return 1;
	if (neg) return 2;
	if (sz(m)) { if (lst == ID) return 3; }
	return 0;
}

int main() {
	setIO(); re(a);
	int N; re(N);
	F0R(i,N) {
		char c; re(c);
		if (c == 'A') {
			T t; re(t);
			t = t*sum(a)-a*sum(t); assert(sum(t) == 0);
			pl p = {dot(t,{1,-1,0}),dot(t,{1,1,-2})};
			ll g = __gcd(abs(p.f),abs(p.s));
			if (p.f || p.s) p.f /= g, p.s /= g;
			cat.pb(p); ad(cat.bk,1);
		} else {
			int r; re(r); r --;
			ad(cat[r],-1);
		}
		ps(answer());
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/