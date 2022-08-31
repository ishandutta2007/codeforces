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

int n,m,disc[MX],co,ans[MX];
int pre[MX];
vi adj[MX];
bool done = 0;
vi v;

void dfs(int a) {
	if (done) return;
	if (sz(adj[a]) > 3) {
		ans[a] = 2;
		F0R(j,4) ans[adj[a][j]] = 1;
		done = 1; return;
	}
	if (sz(adj[a]) == 3) v.pb(a);
	disc[a] = ++co;
	trav(t,adj[a]) if (t != pre[a]) {
		if (done) return;
		if (!disc[t]) {
			// ps("HUH",a,t);
			pre[t] = a;
			dfs(t);
		} else if (disc[t] < disc[a]) {
			while (a != t) {
				ans[a] = 1;
				a = pre[a];
			}
			ans[a] = 1; done = 1;
			return;
		}
	}
}

void zz() {
	ps("YES");
	FOR(i,1,n+1) pr(ans[i],' ');
	ps();
}

bool onPath[MX];

void DFS(int a, int b) {
	trav(t,adj[a]) if (t != b) {
		pre[t] = a;
		DFS(t,a);
	}
}

void genPath(int a, int b) {
	FOR(i,1,n+1) onPath[i] = pre[i] = 0;
	DFS(a,0);
	for (int t = b; t != a; t = pre[t]) ans[t] = 2, onPath[t] = 1;
	ans[a] = 2, onPath[a] = 1;
	int cnt = 0;
	trav(t,adj[a]) if (!onPath[t]) {
		ans[t] = 1;
		cnt ++;
		if (cnt == 2) break;
	}
	cnt = 0;
	trav(t,adj[b]) if (!onPath[t]) {
		ans[t] = 1;
		cnt ++;
		if (cnt == 2) break;
	}
}

void fill(vi& a, int x, int y) {
	a.pb(x);
	trav(t,adj[x]) if (t != y) {
		fill(a,t,x);
	}
}

double r(int x) { return 1.0/x; }

void solve() {
	string x; re(x);
	if (!isdigit(x[0])) re(n);
	else n = stoi(x);
	re(m);
	/*ps("HUH",n,m);
	exit(0);*/
	done = 0;
	FOR(i,1,n+1) {
		pre[i] = disc[i] = ans[i] = 0;
		adj[i].clear();
	}
	F0R(i,m) {
		int a,b; re(a,b); 
		adj[a].pb(b), adj[b].pb(a);
	}
	FOR(i,1,n+1) if (!disc[i]) {
		v.clear(); dfs(i);
		if (done) return zz();
		if (sz(v) > 1) {
			genPath(v[0],v[1]);
			return zz();
		}
		if (sz(v) == 1) {
			vi a[3];
			F0R(i,3) {
				a[i].pb(v[0]);
				fill(a[i],adj[v[0]][i],v[0]);
			}
			if (r(sz(a[0]))+r(sz(a[1]))+r(sz(a[2])) <= 1) {
				while (r(sz(a[0])-1)+r(sz(a[1]))+r(sz(a[2])) <= 1) a[0].pop_back();
				while (r(sz(a[0]))+r(sz(a[1])-1)+r(sz(a[2])) <= 1) a[1].pop_back();
				while (r(sz(a[0]))+r(sz(a[1]))+r(sz(a[2])-1) <= 1) a[2].pop_back();
				// ps("HUH",a[0],a[1],a[2]); exit(0);
				int g = 1;
				F0R(i,3) g = g*sz(a[i])/__gcd(g,sz(a[i]));
				ans[v[0]] = g;
				F0R(i,3) {
					FOR(j,1,sz(a[i])) ans[a[i][j]] = g*(sz(a[i])-j)/sz(a[i]);	
				}
				return zz();
			}
			// ps("HUH",a[0],a[1],a[2]); exit(0);
		}
	}
	ps("NO");
}

int main() {
    setIO(); int t; re(t); 
    F0R(i,t) solve();
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/