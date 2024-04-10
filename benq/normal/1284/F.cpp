#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 

typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 
#define mp make_pair
#define f first
#define s second

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi; 
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

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

const int MOD = 1e9+7; // 998244353; // = (119<<23)+1
const int MX = 3e5+5; 
const ll INF = 1e18; 
const ld PI = 4*atan((ld)1); 
const int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0}; 

template<class T> bool ckmin(T& a, const T& b) { 
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 
// change null_type for map
#define ook order_of_key
#define fbo find_by_order

void treeExample() {
	Tree<int> t, t2; t.insert(8);
	auto it = t.insert(10).f; assert(it == t.lb(9));
	assert(t.ook(10) == 1); assert(t.ook(11) == 2);
	assert(*t.fbo(0) == 8);
	t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}

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

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
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
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

struct mi {
	typedef decay<decltype(MOD)>::type T;
	T val; 
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(ll v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.val < b.val; }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }
	friend void pr(const mi& a) { pr(a.val); }
	friend ostream& operator<<(ostream& os, const mi& a) { 
		return os << a.val; }
   
	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) { 
		if ((val += m.val) >= MOD) val -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((val -= m.val) < 0) val += MOD; 
		return *this; }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }

	mi& operator*=(const mi& m) { 
		val = (ll)val*m.val%MOD; return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { 
		assert(!(a == 0)); return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

struct DSU {
	vi e; void init(int n) { e = vi(n,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y); assert(x != y);
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x;
		// trav(t,cool[y]) cool[x].pb(t);
		return 1;
	}
};
DSU D;

typedef struct snode* sn;
struct snode { 
	//////// VARIABLES
	sn p, c[2]; // parent, children
	// sn extra; // extra cycle node
	bool flip = 0; // subtree flipped or not
	int val; // value in node, # nodes in subtree

	// int vir = 0; stores sum of virtual children
	snode(int v) {
		p = c[0] = c[1] = NULL;
		val = v; calc();
	}
	// friend int getSz(sn x) { return x?x->sz:0; }
	void prop() { // lazy prop
		if (!flip) return;
		swap(c[0],c[1]); F0R(i,2) if (c[i]) c[i]->flip ^= 1;
		flip = 0; 
	}
	void calc() { // recalc vals
		F0R(i,2) if (c[i]) c[i]->prop();
		// sz = 1+getSz(c[0])+getSz(c[1]);
	}
	//////// SPLAY TREE OPERATIONS
	int dir() {
		if (!p) return -2;
		F0R(i,2) if (p->c[i] == this) return i;
		return -1; // p is path-parent pointer,
		// so not in current splay tree
	}
	bool isRoot() { return dir() < 0; } 
	// test if root of current splay tree
	friend void setLink(sn x, sn y, int d) {
		if (y) y->p = x;
		if (d >= 0) x->c[d] = y;
	}
	void rot() { // assume p and p->p propagated
		assert(!isRoot()); int x = dir(); sn pa = p;
		setLink(pa->p, this, pa->dir());
		setLink(pa, c[x^1], x);
		setLink(this, pa, x^1);
		pa->calc(); calc();
	}
	void splay() {
		while (!isRoot() && !p->isRoot()) {
			p->p->prop(), p->prop(), prop();
			dir() == p->dir() ? p->rot() : rot();
			rot();
		}
		if (!isRoot()) p->prop(), prop(), rot();
		prop();
	}
	//////// LINK CUT TREE BASE OPERATIONS
	void access() { // bring this to top of tree
		for (sn v = this, pre = NULL; v; v = v->p) {
			v->splay(); 
			// if (pre) v->vir -= pre->sz;
			// if (v->c[1]) v->vir += v->c[1]->sz;
			v->c[1] = pre; v->calc();
			pre = v;
			// v->sz should remain the same if using vir
		}
		splay(); // left subtree of this is now path to root
		assert(!c[1]); // right subtree is empty
	}
	void makeRoot() { access(); flip ^= 1; }
	void set(int v) { splay(); val = v; calc(); } 
	// change val in node,
	// splay suffices instead of access because 
	// it doesn't affect values in nodes above it
	//////// LINK CUT TREE QUERIES
	friend sn lca(sn x, sn y) {
		if (x == y) return x;
		x->access(), y->access(); if (!x->p) return NULL; 
		// access at y did not affect x
		// so they must not be connected
		x->splay(); return x->p ? x->p : x;
	}
	friend bool connected(sn x, sn y) { return lca(x,y); } 
	// LCA is null if not connected
	// int distRoot() { access(); return getSz(c[0]); } 
	// # nodes above
	sn getRoot() { // get root of LCT component
		access(); auto a = this; 
		while (a->c[0]) a = a->c[0], a->prop();
		a->access(); return a;
	}
	/*sn dfs(int b) {
		int z = getSz(c[0]);
		if (b < z) return c[0]->dfs(b);
		if (b == z) { access(); return this; }
		return c[1]->dfs(b-z-1);
	}*/
	//////// LINK CUT TREE MODIFICATIONS
	friend bool link(sn x, sn y) { // make x parent of y
		if (connected(x,y)) return 0; // don't induce cycle
		// y->access(); assert(!y->c[0]); 
		y->makeRoot(); // if you want to ensure link succeeds
		y->p = x; 
		// x->access(); x->sz += y->sz; x->vir += y->sz;
		return 1;
	}
	friend bool cut(sn y) { // cut y from its parent
		y->access(); if (!y->c[0]) return 0;
		y->c[0]->p = NULL; y->c[0] = NULL;
		y->calc(); return 1;
	}
	friend bool cut(sn x, sn y) { // if x, y adjacent in tree
		x->makeRoot(); y->access(); 
		if (y->c[0] != x || x->c[0] || x->c[1]) return 0; 
		// splay tree with y should not contain anything besides x
		assert(cut(y)); return 1;
	}
};

sn LCT[MX];

template<int SZ> struct LCA {
	static const int BITS = 32-__builtin_clz(SZ);
	int N, R = 1; 
	vi adj[SZ];
	int par[BITS][SZ], depth[SZ];
	// INITIALIZE
	void addEdge(int u, int v) { adj[u].pb(v), adj[v].pb(u); }
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
		return a;
	}
	int lca(int u, int v){
		if (depth[u] < depth[v]) swap(u,v);
		u = getPar(u,depth[u]-depth[v]);
		R0F(k,BITS) if (par[k][u] != par[k][v]) 
			u = par[k][u], v = par[k][v];
		return u == v ? u : par[0][u];
	}
	int dist(int u, int v) {
		return depth[u]+depth[v]-2*depth[lca(u,v)];
	}
};

int n;
vi adj[2][MX];
vector<pair<pi,pi>> ans;

sn nex(sn a, int b) {
	if (!a) return a;
	a->prop();
	if (D.sameSet(a->val,b)) {
		sn t = nex(a->c[0],b); 
		return t?t:a;
	} else {
		return nex(a->c[1],b); 
	}
}

sn NEX(sn a) {
	a->access();
	a = a->c[0];
	while (1) {
		a->prop();
		if (a->c[1]) a = a->c[1];
		else return a;
	}
}

pi nextPath(int a, int b) {
	LCT[b]->makeRoot(); LCT[a]->access();
	sn z = nex(LCT[a],a); // ps(z->val); 
	sn Z = NEX(z); Z->access(); // ps(Z->val); exit(0);
	return {z->val,Z->val};
	/*exit(0);
	ps("HA",a,b); exit(0);*/
}

void dfs(int a, int b) {
	// ps("HA",a,b);
	trav(t,adj[0][a]) if (t != b) {
		dfs(t,a);
	}
	if (a > 1) {
		pi z = nextPath(a,b); 
		ans.pb({{a,b},z});
		assert(cut(LCT[z.f],LCT[z.s])); assert(link(LCT[a],LCT[b]));
		D.unite(a,b);
	}
}

LCA<MX> L;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	re(n); 
	FOR(i,1,n+1) LCT[i] = new snode(i);

	D.init(n+1);
	F0R(j,2) F0R(i,n-1) {
		int a,b; re(a,b);
		adj[j][a].pb(b), adj[j][b].pb(a);
		if (j == 1) assert(link(LCT[a],LCT[b]));
		else L.addEdge(a,b);
	}
	// L.init(n);
	// exit(0);
	dfs(1,0);
	ps(sz(ans));
	trav(t,ans) {
		ps(t.f.f,t.f.s,t.s.f,t.s.s);
		// int d = L.dist(t.s.f,t.s.s);
		// assert(d == L.dist(t.s.f,t.f.f)+L.dist(t.f.s,t.s.s)+1 || d == L.dist(t.s.s,t.f.f)+L.dist(t.f.s,t.s.f)+1);
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/