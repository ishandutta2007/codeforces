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
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 100001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace io {
    // TYPE ID (StackOverflow)
    
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
    
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest);
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
    
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
    
    // OUTPUT 
    
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
    template<class T> ostream& operator<<(ostream& os, const set<T>& a) {
        os << vector<T>(all(a)); return os;
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {
        os << vector<pair<T1,T2>>(all(a)); return os;
    }
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
}

using namespace io;

/*namespace modOp {
    int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
    int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
    int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }
    
    int AD(int& a, int b, int mod = MOD) { return a = ad(a,b,mod); }
    int SUB(int& a, int b, int mod = MOD) { return a = sub(a,b,mod); }
    int MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }
    
    int po (int b, int p, int mod = MOD) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
    int inv (int b, int mod = MOD) { return po(b,mod-2,mod); }
    
    int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
        if (a == 0) return b == 1 ? 0 : -1;
        int x = invGeneral(b%a,a); 
        return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
    }
}

using namespace modOp;*/



vi tour;
int n, gen[MX], f[MX];
ll ans[MX];

bool used[MX];
int cnt[MX][2];
vector<array<int,4>> todo;

bool cmp(array<int,4> a, array<int,4> b) { // sort queries
    int block = sqrt(n);
    if (a[0]/block != b[0]/block) return a[0] < b[0];
    return a[1] < b[1];
}

int l = 0, r = -1;
ll cans = 0;

void ad(int x) {
    x = tour[x];
    if (used[x]) {
        cans -= cnt[f[x]][gen[x]^1];
        cnt[f[x]][gen[x]] --;
    } else {
        cans += cnt[f[x]][gen[x]^1];
        cnt[f[x]][gen[x]] ++;
    }
    // if condition: cans --;
    // if condition: cans ++;
    used[x] ^= 1;
}

int answer(int L, int R) { // adjust interval
    while (l > L) ad(--l);
    while (r < R) ad(++r);
    while (l < L) ad(l++);
    while (r > R) ad(r--);
    return cans;
}

template<int SZ> struct LCA {
    const int MAXK = 32-__builtin_clz(SZ);
    
    int N, R = 1; // vertices from 1 to N, R = root
    vi adj[SZ];
    int par[32-__builtin_clz(SZ)][SZ], depth[SZ];
    vi oc[SZ];
    
    void addEdge(int u, int v) {
        adj[u].pb(v), adj[v].pb(u);
    }
    
    void addTour(int x) {
        oc[x].pb(sz(tour));
        tour.pb(x);
    }
    
    void dfs(int u, int prev){
        addTour(u);
        par[0][u] = prev;
        depth[u] = depth[prev]+1;
        for (int v: adj[u]) if (v != prev) dfs(v, u);
        addTour(u);
    }
    
    void init(int _N) {
    	N = _N;
        dfs(R, 0);
        FOR(k,1,MAXK) FOR(i,1,N+1)
            par[k][i] = par[k-1][par[k-1][i]];
    }
    
    int lca(int u, int v){
        if (depth[u] < depth[v]) swap(u,v);
        
        F0Rd(k,MAXK) if (depth[u] >= depth[v]+(1<<k))  u = par[k][u];
        F0Rd(k,MAXK) if (par[k][u] != par[k][v]) u = par[k][u], v = par[k][v];
        
        if(u != v) u = par[0][u], v = par[0][v];
        return u;
    }
    
    int dist(int u, int v) {
        return depth[u]+depth[v]-2*depth[lca(u,v)];
    }
};

LCA<MX> L;

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n); 
    FOR(i,1,n+1) re(gen[i]);
    map<int,int> m;
    FOR(i,1,n+1) {
        re(f[i]);
        m[f[i]] = 0;
    }
    int co = 0;
    trav(x,m) x.s = co++;
    FOR(i,1,n+1) f[i] = m[f[i]];
    F0R(i,n-1) {
        int a,b; re(a,b);
        L.addEdge(a,b);
    }
    L.init(n);
    int q; re(q);
    F0R(i,q) {
        int a,b; re(a,b);
        int x = L.lca(a,b);
        if (x == b) swap(a,b);
        if (x == a) todo.pb({L.oc[a][0],L.oc[b][0],i,-1});
        else {
            if (L.oc[a][1] > L.oc[b][0]) swap(a,b);
            assert(L.oc[a][1] < L.oc[b][0]);
            todo.pb({L.oc[a][1],L.oc[b][0],i,x});
        }
    }
    sort(all(todo),cmp);
    trav(x,todo) {
        answer(x[0],x[1]);
        ans[x[2]] = cans;
        if (x[3] != -1) ans[x[2]] += cnt[f[x[3]]][gen[x[3]]^1];
    }
    F0R(i,q) pr(ans[i]);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/