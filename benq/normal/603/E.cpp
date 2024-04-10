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

int n,m,odd;
int a[400001], b[400001], w[400001];

typedef struct snode* sn;

struct snode {
    //////// VARIABLES
    int val, sz = 0, vir = 0, mx = 0;
    sn p, c[2]; // parent, children
    bool flip = 0; 
    
    snode(int _val) {
        p = c[0] = c[1] = NULL;
        val = _val;
        if (val <= n) sz = 1;
    }
    
    /*friend int getSum(sn x) { return x?x->sum:0; }
    friend int getMn(sn x) { return x?x->mn:0; }
    friend int getMx(sn x) { return x?x->mx:0; }*/
    
    //////// SPLAY TREE OPERATIONS
    void prop() {
        if (!flip) return;
        swap(c[0],c[1]); 
        F0R(i,2) if (c[i]) c[i]->flip ^= 1;
        flip = 0; 
    }
    int bet(int a, int b) {
        if (min(a,b) == 0) return max(a,b);
        if (w[a] > w[b]) return a;
        return b;
    }
    void calc() { 
        F0R(i,2) if (c[i]) c[i]->prop();
        mx = (val > n ? val : 0);
        sz = (val <= n)+vir;
        F0R(i,2) if (c[i]) {
            mx = bet(mx,c[i]->mx);
            sz += c[i]->sz;
        }
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
            p->p->prop(), p->prop(), prop();
            dir() == p->dir() ? p->rot() : rot();
            rot();
        }
        if (!isRoot()) p->prop(), prop(), rot();
        prop();
    }

    //////// LINK CUT TREE BASE OPERATIONS
    void access() { // bring this to top of tree
        for (sn v = this, pre = NULL; v; v = v->p) {
            v->splay(); int a = v->sz;
            /*if (a == 2) {
                ps("??",v->label,v->vir,v->);
            }*/
            if (v->c[1]) v->vir += v->c[1]->sz;
            v->c[1] = pre; 
            if (v->c[1]) v->vir -= v->c[1]->sz;
            v->calc(); 
            if (a != v->sz) {
                exit(5);
                ps("HUH",v->val,a,v->vir,v->sz,v->c[0]==NULL,v->c[1]==NULL);
                exit(0);
            }
            pre = v;
        }
        splay(); assert(!c[1]); // left subtree of this is now path to root, right subtree is empty
    }
    void makeRoot() { access(); flip ^= 1; }
    
    //////// LINK CUT TREE QUERIES
    friend sn lca(sn x, sn y) {
        if (x == y) return x;
        x->access(), y->access(); if (!x->p) return NULL; // access at y did not affect x, so they must not be connected
        x->splay(); return x->p ? x->p : x;
    }
    friend bool connected(sn x, sn y) { return lca(x,y); }
    
    //////// LINK CUT TREE MODIFICATIONS
    friend bool link(sn x, sn y) { // make x parent of y
        if (connected(x,y)) return 0; // don't induce cycle
        y->makeRoot(); y->p = x; 
        x->access(); x->sz += y->sz; x->vir += y->sz;
        return 1; // success!
    }
    friend bool cut(sn x, sn y) { // x is originally parent of y
        x->makeRoot(); y->access(); 
        if (y->c[0] != x || x->c[0] || x->c[1]) return 0; // splay tree with y should not contain anything else besides x
        x->p = y->c[0] = NULL; y->calc(); return 1; // calc is redundant as it will be called elsewhere anyways?
    }
};

set<pi> ed;
sn S[400001];

void del(int x) {
    assert(cut(S[x],S[a[x]]));
    assert(cut(S[x],S[b[x]]));
    ed.erase({w[x],x});
}

void ins(int x) {
    assert(link(S[x],S[a[x]]));
    assert(link(S[x],S[b[x]]));
    // ps("WUT",x,a[x],b[x]);
    ed.insert({w[x],x});
}

int getMax(int a, int b) {
    if (!connected(S[a],S[b])) return 0;
    S[a]->makeRoot(); S[b]->access();
    return S[b]->mx;
}

bool ok(int x) {
    S[x]->makeRoot(); S[a[x]]->access();
    int res = 1+S[a[x]]->vir;
    if (S[a[x]]->c[1]) res += S[a[x]]->c[1]->sz;
    return res%2 == 0;
}

void updOdd(int x, int y) {
    S[x]->makeRoot();
    if (S[x]->sz%2 == 1) odd += y;
}

int main() {
    setIO(); re(n,m); odd = n;
    FOR(i,1,n+m+1) S[i] = new snode(i);
    F0R(i,m) {
        int ind = n+1+i;
        re(a[ind],b[ind],w[ind]);
        int x = getMax(a[ind],b[ind]);
        if (!x) {
            updOdd(a[ind],-1); updOdd(b[ind],-1);
            ins(ind); updOdd(a[ind],1); 
            // ps("HUH",a[ind],b[ind],S[a[ind]]->sz);
        } else if (w[x] > w[ind]) {
            del(x);
            ins(ind);
        }
        /*if (i == 1) {
            S[6]->makeRoot(); S[2]->access(); ps("??",S[2]->sz);
            ps(x,ed,ok(ed.rbegin()->s));
            exit(0);
        }*/
        while (!odd && ok(ed.rbegin()->s)) del(ed.rbegin()->s);
        /*ps("HA",i,odd,ed);
        exit(0);*/
        if (odd) ps(-1);
        else ps(ed.rbegin()->f);
    }
}


/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/