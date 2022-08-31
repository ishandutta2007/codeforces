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
const int MX = 2e5+5; 
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

template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
template<class T> T poll(pqg<T>& x) {
	T y = x.top(); x.pop(); return y; }

template<int SZ> struct MCMF { 
	typedef ll F; typedef ll C;
	struct Edge { int to, rev; F flow, cap; C cost; 
		pair<int,char> cool;
	};
	vector<Edge> adj[SZ];
	void ae(int u, int v, F cap, C cost, pi cool = {-1,-1}) {
		assert(cap >= 0);
		Edge a{v,sz(adj[v]),0,cap,cost,cool}, b{u,sz(adj[u]),0,0,-cost,{-1,-1}};
		adj[u].pb(a), adj[v].pb(b);
	}
	int N, s, t;
	pi pre[SZ]; // previous vertex, edge label on path
	pair<C,F> cost[SZ]; // tot cost of path, amount of flow
	C totCost, curCost; F totFlow; 
	bool spfa() { // find lowest cost path to send flow through
		F0R(i,N) cost[i] = {numeric_limits<C>::max(),0}; 
		cost[s] = {0,numeric_limits<F>::max()};
		pqg<pair<C,int>> todo; todo.push({0,s});
		while (sz(todo)) {
			auto x = poll(todo); if (x.f > cost[x.s].f) continue;
			trav(a,adj[x.s]) if (a.flow < a.cap 
				&& ckmin(cost[a.to].f,x.f+a.cost)) { 
				// if costs are doubles, add some small constant so
				// you don't traverse some ~0-weight cycle repeatedly
				pre[a.to] = {x.s,a.rev};
				cost[a.to].s = min(a.cap-a.flow,cost[x.s].s);
				todo.push({cost[a.to].f,a.to});
			}
		}
		return cost[t].s;
	}
	void backtrack() {
		F df = cost[t].s; totFlow += df;
		curCost += cost[t].f; totCost += curCost*df;
		for (int x = t; x != s; x = pre[x].f) {
			adj[x][pre[x].s].flow -= df;
			adj[pre[x].f][adj[x][pre[x].s].rev].flow += df;
		}
		F0R(i,N) trav(p,adj[i]) p.cost += cost[i].f-cost[p.to].f;
		// all reduced costs non-negative
		// edges on shortest path become 0
	}
	pair<F,C> calc(int _N, int _s, int _t) {
		N = _N; s = _s, t = _t; totFlow = totCost = curCost = 0;
		while (spfa()) backtrack();
		return {totFlow,totCost};
	}
};

MCMF<500> D;

int n1,n2,m,R,B;
int out[500];
str x, y;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	re(n1,n2,m,R,B,x,y);
	F0R(i,m) {
		int a,b; re(a,b); a--,b--;
		if (x[a] == 'U') {
			if (y[b] == 'U') continue;
			if (y[b] == 'R') D.ae(0,n1+1+b,1,R,{i,'R'});
			if (y[b] == 'B') D.ae(n1+1+b,0,1,B,{i,'B'});
		} else if (x[a] == 'R') {
			if (y[b] == 'U') D.ae(1+a,0,1,R,{i,'R'});
			if (y[b] == 'R') D.ae(1+a,n1+1+b,1,R,{i,'R'});
			if (y[b] == 'B') {
				D.ae(a+1,n1+1+b,1,R,{i,'R'});
				D.ae(n1+1+b,a+1,1,B,{i,'B'});
			}
		} else if (x[a] == 'B') {
			if (y[b] == 'U') D.ae(0,1+a,1,B,{i,'B'});
			if (y[b] == 'B') D.ae(n1+1+b,1+a,1,B,{i,'B'});
			if (y[b] == 'R') {
				D.ae(a+1,n1+1+b,1,R,{i,'R'});
				D.ae(n1+1+b,a+1,1,B,{i,'B'});
			}
		}
	}
	F0R(a,n1) {
		if (x[a] == 'R') {
			out[0] ++, out[1+a] --;
			D.ae(0,1+a,MOD,0);
		} 
		if (x[a] == 'B') {
			out[1+a] ++; out[0] --;
			D.ae(1+a,0,MOD,0);
		}
	}
	F0R(b,n2) {
		if (y[b] == 'R') {
			out[n1+1+b] ++, out[0] --;
			D.ae(n1+1+b,0,MOD,0);
		} 
		if (y[b] == 'B') {
			out[0] ++, out[n1+1+b] --;
			D.ae(0,n1+1+b,MOD,0);
		}
	}
	int src = n1+n2+1, snk = n1+n2+2;
	int cnt = 0;
	F0R(i,n1+n2+1) {
		if (out[i] > 0) {
			D.ae(i,snk,out[i],0);
			cnt += out[i];
		} 
		if (out[i] < 0) {
			D.ae(src,i,-out[i],0);
		}
	}
	auto a = D.calc(snk+1,src,snk);
	if (a.f != cnt) {
		ps(-1);
		exit(0);
	}
	str res(m,'U');
	F0R(i,snk+1) trav(t,D.adj[i]) if (t.flow && t.cool.f != -1)
		res[t.cool.f] = t.cool.s;
	ps(a.s);
	ps(res);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/