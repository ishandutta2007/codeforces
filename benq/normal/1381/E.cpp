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

/**
 * Description: Use in place of \texttt{complex<T>}.
 * Source: http://codeforces.com/blog/entry/22175, KACTL
 * Verification: various
 */

typedef ld T;
int sgn(T a) { return (a>0)-(a<0); }
T sq(T a) { return a*a; }

namespace Point {
	typedef pair<T,T> P; typedef vector<P> vP;
	T norm(const P& p) { return sq(p.f)+sq(p.s); }
	T abs(const P& p) { return sqrt(norm(p)); }
	T arg(const P& p) { return atan2(p.s,p.f); }
	P conj(const P& p) { return P(p.f,-p.s); }
	P perp(const P& p) { return P(-p.s,p.f); }
	P dir(T ang) { return P(cos(ang),sin(ang)); }
	
	P operator-(const P& l) { return P(-l.f,-l.s); }
	P operator+(const P& l, const P& r) { 
		return P(l.f+r.f,l.s+r.s); }
	P operator-(const P& l, const P& r) { 
		return P(l.f-r.f,l.s-r.s); }
	P operator*(const P& l, const T& r) { 
		return P(l.f*r,l.s*r); }
	P operator*(const T& l, const P& r) { return r*l; }
	P operator/(const P& l, const T& r) { 
		return P(l.f/r,l.s/r); }
	P operator*(const P& l, const P& r) { 
		return P(l.f*r.f-l.s*r.s,l.s*r.f+l.f*r.s); }
	P operator/(const P& l, const P& r) { 
		return l*conj(r)/norm(r); }
	P& operator+=(P& l, const P& r) { return l = l+r; }
	P& operator-=(P& l, const P& r) { return l = l-r; }
	P& operator*=(P& l, const T& r) { return l = l*r; }
	P& operator/=(P& l, const T& r) { return l = l/r; }
	P& operator*=(P& l, const P& r) { return l = l*r; }
	P& operator/=(P& l, const P& r) { return l = l/r; }
	
	P unit(const P& p) { return p/abs(p); }
	T dot(const P& a, const P& b) { return a.f*b.f+a.s*b.s; }
	T cross(const P& a, const P& b) { return a.f*b.s-a.s*b.f; }
	T cross(const P& p, const P& a, const P& b) {
		return cross(a-p,b-p); }
	P reflect(const P& p, const P& a, const P& b) { 
		return a+conj((p-a)/(b-a))*(b-a); }
	P foot(const P& p, const P& a, const P& b) { 
		return (p+reflect(p,a,b))/(T)2; }
	bool onSeg(const P& p, const P& a, const P& b) { 
		return cross(a,b,p) == 0 && dot(p-a,p-b) <= 0; }
	ostream& operator<<(ostream& os, const P& p) {
		return os << "(" << p.f << "," << p.s << ")"; }
};
using namespace Point;

/**
 * Description: centroid (center of mass) of a polygon with 
 	* constant mass per unit area and SIGNED area
 * Time: O(N)
 * Source: http://codeforces.com/blog/entry/22175, KACTL
 * Verification: kattis polygonarea, VT HSPC 2018 Holiday Stars
 */

//#include "../Primitives/Point.h"

pair<P,T> cenArea(const vP& v) { 
	P cen(0,0); T area = 0; 
	F0R(i,sz(v)) {
		int j = (i+1)%sz(v); T a = cross(v[i],v[j]);
		cen += a*(v[i]+v[j]); area += a;
	}
	return {cen/area/(T)3,area/2};
}

vP v;
vP L, R;

typedef array<T,3> Q;

int pos = 0;
vector<pair<T,Q>> ev;
Q sum;

int n,q;

T get(T x) {
	while (pos < sz(ev) && ev[pos].f < x) {
		F0R(i,3) sum[i] += ev[pos].s[i];
		pos ++;
	}
	return (sum[2]*x+sum[1])*x+sum[0];
}

Q mul(T a, Q b) {
	trav(t,b) t *= a;
	return b;
}

Q operator-(Q a, Q b) {
	F0R(i,3) a[i] -= b[i];
	return a;
}
Q operator+(Q a, Q b) {
	F0R(i,3) a[i] += b[i];
	return a;
}

const int BIG = 2e5;

Q getEq(T l, T r, T a, T b, T c) {
	assert(l < r);
	Q ori = {0,(c-a)/(r-l),0};
	ori[0] = a-ori[1]*l;
	b -= (a+c)/2;
	T m = (l+r)/2;
	// (x-l)*(x-r)*k = b
	b /= (m-l)*(m-r);
	ori = ori+mul(b,Q{l*r,-l-r,1});
	//dbg("GETEQ",l,r,a,b,c,ori); exit(0);
	return ori;
}

T getX(P a, P b, T y) {
	return ((b.s-y)*a.f+(y-a.s)*b.f)/(b.s-a.s);
}

T getArea(P a, P b) {
	//dbg("DOING",a,b);
	vd impY = {0,1};
	auto ad = [&](T l, T r) { // 5, -1 -> 5/6
		if (min(l,r) < 0 && max(l,r) > 0) impY.pb(l/(l-r)); // get point where it becomes 0
	};
	ad(a.f,b.f); ad(a.s,b.s);
	ad((a.f+a.s)/2,(b.f+b.s)/2);
	remDup(impY);
	T ans = 0;
	F0R(i,sz(impY)-1) {
		T difY = impY[i+1]-impY[i];
		T y = (impY[i]+impY[i+1])/2;
		T xl = getX({a.f,0},{b.f,1},y), xr = getX({a.s,0},{b.s,1},y);
		auto cur = [&]() {
			if (min(xl,xr) >= 0 || max(xl,xr) <= 0) return (xr-xl);
			return max(abs(xl),abs(xr));
		};
		ans += cur()*difY;
	}
	// dbg("GETAREA",a,b,ans);
	return ans;
}

T getArea(P a, P b, T c) {
	a.f -= c, a.s -= c;
	b.f -= c, b.s -= c;
	return getArea(a,b);
}

vector<pair<T,Q>> make(P a, P b) {
	// evaluate pos and interpolate?
	vd reg;
	reg.pb(-BIG);
	reg.pb(BIG);
	reg.pb(a.f); reg.pb((a.f+a.s)/2); reg.pb(a.s);
	reg.pb(b.f); reg.pb((b.f+b.s)/2); reg.pb(b.s);
	remDup(reg);
	vd ans;
	F0R(i,sz(reg)) ans.pb(getArea(a,b,reg[i]));
	vd mid;
	F0R(i,sz(reg)-1) mid.pb(getArea(a,b,(reg[i]+reg[i+1])/2));
	// dbg(reg);
	// dbg(ans);
	// dbg(mid);
	vector<Q> eqs;
	F0R(i,sz(mid)) eqs.pb(getEq(reg[i],reg[i+1],ans[i],mid[i],ans[i+1]));
	ROF(i,1,sz(eqs)) eqs[i] = eqs[i]-eqs[i-1];
	vector<pair<T,Q>> res;
	F0R(i,sz(mid)) res.pb({reg[i],eqs[i]});
	return res;
}

vector<pair<T,pair<P,P>>> tmp;

T brute(T x) {
	T ans = 0;
	trav(t,tmp) ans += t.f*getArea(t.s.f,t.s.s,x);
	return ans;
}

int main() {
	setIO(); re(n,q);
	v.rsz(n); re(v);
	if (cenArea(v).s > 0) reverse(all(v));
	int ind = 0;
	F0R(i,n) if (v[i].s < v[ind].s) ind = i;
	rotate(begin(v),ind+all(v));
	F0R(i,n) if (v[i].s > v[ind].s) ind = i;
	F0R(i,ind+1) L.pb(v[i]);
	FOR(i,ind,n+1) R.pb(v[i%n]);
	reverse(all(R));
	// dbg(L);
	// dbg(R);

	int il = 0, ir = 0;
	T cy = v[0].s;
	while (il < sz(L)-1 && ir < sz(R)-1) {
		T ny = min(L[il+1].s,R[ir+1].s); assert(ny > cy);
		T dif = ny-cy;
		//dbg("HA",cy,ny);
		P x0 = {getX(L[il],L[il+1],cy),getX(R[ir],R[ir+1],cy)};
		P x1 = {getX(L[il],L[il+1],ny),getX(R[ir],R[ir+1],ny)};
		tmp.pb({dif,{x0,x1}});
		// dbg(cy,ny,x0,x1);
		//dbg(ny-cy,x0,x1);
		auto evs = make(x0,x1);
		trav(t,evs) ev.pb({t.f,mul(dif,t.s)});
		cy = ny;
		if (L[il+1].s == cy) il ++;
		if (R[ir+1].s == cy) ir ++;
	}
	sort(all(ev));
	// trav(t,tmp) dbg(t);
	//exit(0);
	vector<pair<T,int>> query;
	vd ans(q);
	F0R(i,q) {
		T f; re(f);
		query.pb({f,i});
	}
	sort(all(query));
	trav(t,query) {
		ans[t.s] = get(t.f);
	}
	trav(t,ans) cout << fixed << setprecision(10) << t << "\n";
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/