#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;
 
typedef double db;
typedef long long ll;
typedef long double ld;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define rsz resize
#define ins insert

const int MOD = 1e9+7; // 998244353 = (119<<23)+1
const ll INF = 1e18;
const int MX = 2e5+5;
const ld PI = 4*atan((ld)1);

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ook order_of_key
#define fbo find_by_order

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
    bitset<SZ> ans;
    int N = 0;
    int addVar() { return N++; }

    void either(int x, int y) { 
        x = max(2*x,-1-2*x), y = max(2*y,-1-2*y);
        S.addEdge(x^1,y); S.addEdge(y^1,x); 
    }
    void implies(int x, int y) { either(~x,y); }
    void setVal(int x) { either(x,x); }
    void atMostOne(const vi& li) {
        if (sz(li) <= 1) return;
        int cur = ~li[0];
        FOR(i,2,sz(li)) {
            int next = addVar();
            either(cur,~li[i]);
            either(cur,next);
            either(~li[i],next);
            cur = ~next;
        }
        either(cur,~li[1]);
    }

    bool solve(int _N) {
    	if (_N != -1) N = _N; 
    	// ps("HA",N);
    	S.init(2*N);
        for (int i = 0; i < 2*N; i += 2) 
            if (S.comp[i] == S.comp[i^1]) return 0;
        reverse(all(S.allComp));
        vi tmp(2*N);
        trav(i,S.allComp) if (tmp[i] == 0) 
            tmp[i] = 1, tmp[S.comp[i^1]] = -1;
        F0R(i,N) if (tmp[S.comp[2*i]] == 1) ans[i] = 1;
        return 1;
    }
};

TwoSat<5000000> T;

int n;

struct Seg { 
	vi seg[200010];
	int var[200010];
    void upd(int l, int r, int x) {  // sum on interval [l, r]
    	// ps("UPD",l,r,x);
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) seg[l++].pb(x);
            if (r&1) seg[--r].pb(x);
        }
    }
    void genEdges() {
    	FOR(i,1,2*n) var[i] = T.addVar();
    	ROF(i,1,2*n) {
    		if (i > 1) seg[i].pb(var[i/2]);
    		// ps("HUH",i,seg[i]);
    		trav(t,seg[i]) T.implies(t,var[i]);
    		T.atMostOne(seg[i]);
    	}
    }
};

template<int SZ, bool VALUES_IN_EDGES> struct HLD { 
    int N; vi adj[SZ];
    int par[SZ], sz[SZ], depth[SZ];
    int root[SZ], pos[SZ];
    Seg tree;
    void addEdge(int a, int b) { adj[a].pb(b), adj[b].pb(a); }
    
    void dfs_sz(int v = 1) {
        if (par[v]) adj[v].erase(find(all(adj[v]),par[v]));
        sz[v] = 1;
        trav(u,adj[v]) {
            par[u] = v; depth[u] = depth[v]+1;
            dfs_sz(u); sz[v] += sz[u];
            if (sz[u] > sz[adj[v][0]]) swap(u, adj[v][0]);
        }
    }
    void dfs_hld(int v = 1) {
        static int t = 0;
        pos[v] = t++;
        trav(u,adj[v]) {
            root[u] = (u == adj[v][0] ? root[v] : u);
            dfs_hld(u);
        }
    }
    void init(int _N) {
        N = _N; par[1] = depth[1] = 0; root[1] = 1; 
        dfs_sz(); dfs_hld();
    }

    template <class BinaryOperation>
    void processPath(int u, int v, BinaryOperation op) {
        for (; root[u] != root[v]; v = par[root[v]]) {
            if (depth[root[u]] > depth[root[v]]) swap(u, v);
            op(pos[root[v]], pos[v]);
        }
        if (depth[u] > depth[v]) swap(u, v);
        op(pos[u]+VALUES_IN_EDGES, pos[v]); 
    }

    void modifyPath(int u, int v, int val) { // add val to vertices/edges along path
        processPath(u, v, [this, &val](int l, int r) { tree.upd(l, r, val); });
    }
};

HLD<100005,1> H;

int main() {
	setIO(); re(n);
	F0R(i,n-1) {
		int u,v; re(u,v);
		H.addEdge(u,v);
	}
	H.init(n);
	int m; re(m);
	vi ans;
	F0R(i,m) {
		int a,b,c,d; re(a,b,c,d);
		int x = T.addVar(); ans.pb(x);
		H.modifyPath(a,b,x); H.modifyPath(c,d,~x);
	}
	H.tree.genEdges();
	if (!T.solve(-1)) {
		ps("NO");
		exit(0);
	}
	ps("YES");
	F0R(i,m) {
		if (T.ans[ans[i]]) ps(1);
		else ps(2);
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/