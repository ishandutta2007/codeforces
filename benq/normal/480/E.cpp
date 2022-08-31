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

template<class T> struct MinDeque { 
    int lo = 0, hi = -1;
    deque<pair<T,int>> d;
    
    void ins(T x) { // add to back
        while (sz(d) && d.back().f >= x) d.pop_back();
        d.pb({x,++hi});
    }
    
    void del() { // delete from front
        if (d.front().s == lo++) d.pop_front();
    }
    
    T get() { 
        return sz(d) ? d.front().f : MOD; // change based on T
    }
};

int n,m,k,ans[2000];
string g[2000];

int calc(vi lo, vi hi) {
	int tmp = 0; int r = -1;
    MinDeque<int> LO, HI;
	F0R(l,sz(lo)) {
        while (r+1 < sz(lo) && (r+1)-l+1 <= 
            min(LO.get(),lo[r+1])+min(HI.get(),hi[r+1])) {
            r ++;
            LO.ins(lo[r]); HI.ins(hi[r]);
        }
        // assert(r-l+1 <= LO+HI);
        ckmax(tmp,r-l+1);
        if (r+1 < sz(lo)) {
            // assert(min(LO,lo[r+1])+min(HI,hi[r+1]) < (r+1)-l+1);
            ckmax(tmp,min(LO.get(),lo[r+1])+min(HI.get(),hi[r+1]));
        }
        if (r < l) {
            r ++;
            // ps("??",l,r,lo,hi); exit(0);
        } else {
            LO.del(), HI.del();
        }
	}
	return tmp;
}

void divi(int x0, int x1, int y0, int y1, vector<pair<pi,int>> v) {
	if (x0 == x1 && y0 == y1) {
        if (g[x0][y0] == 'X') return;
		if (!sz(v)) ckmax(ans[k-1],1);
		else if (v[0].s) ckmax(ans[v[0].s-1],1);
		return;
	}
	if (x1-x0 > y1-y0) {
		int m = (x0+x1)/2;
		vi lo, hi;
		FOR(j,y0,y1+1) {
			int cur = m; while (cur >= x0 && g[cur][j] == '.') cur --;
			lo.pb(m-cur);
			cur = m+1; while (cur <= x1 && g[cur][j] == '.') cur ++;
			hi.pb(cur-m-1); // [x0,m], [m+1,x1]
		}
		F0R(i,sz(v)+1) {
			int ind = (i == sz(v) ? k-1 : v[i].s-1);
			if (ind >= 0) ckmax(ans[ind],calc(lo,hi));
			// if (ind == k-1 && calc(lo,hi) == 4) ps("HUHX",x0,x1,y0,y1,lo,hi,v);
			if (i < sz(v)) {
				if (v[i].f.f <= m) ckmin(lo[v[i].f.s-y0],m-v[i].f.f);
				else ckmin(hi[v[i].f.s-y0],v[i].f.f-m-1);
			}
		}
		// do smth ...
		vector<pair<pi,int>> V[2]; trav(t,v) V[t.f.f > m].pb(t);
		divi(x0,m,y0,y1,V[0]);
		divi(m+1,x1,y0,y1,V[1]);
	} else {
		int m = (y0+y1)/2;
		vi lo, hi;
		FOR(i,x0,x1+1) {
			int cur = m; while (cur >= y0 && g[i][cur] == '.') cur --;
			lo.pb(m-cur);
			cur = m+1; while (cur <= y1 && g[i][cur] == '.') cur ++;
			hi.pb(cur-m-1); // [x0,m], [m+1,x1]
		}
		F0R(i,sz(v)+1) {
			int ind = (i == sz(v) ? k-1 : v[i].s-1);
			if (ind >= 0) ckmax(ans[ind],calc(lo,hi));
			// if (ind == k-1 && calc(lo,hi) == 4) ps("HUHY",x0,x1,y0,y1,lo,hi);
			if (i < sz(v)) {
				if (v[i].f.s <= m) ckmin(lo[v[i].f.f-x0],m-v[i].f.s);
				else ckmin(hi[v[i].f.f-x0],v[i].f.s-m-1);
			}
		}
		// do smth ...
		vector<pair<pi,int>> V[2]; trav(t,v) V[t.f.s > m].pb(t);
		divi(x0,x1,y0,m,V[0]);
		divi(x0,x1,m+1,y1,V[1]);
	}
}

int main() {
    // setIO("E"); 
    setIO();
    re(n,m,k);
    F0R(i,n) re(g[i]);
    vector<pair<pi,int>> v(k);
    F0R(i,k) {
    	v[i].s = i;
    	re(v[i].f);
    	v[i].f.f --, v[i].f.s --;
    }
    // exit(0);
    divi(0,n-1,0,m-1,v);
    F0Rd(i,k-1) ckmax(ans[i],ans[i+1]);
    F0R(i,k) ps(ans[i]);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/