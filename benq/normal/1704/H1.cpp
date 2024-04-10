#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python! 

// pairs
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MX = 2e5+5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; // for every grid problem!!
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
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

tcTU> T fstTrue(T lo, T hi, U f) {
	++hi; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	--lo; assert(lo <= hi); // assuming f is decreasing
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

#define tcTUU tcT, class ...U

inline namespace Helpers {
	//////////// is_iterable
	// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
	// this gets used only when we can call begin() and end() on that type
	tcT, class = void> struct is_iterable : false_type {};
	tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
	                                  decltype(end(declval<T>()))
	                                 >
	                       > : true_type {};
	tcT> constexpr bool is_iterable_v = is_iterable<T>::value;

	//////////// is_readable
	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_readable_v = is_readable<T>::value;

	//////////// is_printable
	// // https://nafe.es/posts/2020-02-29-is-printable/
	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); // pairs

	// re: read
	tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } // default
	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } // complex
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); // ex. vectors, arrays
	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
		each(x,i) re(x); }
	tcTUU> void re(T& t, U&... u) { re(t); re(u...); } // read multiple

	// rv: resize and read vectors
	void rv(size_t) {}
	tcTUU> void rv(size_t N, V<T>& t, U&... u);
	template<class...U> void rv(size_t, size_t N2, U&... u);
	tcTUU> void rv(size_t N, V<T>& t, U&... u) {
		t.rsz(N); re(t);
		rv(N,u...); }
	template<class...U> void rv(size_t, size_t N2, U&... u) {
		rv(N2,u...); }

	// dumb shortcuts to read in ints
	void decrement() {} // subtract one from each
	tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
	#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
	#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}

inline namespace ToString {
	tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

	// ts: string representation to print
	tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } // default
	tcT> str bit_vec(T t) { // bit vector to string
		str res = "{"; F0R(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } // bit vector
	tcTU> str ts(pair<T,U> p); // pairs
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v); // vectors, arrays
	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {
		// convert container to string w/ separator sep
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	// for nested DS
	template<int, class T> typename enable_if<!needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = ts_lev<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		F0R(i,sz(res)) {
			str bef = " "; if (i == 0) bef = "{";
			res[i] = bef+res[i];
		}
		res.bk += "}";
		return res;
	}
}

inline namespace Output {
	template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
	template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
		pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
	// print w/ no spaces
	template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
	// print w/ spaces, end with newline
	void ps() { cout << "\n"; }
	template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
	// debug to cerr
	template<class ...T> void dbg_out(const T&... t) {
		pr_sep(cerr," | ",t...); cerr << endl; }
	void loc_info(int line, str names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template<int lev, class T> void dbgl_out(const T& t) {
		cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
	#ifdef LOCAL
		#define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
		#define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
	#else // don't actually submit with this
		#define dbg(...) 0
		#define dbgl(lev,x) 0
	#endif

	const clock_t beg = clock();
	#define dbg_time() dbg((db)(clock()-beg)/CLOCKS_PER_SEC)
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
		// cin.exceptions(cin.failbit);
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
	}
}

/**
 * Description: Barrett reduction computes $a \% b$ about 4 times faster than usual 
 	* where $b>1$ is constant but not known at compile time. Division by $b$ is replaced
 	* by multiplication by $m$ and shifting right 64 bits.
 * Source: KACTL
 	* https://github.com/kth-competitive-programming/kactl/blob/master/content/various/FastMod.h
 	* https://en.wikipedia.org/wiki/Barrett_reduction
 * Verification: http://www.usaco.org/index.php?page=viewproblem2&cpid=1045
 */

using ul = uint64_t; using L = __uint128_t;
struct FastMod {
	ul b, m; FastMod(ul b) : b(b), m(-1ULL / b) {}
	ul reduce(ul a) {
		ul q = (ul)((__uint128_t(m) * a) >> 64), r = a - q * b;
		return r - (r >= b) * b; }
};


/**
 * Description: modular arithmetic operations 
 * Source: 
	* KACTL
	* https://codeforces.com/blog/entry/63903
	* https://codeforces.com/contest/1261/submission/65632855 (tourist)
	* https://codeforces.com/contest/1264/submission/66344993 (ksun)
	* also see https://github.com/ecnerwala/cp-book/blob/master/src/modnum.hpp (ecnerwal)
	* https://github.com/atcoder/ac-library/blob/master/atcoder/modint.hpp
 * Verification: 
	* https://open.kattis.com/problems/modulararithmetic
 */

template<int id> struct mint {
	static FastMod MF;
	static int mod() { return (int)MF.b; }
	static void set_mod(int m) { assert(1 <= m); MF = FastMod(m); }
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() { v = 0; }
	mint(ll _v) { v = int((-mod() < _v && _v < mod()) ? _v : _v % mod());
		if (v < 0) v += mod(); }
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend void re(mint& a) { ll x; re(x); a = mint(x); }
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= mod()) v -= mod(); 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += mod(); 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = (int)MF.reduce((ll)v*m.v); return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,mod()-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};
template<int id> FastMod mint<id>::MF = FastMod(1);

typedef mint<0> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;


/**
 * Description: pre-compute factorial mod inverses,
 	* assumes $MOD$ is prime and $SZ < MOD$.
 * Time: O(SZ)
 * Source: KACTL
 * Verification: https://dmoj.ca/problem/tle17c4p5
 */

vmi invs, fac, ifac;
void genFac(int SZ) {
	invs.rsz(SZ), fac.rsz(SZ), ifac.rsz(SZ); 
	invs[1] = fac[0] = ifac[0] = 1; 
	FOR(i,2,SZ) invs[i] = mi(-(ll)mi::mod()/i*(int)invs[mi::mod()%i]);
	FOR(i,1,SZ) fac[i] = fac[i-1]*i, ifac[i] = ifac[i-1]*invs[i];
}
mi comb(int a, int b) {
	if (a < b || b < 0) return 0;
	return fac[a]*ifac[b]*ifac[a-b]; }

/**
 * Description: Multiply polynomials of ints for any modulus $<2^{31}$. 
 	* For XOR convolution ignore \texttt{m} within \texttt{fft}. 
 * Time: O(N\log N)
 * Source: 
 	* KACTL (https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/NumberTheoreticTransform.h)
 	* https://cp-algorithms.com/algebra/fft.html
 	* https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it
 	* maroonrk
 	* https://github.com/atcoder/ac-library/blob/master/atcoder/convolution.hpp
 * Verification: 
	* https://judge.yosupo.jp/problem/convolution_mod
	* SPOJ polymul, CSA manhattan, CF Perfect Encoding
	* http://codeforces.com/contest/632/problem/E
 */

// #include "ModInt.h"

// const int MOD = 998244353;
tcT> void fft(V<T>& A, bool inv = 0) { // NTT
	int n = sz(A); assert((T::mod()-1)%n == 0); V<T> B(n);
	mi rt = 1;
	while (pow(rt, (T::mod()-1)/2) != -1) ++rt;
	for(int b = n/2; b; b /= 2, swap(A,B)) { // w = n/b'th root
		T w = pow(rt,(T::mod()-1)/n*b), m = 1; 
		for(int i = 0; i < n; i += b*2, m *= w) F0R(j,b) {
			T u = A[i+j], v = A[i+j+b]*m;
			B[i/2+j] = u+v; B[i/2+j+n/2] = u-v;
		}
	}
	if (inv) { reverse(1+all(A)); 
		T z = T(1)/T(n); each(t,A) t *= z; }
} // for NTT-able moduli
tcT> V<T> mul(V<T> A, V<T> B) {
	if (!min(sz(A),sz(B))) return {};
	int s = sz(A)+sz(B)-1, n = 1; for (; n < s; n *= 2);
	bool eq = A == B; A.rsz(n), fft(A);
	if (eq) B = A; // squaring A, reuse result
	else B.rsz(n), fft(B);
	F0R(i,n) A[i] *= B[i];
	fft(A,1); A.rsz(s); return A;
}

/**
 * Description: Basic poly ops including division. Can replace \texttt{T} with double, complex.
 * Source: Own. Also see
	* https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/PolyInterpolate.h
	* https://github.com/ecnerwala/icpc-book/blob/master/content/numerical/fft.cpp
 * Verification: see FFT
 */

// #include "../../number-theory (11.1)/Modular Arithmetic/ModInt.h"

using T = mi; using poly = V<T>;
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
	static poly invs{0,1};
	for (int i = sz(invs); i <= sz(p); ++i) 
		invs.pb(-mi::mod()/i*invs[mi::mod()%i]);
	poly res(sz(p)+1); F0R(i,sz(p)) res[i+1] = p[i]*invs[i+1];
	return res; 
}

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
// poly operator*(const poly& l, const poly& r) {
// 	if (!min(sz(l),sz(r))) return {};
// 	poly x(sz(l)+sz(r)-1); 
// 	F0R(i,sz(l)) F0R(j,sz(r)) x[i+j] += l[i]*r[j];
// 	return x;
// }
// poly& operator*=(poly& l, const poly& r) { return l = l*r; }

pair<poly,poly> quoRemSlow(poly a, poly b) { 
	remz(a); remz(b); assert(sz(b));
	T lst = b.bk, B = T(1)/lst; each(t,a) t *= B; 
	each(t,b) t *= B;
	poly q(max(sz(a)-sz(b)+1,0));
	for (int dif; (dif=sz(a)-sz(b)) >= 0; remz(a)) {
		q[dif] = a.bk; F0R(i,sz(b)) a[i+dif] -= q[dif]*b[i]; }
	each(t,a) t *= lst;
	return {q,a}; // quotient, remainder
}
poly operator%(const poly& a, const poly& b) { 
	return quoRemSlow(a,b).s; }
/**poly operator/(const poly& a, const poly& b) { 
	return quoRemSlow(a,b).f; }
poly a = {1,3,5,8,6,0,0,0,0}, b = {1,5,1};
ps(quoRemSlow(a,b)); a = 2*a, b = 2*b; ps(quoRemSlow(a,b));
poly gcd(poly a, poly b) { return b == poly{} ? a : gcd(b,a%b); }*/
T resultant(poly a, poly b) { // R(A,B)
	// =b_m^n*prod_{j=1}^mA(mu_j)
	// =b_m^na_n^m*prod_{i=1}^nprod_{j=1}^m(mu_j-lambda_i)
	// =(-1)^{mn}a_n^m*prod_{i=1}^nB(lambda_i)
	// =(-1)^{nm}R(B,A)
	// Also, R(A,B)=b_m^{deg(A)-deg(A-CB)}R(A-CB,B)
	int ad = sz(a)-1, bd = sz(b)-1; 
	if (bd <= 0) return bd < 0 ? 0 : pow(b.bk,ad);
	int pw = ad; a = a%b; pw -= (ad = sz(a)-1);
	return resultant(b,a)*pow(b.bk,pw)*T((bd&ad&1)?-1:1);
}

/**
 * Description: Multiply small polys directly, otherwise use FFT.
 * Source: KACTL, https://cp-algorithms.com/algebra/fft.html
 */

// #include "Poly.h"
// #include "FFT.h"

bool small(const poly& a, const poly& b) { // multiply directly
	return min(sz(a),sz(b)) <= 60; }
// vmi smart(const vmi& a, const vmi& b) { return mul(a,b); }
// vl smart(const vl& a, const vl& b) {
// 	auto X = mul(vcd(all(a)),vcd(all(b)));
// 	vl x(sz(X)); F0R(i,sz(X)) x[i] = round(X[i].real());
// 	return x; }
poly conv(const poly& a, const poly& b) {
	return mul(a,b); 
	// small(a,b) ? a*b : 
} 

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
// return {quotient, remainder}
pair<poly,poly> quoRem(const poly& f, const poly& g) {
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

// vmi sanity_check(int N) {
// 	vmi rooted_trees{0}, rooted_tree_prods{1};
// 	// rooted trees
// 	FOR(i,1,N+1) {
// 		rooted_trees.pb(i*rooted_tree_prods.at(i-1));
// 		rooted_tree_prods.eb();
// 		FOR(j,1,i+1) {
// 			rooted_tree_prods.at(i) += rooted_trees.at(j) * scmb.at(i-1).at(j-1) * rooted_tree_prods.at(i - j);
// 		}
// 	}
// 	// connected components
// 	vmi ccs(N+1);
// 	FOR(i,1,N+1) {
// 		ccs.at(i) = rooted_trees.at(i);
// 		FOR(j,1,i) {
// 			ccs.at(i) += ccs.at(j) * scmb.at(i-1).at(j-1) * rooted_trees.at(i - j);
// 		}
// 	}
// 	FOR(i,1,N+1) ccs.at(i) -= rooted_trees.at(i);
// 	vmi ans(N+1);
// 	ans.at(0) = 1;
// 	FOR(i,1,N+1) FOR(j,1,i+1) ans.at(i) += ans.at(i-j) * scmb.at(i-1).at(j-1) * ccs.at(j);
// 	assert(ans.at(N) == pow(mi(N-1), N));
// 	return ans;
// }


void mul_fac(vmi& v) {
	mi mul = 1;
	FOR(i,1,sz(v)) {
		mul *= i;
		v[i] *= mul;
	}
}


vmi solve(int N) {
	AR<vmi,2> rooted_trees{{{0},{0}}}; // 1 -> remains at same position, 0 -> not
	AR<vmi,3> rooted_tree_prods{{{1},{1},{0}}}; // 2 -> assigned, 1 -> there was a 1, 0 -> no 1 yet


	// T_0 = x*P_2
	// T_1 = x*P_0
	// P_0 = exp(T_0)
	// P_2 = (T_0+T_1)*exp(T_0+T_1)
	// P_1 = exp(T_0+T_1)-exp(T_0)

	// P_0 = 
	// P_2 = x*(exp(x*P_2)+P_2)*exp(x*(exp(x*P_2)+P_2))

	// x*(x*A(x))'
	// rooted trees
	auto go = [&](auto self, int l, int r) {
		if (l == r) {
			if (l == 0) return;
			F0R(k,2) rooted_tree_prods.at(k).at(l) /= l;
			return;
		}
		int m = (l+r)/2;
		self(self, l, m);
		// auto process = [&](int i, int j) {
		// 	if (m < i+j+1 && i+j+1 <= r) {
		// 		rooted_tree_prods.at(0).at(i+j+1) += (i+1) * rooted_tree_prods.at(2).at(i) * rooted_tree_prods.at(0).at(j);
		// 		rooted_tree_prods.at(1).at(i+j+1) += (i+1) * (rooted_tree_prods.at(2).at(i) + rooted_tree_prods.at(0).at(i)) * rooted_tree_prods.at(1).at(j);
		// 		rooted_tree_prods.at(2).at(i+j+1) += (rooted_tree_prods.at(2).at(i) + rooted_tree_prods.at(0).at(i)) * rooted_tree_prods.at(1).at(j);
		// 	}
		// };
		auto process_all = [&](int l1, int r1, int l2, int r2) {
			F0R(k,3) {
				vmi L, R;
				FOR(i,l1,r1+1) {
					mi v;
					if (k == 0) {
						v = (i+1) * rooted_tree_prods.at(2).at(i);
					} else if (k == 1) {
						v = (i+1) * (rooted_tree_prods.at(2).at(i) + rooted_tree_prods.at(0).at(i));
					} else {
						v = (rooted_tree_prods.at(2).at(i) + rooted_tree_prods.at(0).at(i));
					}
					L.pb(v);
				}
				FOR(j,l2,r2+1) {
					mi v;
					if (k == 0) {
						v = rooted_tree_prods.at(0).at(j);
					} else if (k == 1) {
						v = rooted_tree_prods.at(1).at(j);
					} else {
						v = rooted_tree_prods.at(1).at(j);
					}
					R.pb(v);
				}
				vmi Z = conv(L, R);
				F0R(i,sz(Z)) if (m < l1+l2+i+1 && l1+l2+i+1 <= r) {
					rooted_tree_prods.at(k).at(l1+l2+i+1) += Z.at(i);
				}
			}
		};
		assert(l == 0 || 2*l-1 >= r);
		if (l == 0) {
			process_all(0, m, 0, m);
			// F0R(i,m+1) F0R(j,m+1) process(i,j);
		} else {
			process_all(l, m, 0, r-l);
			process_all(0, r-l, l, m);
		}
		self(self, m+1, r);
	};
	FOR(i,1,N+1) F0R(k,3) rooted_tree_prods.at(k).eb();
	go(go, 0, N);
	F0R(k,3) dbg(k, rooted_tree_prods[k]);
	FOR(i,1,N+1) {
		rooted_trees.at(0).pb(rooted_tree_prods.at(2).at(i-1));
		rooted_trees.at(1).pb(rooted_tree_prods.at(2).at(i-1) + rooted_tree_prods.at(0).at(i-1));
	}
	rooted_trees.at(1) -= rooted_trees.at(0);
	rooted_tree_prods.at(1) -= rooted_tree_prods.at(0);
	F0R(i,2) {
		mul_fac(rooted_trees.at(i));
	}
	F0R(i,3) {
		mul_fac(rooted_tree_prods.at(i));
	}
	// FOR(i,1,N+1) dbg("??",i,fac.at(i)*ifac.at(i));
	// auto tran = [&](AR<vmi,2>& dp, int i) {
	// 	// A(x) = known(x) + known(x) * B(x) + known(x) * A(x)
	// 	// B(x) = known(x) * A(x)
	// 	FOR(j, 1, i) F0R(k,2) {
	// 		if (k == 1) {
	// 			// assign from branch
	// 			dp.at(0).at(i-1) += rooted_trees.at(0).at(j) * ifac.at(j) * dp.at(k).at(i-j-1);
	// 			// assign prev from cycle
	// 			dp.at(0).at(i-1) += (rooted_trees.at(1).at(j) + j * rooted_tree_prods.at(1).at(j-1)) * ifac.at(j) * dp.at(k).at(i-j-1);
	// 		} else {
	// 			// assign from branch
	// 			dp.at(0).at(i-1) += rooted_trees.at(0).at(j) * ifac.at(j) * dp.at(k).at(i-j-1);
	// 			// assign itself
	// 			dp.at(1).at(i-1) += rooted_trees.at(1).at(j) * ifac.at(j) * dp.at(k).at(i-j-1);
	// 			// assign prev from cycle
	// 			dp.at(0).at(i-1) += (rooted_trees.at(1).at(j) + j * rooted_tree_prods.at(1).at(j-1)) * ifac.at(j) * dp.at(k).at(i-j-1);
	// 		}
	// 	}
	// };
	vmi ccs(N+1);
	{ // filled with branch: rooted_trees.at(0).at(i)
		// #warning speed up
		AR<vmi,2> dp{};
		// FOR(i,1,N+1) {
		// 	F0R(k,2) dp.at(k).eb();
		// 	dp.at(0).at(i-1) = rooted_trees.at(0).at(i) * ifac.at(i-1);
		// 	// A(x) = ?_1 + ?_2 * A(x) + ?_3 * B(x)
		// 	// B(x) = ?_4 + ?_5 * A(x)
		// 	// A(x) = ?_1 + ?_2 * A(x) + ?_3 * ?_4 + ?_3 * ?_5 * A(x)
		// 	tran(dp, i);
		// }

		vmi q1(N); FOR(i,1,N+1) q1.at(i-1) = rooted_trees.at(0).at(i) * ifac.at(i-1);
		vmi q2(N); FOR(j,1,N) q2.at(j) = rooted_trees.at(0).at(j) * ifac.at(j) + (rooted_trees.at(1).at(j) + j * rooted_tree_prods.at(1).at(j-1)) * ifac.at(j);
		vmi q3(N); FOR(j,1,N) q3.at(j) = rooted_trees.at(0).at(j) * ifac.at(j) + (rooted_trees.at(1).at(j) + j * rooted_tree_prods.at(1).at(j-1)) * ifac.at(j);
		vmi q4(N);
		vmi q5(N); FOR(j,1,N) q5[j] = rooted_trees.at(1).at(j) * ifac.at(j);

		dp.at(0) = RSZ(conv((q1+RSZ(conv(q3,q4),N)),inv(poly{1}-q2-RSZ(conv(q3,q5),N),N)),N);
		dp.at(1) = q4 + RSZ(conv(q5,dp.at(0)), N);

		FOR(i,1,N+1) {
			ccs.at(i) += (dp.at(0).at(i-1) + dp.at(1).at(i-1))*fac.at(i-1) - rooted_trees.at(0).at(i);
		}
	}
	dbg(ccs);
	dbg("CASE B");
	{ // filled with prev along cycle: rooted_trees.at(1).at(i)
		// #warning speed up
		AR<vmi,2> dp{};

		// FOR(i,1,N+1) {
		// 	F0R(k,2) dp.at(k).eb();
		// 	dp.at(0).at(i-1) = (rooted_trees.at(1).at(i) + i * rooted_tree_prods.at(1).at(i - 1)) * ifac.at(i-1);
		// 	tran(dp, i);
		// }

		vmi q1(N); FOR(i,1,N+1) q1.at(i-1) = (rooted_trees.at(1).at(i) + i * rooted_tree_prods.at(1).at(i - 1)) * ifac.at(i-1);
		vmi q2(N); FOR(j,1,N) q2.at(j) = rooted_trees.at(0).at(j) * ifac.at(j) + (rooted_trees.at(1).at(j) + j * rooted_tree_prods.at(1).at(j-1)) * ifac.at(j);
		vmi q3(N); FOR(j,1,N) q3.at(j) = rooted_trees.at(0).at(j) * ifac.at(j) + (rooted_trees.at(1).at(j) + j * rooted_tree_prods.at(1).at(j-1)) * ifac.at(j);
		vmi q4(N);
		vmi q5(N); FOR(j,1,N) q5[j] = rooted_trees.at(1).at(j) * ifac.at(j);

		dp.at(0) = RSZ(conv((q1+RSZ(conv(q3,q4),N)),inv(poly{1}-q2-RSZ(conv(q3,q5),N),N)),N);
		dp.at(1) = q4 + RSZ(conv(q5,dp.at(0)), N);

		FOR(i,1,N+1) ccs.at(i) += (dp.at(0).at(i-1) + dp.at(1).at(i-1)) * fac.at(i-1);
	}
	dbg(ccs);
	{ // subtract only prev
		vmi A; FOR(i,1,N+1) A.pb((rooted_trees.at(1).at(i) + i * rooted_tree_prods.at(1).at(i-1)) * ifac.at(i-1));
		vmi B{1}; FOR(j,1,N) B.pb(-(rooted_trees.at(1).at(j) + j * rooted_tree_prods.at(1).at(j-1)) * ifac.at(j));
		vmi dp = RSZ(conv(A,inv(B,N)),N);
		FOR(i,1,N+1) ccs.at(i) -= dp.at(i-1) * fac.at(i-1);
	}
	{ // filled with itself: rooted_trees.at(1).at(i)
		// #warning speed up
		AR<vmi,2> dp{};
		// FOR(i,1,N+1) {
		// 	F0R(k,2) dp.at(k).eb();
		// 	dp.at(1).at(i-1) = rooted_trees.at(1).at(i) * ifac.at(i-1);
		// 	tran(dp, i);
		// }

		vmi q1(N); // FOR(i,1,N+1) q1.at(i-1) = (rooted_trees.at(1).at(i) + i * rooted_tree_prods.at(1).at(i - 1)) * ifac.at(i-1);
		vmi q2(N); FOR(j,1,N) q2.at(j) = rooted_trees.at(0).at(j) * ifac.at(j) + (rooted_trees.at(1).at(j) + j * rooted_tree_prods.at(1).at(j-1)) * ifac.at(j);
		vmi q3(N); FOR(j,1,N) q3.at(j) = rooted_trees.at(0).at(j) * ifac.at(j) + (rooted_trees.at(1).at(j) + j * rooted_tree_prods.at(1).at(j-1)) * ifac.at(j);
		vmi q4(N); FOR(i,1,N+1) q4.at(i-1) = rooted_trees.at(1).at(i) * ifac.at(i-1);
		vmi q5(N); FOR(j,1,N) q5[j] = rooted_trees.at(1).at(j) * ifac.at(j);

		dp.at(0) = RSZ(conv((q1+RSZ(conv(q3,q4),N)),inv(poly{1}-q2-RSZ(conv(q3,q5),N),N)),N);
		dp.at(1) = q4 + RSZ(conv(q5,dp.at(0)), N);

		FOR(i,1,N+1) ccs.at(i) += dp.at(0).at(i-1) * fac.at(i-1);
	}
	FOR(i,1,N+1) ccs.at(i) *= ifac.at(i);
	vmi ans = exp(ccs, N+1);
	mul_fac(ans);
	return ans;
}

int main() {
	setIO();
	ints(N,M); mi::set_mod(M);
	genFac(N+1);
	// vmi res = sanity_check(N);
	vmi res = solve(N);
	dbg(res);
	ps(res.at(N));
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/