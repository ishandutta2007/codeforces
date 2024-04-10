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

const int MOD = 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bit(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 

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
template<class A, class B> str ts(pair<A,B> p);
template<class A> str ts(complex<A> c) { return ts(mp(c.real(),c.imag())); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(char c) { str s = ""; s += c; return s; }
str ts(str s) { return s; }
str ts(const char* s) { return (str)s; }
str ts(vector<bool> v) { 
	bool fst = 1; str res = "{";
	F0R(i,sz(v)) {
		if (!fst) res += ", ";
		fst = 0; res += ts(v[i]);
	}
	res += "}"; return res;
}
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class T> str ts(T v) {
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
	cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 42
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
	friend str to_string(mi a) { return to_string(a.v); }
   
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

/**
 * Description: Use in place of \texttt{complex<T>}.
 * Source: http://codeforces.com/blog/entry/22175, KACTL
 * Verification: various
 */

typedef ll T;
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

int n,par[101],depth[101];
P pos[201];
mi dp[101], childProd[101];
vi adj[101];

bool ccw(int a, int b, int c) {
	return cross(pos[a],pos[b],pos[c]) >= 0; } // OK

vi tot;
void genChild(int x) { // OK
	tot.pb(x);
	trav(t,adj[x]) genChild(t);
}

vi path(int a, int b) {
	int _a = a, _b = b;
	vi x, y;
	while (a != b) {
		if (depth[a] > depth[b]) {
			x.pb(a);
			a = par[a];
		} else {
			y.pb(b);
			b = par[b];
		}
	}
	reverse(all(y));
	x.pb(a); x.insert(end(x),all(y));
	// dbg("??",_a,_b,x);
	return x;
} // OK

bool bet(P a, P b, P c) {
	if (cross(a,c) > 0) {
		return cross(a,b) > 0 && cross(b,c) > 0;
	}
	return cross(a,b) > 0 || cross(b,c) > 0;
}

mi get(int a, int b, int c) {
	mi prod = 1;
	trav(t,adj[b]) {
		if (t == a || t == c) continue;
		if (bet(pos[a]-pos[b],pos[t]-pos[b],pos[c]-pos[b])) {
			//ps("WUT",a,b,c,t);
			prod *= dp[t];
		}
	}
	return prod;
}

mi val(int x, int y) {
	if (x == y) return 0; // OK
	vi v = path(x,y); // OK
	trav(t,v) if (!ccw(x,y,t)) return 0; // OK
	mi prod = 1; trav(t,adj[x]) if (t != v[1]) prod *= dp[t];
	FOR(i,1,sz(v)-1) prod *= get(v[i-1],v[i],v[i+1]);
	// dbg("VAL",x,y,prod);
	return prod;
}

mi nex[201][201];
mi lo[201][201], hi[201][201];
vi TMP[201];

mi solveConvex(vi c) {
	mi res = 0;
	sort(all(c),[&](int x, int y) { return pos[x] < pos[y]; });
	F0R(i,sz(c)) {
		vector<pair<P,int>> tmp;
		F0R(j,sz(c)) if (nex[c[i]][c[j]] != 0 || nex[c[j]][c[i]] != 0) {
			if (j < i) tmp.pb({pos[c[i]]-pos[c[j]],j});
			else tmp.pb({pos[c[j]]-pos[c[i]],j});
		}
		sort(all(tmp),[](pair<P,int> x, pair<P,int> y) {
			return cross(x.f,y.f) > 0; });
		TMP[i].clear(); trav(t,tmp) TMP[i].pb(t.s);
	}
	F0R(st,sz(c)) {
		F0R(a,sz(c)) FOR(b,a+1,sz(c)) lo[a][b] = hi[a][b] = 0;
		FOR(i,st,sz(c)) {
			mi LO = (i == st);
			trav(t,TMP[i]) {
				if (t < i) LO += lo[t][i];
				else lo[i][t] = nex[c[i]][c[t]]*LO;
			}
			reverse(all(TMP[i]));
			mi HI = (i == st);
			trav(t,TMP[i]) {
				if (t < i) HI += hi[t][i];
				else hi[i][t] = nex[c[t]][c[i]]*HI;
			}
			reverse(all(TMP[i]));
			if (i != st) res += LO*HI;
		}
	}
	return res;
}

int makeEd(int a, int b) {
	assert(abs(depth[a]-depth[b]) == 1);
	if (depth[a] < depth[b]) return b;
	return a+n;
}

mi deal(vi c, int a) {
	auto _c = c;
	vi verts; trav(x,c) verts.pb(x), verts.pb(x+n);
	trav(x,verts) trav(y,verts) nex[x][y] = 0;
	// return 0;
	// val[x,y] for all good pairs
	trav(x,c) trav(y,c) {
		mi z = val(x,y); if (!ccw(x,y,a)) z = 0;
		if (z == 0) continue;
		vi v = path(x,y);
		nex[makeEd(v[1],x)][makeEd(v[sz(v)-2],y)] = z;
	}
	return solveConvex(verts);
}

void dfs(int a) {
	childProd[a] = 1;
	trav(t,adj[a]) dfs(t), childProd[a] *= dp[t];
	dp[a] = childProd[a];
	tot.clear(); genChild(a);
	dp[a] += deal(tot,a);
	trav(t,adj[a]) {
		tot.clear(); genChild(t);
		dp[a] -= deal(tot,a);
	}
	// dbg(a,dp[a],adj[a]);
}

void genDepth(int x) {
	trav(t,adj[x])  {
		par[t] = x; depth[t] = depth[x]+1;
		pos[t+n] = pos[x];
		adj[t].erase(find(all(adj[t]),x));
		genDepth(t);
	}
}

int main() {
	setIO(); re(n);
	FOR(i,1,n+1) re(pos[i]);
	F0R(i,n-1) {
		int a,b; re(a,b);
		adj[a].pb(b), adj[b].pb(a);
	}
	genDepth(1); dfs(1);
	ps(dp[1]);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/