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

template<int SZ> struct DSU {
    int par[SZ], sz[SZ];
    vpi stor;

    DSU() {
        F0R(i,SZ) par[i] = i, sz[i] = 1;
    }

    int get(int x) { // no path compression
        if (x == par[x]) return x;
        return get(par[x]);
    }

    void unite(int x, int y) { // union-by-rank
    	x = get(x), y = get(y);
    	if (x == y) { stor.pb({-1,-1}); return; }
    	if (sz[x] < sz[y]) swap(x,y);
    	stor.pb({x,y});	sz[x] += sz[y], par[y] = x;
    }

    void rollback() { // delete last edge added
        auto a = stor.back(); stor.pop_back();
        int x = a.f, y = a.s;
        if (x == -1) return;
        sz[x] -= sz[y]; par[y] = y;
    }
};

vpi ins[1<<19];
DSU<1<<18> D;

int n,m,lst;
map<pi,vi> oc;

void nor(int& x) {
	x = (x%n+n)%n;
	if (x == 0) x = n;
}

pi nor(int x, int y) {
	nor(x), nor(y);
	if (x > y) swap(x,y);
	return {x,y};
}
   
vector<array<int,3>> ed;
vpi posi[MX];
set<pi> cur;

void ad(pi t, int lo, int hi, int ind = 1, int l = 0, int r = -1) {
	if (r < 0) r += m;
	if (hi < l || r < lo) return;
	if (lo <= l && r <= hi) {
		ins[ind].pb(t);
		return;
	}
	int m = (l+r)/2;
	ad(t,lo,hi,2*ind,l,m);
	ad(t,lo,hi,2*ind+1,m+1,r);
}

void gen(int ind, int l, int r) {
	trav(t,ins[ind]) {
		// ps("HA",ind,l,r,t);
		D.unite(t.f,t.s);
	}
	if (l == r) {
		if (ed[l][0] == 1) {
			pi des = nor(ed[l][1]+lst-1,ed[l][2]+lst-1);
			trav(t,posi[l]) {
				assert(oc[t].back() == l); oc[t].pop_back();
				if (t == des) {
					if (cur.count(t)) {
						cur.erase(t);
					} else {
						// ps("INSERT",t,l+1,(sz(oc[t])?m:oc[t].back())-1);
						cur.insert(t);
						ad(t,l+1,(sz(oc[t])?oc[t].back():m)-1);
					}
				} else {
					if (cur.count(t)) {
						ad(t,l+1,(sz(oc[t])?oc[t].back():m)-1);
					}
				}
			}
			// add an ed
		} else {
			// ps("WUT",ind,l,r,sz(cur),sz(D.stor));
			pi x = nor(ed[l][1]+lst-1,ed[l][2]+lst-1);
			//ps("QUERY",x,cur);
			//ps("HUH",cur,x,D.stor);
			//ps();
			lst = D.get(x.f) == D.get(x.s);
			pr(lst);
		}
	} else {
		int m = (l+r)/2;
		gen(2*ind,l,m); gen(2*ind+1,m+1,r);
	}
	// ps("HA",ind,l,r,sz(ins[ind]),sz(D.stor));
	trav(t,ins[ind]) {
		// ps("DEL",ind,l,r,t);
		D.rollback();
	}
}

int main() {
    // setIO("tmp"); 
    setIO();
    re(n,m);
    F0R(i,m) {
    	int t,x,y; re(t,x,y);
    	ed.pb({t,x,y});
    }
    F0Rd(i,m) if (ed[i][0] == 1) {
    	pi x = nor(ed[i][1],ed[i][2]), y = nor(ed[i][1]-1,ed[i][2]-1);
    	posi[i].pb(x); oc[x].pb(i);
    	if (y != x) {
    		posi[i].pb(y); oc[y].pb(i);
    	}
    }
    //ps("WUT",oc[{1,2}]);
    gen(1,0,m-1);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/