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
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
}

using namespace io;

int totEdge;

vi cyc;

namespace splayTree {
    typedef struct snode* ps;

    struct snode {
        ps p, pp, c[2]; // essential
        int sz, ans, totsz, totans; // # nodes in subtree
        bool flip; // range flip 

        snode (int _sz) { 
            c[0] = c[1] = p = pp = NULL; 
            totsz = sz = _sz; 
            ans = totans = flip = 0;
        }
    };

    int getsz(ps x) { return x?x->totsz:0; }
    int getans(ps x) { return x?x->totans:0; }
    int getDir(ps x, ps y) { return x?(x->c[1] == y):-1; }

    /*void trav(ps x, vi& v) {
        if (!x) return;
        trav(x->c[0],v); v.pb(x->val); trav(x->c[1],v);
    }*/
    
    void prop(ps x) {
        if (!x || !x->flip) return; 
        x->totans = x->totsz-x->totans;
        x->ans = x->sz-x->ans;
        if (x->c[0]) x->c[0]->flip ^= 1;
        if (x->c[1]) x->c[1]->flip ^= 1;
        x->flip = 0;
    }
    
    ps recalc(ps x) {
        prop(x);
        prop(x->c[0]), prop(x->c[1]);
        x->totsz = x->sz+getsz(x->c[0])+getsz(x->c[1]);
        x->totans = x->ans+getans(x->c[0])+getans(x->c[1]);
        return x;
    }

    void setLink(ps x, ps y, int d) { // x propagated
        if (x) x->c[d] = y, recalc(x);
        if (y) y->p = x;
    }


    void pushDown(ps x) {
        if (!x) return;
        if (x->p) pushDown(x->p);
        prop(x);
    }

    void rot(ps x, int d) { // precondition: x & parents propagated
        snode *y = x->c[d], *z = x->p;
        prop(y);
        setLink(x, y->c[d^1], d);
        setLink(y, x, d^1);
        setLink(z, y, getDir(z, x));
        y->pp = x->pp; x->pp = NULL;
    }

    ps splay(ps x) {
        pushDown(x);
        while (x && x->p) {
            ps y = x->p, z = y->p;
            int dy = getDir(y, x), dz = getDir(z, y);
            if (!z) rot(y, dy);
            else if (dy == dz) rot(z, dz), rot(y, dy);
            else rot(y, dy), rot(z, dz);
        }
        return x;
    }
    
    ps getExtreme(ps x, int d) { // get leftmost or rightmost node
        prop(x);
        if (x->c[d]) return getExtreme(x->c[d],d);
        return splay(x);
    }
}

using namespace splayTree;

template<int SZ> struct LCT {
    ps S[SZ];
    LCT () { F0R(i,SZ) S[i] = new snode(1); }

    void dis(ps x, int d) { 
        ps y = x->c[d]; 
        if (x) x->c[d] = NULL, recalc(x);
        if (y) y->p = NULL, y->pp = x;
    }
    
    void con(ps x, int d) { setLink(x->pp,x,d); x->pp = NULL; }
    
    void setPref(ps x) { splay(x->pp), dis(x->pp,1), con(x,1); splay(x); }
    
    ps access(ps x) { // x is brought to the root of auxiliary tree
        dis(splay(x),1);
        while (x->pp) setPref(x);
        return x;
    }
    
    //////// UPDATES
    
    // ps makeRoot(ps v) { access(v)->flip = 1; return access(v); }
    
    int num = 0;
    
    void link(ps v, ps w) { 
        num ++;
        access(v);
        access(w)->pp = v;
        con(w,0); 
    }
    
    void cut(ps x) { // cut link between x and its parent
        ps y = access(x)->c[0];
        dis(x,0); y->pp = NULL;
    }
    
    //////// QUERIES
    
    int getDepth(ps v) { access(v); return getsz(v->c[0]); }
    
    int getRoot(ps v) { return getExtreme(access(v),0)->id; }
    
    int query(int x) {
        access(S[x]);
        prop(S[x]); prop(S[x]->c[0]); prop(S[x]->c[1]);
        return getans(S[x]->c[0])+S[x]->ans;
    }
    
    void flip(int x) {
        totEdge -= query(x);
        if (S[x]->c[0]) S[x]->c[0]->flip ^= 1;
        S[x]->ans = S[x]->sz-S[x]->ans; 
        recalc(S[x]);
        totEdge += query(x);
    }
    
    void flip(int a, int b) {
        // cout << "BLAH " << num << " " << a << " " << b << "\n";
        // cout <<
        flip(a); 
        // cout << query(1) << " " << query(2) << " " << query(3) << "\n"; 
        /*access(S[1]); cout << "1 " << S[1]->totsz << "\n"; //exit(0);
        access(S[2]); cout << "2 " << S[2]->totsz << "\n"; //exit(0);
        access(S[3]); cout << "3 " << S[3]->totsz << "\n"; //exit(0);*/
        // cout << totEdge << " " << cyc << " " << query(cyc.back()) << "\n";
        flip(b);
        // cout << totEdge << " " << cyc << " " << query(cyc.back()) << "\n";
    }
};

LCT<MX> A,B;

int n,m,comp[MX],par[MX];
bool inCyc[MX];
int cycInd[MX];
vi adj[MX];
pi ed;
int extraEdge;

void dfs(int x) {
    for (int y: adj[x]) if (y != par[x]) {
        if (par[y]) {
            if (ed.f == 0) ed = {x,y};
        } else {
            par[y] = x;
            dfs(y);
        }
    }
}

void dfs2(int x, int y) {
    comp[x] = y;
    trav(z,adj[x]) if (!inCyc[z] && !comp[z]) {
        // A.link(A.S[x],A.S[z]);
        A.link(A.S[z],A.S[x]);
        dfs2(z,y);
    }
}

void gen() {
    // you should actually read the stuff at the bottom
    setIO(); re(n,m);
    F0R(i,n) {
        int a,b; re(a,b);
        adj[a].pb(b), adj[b].pb(a);
    }
    par[1] = -1; dfs(1); 
    while (ed.f != ed.s) {
        cyc.pb(ed.f);
        ed.f = par[ed.f];
    }
    cyc.pb(ed.f); trav(x,cyc) inCyc[x] = 1;
    int co = 0;
    FOR(i,1,n+1) cycInd[i] = -1;
    trav(x,cyc) {
        cycInd[x] = co++;
        dfs2(x,x);
    }
    // FOR(i,1,n+1) pr(i,comp[i]);
    //pr(cyc);
    F0R(i,sz(cyc)-1) {
        //cout << "OOPS " << cyc[i+1] << " " << cyc[i] << "\n";
        B.link(B.S[cyc[i+1]],B.S[cyc[i]]);
    }
}

int getCyc(int ind) {
    ind = (ind%sz(cyc)+sz(cyc))%sz(cyc);
    return cyc[ind];
}

int cycEdge() {
    return B.query(cyc.back())+extraEdge;
}

void triCyc(int v, int u) {
    totEdge -= extraEdge;
    int d0 = abs(cycInd[v]-cycInd[u]);
    bool mode = 0;
    if (2*d0 > sz(cyc)) {
        mode = 1;
    } else if (2*d0 == sz(cyc)) {
        if (cycInd[v] > cycInd[u]) {
            if (getCyc(cycInd[v]+1) < getCyc(cycInd[v]-1)) mode = 1;
        } else {
            if (getCyc(cycInd[v]-1) < getCyc(cycInd[v]+1)) mode = 1;
        }
    }
    // cout << "AH " << d0 << " " << v << " " << u << " " << mode << " " << cyc << "\n";
    if (cycInd[v] > cycInd[u]) swap(u,v);
    if (mode == 0) {
        B.flip(v,u);
    } else {
        B.flip(cyc[0],v);
        B.flip(u,cyc.back());
        extraEdge ^= 1;
    }
    totEdge += extraEdge;
}

void flipPath(int v, int u) {
    if (comp[v] != comp[u]) {
        flipPath(v,comp[v]);
        triCyc(comp[v],comp[u]);
        flipPath(comp[u],u);
        return;
    } 
    A.flip(u,v);
}

int main() {
    gen();
    F0R(i,m) {
        int v,u; re(v,u);
        flipPath(v,u);
        pr(n-totEdge+(cycEdge() == sz(cyc)));
    }
    
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/