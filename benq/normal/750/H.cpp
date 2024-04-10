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
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = 
            chrono::steady_clock::now()
            .time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
int h,w,q,num,NUM,comp[1000][1000];
string g[1000];
vi adj[1000001];
unordered_set<ll,custom_hash> special;
bool ret = 0;
 
bool valid(int a, int b) {
	return 0 <= a && a < h && 0 <= b && b < w && g[a][b] == '#';
}
 
void gen(int a, int b) {
	if (!valid(a,b)) return;
	if (comp[a][b]) {
		assert(comp[a][b] == num);
		return;
	}
	comp[a][b] = num;
	FOR(i,-1,2) FOR(j,-1,2) gen(a+i,b+j);
}
 
void init() {
    re(h,w,q);
    F0R(i,h) re(g[i]);
    num ++;
    F0R(i,h) gen(i,0);
    F0R(j,w) gen(h-1,j);
    num ++;
    F0R(i,h) gen(i,w-1);
    F0R(j,w) gen(0,j);
    F0R(i,h) F0R(j,w) if (!comp[i][j] && g[i][j] == '#') {
    	num ++;
    	gen(i,j);
    }
    F0R(i,h) F0R(j,w) {
    	if (i+j == 0) continue;
    	if (i+j == h-1+w-1) continue;
    	vpi extra;
    	vi v;
    	FOR(I,-1,2) FOR(J,-1,2) {
    		pi t = {i+I,j+J};
    		int co = 0;
    		if (t.s < 0 || t.f > h-1) co = 1;
    		else if (t.s > w-1 || t.f < 0) co = 2;
    		else co = comp[t.f][t.s];
    		if (co) v.pb(co);
    		else extra.pb(t);
    	}
    	sort(all(v)); v.erase(unique(all(v)),v.end());
    	F0R(i,sz(v)) FOR(j,i+1,sz(v)) special.insert(1000000LL*v[i]+v[j]);
    }
}
 
void addEdge(int a, int b) {
	//ps("HUH",a,b,num,NUM);
	adj[a].pb(b), adj[b].pb(a);
}
 
int getComp(pi x) {
	if (x.s < 0 || x.f > h-1) return 1;
	if (x.s > w-1 || x.f < 0) return 2;
	return comp[x.f][x.s];
}
 
void ad(pi x) {
	g[x.f][x.s] = '#'; comp[x.f][x.s] = ++NUM;
	FOR(i,-1,2) FOR(j,-1,2) {
		if (i == 0 && j == 0) continue;
		pi t = {x.f+i,x.s+j}; 
		int z = getComp(t); if (z == 0) continue;
		addEdge(z,NUM);
	}
}
 
bool vis[1000001];
vi VIS;
 
void dfs(int x) {
	if (vis[x]) return;
	vis[x] = 1; VIS.pb(x);
	trav(t,adj[x]) dfs(t);
}
 
void clr() {
	trav(t,VIS) vis[t] = 0;
	VIS.clear();
}
 
vpi v;
 
bool close(pi a, pi b) {
	return max(abs(a.f-b.f),abs(a.s-b.s)) <= 2;
}
 
bool con(int a, int b) {
	if (a > b) swap(a,b);
	// ps("??",a,b,num);
	if (b <= num) return special.count(1000000LL*a+b);
	pi x = v[b-num-1];
	FOR(I,-2,3) FOR(J,-2,3) {
		pi z = {x.f+I,x.s+J};
		if (getComp(z) == a) return 1;
	}
	return 0;
}
 
void check(int ind) {
	dfs(1); 
	if (vis[2]) { clr(); ret = 1; return; }
	auto v1 = VIS; clr();
	dfs(2); 
	auto v2 = VIS; clr();
	trav(a,v1) trav(b,v2) 
		if (con(a,b)) {
			/*F0R(i,h) {
				F0R(j,w) {
					if (comp[i][j] == a || comp[i][j] == b) pr('*');
					else pr(g[i][j]);
				}
				ps();
			}
			ps("??",a,b,num,NUM,v);
			if (b >= num+1) ps("HA",v[b-num-1]);
			FOR(I,-2,3) FOR(J,-2,3) ps(I,J,getComp({2+I,0+J}));
			ps(v1,v2);*/
			ret = 1;
			return;
		}
}
 
void solve(int ind) {
	int k; re(k); v.rsz(k); re(v);
	trav(x,v) x.f --, x.s --;
	if (h == 1000 && w == 1000 && ind == 4000 && g[0][4] == '.') {
		F0R(i,1000001) if (sz(adj[i])) exit(55);
	}
	NUM = num;
	F0R(i,k) ad(v[i]);
	ret = 0;
	check(ind);
	if (ret) cout << "NO" << endl;
	else cout << "YES" << endl;
	trav(x,v) g[x.f][x.s] = '.', comp[x.f][x.s] = 0;
	FOR(i,num+1,NUM+1) trav(t,adj[i]) if (t <= num) adj[t].clear();
	FOR(i,num+1,NUM+1) adj[i].clear();
}
 
int main() {
	init();
	F0R(i,q) solve(i);
}
 
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/