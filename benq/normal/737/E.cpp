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
const int MX = 200005;
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
    
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
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

vector<array<int,4>> ret;
int adj[60][60],des[40][10];
bool buy[10];

int n,m,b;
vi p;

void init() {
    setIO(); re(n,m,b); p.rsz(m); re(p);
    F0R(i,n) {
    	int k; re(k);
    	F0R(j,k) {
    		int x,t; re(x,t); 
    		des[i][x-1] = t;
    	}
    }
    priority_queue<pi> pq;
    F0R(j,m) {
    	int tot = 0;
    	F0R(i,n) tot += des[i][j];
    	pq.push({tot,j});
    }
    while (sz(pq)) {
    	auto a = pq.top(); 
    	// ps("HWUT",a,b);
    	if (p[a.s] > b) break;
    	pq.pop(); buy[a.s] = 1; b -= p[a.s];
    	int par = 0;
    	F0R(i,n) {
    		int x = des[i][a.s];
    		adj[i][n+a.s] += x/2;
    		adj[i][n+a.s+m] += x/2;
    		if (x&1) {
    			if (par&1) adj[i][n+a.s] ++;
    			else adj[i][n+a.s+m] ++;
    			par ^= 1;
    		}
    	}
    }
    while (sz(pq)) {
    	auto a = pq.top(); pq.pop();
    	F0R(i,n) adj[i][n+a.s] = des[i][a.s];
    }
}

int match[60], rmatch[60];
bitset<60> vis;

bool dfs(int x) {
	if (x == -1) return 1;
	if (vis[x]) return 0;
	vis[x] = 1;
	F0R(t,n+2*m) if (adj[x][t] && t != match[x] && dfs(rmatch[t])) {
		match[x] = t, rmatch[t] = x;
		return 1;
	}
	return 0;
}

int ti = 0;

bool tri() {
	/*F0R(i,n+2*m) {
		F0R(j,n+2*m) cout << adj[i][j] << " ";
		cout << "\n";
	}*/
	
	F0R(i,n+2*m) match[i] = rmatch[i] = -1;
	vis.reset();
	if (!dfs(0)) return 0;
	FOR(i,1,n+2*m) {
		vis.reset();
		assert(dfs(i));
	}
	int wei = MOD;
	F0R(i,n+2*m) ckmin(wei,adj[i][match[i]]);
	// ps("HUH",ti,wei);
	assert(wei);
	F0R(i,n) if (match[i] >= n) ret.pb({i+1,(match[i]-n)%m+1,ti,wei});
	ti += wei;
	F0R(i,n+2*m) adj[i][match[i]] -= wei;
	return 1;
}

int main() {
	init();
    int ans = 0;
    F0R(i,n) {
    	int tot = 0;
    	FOR(j,n,n+2*m) tot += adj[i][j];
    	ckmax(ans,tot);
    }
    // ps("HUH",ans);
    F0R(j,2*m) {
    	int tot = 0;
    	F0R(i,n) tot += adj[i][n+j];
    	ckmax(ans,tot);
    }
    ps(ans); // exit(0);
    vpi lef, ri;
    F0R(i,n) {
    	int tot = 0;
    	FOR(j,n,n+2*m) tot += adj[i][j];
    	adj[i][i] = ans-tot;
    	ri.pb({tot,i});
    }
    F0R(j,2*m) {
    	int tot = 0;
    	F0R(i,n) tot += adj[i][n+j];
    	adj[n+j][n+j] = ans-tot;
    	lef.pb({tot,n+j});
    }
    // ps("HUH",lef,ri);
    while (1) {
    	while (sz(lef) && !lef.back().f) lef.pop_back();
    	while (sz(ri) && !ri.back().f) ri.pop_back();
    	if (!sz(lef)) {
    		assert(!sz(ri));
    		break;
    	}
    	int x = min(lef.back().f,ri.back().f);
    	adj[lef.back().s][ri.back().s] += x;
    	lef.back().f -= x, ri.back().f -= x;
    }
    F0R(i,m) {
    	if (buy[i]) pr(1);
    	else pr(0);
    }
    ps();
    bool ok = 1;
    while (ok) ok = tri();
    ps(sz(ret));
    trav(a,ret) {
    	trav(b,a) pr(b,' ');
    	ps();
    }
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/