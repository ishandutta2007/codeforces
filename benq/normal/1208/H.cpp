// based off ecnerwal's code

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

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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
const int MX = 1<<17;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// k=-INF -> all blue (0), k=INF -> all red (1)

pi operator+(const pi& l, const pi& r) {
	// [-inf,l.f) -> 0, [l.f,l.s) -> x, [l.s,inf] -> 1
	// [-inf,r.f) -> 0, [r.f,r.s) -> x, [r.s,inf] -> 1 
	return {min(l.s,max(l.f,r.f)),min(l.s,max(l.f,r.s))};
}

int n,s[MX];
int sz[MX],par[MX];
int root[MX],st[MX];
vi ord;
vi adj[MX];

Tree<pi> cval[MX];
decltype(begin(cval[0])) citer[MX];
pi seg[2*MX];

void dfs1(int x) {
	sz[x] = 1;
	trav(t,adj[x]) {
		par[t] = x;
		adj[t].erase(find(all(adj[t]),x));
		dfs1(t);
		sz[x] += sz[t];
	}
}

void dfs2(int x) {
	st[x] = sz(ord); ord.pb(x);
	trav(t,adj[x]) if (sz[t] > sz[adj[x][0]]) swap(adj[x][0],t);
	F0R(i,sz(adj[x])) {
		int t = adj[x][i];
		if (i == 0) root[t] = root[x]; 
		else root[t] = t;
		dfs2(t);
	}
}

int query(int v) {
	v = st[v];
	pi ret = seg[MX+v];
	for (int l = MX+v+1, r = 2*MX; l < r; l /= 2, r /= 2) 
		if (l&1) ret = ret+seg[l++];
	assert(ret.f == ret.s);
	return ret.f;
}

int atMost(Tree<pi>& a, int b) {
	return a.order_of_key({b,MOD});
}

bool ok(int x, int cur, int extra) {
	int red = atMost(cval[x],cur)+extra;
	int blue = sz(cval[x])+1-red;
	return blue-red < cur;
}

void fix(int x, int& cur, int extra) {
	while (ok(x,cur-1,extra)) cur --;
	while (!ok(x,cur,extra)) cur ++;
	// extra=1 -> suppose that we have extra red
	// extra=0 -> suppose that we have extra blue
	// blue-red >= cur -> 0
	// find the first cur such that blue-red < cur
}

void updFunc(int x) {
	pi& func = seg[MX+st[x]];
	if (!sz(adj[x])) {
		if (s[x] == 1) func = {-MOD,-MOD};
		else func = {MOD,MOD};
	} else  {
		fix(x,func.f,1);
		fix(x,func.s,0);
		assert(func.f <= func.s);
	}
	for (int ind = (st[x]+MX)/2; ind; ind /= 2)
		seg[ind] = seg[2*ind]+seg[2*ind+1];
}

int main() {
    setIO(); 
    int k; re(n,k);
    F0R(i,n-1) {
    	int u,v; re(u,v);
    	adj[u].pb(v), adj[v].pb(u);
    }
    dfs1(1);
    root[1] = 1; dfs2(1);
    //FOR(i,1,n+1) ps(i,adj[i],sz[i],par[i],root[i],st[i]);
    //ps(ord);
    FOR(i,1,n+1) {
    	re(s[i]); 
    	if (s[i] == 0 || s[i] == 1) s[i] ^= 1;
    }
    F0Rd(i,sz(ord)) {
    	int x = ord[i];
    	updFunc(x);
    	if (root[x] == x && x != 1) {
    		int p = par[x];
    		citer[x] = cval[p].insert({query(x),x}).f;
    	}
    }
    int q; re(q);
    F0R(i,q) {
    	int t; re(t);
    	if (t == 1) {
    		int v; re(v);
    		int t = query(v);
    		if (k >= t) ps(0);
    		else ps(1);
    	} else if (t == 2) {
    		int x,c; re(x,c); 
    		s[x] = c^1;
    		while (1) {
    			updFunc(x); 
    			// ps("HUH",x,seg[st[x]+MX]);
    			// trav(t,cval[x]) ps(t.f,t.s);
    			// ps("-----");
    			x = root[x]; if (x == 1) break;
    			int p = par[x];
    			cval[p].erase(citer[x]);
    			// ps("WUT",x,query(x));
    			citer[x] = cval[p].insert({query(x),x}).f;
    			x = p;
    		}
    	} else {
    		re(k);
    	}
    }
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/