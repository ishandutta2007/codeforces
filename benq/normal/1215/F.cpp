#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 200005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
		cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

template<class T> T invGeneral(T a, T b) {
	a %= b; if (a == 0) return b == 1 ? 0 : -1;
	T x = invGeneral(b,a); 
	return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modular {
	T val; 
	explicit operator T() const { return val; }
	modular() { val = 0; }
	modular(const ll& v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	
	// friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
	friend void pr(const modular& a) { pr(a.val); }
	friend void re(modular& a) { ll x; re(x); a = modular(x); }
   
	friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
	friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
	friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

	modular operator-() const { return modular(-val); }
	modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
	friend modular pow(modular a, ll p) {
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend modular inv(const modular& a) { 
		auto i = invGeneral(a.val,MOD); assert(i != -1);
		return i;
	} // equivalent to return exp(b,MOD-2) if MOD is prime
	modular& operator/=(const modular& m) { return (*this) *= inv(m); }
	
	friend modular operator+(modular a, const modular& b) { return a += b; }
	friend modular operator-(modular a, const modular& b) { return a -= b; }
	friend modular operator*(modular a, const modular& b) { return a *= b; }
	
	friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

template<int SZ> struct SCC {
    int N, comp[SZ];
    vi adj[SZ], radj[SZ], todo, allComp;
    bitset<SZ> visit;
    
    void addEdge(int a, int b) { adj[a].pb(b), radj[b].pb(a); }

    void dfs(int v) {
        visit[v] = 1;
        trav(w,adj[v]) if (!visit[w]) dfs(w);
        todo.pb(v);
    }

    void dfs2(int v, int val) {
        comp[v] = val;
        trav(w,radj[v]) if (comp[w] == -1) dfs2(w,val);
    }

    void init(int _N) { // fills allComp
        N = _N;
        F0R(i,N) comp[i] = -1, visit[i] = 0;
        F0R(i,N) if (!visit[i]) dfs(i);
        reverse(all(todo)); // now todo stores vertices in order of topological sort
        trav(i,todo) if (comp[i] == -1) dfs2(i,i), allComp.pb(i);
    }
};

template<int SZ> struct TwoSat {
    SCC<2*SZ> S;
    int N;

    void OR(int x, int y) { S.addEdge(x^1,y); S.addEdge(y^1,x); }
    void IMPLIES(int x, int y) { OR(x^1,y); }

    int tmp[2*SZ];
    bitset<SZ> ans;

    bool solve(int _N) {
        N = _N; S.init(2*N);
        for (int i = 0; i < 2*N; i += 2) if (S.comp[i] == S.comp[i^1]) return 0;
        reverse(all(S.allComp));
        trav(i,S.allComp) if (tmp[i] == 0) tmp[i] = 1, tmp[S.comp[i^1]] = -1;
        F0R(i,N) if (tmp[S.comp[2*i]] == 1) ans[i] = 1;
        return 1;
    }
};

TwoSat<1300000> T;

int n,p,M,m;
int l[400005], r[400005];

int main() {
	setIO(); re(n,p,M,m);
	F0R(i,n) {
		int x,y; re(x,y);
		T.OR(2*x,2*y);
		// ps("HUH",x,y);
	}
	FOR(i,1,p+1) {
		re(l[i],r[i]);
		T.IMPLIES(2*i,2*(p+l[i]));
		T.IMPLIES(2*i,2*(p+M+r[i]));
	}
	FOR(i,1,M) {
		T.IMPLIES(2*(p+i+1),2*(p+i));
		T.IMPLIES(2*(p+M+i),2*(p+M+i+1));
	}
	FOR(i,1,M) {
		T.OR(2*(p+M+i)+1,2*(p+i+1)+1);
	}
	F0R(i,m) {
		int u,v; re(u,v);
		T.OR(2*u+1,2*v+1);
	}
	if (!T.solve(p+2*M+1)) ps(-1);
	else {
		vi ret;
		int lo = -MOD, hi = MOD;
		FOR(i,1,p+1) if (T.ans[i]) {
			ret.pb(i);
			ckmax(lo,l[i]);
			ckmin(hi,r[i]);
		}
		assert(lo <= hi);
		/*if (lo > hi) {
			ps("HUH",ret,lo,hi);
			exit(0);
		}*/
		ps(sz(ret),lo);
		trav(t,ret) pr(t,' ');
	}
	
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/