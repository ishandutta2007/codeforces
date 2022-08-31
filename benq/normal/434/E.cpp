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

int MOD = 1000000007; // 998244353
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

int n,k,des,in[MX],out[MX];
mi v[MX];
vi adj[MX];
ll p, ans;
mi po[MX], ipo[MX];

template<int SZ> struct CD {
    vi adj[SZ];
    
    bool done[SZ];
    int sub[SZ], par[SZ];

    void addEdge(int a, int b) { 
    	adj[a].pb(b), adj[b].pb(a);
    }

    void dfs (int x) {
        sub[x] = 1;
        trav(y,adj[x]) {
            if (!done[y] && y != par[x]) {
                par[y] = x; dfs(y);
                sub[x] += sub[y];
            }
        }
    }

    int centroid(int x) {
        par[x] = -1;  dfs(x); 
        for (int sz = sub[x];;) {
            pi mx = {0,0};
            trav(y,adj[x]) {
                if (!done[y] && y != par[x]) ckmax(mx,{sub[y],y});
            }
            if (mx.f*2 <= sz) return x; 
            x = mx.s;
        }
    }

	// unordered_map<int,int> pathTo, pathFrom;
	
	/*void ad(mi a, int b) {
		paths[(int)a] += b;
	}
	int num(mi A) {
		int a = (int)A;
		if (!paths.count(a)) return 0;
		return paths[a];
	}*/
	pair<mi,int> fromCen[MX], toCen[MX];
	
	/*void add(int y, int x, pair<mi,int> out, pair<mi,int> in, int b) {
		out.f += v[y]*po[out.s]; out.s ++; 
		in.f = v[y]+k*in.f; in.s ++;
		pathTo[(int)out.f] += b; pathFrom[(int)in.f] += b;
		trav(t,adj[y]) if (!done[t] && t != x) 
			add(t,y,out,in,b);
	}
	
	void genAns(int y, int x, pair<mi,int> out, pair<mi,int> in) {
		out.f += v[y]*po[out.s]; out.s ++; 
		in.f = v[y]+k*in.f; in.s ++;
		// in.f+po[in.s]*?? = des
		out[y] += (des-in.f)*ipo[in.s];
		// ??.f+
		trav(t,adj[y]) if (!done[t] && t != x) 
			genAns(t,y,out,in);
	}*/
	
	void add(int y, int x, vi& vis) {
		vis.pb(y);
		fromCen[y] = fromCen[x]; 
		fromCen[y].f += v[y]*po[fromCen[y].s]; fromCen[y].s ++;
		toCen[y] = toCen[x];
		toCen[y].f = v[y]+k*toCen[y].f; toCen[y].s ++;
		trav(t,adj[y]) if (!done[t] && t != x) 
			add(t,y,vis);
	}
	
	void check(vi v, int c) {
		// ps("CHECK",v,c);
		unordered_map<int,int> M, RM;
		trav(t,v) M[(int)fromCen[t].f] ++;
		trav(t,v) {
			// toCen[t].f+po[toCen[t].s]*? = des
			mi need = (des-toCen[t].f)*ipo[toCen[t].s];
			if (M.count((int)need)) {
				out[t] += c*M[(int)need];
				RM[(int)need] ++;
			}
		}
		trav(t,v) if (RM.count((int)fromCen[t].f))
			in[t] += c*RM[(int)fromCen[t].f];
	}
	
    void gen(int x) { // call init(1) to start
        done[x = centroid(x)] = 1; 
        vi tot = {x}; vector<vi> vis; 
        fromCen[x] = {v[x],1}; toCen[x] = {0,0};
        trav(y,adj[x]) if (!done[y]) {
        	vis.pb({});
        	add(y,x,vis.back());
        	tot.insert(end(tot),all(vis.back()));
        }
        check(tot,1); 
        trav(t,vis) check(t,-1);
        trav(y,adj[x]) if (!done[y]) gen(y);
    }
    
    void init() { gen(1); }
};

CD<MX> C;

int main() {
    setIO(); re(n,MOD,k,des);
    FOR(i,1,n+1) re(v[i]);
    F0R(i,n-1) {
    	int a,b; re(a,b);
    	C.addEdge(a,b);
    }
    po[0] = ipo[0] = 1; FOR(i,1,n+1) po[i] = k*po[i-1];
    ipo[1] = inv(mi(k)); FOR(i,2,n+1) ipo[i] = ipo[i-1]*ipo[1];
    C.init();
    // FOR(i,1,n+1) ps(i,in[i],out[i]);
    FOR(i,1,n+1) {
    	p += 2LL*out[i]*(n-out[i]);
    	p += 2LL*in[i]*(n-in[i]);
    	p += (ll)in[i]*(n-out[i]);
    	p += (ll)out[i]*(n-in[i]);
    }
    // ps("HUH",p);
    ps((ll)n*n*n-p/2);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/