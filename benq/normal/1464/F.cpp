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

#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }

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
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(V<T>& x) { trav(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { trav(a,x) re(a); }
tcT> void rv(int n, V<T>& x) { x.rsz(n); re(x); }

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
 * Description: 1D range minimum query. Can also do queries 
 	* for any associative operation in $O(1)$ with D\&C
 * Source: KACTL
 * Verification: 
	* https://cses.fi/problemset/stats/1647/
	* http://wcipeg.com/problem/ioi1223
	* https://pastebin.com/ChpniVZL
 * Memory: O(N\log N)
 * Time: O(1)
 */

template<class T> struct RMQ { // floor(log_2(x))
	int level(int x) { return 31-__builtin_clz(x); } 
	vector<T> v; vector<vi> jmp;
	int comb(int a, int b) { // index of min
		return v[a]==v[b]?min(a,b):(v[a]<v[b]?a:b); } 
	void init(const vector<T>& _v) {
		v = _v; jmp = {vi(sz(v))}; iota(all(jmp[0]),0);
		for (int j = 1; 1<<j <= sz(v); ++j) {
			jmp.pb(vi(sz(v)-(1<<j)+1));
			F0R(i,sz(jmp[j])) jmp[j][i] = comb(jmp[j-1][i],
									jmp[j-1][i+(1<<(j-1))]);
		}
	}
	int index(int l, int r) { // get index of min element
		assert(l <= r); int d = level(r-l+1);
		return comb(jmp[d][l],jmp[d][r-(1<<d)+1]); }
	T query(int l, int r) { return v[index(l,r)]; }
};

/**
 * Description: Euler Tour LCA. Compress takes a subset $S$ of nodes 
 	* and computes the minimal subtree that contains all the nodes 
	* pairwise LCAs and compressing edges. Returns a list of
	* \texttt{(par, orig\_index)} representing a tree rooted at 0. 
	* The root points to itself.
 * Time: O(N\log N) build, O(1) LCA, O(|S|\log |S|) compress
 * Source: USACO, Simon Lindholm (KACTL)
 * Verification: USACO Debug the Bugs
 	* https://codeforces.com/contest/1320/problem/E
 */

// #include "../../data-structures/Static Range Queries (9.1)/RMQ (9.1).h"

struct LCA {
	int N; vector<vi> adj;
	vi depth, pos, par, rev; // rev is for compress
	vpi tmp; RMQ<pi> r;
	void init(int _N) { N = _N; adj.rsz(N); 
		depth = pos = par = rev = vi(N); }
	void ae(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
	void dfs(int x) {
		pos[x] = sz(tmp); tmp.eb(depth[x],x); 
		trav(y,adj[x]) if (y != par[x]) {
			depth[y] = depth[par[y]=x]+1, dfs(y);
			tmp.eb(depth[x],x); }
	}
	void gen(int R = 0) { par[R] = R; dfs(R); r.init(tmp); }
	int lca(int u, int v){
		u = pos[u], v = pos[v]; if (u > v) swap(u,v);
		return r.query(u,v).s; }
	int dist(int u, int v) {
		return depth[u]+depth[v]-2*depth[lca(u,v)]; }
	vpi compress(vi S) {
		auto cmp = [&](int a, int b) { return pos[a] < pos[b]; };
		sort(all(S),cmp); R0F(i,sz(S)-1) S.pb(lca(S[i],S[i+1]));
		sort(all(S),cmp); S.erase(unique(all(S)),end(S));
		vpi ret{{0,S[0]}}; F0R(i,sz(S)) rev[S[i]] = i;
		FOR(i,1,sz(S)) ret.eb(rev[lca(S[i-1],S[i])],S[i]);
		return ret;
	}
	bool path(int a, int b, int c) {
		return dist(a,b)+dist(b,c) == dist(a,c);
	}
};

LCA lca;

int N,Q;

int closest(pi a, int b) {
	vi cand{lca.lca(a.f,b),lca.lca(a.s,b),lca.lca(a.f,a.s)};
	pi bes{MOD,MOD};
	trav(t,cand) if (lca.path(a.f,t,a.s))
		ckmin(bes,mp(lca.dist(t,b),t));
	return bes.s;
}

pi isect(pi a, pi b) {
	int x = closest(b,a.f);
	if (!lca.path(a.f,x,a.s)) return {-1,-1};
	return {closest(b,a.f),closest(b,a.s)};
}

pair<int,pi> add(pair<int,pi> a, pi b) {
	if (a.f == -1) return {0,b};
	pi p = isect(a.s,b);
	if (a.f == 0) {
		if (p != mp(-1,-1)) return {0,p};
		return {1,{closest(b,a.s.f),closest(a.s,b.f)}};
	}  else {
		if (p != mp(-1,-1)) return a;
		int x = closest(b,a.s.f);
		auto eval = [&](int v0, int v1) {
			return mp(lca.dist(v0,v1),mp(v0,v1));
		};
		pair<int,pi> bes = eval(a.s.f,a.s.s);
		ckmax(bes,eval(x,a.s.f));
		ckmax(bes,eval(x,a.s.s));
		return {1,bes.s};
	}
}

vi ans;

void divi(int l, int r, V<pair<pi,pi>> ad, pair<int,pi> data) {
	// dbg("DIVI",l,r,ad,data);
	V<pair<pi,pi>> extra;
	trav(t,ad) {
		if (t.f.s < l) continue;
		if (r < t.f.f) continue;
		if (t.f.f <= l && r <= t.f.s) {
			data = add(data,t.s);
			continue;
		}
		extra.pb(t);
	}
	if (l == r) {
		ans[l] = (data.f <= 0 ? 0 : lca.dist(data.s.f,data.s.s));
		return;
	}
	int m = (l+r)/2;
	divi(l,m,extra,data);
	divi(m+1,r,extra,data);
}

int main() {
	setIO();
	re(N,Q);
	lca.init(N);
	F0R(_,N-1) {
		int x,y; re(x,y); --x,--y;
		lca.ae(x,y);
	}
	lca.gen();
	map<pi,vi> st;
	V<pair<pi,pi>> ad;
	vpi query;
	F0R(_,Q) {
		int t; re(t);
		if (t == 1) {
			int u,v; re(u,v); --u,--v;
			if (u > v) swap(u,v);
			st[{u,v}].pb(_);
		} else if (t == 2) {
			int u,v; re(u,v); --u,--v;
			if (u > v) swap(u,v);
			ad.pb({{st[{u,v}].bk,_},{u,v}});
			st[{u,v}].pop_back();
		} else {
			int d; re(d);
			query.pb({_,d});
		}
	}
	trav(x,st) {
		trav(y,x.s) ad.pb({{y,Q-1},x.f});
	}
	// dbg(ad);
	// exit(0);
	ans.rsz(Q);
	divi(0,Q-1,ad,{-1,{-1,-1}});
	dbg("DONE DIVI");
	trav(t,query) if (ans[t.f] <= 2*t.s) ps("Yes");
	else ps("No");
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/