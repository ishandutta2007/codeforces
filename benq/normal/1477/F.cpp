#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python!

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define rtn return

#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define EACH(a,x) for (auto& a: x)

const int MOD = 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
	return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

tcTU> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
tcT> void remDup(vector<T>& v) { // sort and remove duplicates
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
	auto it = t.find(u); assert(it != end(t));
	t.erase(it); } // element that doesn't exist from (multi)set

// INPUT
#define tcTUU tcT, class ...U
tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(V<T>& v);
tcT, size_t SZ> void re(AR<T,SZ>& a);

tcT> void re(T& x) { cin >> x; }
void re(double& d) { str t; re(t); d = stod(t); }
void re(long double& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(V<T>& x) { EACH(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { EACH(a,x) re(a); }
tcT> void rv(int n, V<T>& x) { x.rsz(n); re(x); }

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	// #ifdef LOCAL
	// 	return b ? "true" : "false"; 
	// #else 
	return ts((int)b);
	// #endif
}
tcT> str ts(complex<T> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(V<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
tcTU> str ts(pair<T,U> p);
tcT> str ts(T v) { // containers with begin(), end()
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
tcTU> str ts(pair<T,U> p) {
	#ifdef LOCAL
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}

// OUTPUT
tcT> void pr(T x) { cout << ts(x); }
tcTUU> void pr(const T& t, const U&... u) { 
	pr(t); pr(u...); }
void ps() { pr("\n"); } // print w/ spaces
tcTUU> void ps(const T& t, const U&... u) { 
	pr(t); if (sizeof...(u)) pr(" "); ps(u...); }

// DEBUG
void DBG() { cerr << "]" << endl; }
tcTUU> void DBG(const T& t, const U&... u) {
	cerr << ts(t); if (sizeof...(u)) cerr << ", ";
	DBG(u...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif

void setPrec() { cout << fixed << setprecision(15); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void setIO(str s = "") {
	unsyncIO(); setPrec();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for USACO
}

/**
 * Description: modular arithmetic operations 
 * Source: 
	* KACTL
	* https://codeforces.com/blog/entry/63903
	* https://codeforces.com/contest/1261/submission/65632855 (tourist)
	* https://codeforces.com/contest/1264/submission/66344993 (ksun)
	* also see https://github.com/ecnerwala/cp-book/blob/master/src/modnum.hpp (ecnerwal)
 * Verification: 
	* https://open.kattis.com/problems/modulararithmetic
 */

template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() { v = 0; }
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend void re(mint& a) { ll x; re(x); a = mint(x); }
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = int((ll)v*m.v%MOD); return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

typedef mint<MOD,5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vector<vmi> scmb; // small combinations
void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	FOR(i,1,SZ) F0R(j,i+1) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}

/**
 * Description: pre-compute factorial mod inverses,
 	* assumes $MOD$ is prime and $SZ < MOD$.
 * Time: O(SZ)
 * Source: KACTL
 * Verification: https://dmoj.ca/problem/tle17c4p5
 */

vi invs, fac, ifac; // make sure to convert to LL before doing any multiplications ...
void genFac(int SZ) {
	invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
	invs[1] = fac[0] = ifac[0] = 1; 
	FOR(i,2,SZ) invs[i] = int(MOD-(ll)MOD/i*invs[MOD%i]%MOD);
	FOR(i,1,SZ) {
		fac[i] = int((ll)fac[i-1]*i%MOD);
		ifac[i] = int((ll)ifac[i-1]*invs[i]%MOD);
	}
}
/**
ll comb(int a, int b) {
	if (a < b || b < 0) return 0;
	return (ll)fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;
}
*/

/**
 * Description: Basic poly ops including division. Can replace \texttt{T} with double, complex.
 * Source: Own. Also see
	* https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/PolyInterpolate.h
	* https://github.com/ecnerwala/icpc-book/blob/master/content/numerical/fft.cpp
 * Verification: see FFT
 */

// #include "../../number-theory (11.1)/Modular Arithmetic/ModInt.h"

using T = mi; 
using poly = vector<T>;
void remz(poly& p) { while (sz(p)&&p.bk==T(0)) p.pop_back(); }
poly REMZ(poly p) { remz(p); return p; }
poly rev(poly p) { reverse(all(p)); return p; }
poly shift(poly p, int x) { 
	if (x >= 0) p.insert(begin(p),x,0); 
	else assert(sz(p)+x >= 0), p.erase(begin(p),begin(p)-x);
	return p; 
}
poly RSZ(const poly& p, int x) { 
	if (x <= sz(p)) return poly(begin(p),begin(p)+x);
	poly q = p; q.rsz(x); return q;  }
T eval(const poly& p, T x) { // evaluate at point x
	T res = 0; R0F(i,sz(p)) res = x*res+p[i]; 
	return res; }
poly dif(const poly& p) { // differentiate
	poly res; FOR(i,1,sz(p)) res.pb(T(i)*p[i]); 
	return res; }
poly integ(const poly& p) { // integrate
	poly res(sz(p)+1); F0R(i,sz(p)) res[i+1] = p[i]/T(i+1);
	return res; }

poly& operator+=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] += r[i]; 
	return l; }
poly& operator-=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] -= r[i]; 
	return l; }
poly& operator*=(poly& l, const T& r) { EACH(t,l) t *= r; 
	return l;	 }
poly& operator/=(poly& l, const T& r) { EACH(t,l) t /= r; 
	return l; }
poly operator+(poly l, const poly& r) { return l += r; }
poly operator-(poly l, const poly& r) { return l -= r; }
poly operator-(poly l) { EACH(t,l) t *= -1; return l; }
poly operator*(poly l, const T& r) { return l *= r; }
poly operator*(const T& r, const poly& l) { return l*r; }
poly operator/(poly l, const T& r) { return l /= r;	 }
poly operator*(const poly& l, const poly& r) {
	if (!min(sz(l),sz(r))) return {};
	poly x(sz(l)+sz(r)-1); 
	F0R(i,sz(l)) F0R(j,sz(r)) x[i+j] += l[i]*r[j];
	return x;
}
poly& operator*=(poly& l, const poly& r) { return l = l*r; }

pair<poly,poly> quoRem(poly a, poly b) { 
	remz(a); remz(b); assert(sz(b));
	T lst = b.bk, B = T(1)/lst; EACH(t,a) t *= B; 
	EACH(t,b) t *= B;
	poly q(max(sz(a)-sz(b)+1,0));
	for (int dif; (dif=sz(a)-sz(b)) >= 0; remz(a)) {
		q[dif] = a.bk; F0R(i,sz(b)) a[i+dif] -= q[dif]*b[i]; }
	EACH(t,a) t *= lst;
	return {q,a}; // quotient, remainder
}
poly operator/(const poly& a, const poly& b) { return quoRem(a,b).f; }
poly operator%(const poly& a, const poly& b) { return quoRem(a,b).s; }
/**poly a = {1,3,5,8,6,0,0,0,0}, b = {1,5,1};
ps(quoRem(a,b)); a = 2*a, b = 2*b; ps(quoRem(a,b));*/
poly gcd(poly a, poly b) { return b == poly{} ? a : gcd(b,a%b); }
T resultant(poly a, poly b) { // R(A,B)
	// =b_m^n*prod_{j=1}^mA(mu_j)
	// =b_m^na_m^n*prod_{i=1}^nprod_{j=1}^m(mu_j-lambda_i)
	// =(-1)^{mn}a_n^m*prod_{i=1}^nB(lambda_i)
	// =(-1)^{nm}R(B,A)
	// Also, R(A,B)=b_m^{deg(A)-deg(A-CB)}R(A-CB,B)
	int ad = sz(a)-1, bd = sz(b)-1; 
	if (bd <= 0) return bd < 0 ? 0 : pow(b.bk,ad);
	int pw = ad; a = a%b; pw -= (ad = sz(a)-1);
	return resultant(b,a)*pow(b.bk,pw)*T((bd&ad&1)?-1:1);
}

int N,K;

int main() {
	// genFac(2500);
	setIO(); re(N,K);
	vi L(N); re(L);
	int sum = 0; EACH(l,L) sum += l; 
	V<poly> prod{{1}};
	auto get_fac = [&](int x) {
		T prod = 1;
		FOR(i,1,x+1) prod *= i;
		return prod;
	};
	EACH(l,L) {
		V<poly> coef((l+K-1)/K);
		coef[0] = {1};
		for (int k = 1; k*K < l; ++k) {
			// (-1)^k
			// r^k/k!*x^k
			// r^{k-1}/k!*x^{k-1}
			T r = T(l-k*K)/sum;
			// T mul = 1/get_fac(k);
			// T mul = 1;  FOR(i,1,k+1) mul /= i;
			T mul = 1;
			if (k&1) mul *= -1;
			assert(k < sz(coef));
			coef[k] = {mul*pow(r,k)/get_fac(k),mul*pow(r,k-1)/get_fac(k-1)};
			// coef[k].rsz(k+1);
			// coef[k][k] += mul*pow(r,k);
			// coef[k][0] = mul*pow(r,k);
			// coef[k][k-1] += mul*pow(r,k-1);
			// coef[l-k*K] += (r^kx^k+r^{k-1}x^{k-1})*(-1)^k/k!
		}
		// dbg(prod,coef);
		// dbg("??",prod,coef);
		V<poly> res(sz(prod)+sz(coef)-1);
		F0R(i,sz(prod)) F0R(j,sz(coef)) 
			res[i+j] += (prod[i]*coef[j]);
		// dbg("CONV",res);
		swap(res,prod);
	}
	auto get_comb = [&](int x, int y) -> T {
		if (x < y) return 0;
		return get_fac(x)/get_fac(x-y)/get_fac(y);
	};

	// dbg("RESULT",prod);
	T ans = 0;
	FOR(i,1,sz(prod)) F0R(j,sz(prod[i])) {
		// dbg("HA",i,j,prod[i][j]);
		int k = sum-K*i; // e^{k/sum}
		int d = i-j; assert(d >= 0);
		T contrib = pow(T(sum)/(K*i),d+1);
		contrib *= get_fac(d);
		contrib *= prod[i][j];
		// dbg("WHOOPS",i,j,k,d,prod[i][j],pow(T(sum)/(K*i),d+1)*get_fac(d));
		// dbg("WHOOPS",i,j,contrib);
		ans += contrib;
	}
	ps(-ans);
	// // dbg("DONE ANS");
	// T estimate = 0;
	// F0R(t,100) {
	// 	T not_done = 0;
	// 	for (int k = 1; k*K < sum; ++k) {
	// 		db mul = 1;
	// 		mul *= pow(T(sum-k*K)/sum,t);
	// 		mul *= get_comb(t+1,k);
	// 		if (k%2 == 0) mul *= -1;
	// 		not_done += mul;
	// 		// not_done += (t+1)*pow(,1);
	// 	}
	// 	// dbg("CALCED",t,not_done);
	// 	estimate += not_done;
	// }
	// ps(estimate);
	// // e^x-product

	// 1/(1-powers)
	
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/