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
    template<class T> void pr(const multiset<T>& x);
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
    template<class T> void pr(const multiset<T>& x) { prContain(x); }
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

int n,root,sz[MX],ans[MX],par[MX];
vi adj[MX];
multiset<int> below[MX], above, path;

void dfs1(int a) {
    sz[a] = 1;
    trav(t,adj[a]) {
        dfs1(t); 
        sz[a] += sz[t];
    }
    sort(all(adj[a]), [](int a, int b) { return sz[a] > sz[b]; });
    above.insert(sz[a]);
}

int query(int a, int b, multiset<int>& B, int cc = 0) {
    assert(a <= b);
    auto it = B.lb((b-a)/2-cc);
    int ret = b;
    if (it != B.end()) {
        int t = *it+cc;
        ckmin(ret,max(a+t,b-t));
    }
    if (it != B.begin()) {
        it --;
        int t = *it+cc;
        ckmin(ret,max(a+t,b-t));
    }
    return ret;
}

void insAbove(int a) {
    above.insert(sz[a]);
    trav(t,adj[a]) insAbove(t);
}

void delAbove(int a) {
    above.erase(above.find(sz[a]));
    trav(t,adj[a]) delAbove(t);
}

void dfs2(int a) {
    // ps("START",a,sz(above));
    if (par[a]) {
        above.erase(above.find(sz[par[a]]));
        path.insert(sz[par[a]]);
    } 
    F0Rd(i,sz(adj[a])) {
        int c = adj[a][i]; dfs2(c);
        if (i) insAbove(c);
        path.erase(path.find(sz[a]));
        above.insert(sz[a]);
    }
    above.erase(above.find(sz[a]));
    FOR(i,1,sz(adj[a])) {
        int c = adj[a][i];
        delAbove(c);
    }
    assert(sz(path)+sz(above) == n-sz[a]);
    if ((sz[a] != n)+sz(adj[a]) <= 1) {
        ans[a] = n-1;
    } else {
        if (n-sz[a] >= sz[adj[a][0]]) {
            /*if (a == 1) {
                ps("HA",n-sz[a],sz[adj[a][0]],sz[adj[a].back()],above,path,-sz[a]);
            }*/
            ans[a] = sz[adj[a][0]];
            int t = query(sz[adj[a].back()],n-sz[a],above);
            ckmin(t,query(sz[adj[a].back()],n-sz[a],path,-sz[a]));
            ckmax(ans[a],t);
        } else {
            ans[a] = n-sz[a]; if (sz(adj[a]) > 1) ckmax(ans[a],sz[adj[a][1]]);
            int mn = sz[adj[a].back()];
            if (n-sz[a]) ckmin(mn,n-sz[a]);
            /*if (a == 1) {
                ps("WUT",mn,sz[adj[a][0]],below[adj[a][0]],ans[a],query(mn,sz[adj[a][0]],below[adj[a][0]]));
            }*/
            ckmax(ans[a],query(mn,sz[adj[a][0]],below[adj[a][0]]));
        }
    }
    below[a].insert(sz[a]);
    if (sz(adj[a])) swap(below[a],below[adj[a][0]]);
    trav(x,adj[a]) {
        trav(y,below[x]) below[a].insert(y);
        below[x].clear();
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    setIO("A"); 
    #endif
    re(n);
    FOR(i,1,n+1) {
        int p,v; re(p,v);
        adj[par[v] = p].pb(v);
    }
    dfs1(adj[0][0]);
    dfs2(adj[0][0]);
    FOR(i,1,n+1) ps(ans[i]);
}


/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/