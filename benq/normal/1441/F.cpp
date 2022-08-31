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
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

// helper funcs
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
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
tcT> void rv(int& n, vector<T>& x) { re(n); x.rsz(n); trav(a,x) re(a); }

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

// make sure to intialize ALL GLOBAL VARS between tcs!

/**
 * Description: Use in place of \texttt{complex<T>}.
 * Source: http://codeforces.com/blog/entry/22175, KACTL
 * Verification: various
 */

using T = ll;
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

/**
 * Description: Sorts points in ccw order about origin in the same way as
 	* \texttt{atan2}, which returns real in $(-\pi,\pi]$ so points on 
 	* negative $x$-axis come last.
 * Verification: https://codeforces.com/contest/1284/submission/68175790
 	* https://codeforces.com/contest/1284/submission/68207607 
 	* (don't use atan2, weird stuff happens!)
 */

// #include "Point.h"

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

int N,M;

void solve(int tc) {
	re(N,M);
	vP verts(N); re(verts);
	V<vi> adj(N);
	vi nex(2*M,-1), pre(2*M,-1), dest(2*M,-1), cc(2*M,-1);
	vb dead(M);
	F0R(i,M) {
		int u,v; re(u,v); --u,--v;
		adj[u].pb(2*i);   dest[2*i] = v;
		adj[v].pb(2*i+1); dest[2*i+1] = u;
	}
	auto link = [&](int x, int y) { // link two edges
		nex[x] = y, pre[y] = x;
	};
	F0R(i,N) {
		sort(all(adj[i]),[&](int a, int b) {
			return angleCmp(verts[dest[a]]-verts[i],verts[dest[b]]-verts[i]);
		});
		F0R(j,sz(adj[i])) {
			int J = (j+1)%sz(adj[i]);
			link(adj[i][j]^1,adj[i][J]);
		}
	}
	F0R(i,2*M) if (cc[i] == -1) {
		for (int j = i; cc[j] == -1; j = nex[j]) cc[j] = i;
	}
	vi bridges;
	auto check_bridge = [&](int x) {
		if (cc[2*x] == cc[2*x+1]) bridges.pb(x);
	};
	F0R(i,M) check_bridge(i);
	auto join_lines = [&](pi a, pi b) {
		assert(nex[a.s] == -1 && nex[b.s] == -1);
		// dbg("JOIN LINES");
		{
			int ta = a.f, tb = b.f;
			for (; ta != -1 && tb != -1; ta = nex[ta], tb = nex[tb]);
			if (ta != -1) swap(a,b);
		}
		{
			int ta = a.f;
			for (;ta != -1; ta = nex[ta]) {
				cc[ta] = cc[b.f];
				check_bridge(ta/2);
			}
		}
		link(a.s,b.f), link(b.s,a.f);
	};
	auto del_edge = [&](int e) {
		if (dead[e]) return;
		dead[e] = 1;
		int a = pre[2*e], b = nex[2*e+1];
		int c = pre[2*e+1], d = nex[2*e];
		if (cc[2*e] == cc[2*e+1]) {
			// split into two
			link(a,b); link(c,d);
			// link(pre[2*e],nex[2*e+1]);
			// link(pre[2*e+1],nex[2*e]);
		} else {
			// join two comps
			nex[a] = nex[c] = pre[b] = pre[d] = -1;
			join_lines({d,a},{b,c});
		}
		// splice(pre[2*e],nex[2*e+1]);
		// splice(pre[2*e+1],nex[2*e]);
		// pre[2*e] -> nex[2*e+1]
		// pre[2*e+1] -> nex[2*e];
	};
	vi vis(N);
	int tot = 0, epoch = 0;
	while (sz(bridges)) {
		int e = bridges.bk; bridges.pop_back();
		if (dead[e]) continue;
		del_edge(e);
		int u = dest[2*e], v = dest[2*e+1];
		auto should_cut = [&]() {
			epoch ++;
			queue<int> q[2];
			auto ad = [&](int ind, int vert) {
				if (vis[vert] == epoch) return;
				vis[vert] = epoch;
				q[ind].push(vert);
			};
			ad(0,u), ad(1,v);
			int cnt = 0;
			while (sz(q[0]) && sz(q[1])) {
				cnt ++;
				F0R(i,2) {
					int x = q[i].ft; q[i].pop();
					trav(y,adj[x]) if (!dead[y/2]) ad(i,dest[y]);
				}
			}
			return cnt&1;
		};
		if (should_cut()) {
			tot ++;
			trav(oe,adj[u]) del_edge(oe/2);
			trav(oe,adj[v]) del_edge(oe/2);
		}
	}
	ps(2*tot == N);
}

int main() {
	setIO();
	int TC; re(TC);
	FOR(i,1,TC+1) solve(i);
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/