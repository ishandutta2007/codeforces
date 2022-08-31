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


struct MCMF { 
	using F = ll; using C = ll; // flow type, cost type
	struct Edge { int to, rev; F flo, cap; C cost; int id; };
	int N; V<C> p, dist; vpi pre; V<V<Edge>> adj;
	void init(int _N) { N = _N;
		p.rsz(N), adj.rsz(N), dist.rsz(N), pre.rsz(N); }
	void ae(int u, int v, F cap, C cost, int id) { assert(cap >= 0); 
		adj[u].pb({v,sz(adj[v]),0,cap,cost,id}); 
		adj[v].pb({u,sz(adj[u])-1,0,0,-cost,-1});
	} // use asserts, don't try smth dumb
	bool path(int s, int t) { // find lowest cost path to send flow through
		const C inf = numeric_limits<C>::max(); dist.assign(N,inf);
		using T = pair<C,int>; priority_queue<T,vector<T>,greater<T>> todo; 
		todo.push({dist[s] = 0,s}); 
		while (sz(todo)) { // Dijkstra
			T x = todo.top(); todo.pop(); if (x.f > dist[x.s]) continue;
			trav(e,adj[x.s]) { // all weights should be non-negative
				if (e.flo < e.cap && ckmin(dist[e.to],x.f+e.cost+p[x.s]-p[e.to]))
					pre[e.to] = {x.s,e.rev}, todo.push({dist[e.to],e.to});
			}
		} // if costs are doubles, add some EPS so you 
		// don't traverse ~0-weight cycle repeatedly
		return dist[t] != inf; // return flow
	}
	pair<F,C> calc(int s, int t) { assert(s != t);
		F0R(_,N) F0R(i,N) trav(e,adj[i]) // Bellman-Ford
			if (e.cap) ckmin(p[e.to],p[i]+e.cost);
		dbg("FINISHED BELLMAN");
		F totFlow = 0; C totCost = 0;
		while (path(s,t)) { // p -> potentials for Dijkstra
			dbg("PATH",s,t);
			F0R(i,N) p[i] += dist[i]; // don't matter for unreachable nodes
			F df = numeric_limits<F>::max();
			for (int x = t; x != s; x = pre[x].f) {
				Edge& e = adj[pre[x].f][adj[x][pre[x].s].rev]; 
				ckmin(df,e.cap-e.flo); }
			totFlow += df; totCost += (p[t]-p[s])*df;
			for (int x = t; x != s; x = pre[x].f) {
				adj[pre[x].f][adj[x][pre[x].s].rev].flo += df;
				adj[x][pre[x].s].flo -= df; }
		} // get max flow you can send along path
		return {totFlow,totCost};
	}
};

int n,k;
MCMF m;
 
vector<array<int,3>> compress(vector<array<int,3>> v) {
    map<int,int> m;
    trav(t,v) m[t[0]] = m[t[1]] = 0;
    int co = 0;
    trav(t,m) t.s = ++co;
    trav(t,v) t[0] = m[t[0]], t[1] = m[t[1]];
    return v;
}
 
bool ans[1001];
 
int main() {
	m.init(2002);
    setIO(); re(n,k);
    vector<array<int,3>> v(n); 
    re(v); trav(t,v) t[1] += t[0];
    auto V = compress(v);
    m.ae(0,1,k,0,-1);
    FOR(i,2,2002) m.ae(i-1,i,INF,0,-1);
    int co = 0;
    trav(t,V) m.ae(t[0],t[1],1,-t[2],++co);
    dbg("STARTING");
    m.calc(0,2001);
    dbg("ENDING");
    F0R(i,2002) trav(t,m.adj[i]) if (t.flo > 0) if (t.id > 0) ans[t.id] = 1;
    FOR(i,1,n+1) {
    	if (ans[i]) pr(1);
    	else pr(0);
    	pr(' ');
    }
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/