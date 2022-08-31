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
int pct(int x) { return __builtin_popcount(x); } 
int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 
int fstTrue(function<bool(int)> f, int lo, int hi) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		int mid = (lo+hi)/2; 
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
 
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
 * Description: Eulerian path starting at \texttt{src} if it exists, 
 	* visits all edges exactly once. Works for both directed and 
 	* undirected. Returns vector of {vertex,label of edge to vertex}.
 	* The second element of the first pair is always $-1$.
 * Time: O(N+M)
 * Source: USACO Training, MIT ICPC Notebook
 * Verification:
	* directed -> https://open.kattis.com/problems/eulerianpath
	* undirected -> USACO Training 3.3, Riding the Fences
 */
 
template<int SZ, bool directed> struct Euler {
	int N; vpi adj[SZ]; vpi::iterator its[SZ];
	vector<bool> used;
	void ae(int a, int b) {
		int M = sz(used); used.pb(0); 
		adj[a].eb(b,M); if (!directed) adj[b].eb(a,M); }
	vpi solve(int _N, int src = 0) {
		N = _N; F0R(i,N) its[i] = begin(adj[i]);
		vector<pair<pi,int>> ret, s = {{{src,-1},-1}}; 
		// {{vert, prev vert}, edge label}
		while (sz(s)) {
			int x = s.bk.f.f; auto& it = its[x], en = end(adj[x]);
			while (it != en && used[it->s]) it ++;
			if (it == en) { // no more edges out of vertex
				if (sz(ret) && ret.bk.f.s != x) return {}; 
				ret.pb(s.bk), s.pop_back(); 
			} else { s.pb({{it->f,x},it->s}); used[it->s] = 1; }
		}
		if (sz(ret) != sz(used)+1) return {};
		vpi ans; trav(t,ret) ans.pb({t.f.f,t.s});
		reverse(all(ans)); return ans;
	}
};
 
/**
 * Description: Disjoint Set Union with path compression
 	* and union by size. Add edges and test connectivity. 
 	* Use for Kruskal's or Boruvka's minimum spanning tree.
 * Time: O(\alpha(N))
 * Source: CSAcademy, KACTL
 * Verification: USACO superbull
 */
 
struct DSU {
	vi e; void init(int n) { e = vi(n,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
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
 
 
Euler<1<<20,0> E;
int n;
 
int main() {
	setIO(); re(n);
	vpi ed;
	F0R(i,n) {
		int a,b; re(a,b);
		ed.pb({a,b});
	}
	R0F(i,21) {
		vpi ED; trav(t,ed) ED.pb({t.f%(1<<i),t.s%(1<<i)}); // OK
		vi deg(1<<i); DSU D; D.init(1<<i); // OK
		trav(t,ED) {
			deg[t.f] ++, deg[t.s] ++;
			D.unite(t.f,t.s);
		}
		bool bad = 0;
		F0R(j,1<<i) if (deg[j]&1) bad = 1;
		if (bad) continue;
		set<int> comp;
		trav(t,ED) {
			comp.insert(D.get(t.f));
			if (sz(comp) > 1) {
				bad = 1;
				break;
			}
		}
		if (bad) continue;
		ps(i);
		trav(t,ED) E.ae(t.f,t.s);
		vpi v = E.solve(1<<i,ED[0].f); assert(sz(v) == n+1);
		dbg("??",v);
		vi ans;
		FOR(z,1,sz(v)) {
			// dbg("DOING",i);
			int label = v[z].s;
			if (v[z].f == ed[label].f%(1<<i)) {
				assert(v[z-1].f == ed[label].s%(1<<i));
				assert(v[z].f == ed[label].f%(1<<i));
				ans.pb(2*label+2);
				ans.pb(2*label+1);
			} else {
				//dbg("???",label,ed[label],v[z-1].f,ed[label].f%(1<<i));
				assert(v[z-1].f == ed[label].f%(1<<i));
				assert(v[z].f == ed[label].s%(1<<i));
				ans.pb(2*label+1);
				ans.pb(2*label+2);
			}
		}
		trav(t,ans) pr(t,' ');
		// dbg(v);
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