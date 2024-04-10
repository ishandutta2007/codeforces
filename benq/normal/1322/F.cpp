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
const int MX = 5e5+5; 
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
 * Description: Disjoint Set Union with path compression. 
 	* Add edges and test connectivity. Use for Kruskal's 
 	* minimum spanning tree.
 * Time: O(\alpha(N))
 * Source: CSAcademy, KACTL
 * Verification: USACO superbull
 */

struct DSU {
	vpi par;
	void init(int n) { 
		par.rsz(n);
		F0R(i,n) par[i] = {i,0}; 
	}
	pi get(int x) { 
		if (par[x].f == x) return par[x];
		pi p = get(par[x].f); p.s ^= par[x].s;
		return par[x] = p;
	}
	void unite(int x, int y, int z) { // union-by-rank
		pi X = get(x), Y = get(y);
		// ps("UNITE",x,y,z);
		if (X.f == Y.f) {
			if ((X.s^Y.s) != z) {
				ps(-1);
				exit(0);
			}
		} else {
			par[Y.f] = {X.f,X.s^Y.s^z};
		}
	}
};

/**
 * Description: Calculates least common ancestor in tree 
 	* with root $R$ using binary jumping. 
 * Time: O(N\log N) build, O(\log N) query
 * Source: USACO Camp
 * Verification: Debug the Bugs
 */

template<int SZ> struct LCA {
	static const int BITS = 32-__builtin_clz(SZ);
	int N, R = 1, par[BITS][SZ], depth[SZ];
	vi adj[SZ]; 
	/// INITIALIZE
	void ae(int u, int v) { adj[u].pb(v), adj[v].pb(u); }
	void dfs(int u, int prev){
		par[0][u] = prev; depth[u] = depth[prev]+1;
		trav(v,adj[u]) if (v != prev) dfs(v, u);
	}
	void init(int _N) {
		N = _N; dfs(R,0);
		FOR(k,1,BITS) FOR(i,1,N+1) 
			par[k][i] = par[k-1][par[k-1][i]];
	}
	/// QUERY
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
int n,m, mn[MX], c[MX], mid;
bool bad;

DSU D;
bool par[MX], tmpPar[MX];
pi stor[MX];

bool fin;

void dfs(int x) {
	trav(t,L.adj[x]) if (t != L.par[0][x]) {
		dfs(t); if (bad) return;
	}
	trav(t,L.adj[x]) if (t != L.par[0][x]) {
		stor[D.get(t).f].f = MOD;
		// ps("OH",x,t,D.get(x).f,D.get(t).f);
	}
	pi p = D.get(x); stor[p.f] = {1,mid};
	vi todo = {p.f};
	trav(t,L.adj[x]) if (t != L.par[0][x]) {
		pi p = D.get(t);
		if (stor[p.f].f == MOD) {
			// ps("WAT",x,p);
			stor[p.f] = {1,mid};
			todo.pb(p.f);
		}
		if (p.s == 0) ckmax(stor[p.f].f,mn[t]+1); // goes up
		else ckmin(stor[p.f].s,mid-mn[t]);
		// ps("AH",stor[p.f]);
	}
	pi P = stor[p.f]; if (p.s) P = {mid+1-P.s,mid+1-P.f};
	pi ban = {MOD,-MOD};
	int LL = P.f, RR = P.s;
	FOR(i,1,sz(todo)) {
		pi z = stor[todo[i]];
		if (z.f > z.s) { bad = 1; return; }
		pi Z = {mid+1-z.s,mid+1-z.f};
		if (z > Z) swap(z,Z);
		ckmax(LL,z.f), ckmin(RR,Z.s);
		if (z.s+1 < Z.f) { ckmin(ban.f,z.s+1), ckmax(ban.s,Z.f-1); }
	}
	if (LL > RR) { bad = 1; return; }
	int val;
	// ps("HAHA",LL,RR,ban);
	if (LL < ban.f) val = LL;
	else if (LL > ban.s) val = LL;
	else if (ban.s < RR) val = ban.s+1;
	else { bad = 1; return; }
	mn[x] = val; tmpPar[p.f] = p.s;
	FOR(i,1,sz(todo)) {
		pi t = stor[todo[i]];
		//ps("OH",t);
		if (t.f <= val && val <= t.s) {
			tmpPar[todo[i]] = 0;
		} else {
			// assert(mid+1-t.s.s <= val && val <= mid+1-t.s.f);
			tmpPar[todo[i]] = 1;
		}
	}
	if (fin) {
		trav(t,L.adj[x]) if (t != L.par[0][x]) {
			pi p = D.get(t);
			par[t] = tmpPar[p.f]^p.s;
			//ps("HAHA",t,par[t]);
		}

	}
}

bool ok() {
	bad = 0; dfs(1);
	return !bad;
}

void genAns(int x) {
	if (par[x] == 0) {
		c[x] = mn[x];
	} else {
		c[x] = mid+1-mn[x];
	}
	trav(t,L.adj[x]) if (t != L.par[0][x]) {
		par[t] ^= par[x];
		genAns(t);
	}
}

int ad[MX];
void path(int a, int b) {
	// ps("OH",a,b);
	int x = L.lca(a,b);
	int A,B;
	if (a != x) {
		A = L.getPar(a,L.depth[a]-L.depth[x]-1);
		ad[a] ++; ad[A] --;
	}
	if (b != x) {
		B = L.getPar(b,L.depth[b]-L.depth[x]-1);
		ad[b] ++; ad[B] --;
	}
	if (a != x && b != x) {
		D.unite(A,B,1);
	}
}

void genAd(int x) {
	trav(t,L.adj[x]) if (t != L.par[0][x]) {
		genAd(t);
		ad[x] += ad[t];
	}
	if (ad[x]) {
		D.unite(x,L.par[0][x],0);
	}
}

/**
 * Description: Fast input and output.
 * Time: input is $\sim$300ms faster for $10^6$ long longs on CF
 * Source: 
 	* https://codeforces.com/gym/102394/submission/64154785
 	* https://codeforces.com/contest/1254/submission/65420506 (neal)
 	* https://codeforces.com/blog/entry/45835 (AI.Cash)
 * Verification: https://codeforces.com/gym/102394/problem/G 
 */

namespace FastIO {
	const int BSZ = 1<<15; ////// INPUT
	char ibuf[BSZ]; int ipos, ilen;
	char nc() { // next char
		if (ipos == ilen) {
			ipos = 0; ilen = fread(ibuf,1,BSZ,stdin);
			if (!ilen) return EOF;
		}
		return ibuf[ipos++];
	}
	void rs(str& x) { // read str
		char ch; while (isspace(ch = nc()));
		do { x += ch; } while (!isspace(ch = nc()) && ch != EOF);
	}
	template<class T> void ri(T& x) { // read int or ll
		char ch; int sgn = 1;
		while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;
		x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');
		x *= sgn;
	}
	template<class T, class... Ts> void ri(T& t, Ts&... ts) { 
		ri(t); ri(ts...); } // read ints
	////// OUTPUT (call initO() at start)
	char obuf[BSZ], numBuf[100]; int opos;
	void flushOut() { fwrite(obuf,1,opos,stdout); opos = 0; }
	void wc(char c) { // write char
		if (opos == BSZ) flushOut();
		obuf[opos++] = c; }
	void ws(str s) { trav(c,s) wc(c); } // write str
	template<class T> void wi(T x, char after = '\0') { /// write int
		if (x < 0) wc('-'), x *= -1;
		int len = 0; for (;x>=10;x/=10) numBuf[len++] = '0'+(x%10);
		wc('0'+x); R0F(i,len) wc(numBuf[i]);
		if (after) wc(after);
	}
	void initO() { assert(atexit(flushOut) == 0); } /// auto-flush output
}
using namespace FastIO;
/// initO(); int a,b; ri(a,b); wi(b,'\n'); wi(a,'\n'); 

void init() {
	initO();
	ri(n,m); D.init(n+1);
	F0R(i,n-1) {
		int a,b; ri(a,b);
		L.ae(a,b);
	}
	L.init(n);
	F0R(i,m) {
		int a,b; ri(a,b);
		path(a,b);
	}
	// FOR(i,1,n+1) ps(i,ad[i]);
	genAd(1);
}

int main() {
	init();
	mid = n; // assert(ok());
	// exit(0);
	int lo = 1, hi = n;
	while (lo < hi) {
		mid = (lo+hi)/2;
		if (ok()) hi = mid;
		else lo = mid+1;
	}
	mid = lo; 
	fin = 1;
	assert(ok());
	ps(mid);
	genAns(1);
	FOR(i,1,n+1) {
		if (i < n) wi(c[i],' ');
		else wi(c[i],'\n');
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/