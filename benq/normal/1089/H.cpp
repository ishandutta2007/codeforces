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

template<int SZ> struct scc {
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

    void genSCC(int _N) { // fills allComp
        N = _N; todo.clear(); allComp.clear();
        F0R(i,N) comp[i] = -1, visit[i] = 0;
        F0R(i,N) if (!visit[i]) dfs(i);
        reverse(all(todo)); // toposort
        trav(i,todo) if (comp[i] == -1) dfs2(i,i), allComp.pb(i);
    }
};

template<int SZ> struct twosat {
    scc<2*SZ> S;
    int N;

    void OR(int x, int y) { S.addEdge(x^1,y); S.addEdge(y^1,x); }
    void IMPLIES(int x, int y) { OR(x^1,y); }

    int tmp[2*SZ];
    bitset<SZ> ans;

    bool solve(int _N) {
        N = _N; S.genSCC(2*N);
        F0R(i,N) tmp[i] = 0;
        for (int i = 0; i < 2*N; i += 2) if (S.comp[i] == S.comp[i^1]) return 0;
        reverse(all(S.allComp));
        trav(i,S.allComp) if (tmp[i] == 0) tmp[i] = 1, tmp[S.comp[i^1]] = -1;
        F0R(i,N) if (tmp[S.comp[2*i]] == 1) ans[i] = 1;
        return 1;
    }
};

int T,n,m,uni[2*MX],reach[2*MX];
vi ADJ[2*MX];
string s;
twosat<MX> z;

void cat(int& x) {
	x = 2*(abs(x)-1)+(x<0);
}

bool solve() { // whoops why does this even work lol
	re(n,m,s);
	F0R(i,2*n) {
		uni[i] = reach[i] = 0;
		z.S.adj[i].clear(), z.S.radj[i].clear();
		ADJ[i].clear();
	}
	F0R(i,m) {
		int u,v; re(u,v);
		cat(u); cat(v);
		z.OR(u,v);
	}
	if (!z.solve(n)) return 0;
	F0Rd(i,n) if (s[i] == 'A') {
		uni[z.S.comp[2*i]] ++;
		uni[z.S.comp[2*i+1]] ++;
	} else {
		if (uni[z.S.comp[2*i]] || uni[z.S.comp[2*i+1]]) return 0;
	}
	reverse(all(z.S.allComp));
	// ps("HUH",z.S.allComp);
	// F0R(i,2*n) ps(i,z.S.comp[i]);
	F0R(i,2*n) trav(t,z.S.adj[i]) {
		// ps("??",i,t,z.S.comp[i],z.S.comp[t]);
		// ps("WUT",z.S.comp[i],z.S.comp[t]);
		ADJ[z.S.comp[i]].pb(z.S.comp[t]);
	}
	// ps("??",sz(ADJ[0]),z.S.allComp);
	trav(i,z.S.allComp) if (reach[i] || uni[i]) 
		trav(t,ADJ[i]) if (i != t) {
			// ps("WUT",i,t);
			reach[t] = 1;
		}
	// F0R(i,2*n) ps(uni[i],reach[i]);
	F0R(i,2*n) {
		if (uni[i] > 1) return 0;
		if (uni[i] && reach[i]) return 0;
	}
	return 1;
}

int main() {
    setIO(); re(T);
    F0R(i,T) {
    	if (solve()) ps("TRUE");
    	else ps("FALSE");
    }
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/