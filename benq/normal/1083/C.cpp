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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 1<<18;
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
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    void re(cd& x) { ld a,b; re(a,b); x = cd(a,b); }
    
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
        int x = 31-__builtin_clz(r-l+1);
        return comb(stor[l][x],stor[r-(1<<x)+1][x]);
    }
};

template<int SZ> struct LCA {
    vi adj[SZ];
    RMQ<pi,2*SZ> r;
    vpi tmp;
    int depth[SZ], pos[SZ];
    
    int N, R = 1;
    
    void addEdge(int u, int v) {
        adj[u].pb(v), adj[v].pb(u);
    }
    
    void dfs(int u, int prev){
        pos[u] = sz(tmp); depth[u] = depth[prev]+1;
        tmp.pb({depth[u],u});
        for (int v: adj[u]) if (v != prev) {
            dfs(v, u);
            tmp.pb({depth[u],u});
        }
    }
    
    void init(int _N) {
    	N = _N;
        dfs(R, 0);
        r.build(tmp);
    }
    
    int lca(int u, int v){
        u = pos[u], v = pos[v];
        if (u > v) swap(u,v);
        return r.query(u,v).s;
    }
    
    int dist(int u, int v) {
        return depth[u]+depth[v]-2*depth[lca(u,v)];
    }
    
    bool onPath(int a, int b, int c) {
        return dist(a,c)+dist(c,b) == dist(a,b);
    }
};

LCA<MX> L;

template<class T, int SZ> struct Seg {
    T seg[2*SZ];
    
    Seg() {
        F0R(i,2*SZ) seg[i] = {0,0};
    }
    
    T comb(T a, T b) { 
        if (a == mp(0,0)) return b;
        if (b == mp(0,0)) return a;
        if (a == mp(-1,-1) || b == mp(-1,-1)) return mp(-1,-1);
        pair<int,pi> farthest = {-1,{-1,-1}};
        ckmax(farthest,{L.dist(a.f,a.s),{a.f,a.s}});
        ckmax(farthest,{L.dist(b.f,b.s),{b.f,b.s}});
        ckmax(farthest,{L.dist(a.f,b.f),{a.f,b.f}});
        ckmax(farthest,{L.dist(a.f,b.s),{a.f,b.s}});
        ckmax(farthest,{L.dist(a.s,b.f),{a.s,b.f}});
        ckmax(farthest,{L.dist(a.s,b.s),{a.s,b.s}});
        if (!L.onPath(farthest.s.f,farthest.s.s,a.f)) return {-1,-1};
        if (!L.onPath(farthest.s.f,farthest.s.s,a.s)) return {-1,-1};
        if (!L.onPath(farthest.s.f,farthest.s.s,b.f)) return {-1,-1};
        if (!L.onPath(farthest.s.f,farthest.s.s,b.s)) return {-1,-1};
        return farthest.s;
    } // easily change this to min or max
    
    void upd(int p, int value) {  // set value at position p
        for (seg[p += SZ] = {value,value}; p > 1; p >>= 1)
            seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]); // non-commutative operations
    }
    
    void build() {
        F0Rd(i,SZ) seg[i] = comb(seg[2*i],seg[2*i+1]);
    }
    
    int solve(int ind = 1, int l = 0, int r = MX-1, pi cur = {0,0}) {
        if (l == r) return l;
        //cout << "AH " << ind << " " << l << " " << r << " " << seg[ind] << "\n";
        //if (l != r) cout << "OOPS " << seg[2*ind] << "\n";
        int m = (l+r)/2;
        pi z = comb(cur,seg[2*ind]);
        if (z.f != -1) return solve(2*ind+1,m+1,r,z);
        return solve(2*ind,l,m,cur);
    }
};

Seg<pi,1<<18> S;

int n, p[MX];

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n); FOR(i,1,n+1) re(p[i]);
    FOR(i,2,n+1) {
        int d; re(d);
        L.addEdge(d,i);
    }
    L.init(n);
    FOR(i,1,n+1) S.upd(p[i],i);
    // cout << "AH " << p[5] << " " << S.seg[MX+3] << " " << S.seg[(MX+3)/2] << " " << S.seg[(MX+3)/4] << "\n";
    // cout << L.onPath(2,6,5) << "\n";
    int q; re(q);
    F0R(i,q) {
        int t; re(t);
        if (t == 1) {
            int x,y; re(x,y);
            swap(p[x],p[y]);
            S.upd(p[x],x), S.upd(p[y],y);
        } else {
            pr(min(S.solve(),n));
        }
    }
    
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/