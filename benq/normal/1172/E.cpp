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
const int MX = 400005;
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
    template<class U> modular(const U& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
 
    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular exp(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { return invGeneral(a.val,MOD); } 
    // inv is equivalent to return exp(b,b.mod-2) if prime
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
 
typedef struct snode* sn;
 
ll sq(ll x) { return x*x; }
 
struct snode {
    //////// VARIABLES
    int id; 
    int sz, szi = 0;
    ll sz2i = 0;
    sn p, c[2]; // parent, children
    
    snode(int _id) {
        id = _id;
        p = c[0] = c[1] = NULL;
        calc();
    }
    
    friend int getSz(sn x) { return x?x->sz:0; }
    
    //////// SPLAY TREE OPERATIONS
    void calc() {  
        sz = 1+szi+getSz(c[0])+getSz(c[1]);
    }
    int dir() {
        if (!p) return -2;
        F0R(i,2) if (p->c[i] == this) return i;
        return -1; // p is path-parent pointer, not in current splay tree
    }
    bool isRoot() { return dir() < 0; }
    
    friend void setLink(sn x, sn y, int d) {
        if (y) y->p = x;
        if (d >= 0) x->c[d] = y;
    }
    void rot() { // assume p and p->p propagated
        assert(!isRoot()); int x = dir(); sn pa = p;
        setLink(pa->p, this, pa->dir());
        setLink(pa, c[x^1], x);
        setLink(this, pa, x^1);
        pa->calc(); calc();
    }
    void splay() {
        while (!isRoot() && !p->isRoot()) {
            dir() == p->dir() ? p->rot() : rot();
            rot();
        }
        if (!isRoot()) rot();
        
    }
    int getRoot() {
        if (!c[0]) return id;
        return c[0]->getRoot();
    }
    
    //////// LINK CUT TREE BASE OPERATIONS
    void access() { // bring this to top of tree
        for (sn v = this, pre = NULL; v; v = v->p) {
            v->splay(); 
            int a = getSz(v->c[1]), b = getSz(pre); v->szi += a-b; v->sz2i += sq(a)-sq(b);
            v->c[1] = pre; v->calc();
            pre = v;
        }
        splay(); assert(!c[1]); // left subtree of this is now path to root, right subtree is empty
    }
    
    //////// LINK CUT TREE QUERIES
    friend sn lca(sn x, sn y) {
        if (x == y) return x;
        x->access(), y->access(); if (!x->p) return NULL; // access at y did not affect x, so they must not be connected
        x->splay(); return x->p ? x->p : x;
    }
    friend bool connected(sn x, sn y) { return lca(x,y); }
    
    //////// LINK CUT TREE MODIFICATIONS
    /*friend bool link(sn x, sn y) { // make y parent of x
        if (connected(x,y)) return 0; // don't induce cycle
        x->makeRoot(); x->p = y; return 1; // success!
    }
    friend bool cut(sn x, sn y) {
        x->makeRoot(); y->access(); 
        if (y->c[0] != x || x->c[0] || x->c[1]) return 0; // splay tree with y should not contain anything else besides x
        x->p = y->c[0] = NULL; y->calc(); return 1; // calc is redundant as it will be called elsewhere anyways?
    }*/
};
 
sn S[MX];
int n,m,par[MX],c[MX];
ll cans = 0;
ll cum[MX];
vi adj[MX];
vector<array<int,3>> mod[MX];
 
void dfs(int x) {
    trav(t,adj[x]) if (t != par[x]) {
        par[t] = x;
        dfs(t);
    }
}
 
void CUT(int x) {
    S[x]->access(); int z = S[x]->getRoot(); S[z]->access(); cans -= S[z]->sz2i;
    S[x]->access(); auto c = S[x]->c[0]; c->p = S[x]->c[0] = NULL; S[x]->calc(); cans += S[x]->sz2i;
    S[z]->access(); cans += S[z]->sz2i;
}
 
void LINK(int x) {
    S[x]->access(); cans -= S[x]->sz2i;
    int y = par[x]; S[y]->access();
    /*if (x == 3) {
        ps("AA",x);
        FOR(i,1,n+2) {
            ps(i,S[i]->sz,S[i]->szi,S[i]->sz2i);
            if (S[i]->p) ps("PAR",i,S[i]->p->id);
            F0R(j,2) if (S[i]->c[j]) ps("CHILD",i,j,S[i]->c[j]->id);
        }
        exit(0);
    }*/
    int z = S[y]->getRoot(); S[z]->access(); cans -= S[z]->sz2i;
    /*if (x == 2) {
        ps("??",x,z);
        FOR(i,1,n+2) {
            ps(i,S[i]->sz,S[i]->szi,S[i]->sz2i);
            if (S[i]->p) ps("PAR",i,S[i]->p->id);
            F0R(j,2) if (S[i]->c[j]) ps("CHILD",i,j,S[i]->c[j]->id);
        }
        exit(0);
    }
    ps("ST",z,S[z]->sz2i);
    if (x == 2) {
        FOR(i,1,n+2) {
            ps(i,S[i]->sz,S[i]->szi,S[i]->sz2i);
            if (S[i]->p) ps("PAR",i,S[i]->p->id);
            F0R(j,2) if (S[i]->c[j]) ps("CHILD",i,S[i]->c[j]->id);
        }
        exit(0);
    }*/
    S[y]->access(); S[y]->szi += S[x]->sz, S[y]->sz2i += sq(S[x]->sz); S[y]->calc(); S[x]->p = S[y];
    S[z]->access(); cans += S[z]->sz2i;
    /*if (x == 1) {
        FOR(i,1,n+2) {
            ps(i,S[i]->sz,S[i]->szi,S[i]->sz2i);
            if (S[i]->p) ps("PAR",i,S[i]->p->id);
            F0R(j,2) if (S[i]->c[j]) ps("CHILD",i,S[i]->c[j]->id);
        }
        exit(0);
    }*/
    // ps("WHAT",z,S[z]->sz2i);
}
 
void process(vector<array<int,3>>& v) {
    trav(t,v) { // n*n-sum(squares), starts out as 0 
        ll pans = cans;
        if (t[2] == -1) {
            LINK(t[1]);
        } else {
            CUT(t[1]);
        }
        cum[t[0]] += pans-cans;
        // ps("??",pans,cans);
    }
    /*F0R(i,m+1) ps(cum[i]);
    exit(0);*/
}
 
int main() {
	setIO(); re(n,m);
	FOR(u,1,n+1) {
	    re(c[u]);
	    mod[c[u]].pb({0,u,1});
	}
	F0R(i,n-1) {
	    int u,v; re(u,v);
	    adj[u].pb(v); adj[v].pb(u);
	}
	par[1] = n+1; dfs(1);
	FOR(i,1,n+2) S[i] = new snode(i);
	FOR(i,1,n+1) {
	    LINK(i);
	    // ps(i,par[i],cans);
	}
	// exit(0);
	FOR(i,1,m+1) {
	    int u,x; re(u,x);
	    mod[c[u]].pb({i,u,-1});
	    c[u] = x;
	    mod[c[u]].pb({i,u,1});
	}
	FOR(u,1,n+1) mod[c[u]].pb({m+1,u,-1});
	FOR(i,1,n+1) process(mod[i]);
	F0R(i,m+1) {
	    if (i) cum[i] += cum[i-1];
	    ps(cum[i]);
	}
    // you should actually read the stuff at the bottom
}
 
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/