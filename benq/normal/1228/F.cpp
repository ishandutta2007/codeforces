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

template<int SZ> struct TreeDiameter {
	int n; 
	vi adj[SZ];
	void addEdge(int a, int b) { adj[a].pb(b), adj[b].pb(a); }
	int par[SZ], dist[SZ];
	void dfs(int x) {
		trav(y,adj[x]) if (y != par[x]) {
			par[y] = x; dist[y] = dist[x]+1;
			dfs(y);
		}
	}
	void genDist(int x) { par[x] = -1; dist[x] = 0; dfs(x); }
	int diaLen;
	vi center, dia = {1,1}; 
	void init(int _n) {
		n = _n; // find one endpoint of a diameter
		genDist(1); FOR(i,1,n+1) if (dist[i] > dist[dia[0]]) dia[0] = i; 
		genDist(dia[0]); FOR(i,1,n+1) if (dist[i] > dist[dia[1]]) dia[1] = i;
		diaLen = dist[dia[1]];
		int cen = dia[1]; F0R(i,diaLen/2) cen = par[cen];
		if (diaLen&1) center = {cen,par[cen]};
		else center = {cen};
	}
};

TreeDiameter<MX> T;
int n, dist[MX], par[MX];
set<int> ans, leafDist[MX];

void dfs(int a) {
	dist[a] = 0;
	trav(t,T.adj[a]) if (t != par[a]) {
		par[t] = a; dfs(t);
		ckmax(dist[a],dist[t]+1);
	}
}

bool check(int t, int b, int dis) {
	if (dis == 0) return sz(T.adj[t]) == 1;
	if (t != b) {
		int child = 0;
		trav(c,T.adj[t]) if (c != par[t]) {
			child ++;
			if (!check(c,b,dis-1)) return 0;
		}
		if (child != 2) return 0;
	} else {
		vpi v;
		trav(c,T.adj[t]) if (c != par[t]) {
			v.pb({dist[c],c});
		}
		sort(all(v));
		if (dis > 1) {
			return sz(v) == 3 && check(v[0].s,b,dis-2) 
			&& check(v[1].s,b,dis-2)
			&& check(v[2].s,b,dis-1);
		} else {
			return sz(v) == 1 && check(v[0].s,b,dis-1);
		}
	}
	return 1;
}

void test(int t) {
	vi bad;
	FOR(i,1,(1<<n)-1) {
		if (i == t) {
			if (sz(T.adj[i]) != 2) bad.pb(i);
		} else {
			// ps("HUH",i,sz(T.adj[i]));
			if (sz(T.adj[i]) != 3 && sz(T.adj[i]) != 1) bad.pb(i);
		}
	}
	// ps("HA",t,bad);
	if (sz(bad) != 1) return;
	par[t] = 0; dfs(t);
	if (check(t,bad[0],n-1)) ans.insert(bad[0]);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0); 
	re(n);
	F0R(i,(1<<n)-3) {
		int a,b; re(a,b);
		T.addEdge(a,b);
	}
	T.init((1<<n)-2);
	trav(t,T.center) test(t);
	ps(sz(ans));
	trav(t,ans) pr(t,' ');
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/