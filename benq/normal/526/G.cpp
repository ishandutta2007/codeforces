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

template<int SZ> struct TreeDiameter {
    int n; 
    vpi adj[SZ];
    void addEdge(int a, int b, int l) { 
    	adj[a].pb({b,l}), adj[b].pb({a,l}); 
    }

    int par[SZ], dist[SZ];
    void dfs(int x) {
        trav(y,adj[x]) if (y.f != par[x]) {
            par[y.f] = x; dist[y.f] = dist[x]+y.s;
            dfs(y.f);
        }
    }
    void genDist(int x) { par[x] = -1; dist[x] = 0; dfs(x); }

    int diaLength;
    vi center, dia = {1,1}; 
    void init(int _n) {
        n = _n; 
        genDist(1); FOR(i,1,n+1) if (dist[i] > dist[dia[0]]) dia[0] = i; // find one endpoint of a diameter
        genDist(dia[0]); FOR(i,1,n+1) if (dist[i] > dist[dia[1]]) dia[1] = i;
        diaLength = dist[dia[1]];
    }
};

TreeDiameter<MX> T;

int n,q,leaf,tot;
int ans,col[2][MX],res[2][MX],ad[2][MX], par[2][MX][17],depth[2][MX];
int st[2][MX], en[2][MX];
pi mx[2][MX];
vector<pair<int,pi>> tmp;

void dfs(int ind, int x) {
    FOR(i,1,17) par[ind][x][i] = par[ind][par[ind][x][i-1]][i-1];
    mx[ind][x] = {depth[ind][x],x};
    trav(t,T.adj[x]) if (t.f != par[ind][x][0]) {
        par[ind][t.f][0] = x;
        depth[ind][t.f] = depth[ind][x]+t.s;
        dfs(ind,t.f);
        ckmax(mx[ind][x],mx[ind][t.f]);
    }
}

void genPref(int ind, int x, pi bad) {
    trav(t,T.adj[x]) if (t.f != par[ind][x][0]) {
        if (mx[ind][t.f] != bad) {
            tmp.pb({mx[ind][t.f].f-depth[ind][x],{x,mx[ind][t.f].s}});
            genPref(ind,t.f,mx[ind][t.f]);
        } else genPref(ind,t.f,bad);
    }
}

void tri(int ind, int x) {
    dfs(ind,x);
    tmp.clear();
    genPref(ind,x,{-1,-1});
    sort(tmp.rbegin(),tmp.rend());
    F0R(i,sz(tmp)) {
        res[ind][i+1] = res[ind][i]+tmp[i].f;
        st[ind][i+1] = tmp[i].s.f;
        en[ind][i+1] = tmp[i].s.s;
        for (int t = en[ind][i+1]; t != st[ind][i+1]; t = par[ind][t][0]) 
            col[ind][t] = i+1;
    }
    // ps("TRI",ind,x); 
    // ps(tmp);
    // FOR(i,1,n+1) ps(i,mx[ind][i]); exit(0);
}

int getDif(int ind, int c) {
    int ret = depth[ind][en[ind][c]]-depth[ind][st[ind][c]];
    if (ret != res[ind][c]-res[ind][c-1]) {
        ps("??",ind,c,ret,res[ind][c],res[ind][c-1]);
        exit(0);
    }
    return ret;
}

int calc(int ind, int x, int y) {
    if (2*y >= leaf) return tot;
    // select 2*y-1 leaves 
    // ps("HUH",ind,x,col[ind][x]);
    if (col[ind][x] <= 2*y-1) return res[ind][2*y-1];
    int X = x;
    F0Rd(i,17) if (col[ind][par[ind][X][i]] > 2*y-1) X = par[ind][X][i];
    X = par[ind][X][0];
    int c = col[ind][X];
    int path = depth[ind][X]-depth[ind][st[ind][c]];
    int dif = min(getDif(ind,2*y-1),getDif(ind,c)-path); 
    int ret = res[ind][2*y-1]+mx[ind][x].f-depth[ind][X]-dif;
    // ps("WUT",ind,x,y,X,st[ind][c],path,dif,c,ret);
    return ret;
}

int main() {
    setIO(); re(n,q);
    F0R(i,n-1) {
    	int u,v,l; re(u,v,l);
    	T.addEdge(u,v,l); tot += l;
    }
    T.init(n);
    FOR(i,1,n+1) leaf += sz(T.adj[i]) == 1;
    tri(0,T.dia[0]);
    tri(1,T.dia[1]);
    F0R(i,q) {
        int x,y; re(x,y);
        x = (x+ans-1)%n+1;
        y = (y+ans-1)%n+1;
        // ps("QUERY",x,y);
        ans = max(calc(0,x,y),calc(1,x,y));
        ps(ans);
    }
    // ps(T.dia,T.diaLength);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/