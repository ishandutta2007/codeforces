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

const int MOD = 1e9+7; // 998244353;
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

typedef unsigned int ui;

/**
 * Description: Disjoint Set Union with path compression. 
 	* Add edges and test connectivity. Use for Kruskal's 
 	* minimum spanning tree.
 * Time: O(\alpha(N))
 * Source: CSAcademy, KACTL
 * Verification: USACO superbull
 */

struct DSU {
	vi e; void init(int n) { e = vi(n,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

/**template<class T> T kruskal(int n, vector<pair<T,pi>> ed) {
	sort(all(ed));
	T ans = 0; DSU D; D.init(n+1); // edges that unite are in MST
	trav(a,ed) if (D.unite(a.s.f,a.s.s)) ans += a.f; 
	return ans;
}*/

/**
 * Description: Calculates least common ancestor in tree with binary jumping. 
 	* Vertices labeled from $1$ to $N$, $R$ is the root.
 * Time: O(N\log N)
 * Source: USACO Camp
 * Verification: Debug the Bugs
 */

template<int SZ> struct LCA {
	static const int BITS = 32-__builtin_clz(SZ);
	int N, R = 1, par[BITS][SZ], depth[SZ];
	vi adj[SZ];
	// INITIALIZE
	void ae(int u, int v) { adj[u].pb(v), adj[v].pb(u); }
	void dfs(int u, int prev){
		par[0][u] = prev;
		depth[u] = depth[prev]+1;
		trav(v,adj[u]) if (v != prev) dfs(v, u);
	}
	void init(int _N) {
		N = _N; dfs(R, 0);
		FOR(k,1,BITS) FOR(i,1,N+1) 
			par[k][i] = par[k-1][par[k-1][i]];
	}
	// QUERY
	int getPar(int a, int b) {
		R0F(k,BITS) if (b&(1<<k)) a = par[k][a];
		return a; }
	int lca(int u, int v){
		if (depth[u] < depth[v]) swap(u,v);
		u = getPar(u,depth[u]-depth[v]);
		R0F(k,BITS) if (par[k][u] != par[k][v]) 
			u = par[k][u], v = par[k][v];
		return u == v ? u : par[0][u];
	}
	int dist(int u, int v) {
		return depth[u]+depth[v]-2*depth[lca(u,v)]; }
};

LCA<MX> L;

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

int n,m,comp[MX];
vi extra[MX];
map<ui,mi> dp;
map<int,int> adj[MX];
set<int> nei;
int path[MX], dist[MX], xo[MX], pre[MX];

void dfs(int x) {
	trav(t,adj[x]) if (comp[t.f] == -1) {
		comp[t.f] = comp[x];
		dfs(t.f);
	}
}

map<pair<ui,ui>,int> aa;
map<ui,int> bb;

ui p(int x) { return (ui)1<<x; }

bool ok(ui& a, int b) {
	if (a&p(b)) return 0;
	ui res = a;
	F0R(i,32) if (a&p(i)) res ^= p(i^b);
	a = res;
	return 1;
}

void ad(int a, vi b) {
	ui cur = 1;
	trav(t,b) if (!ok(cur,t)) return;
	auto CUR = cur;
	if (ok(CUR,a)) aa[{CUR,cur}] ++; // one
	else aa[{0,cur}] ++; // two
}

void ad(vi b) {
	ui cur = 1;
	trav(t,b) if (!ok(cur,t)) return;
	bb[cur] ++;
}

pair<bool,ui> comb(ui a, ui b) {
	vi x,y;
	F0R(i,32) {
		if (a&p(i)) x.pb(i);
		if (b&p(i)) y.pb(i);
		if (i) if (a&p(i)) if (b&p(i)) return {0,0};
	}
	ui res = 0;
	trav(a,x) trav(b,y) res ^= p(a^b);
	return {1,res};
}

void process(pair<ui,ui> x, int y) {
	map<ui,mi> DP = dp;
	// remove one: x.f
	// remove two: x.s
	// remove both: nothing
	if (x.f != 0) {
		trav(t,dp) {
			pair<bool,ui> z = comb(t.f,x.f);
			if (z.f) {
				if (x.s == 1) {
					DP[z.s] += y*pow(mi(3),y-1)*t.s;
				} else {
					DP[z.s] += y*t.s;
				}
			}
		}
	} 
	if (x.s == 1) {
		trav(t,dp) DP[t.f] += (pow(mi(3),y)-1)*t.s;
	} else {
		trav(t,dp) {
			pair<bool,ui> z = comb(t.f,x.s);
			if (z.f) DP[z.s] += 2*y*t.s;
		}
	}
	swap(dp,DP);
}

void process(ui x, int y) {
	// remove zero: x
	// remove one: nothing
	map<ui,mi> DP = dp;
	if (x == 1) {
		trav(t,dp) DP[t.f] += (pow(mi(2),y)-1)*t.s;
	} else {
		trav(t,dp) {
			pair<bool,ui> z = comb(t.f,x);
			if (z.f) DP[z.s] += y*t.s;
		}
	}
	swap(dp,DP);
}

int main() {
	setIO();
	re(n,m); FOR(i,1,n+1) comp[i] = -1;
	vpi cool;
	F0R(i,m) {
		int a,b,w; re(a,b,w);
		adj[a][b] = w, adj[b][a] = w;
		cool.pb({a,b});
	}
	vpi cyc; vi wei;
	FOR(i,2,n+1) trav(t,adj[i]) if (t.f > i) {
		if (adj[1].count(i) && adj[1].count(t.f)) {
			comp[i] = comp[t.f] = sz(cyc);
			cyc.pb({i,t.f});
			wei.pb(adj[1][i]^adj[1][t.f]^t.s);
		}
	}
	int co = sz(cyc);
	trav(t,adj[1]) if (comp[t.f] == -1) comp[t.f] = co++;
	comp[1] = MOD; trav(t,adj[1]) dfs(t.f);
	FOR(i,1,n+1) dist[i] = MOD, pre[i] = -1;
	queue<int> q; q.push(1); dist[1] = 0;
	while (sz(q)) {
		int x = q.ft; q.pop();
		trav(t,adj[x]) if (dist[t.f] == MOD) {
			dist[t.f] = dist[x]+1;
			xo[t.f] = xo[x]^t.s;
			pre[t.f] = x;
			q.push(t.f);
		}
	}
	FOR(i,1,n+1) assert(dist[i] != MOD);
	trav(t,cool) {
		if (dist[t.f] == 1 && dist[t.s] == 1) continue;
		if (dist[t.f] > dist[t.s]) swap(t.f,t.s);
		if (t.f == pre[t.s]) continue;
		assert(comp[t.f] == comp[t.s]);
		// ps("EXTRAEXTRA",t,adj[t.f][t.s],xo[t.f],xo[t.s]);
		extra[comp[t.f]].pb(xo[t.f]^xo[t.s]^adj[t.f][t.s]);
	}
	dp[1] = 1;
	F0R(i,sz(cyc)) ad(wei[i],extra[i]);
	FOR(i,sz(cyc),co) ad(extra[i]);
	trav(t,aa) process(t.f,t.s);
	trav(t,bb) process(t.f,t.s);
	mi ans = 0; trav(t,dp) ans += t.s;
	ps(ans);
	/*F0R(i,32) if (cnt[i]) pr()
	dp[0] = 1;*/

	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
*/