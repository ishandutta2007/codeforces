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

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 50001;

namespace io {
    // Source: StackOverflow
    
    template<class T> struct like_array : is_array<T>{};
    template<class T, size_t N> struct like_array<array<T,N>> : true_type{};
    template<class T> struct like_array<vector<T>> : true_type{};
    template<class T> bool is_like_array(const T& a) { return like_array<T>::value; }

    // I/O 
    
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // INPUT 
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s; return is;
    }
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        F0R(i,sz(a)) is >> a[i];
        return is;
    }
    
    // OUTPUT 
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}'; return os;
    }
    
    template<class T> ostream& printArray(ostream& os, const T& a, int SZ) {
        os << '{';
        F0R(i,SZ) {
            if (i) {
                os << ", ";
                if (is_like_array(a[i])) cout << "\n";
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
    
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
}

using namespace io;

int n,q, a[MX], par[MX], nex[MX], depth[MX];
vi adj[MX];

bitset<512> exists[MX];
int val[MX][256];

void checkmx(int& a, int b) { a = max(a,b); }

void dfs(int v) {
    for (int i: adj[v]) if (i != par[v]) {
        par[i] = v;
        depth[i] = depth[v]+1;
        dfs(i);
    }   
    nex[v] = v;
    F0R(i,256) {
        checkmx(val[v][a[nex[v]]>>8],(a[nex[v]]^i)&255);
        int ind = 1;
        F0Rd(j,8) {
            int b = (a[nex[v]]>>8>>j)&1;
            ind = 2*ind+b;
            exists[v][ind] = 1;
        }
        nex[v] = par[nex[v]];
    }
}

void init() {
    setIO(); re(n,q);
    FOR(i,1,n+1) {
        re(a[i]);
        // a[i] = rand() % 50000+1;
    }
    F0R(i,n-1) {
        int u,v; re(u,v);
        adj[u].pb(v), adj[v].pb(u);
    }
    depth[1] = 1;
    dfs(1);
}

int solve(int cur, int ad) {
    int ind = 1;
    F0Rd(i,8) {
        int b = (ad>>i)&1;
        if (exists[cur][2*ind+(b^1)]) b ^= 1;
        ind = 2*ind+b;
    }
    ind -= 256;
    return ((ad^ind)<<8)+val[cur][ind];
}

int query(int u, int v) {
    int cur = v, ans = 0, ad = 0;
    for (; depth[cur]-255 >= depth[u]; cur = nex[cur], ad ++) ans = max(ans,solve(cur,ad));
    for (; depth[cur] >= depth[u]; cur = par[cur]) ans = max(ans,a[cur]^(depth[v]-depth[cur]));
    return ans;
}

int main() {
    init();
   F0R(i,q) {
        int u,v; re(u,v);
        cout << query(u,v) << "\n";
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/