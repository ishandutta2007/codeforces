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

struct LCArmq {
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
};

LCArmq lcarmq;

/**
 * Description: Calculates least common ancestor in tree with verts 
 	* $0\ldots N-1$ and root $R$ using binary jumping. 
 * Time: O(N\log N) build, O(\log N) query
 * Memory: O(N\log N)
 * Source: USACO Camp, KACTL
 * Verification: *
 */

struct LCAjmp {
	int N; vector<vi> par, adj; vi depth;
	void init(int _N) {  N = _N;
		int d = 1; while ((1<<d) < N) d ++;
		par.assign(d,vi(N)); adj.rsz(N); depth.rsz(N);
	}
	void ae(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
	void gen(int R = 0) { par[0][R] = R; dfs(R); }
	void dfs(int x = 0) {
		FOR(i,1,sz(par)) par[i][x] = par[i-1][par[i-1][x]];
		trav(y,adj[x]) if (y != par[0][x]) 
			depth[y] = depth[par[0][y]=x]+1, dfs(y);
	}
	int jmp(int x, int d) {
		F0R(i,sz(par)) if ((d>>i)&1) x = par[i][x];
		return x; }
	int lca(int x, int y) {
		if (depth[x] < depth[y]) swap(x,y);
		x = jmp(x,depth[x]-depth[y]); if (x == y) return x;
		R0F(i,sz(par)) {
			int X = par[i][x], Y = par[i][y];
			if (X != Y) x = X, y = Y;
		}
		return par[0][x];
	}
	int dist(int x, int y) { // # edges on path
		return depth[x]+depth[y]-2*depth[lca(x,y)]; }
	int get_midpoint(int x, int y) {
		int d = lcarmq.dist(x,y);
		if (depth[x] < depth[y]) swap(x,y);
		return jmp(x,d);
	}
};

LCAjmp lcajmp;

pl& operator+=(pl& a, const pl& b) { return a = {a.f+b.f,a.s+b.s}; }
// pl& operator-=(pl& a, const pl& b) { return a = {a.f+b.f,a.s+b.s}; }

/**
 * Description: The centroid of a tree of size $N$ is a vertex such that 
 	* after removing it, all resulting subtrees have size at most $\frac{N}{2}.$ 
 	* Supports updates in the form ``add 1 to all verts $v$ such that $dist(x,v)\le y$."
 * Time: O(N\log N) build, O(\log N) update and query
 * Memory: O(N\log N)
 * Source: own
 * Verification: 
	* solves https://dmoj.ca/problem/dmopc19c7p6
	* https://codeforces.com/contest/342/problem/E
	* Triway Cup 2019 G
 */

template<int SZ> struct Centroid {
	vi adj[SZ]; void ae(int a,int b){adj[a].pb(b),adj[b].pb(a);}
	bool done[SZ]; // processed as centroid yet
	int N,sub[SZ],cen[SZ],lev[SZ]; // subtree size, centroid anc
	int dist[32-__builtin_clz(SZ)][SZ]; // dists to all ancs
	pl stor[SZ], STOR[SZ];
	void dfs(int x, int p) { sub[x] = 1; 
		trav(y,adj[x]) if (!done[y] && y != p) 
			dfs(y,x), sub[x] += sub[y]; 
	}
	int centroid(int x) {
		dfs(x,-1); 
		for (int sz = sub[x];;) {
			pi mx = {0,0};
			trav(y,adj[x]) if (!done[y] && sub[y] < sub[x]) 
				ckmax(mx,{sub[y],y});
			if (mx.f*2 <= sz) return x; 
			x = mx.s;
		}
	}
	void genDist(int x, int p, int lev) {
		dist[lev][x] = dist[lev][p]+1;
		trav(y,adj[x]) if (!done[y] && y != p) genDist(y,x,lev); }
	void gen(int CEN, int _x) { // CEN = centroid above x
		int x = centroid(_x); done[x] = 1; cen[x] = CEN; 
		sub[x] = sub[_x]; lev[x] = (CEN == -1 ? 0 : lev[CEN]+1);
		dist[lev[x]][x] = 0; 
		trav(y,adj[x]) if (!done[y]) genDist(y,x,lev[x]);
		trav(y,adj[x]) if (!done[y]) gen(x,y);
	}
	void init(int _N) { 
		// dbg("**INIT CEN",_N);
		N = _N; FOR(i,1,N+1) done[i] = 0;
		gen(-1,1); } // start at vert 1
	void upd(int x, ll y) {
		// dbg("**UPD CEN",x,y);
		int cur = x, pre = -1;
		R0F(i,lev[x]+1) {
			stor[cur] += mp(y*dist[i][x],y); 
			if (pre != -1) STOR[pre] += mp(y*dist[i][x],y);
			if (i > 0) pre = cur, cur = cen[cur];
		}
	} // call propAll() after all updates
	ll query(int x) { // get value at vertex x
		// dbg("**QUERY CEN",x);
		int cur = x, pre = -1;
		ll ans = 0;
		R0F(i,lev[x]+1) { // if pre != -1, subtract those from
			ans += stor[cur].f+stor[cur].s*dist[i][x]; // same subtree
			if (pre != -1) ans -= STOR[pre].f+STOR[pre].s*dist[i][x];
			if (i > 0) pre = cur, cur = cen[cur];
		}
		// dbg("**QUERY CEN END",x,ans);
		return ans;
	}
};

Centroid<MX> cd;
int N;
ll ans;

int val(pi p) {
	assert(1 <= p.f && p.f <= N);
	assert(1 <= p.s && p.s <= N);
	int dist = lcarmq.dist(p.f-1,p.s-1);
	return dist;
}

int val(pi a, pi b) {
	AR<int,4> tmp{a.f,a.s,b.f,b.s};
	int res = 0; F0R(i,4) FOR(j,i+1,4) ckmax(res,val({tmp[i],tmp[j]}));
	return res;
}

int val_one(pi a, pi b) {
	AR<int,4> tmp{a.f,a.s,b.f,b.s};
	int res = 0; 
	F0R(i,4) FOR(j,i+1,4) {
		if (i == 2 && j == 3) continue;
		ckmax(res,val({tmp[i],tmp[j]}));
	}
	return res;
}

int get_midpoint(int a, int b) { return lcajmp.get_midpoint(a-1,b-1)+1; }

pi extend(pi a, int b) {
	pi bes = a;
	{
		pi tmp = {a.f,b};
		if (val(tmp) > val(bes)) bes = tmp;
	}
	{
		pi tmp = {a.s,b};
		if (val(tmp) > val(bes)) bes = tmp;
	}
	return bes;
}

void divi(int L, int R) {
	if (L == R) return;
	int M = (L+R)/2;
	divi(L,M), divi(M+1,R);
	vpi dia_left, dia_right;
	vl cum_val{0};
	FOR(i,M+1,R+1) {
		if (i == M+1) dia_right.pb({i,i});
		else dia_right.pb(extend(dia_right.bk,i));
		cum_val.pb(cum_val.bk+val(dia_right.bk));
	}
	dbg("DOING",L,R);
	// [L,M], [M+1,R]
	// M+1-L, R-M
	// dia_right has indices 0 to R-M-1
	V<V<pair<pi,int>>> query(R-M+1);
	int lst_2 = M, lst_1 = M;
	ROF(i,L,M+1) {
		if (i == M) dia_left.pb({i,i});
		else dia_left.pb(extend(dia_left.bk,i));
		while (lst_2+1 <= R && val(dia_left.bk) == val(dia_left.bk,dia_right[lst_2-M])) {
			++lst_2;
		} // two is equal to to answer
		while (lst_1+1 <= R && val_one(dia_left.bk,dia_right[lst_1-M]) == val(dia_left.bk,dia_right[lst_1-M])) {
			++lst_1;
		}
		// dbg("HUH",i,lst_1,lst_2);
		assert(lst_1 >= lst_2);
		ans += ll(lst_2-M)*val(dia_left.bk);
		dbg(i,lst_1,lst_2);
		// dbg("AA",ans);
		ans += cum_val[R-M]-cum_val[lst_1-M];
		// dbg("BB",ans);
		if (lst_1 > lst_2) {
			query[lst_1-M].pb({dia_left.bk,1});
			query[lst_2-M].pb({dia_left.bk,-1});
		}
	}
	dbg("WUT");
	ll sum_dist = 0;
	vi verts;
	auto upd_cen = [&](pi p) {
		// dbg("UPD CEN",p,get_midpoint(p.f,p.s));
		sum_dist += val(p);
		verts.pb(get_midpoint(p.f,p.s));
		cd.upd(verts.bk,1);
	};
	auto cen_ans = [&](pi p) {
		// dbg("CEN ANS",p,get_midpoint(p.f,p.s));
		int m = get_midpoint(p.f,p.s);
		// dbg("??",cd.query(m));
		// dbg("")
		ll tmp = sum_dist+(ll)sz(verts)*val(p)+cd.query(m);
		assert(tmp%2 == 0);
		return tmp/2;
	};
	FOR(i,M+1,R+1) {
		upd_cen(dia_right[i-M-1]);
		trav(t,query[i-M]) {
			dbg("QUERYING",t);
			ans += t.s*cen_ans(t.f);
		}
	}
	trav(t,verts) cd.upd(t,-1);
	dbg("END",L,R,ans);
}

int main() {
	setIO(); re(N);
	lcarmq.init(N);
	lcajmp.init(2*N-1);
	int cnt = N;
	F0R(i,N-1) { // N+(N-1)
		int u,v; re(u,v);
		lcarmq.ae(u-1,v-1);
		lcajmp.ae(u-1,cnt); lcajmp.ae(cnt,v-1);
		cd.ae(u,1+cnt), cd.ae(1+cnt,v); 
		++cnt;
	}
	cd.init(2*N-1);
	lcarmq.gen();
	lcajmp.gen();
	divi(1,N);
	ps(ans);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/