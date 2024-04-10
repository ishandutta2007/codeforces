#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
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
#define rtn return

#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 3e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937_64 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
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
void re(double& d) { str t; re(t); d = stod(t); }
void re(long double& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
tcT> void re(V<T>& x) { each(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { each(a,x) re(a); }
tcT> void rv(int n, V<T>& x) { x.rsz(n); re(x); }

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	// #ifdef LOCAL
	// 	return b ? "true" : "false"; 
	// #else 
	return ts((int)b);
	// #endif
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

#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);

using ul = unsigned long long;

ul hsh[MX];

/**
 * Description: Persistent min segtree with lazy updates, no propagation.
 	* If making \texttt{d} a vector then save the results of
 	* \texttt{upd} and \texttt{build} in local variables first to
 	* avoid issues when vector resizes in C++14 or lower.
 * Memory: O(N+Q\log N)
 * Source: CF, Franklyn Wang
 * Verification: 
 	* https://codeforces.com/contest/1090/problem/G
 	* https://codeforces.com/gym/102423/submission/70170291
 */ 

template<class T, int SZ> struct pseg {
	static const int LIM = 2e7;
	struct node { 
		int l, r; T val = 0;
		T get() { return val; }
	};
	node d[LIM]; int nex = 0;
	int copy(int c) { d[nex] = d[c]; return nex++; }
	T comb(T a, T b) { return a^b; }
	void pull(int c) { d[c].val = 
		comb(d[d[c].l].get(), d[d[c].r].get()); } 
	//// MAIN FUNCTIONS
	T query(int c, int lo, int hi, int L, int R) {  
		if (lo <= L && R <= hi) return d[c].get();
		if (R < lo || hi < L) return MOD;
		int M = (L+R)/2;
		return comb(query(d[c].l,lo,hi,L,M),
							query(d[c].r,lo,hi,M+1,R));
	}
	int upd(int c, int pos, T v, int L, int R) {
		if (R < pos || pos < L) return c;
		int x = copy(c);
		if (pos <= L && R <= pos) { d[x].val ^= v; return x; }
		int M = (L+R)/2;
		d[x].l = upd(d[x].l,pos,v,L,M);
		d[x].r = upd(d[x].r,pos,v,M+1,R);
		pull(x); return x;
	}
	int build(const vector<T>& arr, int L, int R) {
		int c = nex++;
		if (L == R) {
			if (L < sz(arr)) d[c].val = arr[L];
			return c;
		}
		int M = (L+R)/2;
		d[c].l = build(arr,L,M), d[c].r = build(arr,M+1,R);
		pull(c); return c;
	}
	vi loc; //// PUBLIC
	int upd(int c, int pos, T v) { 
		return upd(c,pos,v,0,SZ-1); 
	}
	T query(int ti, int lo, int hi) { 
		return query(loc[ti],lo,hi,0,SZ-1); }
	int build(const vector<T>&arr) {
		return build(arr,0,SZ-1);
	}
	int get_ans(int a, int b, int lo, int hi, int L = 0, int R = SZ-1) {
		if (R < lo || hi < L) return -1;
		if (lo <= L && R <= hi) {
			if (d[a].val == d[b].val) return -1;
			if (L == R) return L;
		}
		int M = (L+R)/2;
		int ans = get_ans(d[a].l,d[b].l,lo,hi,L,M); 
		if (ans != -1) return ans;
		ans = get_ans(d[a].r,d[b].r,lo,hi,M+1,R); 
		return ans;
	}

};

pseg<ul,MX> PS;
vi adj[MX];

/**
 * Description: Calculates least common ancestor in tree with verts 
 	* $0\ldots N-1$ and root $R$ using binary jumping. 
 * Time: O(N\log N) build, O(\log N) query
 * Memory: O(N\log N)
 * Source: USACO Camp, KACTL
 * Verification: *
 */

struct LCA {
	int N; vector<vi> par; vi depth;
	void init(int _N) {  N = _N;
		int d = 1; while ((1<<d) < N) d ++;
		par.assign(d,vi(N)); depth.rsz(N);
	}
	void ae(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
	void gen(int R = 0) { par[0][R] = R; dfs(R); }
	void dfs(int x = 0) {
		FOR(i,1,sz(par)) par[i][x] = par[i-1][par[i-1][x]];
		each(y,adj[x]) if (y != par[0][x]) 
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
};

LCA L;

int N,Q;
int A[MX], stor[MX];

void dfs(int x, int y, int root) {
	stor[x] = root;
	each(t,adj[x]) if (t != y) {
		dfs(t,x,PS.upd(root,A[t],hsh[A[t]]));
	}
}

int main() {
	setIO(); 
	re(N,Q);
	F0R(i,N) re(A[i]);
	FOR(i,1,N+1) hsh[i] = rng();
	L.init(N);
	rep(N-1) {
		int x,y; re(x,y); --x,--y;
		L.ae(x,y);
	}
	L.gen();
	// dbg(L.lca(3,1));

	V<ul> arr;
	int root = PS.build(arr);
	dfs(0,-1,root);

	rep(Q) {
		int u,v,l,r; re(u,v,l,r); --u,--v;
		int w = L.lca(u,v);
		int c = A[w];
		if (l <= c && c <= r) {
			if (PS.get_ans(stor[u],stor[v],c,c) == -1) {
				dbg("GOT",c);
				ps(c);
				continue;
			}
			dbg("OTHER");
			int ans = PS.get_ans(stor[u],stor[v],l,c-1);
			if (ans != -1) {
				ps(ans);
				continue;
			}
			ans = PS.get_ans(stor[u],stor[v],c+1,r);
			if (ans != -1) {
				ps(ans);
				continue;
			}
			ps(-1);
			continue;
		}
		int ans = PS.get_ans(stor[u],stor[v],l,r);
		ps(ans);
		// if 
		// int m = A[];
	}
	// ps(rng());
	// ps(rng());
	// ps(rng());
	// ps(rng());
	// exit(0);
	
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/