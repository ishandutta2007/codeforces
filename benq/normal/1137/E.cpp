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

namespace treap {
    typedef struct tnode* pt;
    
    struct tnode {
        int pri; pt c[2]; // essential
        pair<int,ll> val, leftVal, rightVal;
        pair<pl,int> mn;
    
        tnode (int a, ll b) {
            pri = rand()+(rand()<<15); c[0] = c[1] = NULL;
            val = leftVal = rightVal = {a,b};
            mn = {{INF,0},MOD};
        }
    };
    
    void tour(pt x, vi& v) {
        if (!x) return;
        tour(x->c[0],v); v.pb(x->val.f); tour(x->c[1],v);
    }
    
    pair<pl,int> bes(pair<pl,int> a, pair<pl,int> b) {
        if (a.f.s == 0) return b;
        if (b.f.s == 0) return a;
        assert(a.f.f >= 0 && b.f.f >= 0 && a.f.s > 0 && b.f.s > 0);
        ll A = (a.f.f+a.f.s-1)/a.f.s, B = (b.f.f+b.f.s-1)/b.f.s;
        if (A < B) return a;
        return b;
    }
    
    void comp(pair<pl,int>& a, const pair<pl,int>& b) {
        a = bes(a,b);
    }
    
    pair<pl,int> calc(pair<int,ll> l, pair<int,ll> r) {
        return {{l.s-r.s,r.f-l.f},r.f};
    }
    
    pt recalc(pt x) {
        x->leftVal = x->rightVal = x->val; x->mn = {{INF,0},MOD};
        if (x->c[0]) {
            x->leftVal = x->c[0]->leftVal;
            comp(x->mn,x->c[0]->mn);
            comp(x->mn,calc(x->c[0]->rightVal,x->val));
        }
        if (x->c[1]) {
            x->rightVal = x->c[1]->rightVal;
            comp(x->mn,x->c[1]->mn);
            comp(x->mn,calc(x->val,x->c[1]->leftVal));
        }
        return x;
    }
    
    pair<pt,pt> split(pt t, int v) { // >= v goes to the right
        if (!t) return {t,t};
        if (t->val.f >= v) {
            auto p = split(t->c[0], v); t->c[0] = p.s;
            return {p.f, recalc(t)};
        } else {
            auto p = split(t->c[1], v); t->c[1] = p.f;
            return {recalc(t), p.s};
        }
    }
    
    pt merge(pt l, pt r) {
        if (!l || !r) return l ? l : r;
        pt t;
        if (l->pri > r->pri) l->c[1] = merge(l->c[1],r), t = l;
        else r->c[0] = merge(l,r->c[0]), t = r;
        return recalc(t);
    }
    
    pt ins(pt x, int a1, ll a2) { // insert v
        auto a = split(x,a1);
        return merge(a.f,merge(new tnode(a1,a2),a.s));
    }
    
    pt del(pt x, int v) { // delete v
        auto a = split(x,v), b = split(a.s,v+1);
        return merge(a.f,b.s);
    }
    
    pt getRight(pt x) {
        if (x->c[1]) return getRight(x->c[1]);
        return x;
    }
}

using namespace treap;

pt root = new tnode(0,0);
int n,m;
pl cadd;

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n,m);
    F0R(i,m) {
        int t; re(t);
        if (t == 1) {
            root = new tnode(0,0); cadd = {0,0};
            int k; re(k); n += k;
            // {0,0}
        } else if (t == 2) {
            root = merge(root,new tnode(n,-cadd.f*n-cadd.s));
            int k; re(k); n += k;
        } else {
            int b,s; re(b,s);
            cadd.s += b; cadd.f += s;
        }
        while (1) {
            auto a = root->mn; // pl, int 
            if (a.f.f <= a.f.s*cadd.f) root = del(root,a.s);
            else break;
        }
        auto z = getRight(root);
        ps(z->val.f+1,z->val.s+cadd.f*z->val.f+cadd.s);
        // exit(0);
    }
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/