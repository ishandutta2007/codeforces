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
constexpr int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 
int fstTrue(function<bool(int)> f, int lo, int hi) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		int mid = (lo+hi)/2; 
		f(mid) ? hi = mid : lo = mid+1; 
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
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
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
	bool fst = 1; str res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += ts(x);
	}
	res += "}"; return res;
}
template<class A, class B> str ts(pair<A,B> p) {
	return "("+ts(p.f)+", "+ts(p.s)+")"; }

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
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(string s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

/**
 * Description: Basic 3D geometry. 
 * Source: Own
 * Verification: (haven't done much 3D geo yet)
	* AMPPZ 2011 Cross Spider
	* https://atcoder.jp/contests/JAG2013Spring/tasks/icpc2013spring_h
	* https://codeforces.com/gym/102040 - I
	* https://codeforces.com/gym/102452/problem/F
 */

typedef ld T;
int sgn(T x) { return (x>0)-(x<0); }
T sq(T x) { return x*x; }

typedef array<T,4> Q;
T norm(const Q& x) { 
	T sum = 0; F0R(i,4) sum += sq(x[i]);
	return sum; }
ll llnorm(const Q& x) { return (ll)round(norm(x)); }
T abs(const Q& x) { return sqrt(norm(x)); }
Q conj(Q x) { return {x[0],-x[1],-x[2],-x[3]}; }

Q& operator+=(Q& l, const Q& r) { F0R(i,4) l[i] += r[i]; 
	return l; }
Q& operator-=(Q& l, const Q& r) { F0R(i,4) l[i] -= r[i]; 
	return l; }
Q& operator*=(Q& l, const T& r) { F0R(i,4) l[i] *= r; 
	return l; }
Q& operator/=(Q& l, const T& r) { F0R(i,4) l[i] /= r; 
	return l; }
Q operator*(Q x, Q y) {
	return {x[0]*y[0]-x[1]*y[1]-x[2]*y[2]-x[3]*y[3],
			x[0]*y[1]+x[1]*y[0]+x[2]*y[3]-x[3]*y[2],
			x[0]*y[2]-x[1]*y[3]+x[2]*y[0]+x[3]*y[1],
			x[0]*y[3]+x[1]*y[2]-x[2]*y[1]+x[3]*y[0]};
}
Q operator-(Q l) { l *= -1; return l; }
Q operator+(Q l, const Q& r) { return l += r; }
Q operator-(Q l, const Q& r) { return l -= r; }
Q operator*(Q l, const T& r) { return l *= r; }
Q operator*(const T& r, const Q& l) { return l*r; }
Q operator/(Q l, const T& r) { return l /= r; }
Q inv(Q x) { return conj(x)/norm(x); }

// T dot(const Q& a, const Q& b) { 
// 	T sum = 0; F0R(i,3) sum += a[i]*b[i]; 
// 	return sum; }
// Q cross(const Q& a, const Q& b) {
// 	return {a[1]*b[2]-a[2]*b[1],a[2]*b[0]-a[0]*b[2],
// 			a[0]*b[1]-a[1]*b[0]}; }
// Q cross(const Q& a, const Q& b, const Q& c) {
// 	return cross(b-a,c-a); }

Q round(Q q) { 
	Q a, b;
	F0R(i,4) a[i] = round(q[i]); 
	F0R(i,4) b[i] = round(q[i]-0.5)+0.5;
	if (norm(a-q) < norm(b-q)) return a;
	return b;
}
Q operator%(Q a, Q b) {
	Q q = round(inv(b)*a);
	return a-b*q;
}
Q gcd(Q a, Q b) {
	if (norm(a) > norm(b)) swap(a,b);
	if (norm(a) == 0) return b;
	return gcd(b%a,a);
}

int n;

void prin(Q q) {
	FOR(i,1,4) pr((ll)round(q[i]),' ');
	ps();
}

bool notClose(T t) { return abs(t-round(t)) > 1e-9; }

bool notClose(Q q) {
	F0R(i,4) if (notClose(q[i])) return 1;
	return 0;
}

int main() {
	setIO(); re(n);
	vector<Q> q(n);
	ll G = 0;
	Q g = Q();
	F0R(i,n) {
		T x,y,z; re(x,y,z);
		q[i] = {0,x,y,z};
		G = __gcd(G,llnorm(q[i]));
		g = gcd(g,q[i]);
	}
	dbg(G,g);
	vl posi;
	for (ll q = 1; q*q <= G; ++q) if (G%q == 0 && G/q%q == 0) posi.pb(q);
	reverse(all(posi));
	// dbg("UH",posi);
	trav(t,posi) {
		Q A = gcd(g,Q{t}), AC = conj(A);
		dbg("??",t,A);
		ll r = llnorm(A); dbg(r);
		Q Aprime = A/r, ACprime = AC/r;
		bool bad = 0;
		trav(z,q) {
			Q v = ACprime*z*Aprime;
			dbg("HAHA",v);
			if (notClose(v)) { bad = 1; break; }
		}
		dbg("UH",bad);
		if (bad) continue;
		ps(r*r);
		prin(A*Q{0,1,0,0}*AC);
		prin(A*Q{0,0,1,0}*AC);
		prin(A*Q{0,0,0,1}*AC);
		exit(0);
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/