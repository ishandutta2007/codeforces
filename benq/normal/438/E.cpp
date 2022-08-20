#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 
 
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 
 
#define mp make_pair 
#define f first
#define s second
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
 
// const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
 
template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }
int pc(int x) { return __builtin_popcount(x); } 
 
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
 
	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = {a,b}; }
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
		// cin.exceptions(cin.failbit); 
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}
 
using namespace io;
 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
 
/**
 * Description: modular arithmetic operations 
 * Source: 
	* KACTL
	* https://codeforces.com/blog/entry/63903
	* https://codeforces.com/contest/1261/submission/65632855 (tourist)
	* https://codeforces.com/contest/1264/submission/66344993 (ksun)
 * Verification: 
	* https://open.kattis.com/problems/modulararithmetic
 */
 
const int MOD = (119<<23)+1, root = 3; // = 998244353
// NTT: For p < 2^30 there is also e.g. (5 << 25, 3), 
// (7 << 26, 3), (479 << 21, 3) and (483 << 21, 5). 
// The last two are > 10^9.
 
struct mi {
	typedef decay<decltype(MOD)>::type T; 
 	/// don't silently convert to T
	T v; explicit operator T() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.v < b.v; }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }
	friend void pr(const mi& a) { pr(a.v); }
	friend ostream& operator<<(ostream& os, const mi& a) { 
		return os << a.v; }
   
	mi& operator+=(const mi& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		v = (ll)v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;
 
vector<vmi> comb;
void genComb(int SZ) {
	comb.assign(SZ,vmi(SZ)); comb[0][0] = 1;
	FOR(i,1,SZ) F0R(j,i+1) 
		comb[i][j] = comb[i-1][j]+(j?comb[i-1][j-1]:0);
}
 
typedef complex<db> cd;
typedef vector<cd> vcd;
 
int size(int s) { return s > 1 ? 32-__builtin_clz(s-1) : 0; }
void genRoots(vcd& roots) { // primitive n-th roots of unity
	int n = sz(roots); db ang = 2*PI/n;
	/// good way to compute these trig functions more quickly?
	F0R(i,n) roots[i] = cd(cos(ang*i),sin(ang*i)); 
}
void genRoots(vmi& roots) { 
	int n = sz(roots); mi r = pow(mi(root),(MOD-1)/n);
	roots[0] = 1; FOR(i,1,n) roots[i] = roots[i-1]*r;
}
 
template<class T> void fft(vector<T>& a, 
  const vector<T>& roots, bool inv = 0) {
	int n = sz(a); // sort #s from 0 to n-1 by reverse binary
	for (int i = 1, j = 0; i < n; i++) { 
		int bit = n>>1; for (; j&bit; bit /= 2) j ^= bit;
		j ^= bit; if (i < j) swap(a[i],a[j]);
	}
	for (int len = 2; len <= n; len *= 2) 
		for (int i = 0; i < n; i += len) F0R(j,len/2) {
			int ind = n/len*j; if (inv && ind) ind = n-ind;
			auto u = a[i+j], v = a[i+j+len/2]*roots[ind]; 
			a[i+j] = u+v, a[i+j+len/2] = u-v;
		}
	if (inv) { T i = T(1)/T(n); trav(x,a) x *= i; }
}
template<class T> vector<T> mul(vector<T> a, vector<T> b) {
	if (!min(sz(a),sz(b))) return {};
	int s = sz(a)+sz(b)-1, n = 1<<size(s);
	vector<T> roots(n); genRoots(roots);
	a.rsz(n), fft(a,roots); b.rsz(n), fft(b,roots);
	F0R(i,n) a[i] *= b[i];
	fft(a,roots,1); a.rsz(s); return a;
}
vl mulMod(const vl& a, const vl& b) { 
	if (!min(sz(a),sz(b))) return {};
	int s = sz(a)+sz(b)-1, n = 1<<size(s), cut = sqrt(MOD);
	vcd roots(n); genRoots(roots);
	vcd ax(n), bx(n);
	// ax(x)=a1(x)+i*a0(x)
	F0R(i,sz(a)) ax[i] = cd((int)a[i]/cut, (int)a[i]%cut); 
	// bx(x)=b1(x)+i*b0(x)
	F0R(i,sz(b)) bx[i] = cd((int)b[i]/cut, (int)b[i]%cut); 
	fft(ax,roots), fft(bx,roots);
	vcd v1(n), v0(n);
	F0R(i,n) {
		int j = (i ? (n-i) : i);
		// v1 = a1*(b1+b0*cd(0,1));
		v1[i] = (ax[i]+conj(ax[j]))*cd(0.5,0)*bx[i]; 
		// v0 = a0*(b1+b0*cd(0,1));
		v0[i] = (ax[i]-conj(ax[j]))*cd(0,-0.5)*bx[i]; 
	}
	fft(v1,roots,1), fft(v0,roots,1);
	vl ret(n);
	F0R(i,n) {
		ll V2 = (ll)round(v1[i].real()); // a1*b1
		ll V1 = (ll)round(v1[i].imag())+(ll)round(v0[i].real()); 
		// a0*b1+a1*b0
		ll V0 = (ll)round(v0[i].imag()); // a0*b0
		ret[i] = ((V2%MOD*cut+V1)%MOD*cut+V0)%MOD;
	}
	ret.rsz(s); return ret;
} 
 
template<class T> bool small(const vector<T>& a, const vector<T>& b) { 
	return (ll)sz(a)*sz(b) <= 500000; // for small vectors, multiply directly
} 
vmi smart(const vmi& a, const vmi& b) { return mul(a,b); }
vcd smart(const vcd& a, const vcd& b) { return mul(a,b); }
vl smart(const vl& a, const vl& b) {
	auto X = smart(vcd(all(a)),vcd(all(b)));
	vl x(sz(X)); F0R(i,sz(X)) x[i] = round(X[i].real());
	return x;
}
template<class T> vector<T> conv(const vector<T>& a, const vector<T>& b) {
	if (small(a,b)) return a*b;
	return smart(a,b);
} 
 
typedef mi T; using poly = vector<T>;
void norm (poly& p) { while (sz(p) && p.bk == 0) p.pop_back(); }
poly rev(poly p) { reverse(all(p)); return p; }
poly RSZ(poly p, int x) { p.rsz(x); return p; }
T eval(const poly& p, T x) {
	T res = 0; R0F(i,sz(p)) res = x*res+p[i]; 
	return res; }
poly dif(const poly& p)	 {
	poly res; FOR(i,1,sz(p)) res.pb(i*p[i]); 
	return res; }
poly integ(const poly& p)  {
	poly res(sz(p)+1); F0R(i,sz(p)) res[i+1] = p[i]/(i+1);
	return res; }
 
poly& operator+=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] += r[i]; 
	return l; }
poly& operator-=(poly& l, const poly& r) {
	l.rsz(max(sz(l),sz(r))); F0R(i,sz(r)) l[i] -= r[i]; 
	return l; }
poly& operator*=(poly& l, const T& r) { trav(t,l) t *= r; 
	return l;	 }
poly& operator/=(poly& l, const T& r) { trav(t,l) t /= r; 
	return l; }
poly operator+(poly l, const poly& r) { return l += r; }
poly operator-(poly l, const poly& r) { return l -= r; }
poly operator-(poly l) { trav(t,l) t *= -1; return l; }
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
	assert(sz(b)); auto B = b.bk; assert(B != 0);
	B = 1/B; trav(t,b) t *= B;
	norm(a); poly q(max(sz(a)-sz(b)+1,0));
	while (sz(a) >= sz(b)) {
		q[sz(a)-sz(b)] = a.bk;
		F0R(i,sz(b)) a[i+sz(a)-sz(b)] -= a.bk*b[i];
		norm(a);
	}
	trav(t,q) t *= B; 
	return {q,a};
}
poly interpolate(vector<pair<T,T>> v) {
	poly ret, prod = {1}; trav(t,v) prod *= poly({-t.f,1});
	F0R(i,sz(v)) {
		T fac = 1; F0R(j,sz(v)) if (i != j) fac *= v[i].f-v[j].f;
		ret += v[i].s/fac*quoRem(prod,{-v[i].f,1}).f;
	}
	return ret;
}
 
poly inv(poly A, int n) { // Q-(1/Q-A)/(-Q^{-2})
	poly B = {1/A[0]};
	while (sz(B) < n) {
		int x = 2*sz(B);
		B = RSZ(2*B-conv(RSZ(A,x),conv(B,B)),x);
	}
	return RSZ(B,n);
}
poly sqrt(const poly& A, int n) {  // Q-(Q^2-A)/(2Q)
	assert(A[0] == 1); poly B = {1};
	while (sz(B) < n) {
		int x = 2*sz(B);
		B = T(1)/T(2)*RSZ(B+mul(RSZ(A,x),inv(B,x)),x);
	}
	return RSZ(B,n);
}
poly log(poly A, int n) { // (ln A)' = A'/A
	assert(A[0] == 1);
	return RSZ(integ(conv(dif(A),inv(A,n))),n);
}
poly exp(poly A, int n) { // Q-(lnQ-A)/(1/Q)
	assert(A[0] == 0); poly B = {1};
	while (sz(B) < n) {
		int x = 2*sz(B);
		B = RSZ(B+conv(B,RSZ(A,x)-log(B,x)),x);
	}
	return RSZ(B,n);
}
pair<poly,poly> divi(const poly& f, const poly& g) { 
	if (sz(f) < sz(g)) return {{},f};
	auto q = mul(inv(rev(g),sz(f)-sz(g)+1),rev(f));
	q = rev(RSZ(q,sz(f)-sz(g)+1));
	auto r = RSZ(f-mul(q,g),sz(g)-1); return {q,r};
}
 
 
int n,m;
vmi c(100001);
// 2/(1+sqrt(c))
 
int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n,m);
    F0R(i,n) {
        int C; re(C);
        c[C] = (int)c[C]+1;
    }
    c = vmi(1,1)-mi(4)*c;
    c = vmi(1,1)+sqrt(c,1<<17);
    c = inv(c*(mi(1)/2),1<<17);
    FOR(i,1,m+1) ps(c[i]);
    // you should actually read the stuff at the bottom
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
*/