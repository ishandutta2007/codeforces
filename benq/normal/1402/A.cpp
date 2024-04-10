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
typedef vector<bool> vb; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 
template<class T> using V = vector<T>; 
template<class T, size_t SZ> using AR = array<T,SZ>; 
 
#define mp make_pair
#define f first
#define s second
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
mt19937 rng;
 
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
	// note: if (lo+hi)/2 is used instead of half(lo+hi) then this will loop infinitely when lo=hi
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
 * Description: Minimum-cost maximum flow, assumes no negative cycles. 
 	* Edges may be negative only during first run of SPFA. To get flow
 	* through original edges, assign ID's during \texttt{ae}.
 * Time: $O(FM\log M)$ if caps are integers and $F$ is max flow
 * Source: GeeksForGeeks
 	* https://courses.csail.mit.edu/6.854/06/scribe/s12-minCostFlowAlg.pdf
 	* running time is only pseudo-polynomial; see https://codeforces.com/blog/entry/70740
 	* https://en.wikipedia.org/wiki/Johnson%27s_algorithm (to get non-negative weights)
 * Verification: https://codeforces.com/contest/164/problem/C
 */
 
int num;

template<int SZ> struct MCMF {
	int N,s,t; // # verts, source, sink
	typedef int F; typedef int C; // flow type, cost type
	struct Edge { int to, rev; F flow, cap; C cost; };
	vector<Edge> adj[SZ]; // use asserts, don't try smth dumb
	void ae(int u, int v, F cap, C cost) { assert(cap >= 0); 
		Edge a{v,sz(adj[v]),0,cap,cost}, b{u,sz(adj[u]),0,0,-cost};
		adj[u].pb(a), adj[v].pb(b); }
	pi pre[SZ]; // previous vertex, edge label on path
	C cost[SZ]; // tot cost of path, amount of flow
	C totCost = 0, curCost = 0; F totFlow = 0; 
	bool spfa() { // find lowest cost path to send flow through
		F0R(i,N) cost[i] = numeric_limits<C>::max();
		cost[s] = 0; // infinite flow at source
		typedef pair<C,int> T; priority_queue<T,vector<T>,greater<T>> todo; 
		todo.push({0,s}); // just do dijkstra
		while (sz(todo)) {
			T x = todo.top(); todo.pop(); num += sz(adj[x.s]);
			if (x.f > cost[x.s]) continue;
			if (cost[t] != numeric_limits<C>::max()) break;
			for (const auto& a : adj[x.s]) if (a.flow < a.cap 
				&& ckmin(cost[a.to],x.f+a.cost)) { 
				pre[a.to] = {x.s,a.rev};
				todo.push({cost[a.to],a.to});
			} // if costs are doubles, add some EPS so you 
		} // don't traverse ~0-weight cycle repeatedly
		return cost[t] == numeric_limits<C>::max() ? 0 : 1; // return flow
	}
	void backtrack() {
		F df = 1;
		totCost += cost[t]*df;
		for (int x = t; x != s; x = pre[x].f) { // subtract from cap,
			adj[x][pre[x].s].flow -= df; // add two reverse edges
			adj[pre[x].f][adj[x][pre[x].s].rev].flow += df;
			// num ++;
		}
		// F0R(i,N) trav(p,adj[i]) p.cost += cost[i].f-cost[p.to].f;
	} // all reduced costs non-negative if flow > 0
	// edges on shortest path become 0
	pair<F,C> calc(int _N, int _s, int _t) {
		N = _N, s = _s, t = _t; assert(s != t);
		while (spfa()) backtrack();
		return {totFlow,totCost};
	}
};
 
int n,m;
MCMF<6402> M;
int g[80][80];
 
int hsh(int a, int b) {
	return m*a+b;
}
 
int main() {
	setIO(); re(n,m);
	int cnt = 0;
	F0R(i,n) F0R(j,m) {
	    g[i][j] = cnt++;
	   re(g[i][j]);
	}
	// F0R(z,2000) {
	//     if (rng()%2 == 0) {
 //    	    int x = rng()%(n-1), y = rng()%m;
 //    	    g[x][y] = g[x+1][y] = cnt++;
	//     } else {
 //    	    int x = rng()%n, y = rng()%(m-1);
 //    	    g[x][y] = g[x][y+1] = cnt++;
	//     }
	// }
	F0R(i,n) F0R(j,m) if ((i+j)%2 == 0) {
		M.ae(n*m,hsh(i,j),1,0);
		F0R(k,4) {
			int I = i+xd[k], J = j+yd[k];
			if (I < 0 || I >= n || J < 0 || J >= m) continue;
			M.ae(hsh(i,j),hsh(I,J),1,g[i][j] != g[I][J]);
		}
	} else M.ae(hsh(i,j),n*m+1,1,0);
	ps(M.calc(n*m+2,n*m,n*m+1).s);
	// ps(num);
	// you should actually read the stuff at the bottom
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/