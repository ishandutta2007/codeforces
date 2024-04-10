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
const int MX = 200005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

template<class A, class B> A operator+=(A& l, const B& r) { return l = l+r; }
template<class A, class B> A operator-=(A& l, const B& r) { return l = l-r; }
template<class A, class B> A operator*=(A& l, const B& r) { return l = l*r; }
template<class A, class B> A operator/=(A& l, const B& r) { return l = l/r; }

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
        bool fst = 1; trav(a,x) pr(!fst?", ":"",a), fst = 0; 
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); } 
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

namespace splayTree {
    typedef struct snode* sn;

    struct snode {
        int val, sz; // value, # nodes in subtree
        sn p, pp, c[2]; // parent, path-parent (for LCT), children
        bool flip; // for range flip 

        snode (int val) : val(val) { 
            sz = 1;
            p = pp = c[0] = c[1] = NULL; 
            flip = 0;
        }
    };

    int getsz(sn x) { return x ? x->sz : 0; }
    int dir(sn x, sn y) { return x ? (x->c[1] == y) : -1; }
    sn recalc(sn x) {
        x->sz = 1+getsz(x->c[0])+getsz(x->c[1]);
        return x;
    }
    void prop(sn x) {
        if (!x || !x->flip) return; 
        swap(x->c[0],x->c[1]);
        if (x->c[0]) x->c[0]->flip ^= 1;
        if (x->c[1]) x->c[1]->flip ^= 1;
        x->flip = 0;
    }
    void propAnc(sn x) { // propagate all ancestors
        if (!x) return;
        if (x->p) propAnc(x->p);
        prop(x);
    }
    void tour(sn x, vi& v) {
        if (!x) return;
        tour(x->c[0],v); v.pb(x->val); tour(x->c[1],v);
    }

    void setLink(sn x, sn y, int d) { // x propagated
        if (x) x->c[d] = y, recalc(x);
        if (y) y->p = x;
    }
    void rot(sn x, int d) { // precondition: x & parents propagated
        sn y = x->c[d], z = x->p; prop(y); 
        setLink(x, y->c[d^1], d);
        setLink(y, x, d^1);
        setLink(z, y, dir(z, x));
        y->pp = x->pp; x->pp = NULL; // set y to be parent of x
    }
    sn splay(sn x) {
        propAnc(x);
        while (x && x->p) {
            sn y = x->p, z = y->p;
            int dy = dir(y, x), dz = dir(z, y);
            if (!z) rot(y, dy);
            else if (dy == dz) rot(z, dz), rot(y, dy);
            else rot(y, dy), rot(z, dz);
        }
        return x;
    }
    sn farthest(sn x, int d) { // get leftmost or rightmost node
        prop(x); return x->c[d]?farthest(x->c[d],d):splay(x);
    }
}

using namespace splayTree;

template<int SZ> struct LCT {
    sn S[SZ];
    LCT () { F0R(i,SZ) S[i] = new snode(i); }

    // disconnect x from d-th child
    void dis(sn x, int d) { 
        sn y = x->c[d]; 
        if (x) x->c[d] = NULL, recalc(x);
        if (y) { y->p = NULL; if (d) y->pp = x; }
    }
    // set x to be child of pp
    void makeChild(sn x) { setLink(x->pp,x,1); x->pp = NULL; } 
    // unlink x->pp from its preferred child, then set x to be preferred child 
    void setPref(sn x) { splay(x->pp), dis(x->pp,1), makeChild(x), splay(x); } 
    // x is brought to the root of auxiliary tree
    sn access(sn x) { dis(splay(x),1); while (x->pp) setPref(x); return x; }
    
    //////// UPDATES
    
    sn makeRoot(sn v) { access(v)->flip = 1; return access(v); }
    // make y the parent of x
    void link(sn x, sn y) { makeRoot(x)->pp = y; }
    // cut link between x and its parent
    void cut(sn x) { dis(access(x),0); }
    
    //////// QUERIES
    
    int getDepth(sn x) { access(x); return getsz(x->c[0]); }
    sn getRoot(sn x) { return farthest(access(x),0); }
    sn lca(sn x, sn y) {
        sn root = getRoot(y); 
        if (farthest(splay(x),0) == root) return x;
        while (splay(x)->pp) {
            if (farthest(splay(x->pp),0) == root) return x->pp;
            setPref(splay(x));
        }
        return NULL;
    }
};

LCT<MX> L;


template<int SZ> struct LazySegTree {
    pi mn[2*SZ];
    int lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        memset (mn,0,sizeof mn);
        memset (lazy,0,sizeof lazy);
        F0R(i,SZ) mn[i+SZ] = {-i,1};
        FORd(i,1,SZ) pull(i);
    }
    
    void push(int ind, int L, int R) {
        mn[ind].f += lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
    
    pi comb(pi a, pi b) {
        if (a.f != b.f) return min(a,b);
        return {a.f,a.s+b.s};
    }
    
    void pull(int ind) {
        mn[ind] = comb(mn[2*ind],mn[2*ind+1]);
    }

    pi qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return {MOD,0};
        if (lo <= L && R <= hi) return mn[ind];
        int M = (L+R)/2;
        return comb(qmin(lo,hi,2*ind,L,M), qmin(lo,hi,2*ind+1,M+1,R));
    }
    
    void upd(int lo, int hi, ll inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};

LazySegTree<1<<18> LL;
int n,m, f[1000][1000];
pi pos[MX];
int l = 1, r = 0;

int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0};

bool same(int a, int b) {
    return L.getRoot(L.S[a]) == L.getRoot(L.S[b]);
}

bool valid(pi p) {
    return 0 <= p.f && p.f < n && 0 <= p.s && p.s < m;
}

bool badLink() {
    vi ed;
    F0R(i,4) {
        pi p = {pos[r+1].f+xd[i],pos[r+1].s+yd[i]};
        if (!valid(p) || f[p.f][p.s] < l || f[p.f][p.s] > r) continue;
        ed.pb(f[p.f][p.s]);
    }
    F0R(i,sz(ed)) {
        if (same(ed[i],r+1)) {
            L.makeRoot(L.S[r+1]);
            F0R(j,i) L.cut(L.S[ed[j]]);
            return 1;
        }
        L.link(L.S[ed[i]],L.S[r+1]);
    }
    r ++;
    return 0;
}

void inc() {
    L.makeRoot(L.S[l]);
    F0R(i,4) {
        pi p = {pos[l].f+xd[i],pos[l].s+yd[i]};
        if (!valid(p) || f[p.f][p.s] < l || f[p.f][p.s] > r) continue;
        L.cut(L.S[f[p.f][p.s]]);
    }
    l ++;
}

int main() {
    setIO(); re(n,m);
    F0R(i,n) F0R(j,m) {
        re(f[i][j]);
        pos[f[i][j]] = {i,j};
    }
    ll ans = 0;
    FOR(i,1,n*m+1) {
        while (badLink()) inc();
        assert(r == i);
        F0R(i,4) {
            pi p = {pos[r].f+xd[i],pos[r].s+yd[i]};
            if (!valid(p) || f[p.f][p.s] > r) continue;
            LL.upd(0,f[p.f][p.s],-1);
        }
        // FOR(j,l,i+1) ps(i,j,LL.qmin(j,j));
        auto t = LL.qmin(l,i); t.f += i;
        if (t.f == 0) ans += t.s;
    }
    ps(ans);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/