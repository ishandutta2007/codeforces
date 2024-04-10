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
const int MX = 4e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
 
template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }
int pct(int x) { return __builtin_popcount(x); } 
 
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
		par[0][u] = prev; depth[u] = depth[prev]+1;
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
int n,k,r,close[MX],dist[MX];
 
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
 
DSU D;
 
int col(int a, int b, int k) {
	int x = L.lca(a,b); // ps("???",a,b,x,L.dist(a,x));
	if (k <= L.dist(a,x)) {
		// ps("HUH",a,k,L.getPar(a,k));
		return D.get(close[L.getPar(a,k)]);
	}
	return D.get(close[L.getPar(b,L.dist(a,b)-k)]);
}
 
int main() {
	setIO(); re(n,k,r);
	F0R(i,n-1) {
		int x,y; re(x,y);
		L.ae(n+1+i,x);
		L.ae(n+1+i,y);
	}
	vi R(r); re(R); // ps("HA",R);
	L.init(2*n); D.init(2*n);
	FOR(i,1,2*n+1) dist[i] = MOD;
	queue<int> q; 
	trav(t,R) {
		dist[t] = 0; close[t] = t;
		q.push(t);
	}
	//ps("???",L.adj[2]);
	while (sz(q)) {
		int x = q.ft; q.pop();
		if (dist[x] < k) {
			trav(t,L.adj[x]) if (dist[t] == MOD) {
				dist[t] = dist[x]+1;
				close[t] = close[x];
				q.push(t);
			} else D.unite(close[t],close[x]);
		}
	}
	//FOR(i,1,2*n+1) ps(i,dist[i],close[i]);
	//ps(L.getPar(7,3),col(7,1,3),col(1,7,3));
	int v; re(v);
	F0R(i,v) {
		int a,b; re(a,b);
		bool ret = 0;
		if (L.dist(a,b) <= 2*k) ret = 1;
		else {
			int x = col(a,b,k), y = col(b,a,k);
			ret = (x && y && x == y);
		}
		if (ret) ps("YES");
		else ps("NO");
	}
	// you should actually read the stuff at the bottom
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
*/