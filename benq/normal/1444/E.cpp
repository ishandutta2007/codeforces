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
void ps() { cout << endl; } // print w/ spaces
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
 * Description: Disjoint Set Union with path compression
 	* and union by size. Add edges and test connectivity. 
 	* Use for Kruskal's or Boruvka's minimum spanning tree.
 * Time: O(\alpha(N))
 * Source: CSAcademy, KACTL
 * Verification: *
 */

struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

/**template<class T> T kruskal(int N, vector<pair<T,pi>> ed) {
	sort(all(ed));
	T ans = 0; DSU D; D.init(N); // edges that unite are in MST
	trav(a,ed) if (D.unite(a.s.f,a.s.s)) ans += a.f; 
	return ans;
}*/

int N, label[101];
vi adj[101];
vb used;
int dist[101][101];
V<pair<int,pi>> ed;

// void dfs(int x, int pre = -1) {
// 	x = label[x];
// 	trav(t,ADJ[x]) if (label[t.f] != pre && label[t.f] != x) {
// 		// dbg("DFS",x,label[t.f]);
// 		dfs(t.f,x);
// 		if (!used[x] && !used[label[t.f]]) {
// 			used[x] = used[label[t.f]] = 1;
// 			ed.pb(t);
// 		}
// 	}
// }

vb active;

void query(int u, int v) {
	ps("?",u,v);
	int res; re(res);
	FOR(i,1,N+1) {
		if (dist[i][res] > dist[i][u^v^res]) active[i] = 0;
	}
}

using BIG = __int128;

BIG po(int i) { return BIG(1)<<i; }

BIG go(int x, int pre = -1) {
	V<pair<BIG,int>> res;
	trav(t,adj[x]) if (t != pre) res.pb({go(t,x),t});
	sort(rall(res));
	V<BIG> en;
	auto ok = [&](BIG pref) {
		en = V<BIG>(sz(res));
		V<BIG> tmp; trav(t,res) tmp.pb(t.f);
		R0F(i,N) if (pref&po(i)) {
			BIG mx = 0; trav(t,tmp) ckmax(mx,t);
			F0R(j,sz(tmp)) if (tmp[j] == mx) {
				tmp[j] -= po(i); en[j] ^= po(i);
				break;
			}
		}
		trav(t,tmp) if (t >= 0) return 0;
		return 1;
	};
	BIG cur = po(N)-1;
	R0F(i,N) {
		cur -= po(i);
		if (!ok(cur)) cur += po(i);
	}
	assert(ok(cur));
	F0R(i,sz(res)) {
		int j = N-1;
		while (((res[i].f>>j)&1) == ((en[i]>>j)&1)) j --;
		ed.pb({j,{x,res[i].s}});
	}
	return cur;
}

int main() {
	re(N);
	FOR(i,1,N+1) FOR(j,1,N+1) if (i != j) dist[i][j] = MOD;
	F0R(i,N-1) {
		int u,v; re(u,v);
		adj[u].pb(v); adj[v].pb(u);
		dist[u][v] = dist[v][u] = 1;
	}
	FOR(k,1,N+1) FOR(i,1,N+1) FOR(j,1,N+1) ckmin(dist[i][j],dist[i][k]+dist[k][j]);
	// dbg(dist[1][5]);
	// FOR(i,1,N+1) label[i] = i;
	// vpi all_eds;
	// while (1) {
	// 	set<int> labs;
	// 	FOR(i,1,N+1) ADJ[i].clear();
	// 	FOR(i,1,N+1) dbg(i,label[i]);
	// 	FOR(i,1,N+1) {
	// 		labs.ins(label[i]);
	// 		ADJ[label[i]].ins(end(ADJ[label[i]]),all(adj[i]));
	// 	}
	// 	dbg(labs); // exit(0);
	// 	if (sz(labs) == 1) break;
	// 	ed.clear();
	// 	used = vb(N+1);
	// 	dfs(1);
	// 	// dbg(ed);
	// 	trav(t,ed) {
	// 		int pre = label[t.f];
	// 		// dbg("HA",t,label[t.f],label[t.s]);
	// 		FOR(i,1,N+1) if (label[i] == pre) label[i] = label[t.s];
	// 	}
	// 	all_eds.ins(end(all_eds),all(ed));
	// }
	// reverse(all(all_eds));
	BIG b = go(1);
	sort(rall(ed));
	active = vb(N+1,1);
	dbg(ed,(ll)b);
	while (1) {
		vi res; 
		FOR(i,1,N+1) if (active[i]) res.pb(i);
		if (sz(res) == 1) {
			ps('!',res[0]);
			exit(0);
		}
		trav(t,ed) if (active[t.s.f] && active[t.s.s]) {
			query(t.s.f,t.s.s);
			break;
		}
	}
	// dbg(all_eds); exit(0);


	// what is the worst case #?
	// centroid decomp, but what if star?
	
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/