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
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

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
tcT> void re(V<T>& x) { each(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { each(a,x) re(a); }
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

void decrement() {}
tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
#define rvi(x,y) vi x(y); re(x);

// https://codeforces.com/blog/entry/87598
// P(x)=2N-x, Q(x)=N-x
// evaluate Q(1...N-1) in blocks of B
// evaluate P(1...N-1) in blocks of B
// evaluate R(1...N-1) in blocks of B
// 

// you want Q(1...N-1) + ... + P(1...a-1)*Q(a..N-1)

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
 * Description: Basic poly ops including division. Can replace \texttt{T} with double, complex.
 * Source: Own. Also see
	* https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/PolyInterpolate.h
	* https://github.com/ecnerwala/icpc-book/blob/master/content/numerical/fft.cpp
 * Verification: see FFT
 */

// #include "../../number-theory (11.1)/Modular Arithmetic/ModInt.h"

using T = mi; using poly = vector<T>;
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
poly& operator*=(poly& l, const T& r) { each(t,l) t *= r; 
	return l;	 }
poly& operator/=(poly& l, const T& r) { each(t,l) t /= r; 
	return l; }
poly operator+(poly l, const poly& r) { return l += r; }
poly operator-(poly l, const poly& r) { return l -= r; }
poly operator-(poly l) { each(t,l) t *= -1; return l; }
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
	T lst = b.bk, B = T(1)/lst; each(t,a) t *= B; 
	each(t,b) t *= B;
	poly q(max(sz(a)-sz(b)+1,0));
	for (int dif; (dif=sz(a)-sz(b)) >= 0; remz(a)) {
		q[dif] = a.bk; F0R(i,sz(b)) a[i+dif] -= q[dif]*b[i]; }
	each(t,a) t *= lst;
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

/**
 * Description: Multiply polynomials of ints for any modulus $<2^{31}$. 
 	* For XOR convolution ignore \texttt{m} within \texttt{fft}. 
 * Time: O(N\log N)
 * Source: 
 	* KACTL (https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/NumberTheoreticTransform.h)
 	* https://cp-algorithms.com/algebra/fft.html
 	* https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it
 	* maroonrk
 * Verification: 
	* https://judge.yosupo.jp/problem/convolution_mod
	* SPOJ polymul, CSA manhattan, CF Perfect Encoding
	* http://codeforces.com/contest/632/problem/E
 */

// #include "ModInt.h"
// const int MOD = 998244353;

template<class T> void fft(V<T>& A, bool inv = 0) { // NTT
	int n = sz(A); assert((T::mod-1)%n == 0); V<T> B(n);
	for(int b = n/2; b; b /= 2, swap(A,B)) {
		T w = pow(T::rt(),(T::mod-1)/n*b), m = 1;
		for(int i = 0; i < n; i += b*2, m *= w) F0R(j,b) {
			T u = A[i+j], v = A[i+j+b]*m;
			B[i/2+j] = u+v; B[i/2+j+n/2] = u-v;
		}
	}
	if (inv) { reverse(1+all(A)); 
		T z = T(1)/T(n); each(t,A) t *= z; }
}
template<class T> V<T> mul(V<T> A, V<T> B) { // only special moduli for NTT
	if (!min(sz(A),sz(B))) return {};
	int s = sz(A)+sz(B)-1, n = 1; for (; n < s; n *= 2);
	bool eq = A == B; A.rsz(n), fft(A);
	if (eq) B = A; // squaring A, reuse result
	else B.rsz(n), fft(B);
	F0R(i,n) A[i] *= B[i];
	fft(A,1); A.rsz(s); return A;
}
template<class M, class T> V<M> mulMod(V<T> x, V<T> y) {
	auto con = [](const V<T>& v) {
		V<M> w(sz(v)); F0R(i,sz(v)) w[i] = (int)v[i];
		return w; };
	return mul(con(x),con(y));
}
template<class T> V<T> MUL(const V<T>& A, const V<T>& B) { // arbitrary moduli
	using m0 = mint<(119<<23)+1,62>; auto c0 = mulMod<m0>(A,B);
	using m1 = mint<(5<<25)+1,  62>; auto c1 = mulMod<m1>(A,B);
	using m2 = mint<(7<<26)+1,  62>; auto c2 = mulMod<m2>(A,B);
	int n = sz(c0); V<T> res(n);
	m1 r01 = 1/m1(m0::mod); m2 r02 = 1/m2(m0::mod), r12 = 1/m2(m1::mod);
	F0R(i,n) { // a is remainder mod m0::mod, b fixes it mod m1::mod
		int a = c0[i].v, b = ((c1[i]-a)*r01).v, c = (((c2[i]-a)*r02-b)*r12).v;
		res[i] = (T(c)*m1::mod+b)*m0::mod+a; // c fixes it mod m2::mod
	}
	return res;
}


/**
 * Description: Multiply small polys directly, otherwise use FFT.
 * Source: KACTL, https://cp-algorithms.com/algebra/fft.html
 */

// #include "Poly.h"
// #include "FFT.h"

bool small(const poly& a, const poly& b) { // multiply directly
	return (ll)sz(a)*sz(b) <= 10000; } 
// vmi smart(const vmi& a, const vmi& b) { return mul(a,b); }
// vl smart(const vl& a, const vl& b) {
// 	auto X = mul(vcd(all(a)),vcd(all(b)));
// 	vl x(sz(X)); F0R(i,sz(X)) x[i] = round(X[i].real());
// 	return x; }
poly conv(const poly& a, const poly& b) {
	return small(a,b) ? a*b : mul(a,b); } 

/**
 * Description: computes $A^{-1}$ such that $AA^{-1}\equiv 1\pmod{x^n}$.
 	* Newton's method: If you want $F(x)=0$ and $F(Q_k)\equiv 0\pmod{x^a}$
 	* then $Q_{k+1}=Q_k-\frac{F(Q_k)}{F'(Q_k)}\pmod{x^{2a}}$ satisfies
 	* $F(Q_{k+1})\equiv 0 \pmod{x^{2a}}$. Application: if $f(n),g(n)$ are the
 	* \#s of forests and trees on $n$ nodes then 
 	* $\sum_{n=0}^{\infty}f(n)x^n=\exp\left(\sum_{n=1}^{\infty}\frac{g(n)}{n!}\right)$.
 * Time: O(N\log N)
 * Source: CF, http://people.csail.mit.edu/madhu/ST12/scribe/lect06.pdf
 	* https://cp-algorithms.com/algebra/polynomial.html
 * Usage: vmi v={1,5,2,3,4}; ps(exp(2*log(v,9),9)); // squares v
 * Verification: https://codeforces.com/contest/438/problem/E
 	* https://codeforces.com/gym/102028/submission/77687049
 	* https://loj.ac/problem/6703 (MultipointEval)
 */

// #include "PolyConv.h"

poly inv(poly A, int n) { // Q-(1/Q-A)/(-Q^{-2})
	poly B{1/A[0]};
	for (int x = 2; x/2 < n; x *= 2)
		B = 2*B-RSZ(conv(RSZ(A,x),conv(B,B)),x);
	return RSZ(B,n);
}
poly sqrt(const poly& A, int n) {  // Q-(Q^2-A)/(2Q)
	assert(A[0] == 1); poly B{1};
	for (int x = 2; x/2 < n; x *= 2)
		B = T(1)/T(2)*RSZ(B+conv(RSZ(A,x),inv(B,x)),x);
	return RSZ(B,n);
}
pair<poly,poly> divi(const poly& f, const poly& g) { // return quotient and remainder
	if (sz(f) < sz(g)) return {{},f};
	poly q = conv(inv(rev(g),sz(f)-sz(g)+1),rev(f));
	q = rev(RSZ(q,sz(f)-sz(g)+1));
	poly r = RSZ(f-conv(q,g),sz(g)-1); return {q,r};
}
poly log(poly A, int n) { assert(A[0] == 1); // (ln A)' = A'/A
	A.rsz(n); return integ(RSZ(conv(dif(A),inv(A,n-1)),n-1)); }
poly exp(poly A, int n) { assert(A[0] == 0);
	poly B{1}, IB{1};
	for (int x = 1; x < n; x *= 2) {
		IB = 2*IB-RSZ(conv(B,conv(IB,IB)),x); // inverse of B to x places
		poly Q = dif(RSZ(A,x)); Q += RSZ(conv(IB,dif(B)-conv(B,Q)),2*x-1); 
		// first x-1 terms of dif(B)-conv(B,Q) are zero
		B = B+RSZ(conv(B,RSZ(A,2*x)-integ(Q)),2*x); 
	} // We know that Q=A' is B'/B to x-1 places, we want to find B'/B to 2x-1 places
	return RSZ(B,n);
}
// poly expOld(poly A, int n) { // Q-(lnQ-A)/(1/Q)
// 	assert(A[0] == 0); poly B = {1};
// 	while (sz(B) < n) { int x = 2*sz(B);
// 		B = RSZ(B+conv(B,RSZ(A,x)-log(B,x)),x); }
// 	return RSZ(B,n);
// }

void segProd(vector<poly>& stor, poly& v, int ind, int l, int r) { // v -> places to evaluate at
	if (l == r) { stor[ind] = {-v[l],1}; return; }
	int m = (l+r)/2; segProd(stor,v,2*ind,l,m); segProd(stor,v,2*ind+1,m+1,r);
	stor[ind] = conv(stor[2*ind],stor[2*ind+1]);
}
void evalAll(vector<poly>& stor, poly& res, poly v, int ind = 1) {
	v = divi(v,stor[ind]).s;
	if (sz(stor[ind]) == 2) { res.pb(sz(v)?v[0]:0); return; }
	evalAll(stor,res,v,2*ind); evalAll(stor,res,v,2*ind+1);
}
poly multiEval(poly v, poly p) {
	vector<poly> stor(4*sz(p)); segProd(stor,p,1,0,sz(p)-1);
	poly res; evalAll(stor,res,v); return res; }

poly combAll(vector<poly>& stor, poly& dems, int ind, int l, int r) {
	if (l == r) return {dems[l]};
	int m = (l+r)/2;
	poly a = combAll(stor,dems,2*ind,l,m), b = combAll(stor,dems,2*ind+1,m+1,r);
	return conv(a,stor[2*ind+1])+conv(b,stor[2*ind]);
}
poly interpolate(vector<pair<T,T>> v) {
	int n = sz(v); poly x; each(t,v) x.pb(t.f);
	vector<poly> stor(4*n); segProd(stor,x,1,0,n-1);
	poly dems; evalAll(stor,dems,dif(stor[1]));
	F0R(i,n) dems[i] = v[i].s/dems[i];
	return combAll(stor,dems,1,0,n-1);
}

const int B = 1<<15;

int M, N = 0;

mi get_p(int i) { return 2*N-i; }

mi get_q(int i) { return N-i; }

// poly divideAndMultiply(V<poly> v) {
// 	if (sz(v) == 1) return v[0];
// 	poly a = divideAndMultiply(V<poly>(begin(v),begin(v)+sz(v)/2));
// 	poly b = divideAndMultiply(V<poly>(begin(v)+sz(v)/2,end(v)));
// 	rtn mul(a,b);
// }

// poly Bconsecutive(mi a, mi b) { // a*(x+i)+b
// 	V<poly> v; FOR(i,1,B+1) v.pb({a*i+b,a});
// 	return divideAndMultiply(v);
// }

AR<poly,3> getR(int l, int r) { 
	// product of p, product of q, desired
	if (l == r) {
		poly tmp_p{2*N-l,-1};
		poly tmp_q{N-l,-1};
		return {tmp_p,tmp_q,tmp_q};
	}
	int m = (l+r)/2;
	auto ans_l = getR(l,m), ans_r = getR(m+1,r);
	return {mul(ans_l[0],ans_r[0]),mul(ans_l[1],ans_r[1]),
		mul(ans_l[2],ans_r[1])+mul(ans_l[0],ans_r[2])};
	// p(x+l), q(x+l), q(x+l)
	// q(x+1) ...          q(x+B)
	// p(x+1) ... p(x+B-1) q(x+B)
}

// p(x+1)*...*p(x+B)
// q(x+1)*...*q(x+B)


mi tot_q_prod = 1;

mi eval_dumb(int t) {
	mi sum = 0;
	FOR(i,1,t+1) {
		mi prod = 1;
		FOR(j,1,i) prod *= get_p(j);
		FOR(j,i,N) prod *= get_q(j);
		sum += prod;
	}
	sum /= tot_q_prod;
	// FOR(j,1,N) sum /= get_q(j);
	return sum;
}

poly PP,QQ,RR;
poly suf_prod;

mi eval_smart(int a) { // 0 to a-1
	mi ans = 0;
	mi pref_prod = 1;
	// last term is P[1..a-1]
	for (int i = 0; ; ++i) {
		// P[1..B*i] Q[B*i+1] onwards
		// over to
		// P[1..B*(i+1)-1] Q[B*i+B] onwards
		if (B*i+B-1 < a) {
			ans += pref_prod*RR[i]*suf_prod[i+1]; // suf_prod[i] has B*i+1 onwards
		} else {
			// start with P[1..B*i] .. Q[B*i+1 onwards]
			mi cur_prod = pref_prod*suf_prod[i];
			FOR(j,B*i,a) {
				if (j > B*i) {
					cur_prod /= get_q(j);
					cur_prod *= get_p(j);
				}
				ans += cur_prod;
			}
			// B*i to a-1
			break;
		}
		pref_prod *= PP[i];
		// PP[0]..PP[i-1]*RR[i]*QQ[i+1]*QQ[i+2]+...
		// B*i to B*i+B-1
	}
	dbg("DIVIDING",tot_q_prod);
	ans /= tot_q_prod;
	return ans;
}

mi eval(int t) {
	// mi x = eval_dumb(t);
	mi y = eval_smart(t);
	// assert(x == y);
	return y;
}

int main() {
	setIO(); 
	re(M); rvi(A,M);
	each(t,A) N += t;

	auto PQR = getR(1,B);
	poly P = PQR[0];
	poly Q = PQR[1];
	poly R = PQR[2];

	poly places; F0R(i,B) places.pb(B*i);

	PP = multiEval(P,places);
	// F0R(i,B) {
	// 	mi mul = 1;
	// 	FOR(j,1,B+1) mul *= get_p(B*i+j);
	// 	dbg("HUH",i,PP[i],mul);
	// }
	QQ = multiEval(Q,places);
	RR = multiEval(R,places);
	for (int i = 0; ; ++i) {
		if (B*i+B < N) {
			tot_q_prod *= QQ[i];
		} else {
			FOR(cur,B*i+1,N) tot_q_prod *= get_q(cur);
			break;
		}
	}
	int ind = 0; while (B*ind < N) ++ind;
	suf_prod = poly(ind+1);
	suf_prod[ind] = suf_prod[ind-1] = 1;
	FOR(j,B*(ind-1)+1,N) suf_prod[ind-1] *= get_q(j);
	R0F(i,ind-1) {
		assert(i < sz(QQ));
		suf_prod[i] = QQ[i]*suf_prod[i+1];
		// dbg("HA",i,QQ[i],suf_prod[i]);
	}
	dbg("CALCED",tot_q_prod);
	// dbg("HA",suf_prod[0],suf_prod,tot_q_prod); exit(0);
	// mi test_prod = 1; FOR(i,1,N) test_prod *= i;
	// dbg(tot_prod,test_prod);



	mi ans = 0;
	each(t,A) ans += eval(t);
	ans -= eval(N);
	ps(-2*ans);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/