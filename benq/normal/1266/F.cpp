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
const int MX = 5e5+5;
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

int n,par[MX],ans[MX],down[MX],up[MX];
vi adj[MX];

void dfs(int a) {
	trav(t,adj[a]) if (t != par[a]) {
		par[t] = a; dfs(t);
		ckmax(down[a],down[t]+1);
	}
}

void dfs2(int x) {
	vi child;
	trav(t,adj[x]) if (t != par[x]) child.pb(t);
	vi pre(sz(child)), suf(sz(child));
	int cur = 0;
	F0R(i,sz(child)) {
		int c = child[i];
		pre[i] = cur; ckmax(cur,down[c]+1);
	}
	cur = 0;
	R0F(i,sz(child)) {
		int c = child[i];
		suf[i] = cur; ckmax(cur,down[c]+1);
	}
	F0R(i,sz(child)) {
		int c = child[i];
		up[c] = max(up[x],max(suf[i],pre[i]))+1;
	}
	trav(t,child) dfs2(t);
}


template <class T, int ...Ns> struct BIT {
	T val = 0;
	void upd(T v) { val += v; }
	T query() { return val; }
};
template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
	BIT<T,Ns...> bit[N+1];
	template<typename... Args> void upd(int pos, Args... args) {
		for (; pos <= N; pos += (pos&-pos)) bit[pos].upd(args...);
	}
	template<typename... Args> T sum(int r, Args... args) {
		T res = 0; for (; r; r -= (r&-r)) 
			res += bit[r].query(args...); 
		return res;
	}
	template<typename... Args> T query(int l, int r, Args... 
		args) { return sum(r,args...)-sum(l-1,args...); }
}; 

BIT<int,MX> B;

bool done[MX];
int cnt[MX];

pi get(int x) {
	return {cnt[x],x};
}

int PAR[MX];
vi todo[MX];

void process(int x) {
	vpi ori;
	vector<pair<pi,vi>> v;
	int co = 0;
	trav(t,adj[x]) {
		cnt[t] = PAR[t] = 0;
		if (t == par[x]) ori.pb({up[x],t});
		else ori.pb({down[t]+1,t});
	}
	trav(t,adj[x]) if (!done[t]) {
		v.eb();
		v.back().f = {t,(t == par[x] ? up[x] : down[t]+1)};
		trav(T,adj[t]) if (T != x) {
			if (T == par[t]) v.back().s.pb(up[t]);
			else v.back().s.pb(down[T]+1);
		}
	}
	trav(t,ori) B.upd(t.f,1);
	vpi ev;
	trav(t,v) {
		B.upd(t.f.s,-1);
		sort(all(t.s));
		F0R(i,sz(t.s)) {
			int x = t.s[i];
			ckmax(ans[2*x],sz(t.s)-i+B.query(x,n));
		}
		B.upd(t.f.s,1);
		trav(z,t.s) ev.pb({z,t.f.f});
	}
	sort(rall(ev));
	sort(all(ori));
	int ind = 0, ret = 0;
	R0F(i,sz(ori)) {
		int x = ori[i].f;
		while (ind < sz(ev) && ev[ind].f >= x) {
			int z = ev[ind].s;
			ckmax(ret,++cnt[z]); 
			if (PAR[z] == 0) todo[cnt[z]].pb(z);
			ind ++;
		}
		if (!done[ori[i].s]) PAR[ori[i].s] = 1;
		while (sz(todo[ret])) {
			int t = todo[ret].back(); 
			if (PAR[t] == 1) todo[ret].pop_back();
			else break;
		}
		int val = sz(ori)-i+ret;
		if (ret && !sz(todo[ret])) val --;
		ckmax(ans[2*x],val);
	}
	F0R(i,ret+1) todo[i].clear();
	trav(t,ori) B.upd(t.f,-1);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0); 
	re(n);
	F0R(i,n-1) {
		int u,v; re(u,v);
		adj[u].pb(v), adj[v].pb(u);
	}
	FOR(i,1,n+1) {
		ans[i] = 1;
		ckmax(ans[1],sz(adj[i])+1);
	}
	dfs(1); dfs2(1);
	FOR(i,1,n+1) {
		vi v;
		trav(t,adj[i]) {
			if (t == par[i]) v.pb(up[i]);
			else v.pb(down[t]+1);
		}
		sort(rall(v));
		FOR(j,1,sz(v)) {
			ckmax(ans[2*min(v[j-1]-1,v[j])+1],j+1);
			ckmax(ans[2*v[j]],j+1);
		}
	}
	vpi todo;
	FOR(i,1,n+1) todo.pb({sz(adj[i]),i});
	sort(rall(todo));
	trav(t,todo) {
		process(t.s);
		done[t.s] = 1;
	}
	// FOR(i,1,n+1) ps(i,up[i],down[i]);
	for (int i = n-2; i >= 1; --i) ckmax(ans[i],ans[i+2]);
	FOR(i,1,n+1) pr(ans[i],' ');
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/