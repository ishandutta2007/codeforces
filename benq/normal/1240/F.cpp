// based off https://codeforces.com/contest/212/problem/A

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
const int MX = 2e5+5;
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


template<int SZ> struct Dinic {
	typedef ll F; // flow type
	struct Edge { int to, rev; F flow, cap; };
	int N,s,t;
	vector<Edge> adj[SZ];
	typename vector<Edge>::iterator cur[SZ];
	void addEdge(int u, int v, F cap) {
		assert(cap >= 0); // don't try smth dumb
		Edge a{v, sz(adj[v]), 0, cap}, b{u, sz(adj[u]), 0, 0};
		adj[u].pb(a), adj[v].pb(b);
	}
	int level[SZ];
	bool bfs() { // level = shortest distance from source
		F0R(i,N) level[i] = -1, cur[i] = begin(adj[i]);
		queue<int> q({s}); level[s] = 0; 
		while (sz(q)) {
			int u = q.front(); q.pop();
			trav(e,adj[u]) if (level[e.to] < 0 && e.flow < e.cap) 
				q.push(e.to), level[e.to] = level[u]+1;
		}
		return level[t] >= 0;
	}
	F sendFlow(int v, F flow) {
		if (v == t) return flow;
		for (; cur[v] != end(adj[v]); cur[v]++) {
			Edge& e = *cur[v];
			if (level[e.to] != level[v]+1 || e.flow == e.cap) 
				continue;
			auto df = sendFlow(e.to,min(flow,e.cap-e.flow));
			if (df) { // saturated at least one edge
				e.flow += df; adj[e.to][e.rev].flow -= df;
				return df;
			}
		}
		return 0;
	}
	F maxFlow(int _N, int _s, int _t) {
		N = _N, s = _s, t = _t; if (s == t) return -1;
		F tot = 0;
		while (bfs()) while (auto df = sendFlow(s,
			numeric_limits<F>::max())) tot += df;
		return tot;
	}
};
 
Dinic<205> D;
int n,m,t;
int tot;
bool adj[201][201];
int ldeg[201], rdeg[201], ans[201][201];
int ret = 0;
vpi ed;
 
void ae(int x, int y, int l, int r, bool flag) {
	if (flag) ret += r-l;
	// ps("OH",x,y,l,r);
	D.addEdge(n+m+1,y,r);
	D.addEdge(y,x,r-l);
	D.addEdge(x,n+m+2,r);
	tot += r;
}

void solve() {
	F0R(i,t) {
		D = Dinic<205>(); tot = 0;
		FOR(a,1,n+1) ldeg[a] = 0;
		FOR(b,1,m+1) rdeg[b] = 0;
		FOR(a,1,n+1) FOR(b,1,m+1) if (adj[a][b]) {
			ldeg[a] ++, rdeg[b] ++;
			D.addEdge(a,n+b,1);
		}
		FOR(a,1,n+1) ae(0,a,ldeg[a]/(t-i),(ldeg[a]+t-i-1)/(t-i), i == 0);
		FOR(b,1,m+1) ae(n+b,0,rdeg[b]/(t-i),(rdeg[b]+t-i-1)/(t-i), i == 0);
		assert(D.maxFlow(n+m+3,n+m+1,n+m+2) == tot);
		FOR(a,1,n+1) trav(t,D.adj[a]) 
			if (n+1 <= t.to && t.to <= n+m && t.flow) {
				adj[a][t.to-n] = 0;
				ans[a][t.to-n] = i+1;
				// ps("HA",a,t.to-n);
			}
		// exit(0);
	}
	// ps(ret);
	trav(t,ed) ps(ans[t.f][t.s]);
	// you should actually read the stuff at the bottom
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0); 
	int z; re(n,z,t); m = n;
	vi w(n); re(w);
	F0R(i,z) {
		int a,b; re(a,b); ed.pb({a,b});
		adj[a][b] = 1;
	}
	solve();
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/