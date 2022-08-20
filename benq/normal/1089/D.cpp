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
const int MX = 100005;
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

int n,m;
ll w[MX];
set<int> adj[MX];
ll ans;

vi cool;
int rcool[MX];
pi path[MX];
vector<array<int,3>> info;
vector<vl> sumwi, sumw;
vector<vi> dist;

void genPath(int a, int b, int p) {
	assert(sz(adj[a]) == 2);
	path[a] = {sz(info)-1,p}; info.back()[2] ++;
	sumwi.back().pb(sumwi.back().back()+info.back()[2]*w[a]);
	sumw.back().pb(sumw.back().back()+w[a]);
	trav(t,adj[a]) if (t != b) {
		// ps("HUH",a,b,p,t,rcool[t]); exit(0);
		if (rcool[t] == -1) genPath(t,a,p+1);
		else info.back()[1] = t;
	}
}

ll special(int i, int z, int d1, int d2) {
	// d1+x=z-x
	int len = info[i].back()+1;
	int x = (z-d1)/2;
	ll ret = 0;
	ret += d1*sumw[i][x]+sumwi[i][x];
	ret += (sumw[i][z]-sumw[i][x])*z-(sumwi[i][z]-sumwi[i][x]);
	
	// x-z=d2+len-x
	// ps(sumwi[i],sumw[i],x,d1,d2); exit(0);
	x = (d2+len+z)/2;
	ret += (sumwi[i][x]-sumwi[i][z])-(sumw[i][x]-sumw[i][z])*z;
	ret += (sumw[i].back()-sumw[i][x])*(d2+len)
		-(sumwi[i].back()-sumwi[i][x]);
	return ret;
}

ll solve(int i, int d1, int d2) {
	// d1+x = d2+len-x
	int len = info[i].back()+1;
	int x = (d2+len-d1)/2;
	return sumw[i][x]*d1+sumwi[i][x]
		+(sumw[i].back()-sumw[i][x])*(d2+len)
		-(sumwi[i].back()-sumwi[i][x]);
}

void tri(int x) {
	ll cur = 0;
	if (rcool[x] != -1) {
		FOR(i,1,n+1) {
			// ps("HUH",i,w[i],dist[rcool[x]][i]);
			cur += w[i]*dist[rcool[x]][i];
		}
	} else {
		F0R(i,sz(cool)) cur += w[cool[i]]*dist[i][x];
		F0R(i,sz(info)) {
			if (i == path[x].f) {
				cur += special(i,path[x].s,dist[rcool[info[i][0]]][x],dist[rcool[info[i][1]]][x]);
				// ps("??",i,x); exit(0);
			} else cur += solve(i,dist[rcool[info[i][0]]][x],dist[rcool[info[i][1]]][x]);
		}
	}
	ans += w[x]*cur;
	
}

int main() {
    setIO(); re(n,m);
    FOR(i,1,n+1) w[i] = 1;
    F0R(i,m) {
    	int x,y; re(x,y);
    	adj[x].insert(y), adj[y].insert(x);
    }
    queue<int> q; FOR(i,1,n+1) if (sz(adj[i]) == 1) q.push(i);
    while (sz(q)) {
    	int x = q.front(); q.pop();
    	if (!sz(adj[x])) {
    		ps(ans);
    		exit(0);
    	}
    	int y = *adj[x].begin();
    	ans += w[x]*(n-w[x]);
    	w[y] += w[x]; w[x] = 0;
    	adj[x].erase(y), adj[y].erase(x);
    	if (sz(adj[y]) == 1) q.push(y);
    }
    ans *= 2;
    /*ps(ans);
    FOR(i,1,n+1) ps(i,adj[i]);*/
    FOR(i,1,n+1) {
    	rcool[i] = -1;
    	path[i] = {-1,-1};
    }
    FOR(i,1,n+1) if (sz(adj[i]) > 2) cool.pb(i);
    if (!sz(cool)) {
    	FOR(i,1,n+1) if (sz(adj[i]) == 2) {
    		cool.pb(i);
    		break;
    	}
    }
    F0R(i,sz(cool)) rcool[cool[i]] = i;
    FOR(i,1,n+1) if (rcool[i] != -1) {
    	trav(t,adj[i]) if (rcool[t] == -1 && path[t] == mp(-1,-1)) {
    		sumw.pb({0}); sumwi.pb({0});
    		info.pb({i,-1,0});
    		genPath(t,i,1);
    		sumwi.back().pb(sumwi.back().back());
    		sumw.back().pb(sumw.back().back());
    		// ps(info.back()); exit(0);
    		/*ps(info);
    		FOR(i,1,n+1) ps(i,path[i]);
    		exit(0);*/
    	}	
    }
    F0R(i,sz(cool)) {
    	dist.pb(vi(n+1,MOD));
    	queue<int> q; dist.back()[cool[i]] = 0; q.push(cool[i]);
    	while (sz(q)) {
    		int x = q.front(); q.pop();
    		trav(t,adj[x]) if (dist.back()[t] == MOD) {
    			dist.back()[t] = dist.back()[x]+1;
    			q.push(t);
    		}
    	}
    	// ps(dist.back());
    }
    FOR(i,1,n+1) if (sz(adj[i])) tri(i);
    assert(ans%2==0);
    ps(ans/2);
    // ps(info);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/