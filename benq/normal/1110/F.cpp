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
const int MX = 1<<19;
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

template<class T, int SZ> struct RMQ {
    T stor[SZ][32-__builtin_clz(SZ)];
    
    T comb(T a, T b) {
        return min(a,b);
    }
    
    void build(vector<T>& x) {
        F0R(i,sz(x)) stor[i][0] = x[i];
        FOR(j,1,32-__builtin_clz(SZ)) F0R(i,SZ-(1<<(j-1))) 
            stor[i][j] = comb(stor[i][j-1],
                        stor[i+(1<<(j-1))][j-1]);
    }
    
    T query(int l, int r) {
        if (l > r) return INF;
        int x = 31-__builtin_clz(r-l+1);
        return comb(stor[l][x],stor[r-(1<<x)+1][x]);
    }
};

template<class T, int SZ> struct Seg {
    T seg[2*SZ], MN = INF;
    
    Seg() {
        F0R(i,2*SZ) seg[i] = INF;
    }
    
    T comb(T a, T b) { return min(a,b); } // easily change this to min or max
    
    void upd(int p, T value) {  // set value at position p
        for (seg[p += SZ] = value; p > 1; p >>= 1)
            seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]); // non-commutative operations
    }
    
    void build() {
        F0Rd(i,SZ) seg[i] = comb(seg[2*i],seg[2*i+1]);
    }
    
    T query(int l, int r) {  // sum on interval [l, r]
        T res1 = MN, res2 = MN; r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) res1 = comb(res1,seg[l++]);
            if (r&1) res2 = comb(seg[--r],res2);
        }
        return comb(res1,res2);
    }
};

RMQ<ll,MX> R;
Seg<ll,MX> lef, ri, cur;

int n,q,depth[MX];
ll dist[MX],ans[MX];
int p[MX], w[MX], par[MX][20];
pi res[MX];
vi child[MX];
vector<array<int,3>> query[MX];

/*int manual(int x, int a, int l, int r) {
    
}*/

void gen(int x) {
    res[x] = {x,x};
    par[x][0] = p[x];
    FOR(i,1,20) par[x][i] = par[par[x][i-1]][i-1];
    for (int i: child[x]) {
        gen(i);
        res[x].s = res[i].s;
    }
}

ll manual(int x, int l, int r) {
    ckmax(l,res[x].f);
    ckmin(r,res[x].s);
    return R.query(l,r)-2*dist[x];
}

int leftExceed(int x, int l) {
    F0Rd(i,20) if (l < res[par[x][i]].f) x = par[x][i];
    if (l < res[x].f) x = par[x][0];
    return x;
}

int rightExceed(int x, int r) {
    F0Rd(i,20) if (res[par[x][i]].s < r) x = par[x][i];
    if (res[x].s < r) x = par[x][0];
    return x;
    
}

ll smth(int x, int l, int r) {
    if (r < res[x].f) {
        F0Rd(i,20) {
            int t = par[x][i];
            if (r < res[t].f) x = t;
        }
        x = par[x][0];
    }
    if (res[x].s < l) {
        F0Rd(i,20) {
            int t = par[x][i];
            if (res[t].s < l) x = t;
        }
        x = par[x][0];
    }
    int a = leftExceed(x,l), b = rightExceed(x,r);
    ll t = min(manual(a,l,r), manual(b,l,r));
    if (depth[a] > depth[b]) {
        ckmin(t,min(cur.query(depth[a]+1,depth[x]),ri.query(depth[b]+1,depth[a]-1)));
    } else {
        ckmin(t,min(cur.query(depth[b]+1,depth[x]),lef.query(depth[a]+1,depth[b]-1)));
    }
    // pr("HI",x,l,r,a,b,t,cur.query(depth[b]+1,depth[x]),lef.query(depth[a]+1,depth[b]),manual(a,l,r));
    return t;
    // depth[a]+1 to depth[x] -> cur 
    // depth[b]+1 to depth[a] -> right 
    // depth[b] -> manual
    
}

void solve(int x) {
    cur.upd(depth[x],manual(x,res[x].f,res[x].s));
    //pr(x,manual(x,res[x].f,res[x].s));
    trav(a,query[x]) ans[a[2]] = dist[x]+smth(x,a[0],a[1]);
    for (int i: child[x]) {
        lef.upd(depth[x],manual(x,res[x].f,res[i].f-1));
        ri.upd(depth[x],manual(x,res[i].s+1,res[x].s));
        solve(i);
    }
}

void init() {
    setIO(); re(n,q);
    FOR(i,2,n+1) {
        re(p[i],w[i]);
        child[p[i]].pb(i);
        depth[i] = depth[p[i]]+1;
        dist[i] = dist[p[i]]+w[i];
    }
    vl dists = {INF};
    FOR(i,1,n+1) {
        if (!sz(child[i])) dists.pb(dist[i]);
        else dists.pb(INF);
    }
    R.build(dists);
    gen(1);
}

int main() {
    // you should actually read the stuff at the bottom
    init();
    // FOR(i,1,n+1) pr(i,res[i],dist[i],par[i][1]);
    res[0] = {-MOD,MOD};
    F0R(i,q) {
        int v,l,r; re(v,l,r);
        query[v].pb({l,r,i});
    }
    // pr(R.query(1,2), R.query(1,1));
    solve(1);
    F0R(i,q) pr(ans[i]);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/