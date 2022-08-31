#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 

typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl;
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define rsz resize
#define ins insert 

#define mp make_pair
#define pb push_back
#define eb emplace_back 
#define f first
#define s second
#define lb lower_bound 
#define ub upper_bound 

const int MOD = 1e9+7; // 998244353; // = (119<<23)+1
const int MX = 1e5+5;
const ll INF = 1e18; 
const ld PI = 4*atan((ld)1); 

template<class T> bool ckmin(T& a, const T& b) { 
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

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
		cin.sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

typedef decay<decltype(MOD)>::type T;
struct mi {
	T val; 
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(const ll& v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	// friend ostream& operator<<(ostream& os, const mi& a) { 
		// return os << a.val; }
	friend void pr(const mi& a) { pr(a.val); }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }
   
	friend bool operator==(const mi& a, const mi& b) { 
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.val < b.val; }

	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) { 
		if ((val += m.val) >= MOD) val -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((val -= m.val) < 0) val += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		val = (ll)val*m.val%MOD; return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { 
		assert(a != 0); return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};

typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

pmi stor[MX];
vpmi STOR[MX];

template<int SZ> struct CD {
	vi adj[SZ];
	bool done[SZ]; 
	int sub[SZ], par[SZ]; // subtree size, current par
	pi cen[SZ]; // immediate centroid anc
	vi dist[SZ]; // dists to all centroid ancs
	void addEdge(int a, int b) { adj[a].pb(b), adj[b].pb(a); }
	void dfs(int x) {
		sub[x] = 1;
		trav(y,adj[x]) if (!done[y] && y != par[x]) {
			par[y] = x; dfs(y);
			sub[x] += sub[y];
		}
	}
	int centroid(int x) {
		par[x] = -1; dfs(x); 
		for (int sz = sub[x];;) {
			pi mx = {0,0};
			trav(y,adj[x]) if (!done[y] && y != par[x]) 
				ckmax(mx,{sub[y],y});
			if (mx.f*2 <= sz) return x; 
			x = mx.s;
		}
	}
	void genDist(int x, int p) {
		dist[x].pb(dist[p].back()+1);
		trav(y,adj[x]) if (!done[y] && y != p) genDist(y,x); 
	}
	void gen(pi CEN, int x) {
		done[x = centroid(x)] = 1; cen[x] = CEN; 
		dist[x].pb(0); int co = 0;
		trav(y,adj[x]) if (!done[y]) genDist(y,x);
		trav(y,adj[x]) if (!done[y]) gen({x,co++},y);
		STOR[x].rsz(co);
		// F0R(i,co) STOR[x].pb(pmi());
	}
	void init() { gen({-1,0},1); }
};

CD<MX> C;
int n,l[MX],r[MX];
mi ans[MX];
vi adj[MX];

// # common / length of interval 
// # common / length of interval (* dist)
// you should actually read the stuff at the bottom

void ad(int a, int b, int st, mi r) {
	stor[a].f += r; stor[a].s -= st*r;
	// return;
	if (a <= 0 || b < -1 || b >= sz(STOR[a])) {
		ps("??",a,b,sz(STOR[a]));
		exit(0);
	}
	//ps("UHOH",a,b,sz(STOR[a]));
	//return;
	if (b != -1) {
		// ps("HA",a,b,sz(STOR[a]),r); return;
		STOR[a][b].f += r; 
		STOR[a][b].s -= st*r;
	}
}

mi overlap(int a, int b, int st) {
	mi res = stor[a].f*st+stor[a].s;
	/*if (b >= sz(STOR[a])) {
		ps("??",a,b,sz(STOR[a]));
		exit(0);
	}*/
	if (b != -1) res -= STOR[a][b].f*st+STOR[a][b].s;
	return res;
}

void upd(int a, int b, int c) {
	int len = r[b]-l[b]+1;
	pi cur = {b,-1};
	mi AD = -(mi)c/len;
	R0F(i,sz(C.dist[b])) {
		/*if (cur.f <= 0) {
			ps("??",b,i,cur);
			exit(0);
		}*/
		mi x = overlap(cur.f,cur.s,a);
		ans[b] += x*c*C.dist[b][i];
		ad(cur.f,cur.s,a,AD);
		// ps("WUT",i,cur,C.cen[cur.f]); exit(0);
		if (i) cur = C.cen[cur.f];
	}	
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0); re(n);
	vector<array<int,3>> todo;
	FOR(i,1,n+1) {
		re(l[i],r[i]);
		todo.pb({l[i]-1,i,-1});
		todo.pb({r[i],i,1});
	}
	sort(all(todo));
	F0R(i,n-1) {
		int u,v; re(u,v);
		C.addEdge(u,v);
	}
	C.init();
	// ps("HA",todo);
	trav(t,todo) upd(t[0],t[1],t[2]);
	mi ret = 0;
	FOR(i,1,n+1) {
		ans[i] /= r[i]-l[i]+1;
		ret += ans[i];
	}
	FOR(i,1,n+1) ret *= r[i]-l[i]+1;
	ps(ret);
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/