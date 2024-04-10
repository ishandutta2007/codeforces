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
		int d = level(r-l+1);
		return comb(jmp[d][l],jmp[d][r-(1<<d)+1]); }
	T query(int l, int r) { return v[index(l,r)]; }
};

/**
 * Description: Euler Tour LCA w/ O(1) query. Compress takes a subset $S$ 
 	* of nodes and computes the minimal subtree that contains all the nodes 
	* pairwise LCA's and compressing edges. Returns a list of (par, orig\_index) 
	* representing a tree rooted at 0. The root points to itself.
 * Source: USACO, Simon Lindholm (KACTL)
 * Verification: USACO Debug the Bugs
 	* https://codeforces.com/contest/1320/problem/E
 */

template<int SZ> struct LCA {
	int N, R = 1, depth[SZ], st[SZ], par[SZ][18];
	vi adj[SZ]; vpi tmp; RMQ<pi> r;
	void ae(int u, int v) { adj[u].pb(v), adj[v].pb(u); }
	int getPar(int a, int b) {
		R0F(i,18) if (b&(1<<i)) a = par[a][i];
		return a;
	}
	int getLast(int a, int b) {
		int t = getPar(a,depth[a]-depth[b]-1); assert(par[t][0] == b);
		return t;
	}
	void dfs(int u, int prev){
		st[u] = sz(tmp), depth[u] = depth[prev]+1;
		par[u][0] = prev;
		FOR(i,1,18) par[u][i] = par[par[u][i-1]][i-1];
		tmp.pb({depth[u],u});
		trav(v,adj[u]) if (v != prev) 
			dfs(v,u), tmp.pb({depth[u],u});
	}
	void init(int _N) { N = _N; dfs(R,0); r.init(tmp); }
	int lca(int u, int v){
		u = st[u], v = st[v]; if (u > v) swap(u,v);
		return r.query(u,v).s; }
	int common(int u, int v) {
		if (u > v) swap(u,v);
		return r.query(u,v).f; }
	/// int dist(int u, int v) {
		/// return depth[u]+depth[v]-2*depth[lca(u,v)]; }
	vpi compress(vi S) {
		static vi rev; rev.rsz(N+1);
		auto cmp = [&](int a, int b) { return st[a] < st[b]; };
		sort(all(S),cmp);
		int m = sz(S)-1; F0R(i,m) S.pb(lca(S[i],S[i+1]));
		sort(all(S),cmp); S.erase(unique(all(S)),end(S));
		F0R(i,sz(S)) rev[S[i]] = i;
		vpi ret = {pi(0,S[0])};
		F0R(i,sz(S)-1) ret.eb(rev[lca(S[i],S[i+1])],S[i+1]);
		return ret;
	}
};

/**
 * Description: A set (not multiset!) with support for finding the $n$'th
 * element, and finding the index of an element. Change \texttt{null\_type} for map.
 * Time: O(\log N)
 * Source: KACTL
 * Verification: many
 */

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order

/*void treeExample() {
	Tree<int> t, t2; t.insert(8);
	auto it = t.insert(10).f; assert(it == t.lb(9));
	assert(t.ook(10) == 1 && t.ook(11) == 2 && *t.fbo(0) == 8);
	t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}*/

LCA<MX> L;
int n,m,k,ad[MX];
ll ans;
vpi path;
map<pi,vpi> todo[MX];

ll c2(ll x) { return x*(x-1)/2; }
int getFst(int x, int d) {
	int lo = 0, hi = x+1;
	while (lo < hi) {
		int mid = (lo+hi)/2;
		if (L.common(mid,x) >= d) hi = mid;
		else lo = mid+1;
	}
	return lo;
}
int getLst(int x, int d) {
	int lo = x-1, hi = sz(L.tmp)-1;
	while (lo < hi) {
		int mid = (lo+hi+1)/2;
		if (L.common(x,mid) >= d) lo = mid;
		else hi = mid-1;
	}
	return lo;
}

struct dat {
	int curd = 0, dumb = 0;
	Tree<pi>* M = new Tree<pi>(); ll csum = 0;
	priority_queue<pi,vpi,greater<pi>> todo;
	dat() {}
	dat(int a) { curd = L.depth[a]; }
	pi getBound(int x) { return {getFst(x,curd),getLst(x,curd)}; }
	int range(int l, int r) { 
		if (l > r) return 0; 
		return M->ook({r,MOD})-M->ook({l,-MOD}); 
	}
	void deal(pi x, pi y) {
		int wut = L.common(x.f,y.f); if (wut < curd) return;
		todo.push({wut,x.f}); todo.push({wut,y.f});
	}
	void ins(int x) {
		// dbg("INSERTING",x);
		pi p = getBound(x); csum += range(p.f,p.s);
		auto it = M->insert({x,dumb}).f;
		if (it != M->begin()) deal(*prev(it),*it);
		if (next(it) != M->end()) deal(*it,*next(it));
		dumb ++;
	}
	ll get(vi v) {
		ll ret = 0; vpi wut;
		trav(t,v) {
			if (sz(wut) && t <= wut.bk.s) continue;
			wut.pb(getBound(t));
		}
		trav(t,wut) ret += c2(range(t.f,t.s));
		return ret;
	}
	void boundary() {
		vi v;
		while (sz(todo) && curd == todo.top().f) {
			v.pb(todo.top().s); todo.pop(); }
		csum -= get(v); curd ++; csum += get(v);
	}
	void upto(int a, int d) {
		// dbg("ORI",d);
		d ++; d = k-d+2*L.depth[a];
		//dbg("UPTO",curd,a,d);
		//trav(t,*M) dbg(t.f,L.tmp[t.f]);
		//dbg(L.tmp);
		//trav(t,M) dbg(t);
		while (curd < d) { // those with LCP x change from x -> x+1
			int nex = d+1; if (sz(todo)) ckmin(nex,todo.top().f+1);
			// [curd+1,nex-1]
			//dbg("TRAN",curd,nex-1);
			ans += (nex-1-curd)*csum; curd = nex-1;
			if (curd < d) {
				boundary();
				ans += csum;
			}
		}
		//dbg("COOL",csum);
	}
};

dat cur[MX];

void merge(dat& l, dat& r) {
	if (l.M->size() < r.M->size()) swap(l,r);
	assert(l.curd == r.curd);
	trav(t,*r.M) l.ins(t.f);
}

void dumb(int x, int y) {
	int dif = L.depth[x]-L.depth[y]-k; 
	if (dif < 0) return;
	ad[x] ++; ad[L.getPar(x,dif+1)] --;
}

void divi(int d, int a, const vpi& v, int l, int r) {
	assert(l <= r);
	if (l == r) { cur[l] = dat(a); cur[l].ins(v[l].s); }
	else {
		int D = L.common(v[l].f,v[r].f); // common depth
		int lo = l+1, hi = r;
		while (lo < hi) {
			int mid = (lo+hi)/2;
			if (L.common(v[l].f,v[mid].f) == D) hi = mid;
			else lo = mid+1;
		}
		int m = lo;
		assert(L.common(v[m-1].f,v[m].f) == D);
		divi(D,a,v,l,m-1); divi(D,a,v,m,r);
		merge(cur[l],cur[m]);
	}
	cur[l].upto(a,d);
}

void deal(int a, vpi v) {
	ll pre = ans;
	sort(all(v));
	divi(L.depth[a],a,v,0,sz(v)-1);
	dbg(L.tmp);
	dbg("HUH",a,v,ans-pre);
}

void dfs(int a, int b) {
	trav(t,todo[a]) deal(a,t.s);
	trav(t,L.adj[a]) if (t != b) { dfs(t,a); ad[a] += ad[t]; }
	ans += c2(ad[a]);
}

ll solve() {
	ans = 0; FOR(i,1,n+1) ad[i] = 0, todo[i].clear();
	trav(t,path) {
		int x = L.lca(t.f,t.s); dumb(t.f,x), dumb(t.s,x);
		dbg(t.f,t.s,x);
		if (t.f != x && t.s != x && k > 1) {
			int a = L.getLast(t.f,x), b = L.getLast(t.s,x);
			assert(a != b);
			if (a > b) swap(a,b), swap(t.f,t.s);
			todo[x][{a,b}].pb({L.st[t.f],L.st[t.s]});
		}
	}
	dfs(1,0);
	return ans;
}

int main() { // OK
	setIO();
	re(n,m,k);
	vi u,v,s,t;
	u.rsz(n-1); v.rsz(n-1); 
	F0R(i,n-1) {
		re(u[i],v[i]);
		L.ae(u[i],v[i]);
	}
	L.init(n);
	s.rsz(m); t.rsz(m); 
	F0R(i,m) {
		re(s[i],t[i]);
		path.pb({s[i],t[i]});
	}
	ll a = solve(); dbg(a);
	k ++;
	ll b = solve(); dbg(b);
	ps(a-b);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/