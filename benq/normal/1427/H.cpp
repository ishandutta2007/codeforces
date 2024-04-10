#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using db = double; 
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
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

// helper funcs
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

#define tcTU tcT, class U
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
	t.erase(u); } // element that doesn't exist from (multi)set

// INPUT
#define tcTUU tcT, class ...U
tcT> void re(complex<T>& c);
tcTU> void re(pair<T,U>& p);
tcT> void re(vector<T>& v);
tcT, size_t SZ> void re(AR<T,SZ>& a);

tcT> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(vector<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { trav(a,x) re(a); }

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
tcT> str ts(complex<T> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
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

// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
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

using T = db;
int sgn(T a) { return (a>0)-(a<0); }
T sq(T a) { return a*a; }

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

int N;
vP poly;
vd dists;
int par;

void genDists() {
	dists = {0}; F0R(i,N) dists.pb(dists.bk+abs(poly[i]-poly[i+1]));
}

void rev() {
	par ^= 1;
	db maxY = poly.bk.s;
	reverse(all(poly));
	genDists();
	trav(t,poly) t.s = maxY-t.s;
}

vP ans;
db vel;

// P ternary(db lo, db hi, function<db(db)> eval) {
// 	F0R(_,50) {
// 		db m1 = (2*lo+hi)/3;
// 		db m2 = (lo+2*hi)/3;
// 		if (eval(m1) < eval(m2)) hi = m2;
// 		else lo = m1;
// 	}
// 	return {lo,eval(lo)};
// }

P ternary(double a, double b, function<db(db)> f) {
	double r = (sqrt(5)-1)/2, eps = 1e-12;
	double x1 = b - r*(b-a), x2 = a + r*(b-a);
	double f1 = f(x1), f2 = f(x2);
	F0R(_,40)
		if (f1 < f2) { //change to > to find maximum
			b = x2; x2 = x1; f2 = f1;
			x1 = b - r*(b-a); f1 = f(x1);
		} else {
			a = x1; x1 = x2; f1 = f2;
			x2 = a + r*(b-a); f2 = f(x2);
		}
	return {a,f(a)};
}

map<pi,P> calced[2];

void tri(int l, int r) {
	// dbg("TRYING",l,r,poly);
	assert(l < r);
	P dirl = unit(poly[l+1]-poly[l]), dirr = unit(poly[r+1]-poly[r]);
	auto eval = [&](db t1, db t2) {
		P pos1 = poly[l]+t1*dirl;
		P pos2 = poly[r]+t2*dirr;
		return abs(pos2-pos1)/((dists[r]+t2)-(dists[l]+t1));
	};
	function<db(db)> getMin = [&](db rig) {
		return ternary(0,dists[l+1]-dists[l],[&](db x) { return eval(x,rig); }).s;
	};
	if (!calced[par].count({l,r})) calced[par][{l,r}] = ternary(0,dists[r+1]-dists[r],getMin);
	P mid = calced[par][{l,r}];
	// if (!calced.count({poly[l],poly[r],poly[l+]}))
	// P mid = ternary(0,dists[r+1]-dists[r],getMin);
	if (mid.s > 1/vel) return;
	db L, R;
	{
		db lo = 0, hi = mid.f;
		F0R(_,50) {
			db m = (lo+hi)/2;
			if (getMin(m) < 1/vel) hi = m;
			else lo = m;
		}
		L = lo;
	}
	{
		db lo = mid.f, hi = dists[r+1]-dists[r];
		F0R(_,50) {
			db m = (lo+hi)/2;
			if (getMin(m) < 1/vel) lo = m;
			else hi = m;
		}
		R = lo;
	}
	ans.pb({dists[r]+L,dists[r]+R});
}

vP ranges() {
	// dbg("RANGES");
	ans.clear();
	F0R(i,N) FOR(j,i+1,N) tri(i,j);
	sort(all(ans));
	vP ANS;
	trav(t,ans) {
		if (!sz(ANS) || ANS.bk.s < t.f) ANS.pb(t);
		else ckmax(ANS.bk.s,t.s);
	}
	return ANS;
}

bool intervalIsect(P a, P b) {
	if (a.s < b.f) return 0;
	if (b.s < a.f) return 0;
	return 1;
}

bool escape(db mid) {
	dbg("DOING",mid);
	vel = mid;
	vP lef = ranges();
	rev();
	vP rig = ranges();
	rev();
	trav(t,rig) t = {dists.bk-t.s,dists.bk-t.f};
	reverse(all(rig));
	// dbg("ESCAPE",mid);
	// dbg(lef); dbg(rig);
	int il = 0, ir = 0;
	while (il < sz(lef) && ir < sz(rig)) {
		if (intervalIsect(lef[il],rig[ir])) return 1;
		if (lef[il].f < rig[ir].f) il ++;
		else ir ++;
	}
	return 0;
}

int main() {
	clock_t beg = clock();
	setIO(); re(N); poly.rsz(N+1); re(poly);
	genDists();
	db lo = 1, hi = 1e4;
	while (hi/lo > 1+1e-8) {
		db mid = sqrt(lo*hi);
		if (escape(mid)) lo = mid;
		else hi = mid;
	}
	// F0R(i,40) {
	// 	db mid = (lo+hi)/2;
	// 	if (escape(mid)) lo = mid;
	// 	else hi = mid;
	// }
	cout << fixed << setprecision(9) << lo;
	dbg((db)(clock()-beg)/CLOCKS_PER_SEC);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/