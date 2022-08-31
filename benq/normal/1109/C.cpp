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
    
    template<class Arg> void ps(const Arg& first) { pr(first,"\n"); } // print w/ spaces
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); 
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

namespace modOp {
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

using namespace modOp;

namespace treap {
    typedef struct tnode* pt;
    
    struct tnode {
        int pri; pt c[2]; // essential
        ll ct, cs;
        pl T; ll S;
        ll mn, tot;
    
        tnode (int t, int s) {
            pri = rand()+(rand()<<15); c[0] = c[1] = NULL;
            ct = t, cs = s;
            T = {t,t}; S = s;
            mn = tot = 0;
        }
    };
    
    ll getmn(pt x) {
        if (!x) return 2*INF;
        return x->mn;
    }
    
    void tour(pt x, vi& v) {
        if (!x) return;
        tour(x->c[0],v); v.pb(x->ct); tour(x->c[1],v);
    }
    
    pt recalc(pt x) {
        x->T.f = x->c[0]?x->c[0]->T.f:x->ct; x->T.s = x->c[1]?x->c[1]->T.s:x->ct;
        x->S = x->c[1]?x->c[1]->S:x->cs;
        
        x->mn = x->tot = 0;
        if (x->c[0]) {
            ckmin(x->mn,x->tot+x->c[0]->mn);
            x->tot += x->c[0]->tot;
            x->tot += x->c[0]->S*(x->ct-x->c[0]->T.s); 
            ckmin(x->mn,x->tot);
        }
        if (x->c[1]) {
            x->tot += x->cs*(x->c[1]->T.f-x->ct);
            ckmin(x->mn,x->tot);
            ckmin(x->mn,x->tot+x->c[1]->mn);
            x->tot += x->c[1]->tot;
        }
        
        return x;
    }
    
    pair<pt,pt> split(pt t, int v) { // >= v goes to the right
        if (!t) return {t,t};
        if (t->ct >= v) {
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
    
    pt ins(pt x, int t, int s) { // insert v
        auto a = split(x,t);
        return merge(a.f,merge(new tnode(t,s),a.s));
    }
    
    pt del(pt x, int t) { // delete v
        auto a = split(x,t), b = split(a.s,t+1);
        return merge(a.f,b.s);
    }
    
    ld solve(int ti, int rate, ll tot) {
        //ps("TT",ti,rate,tot,-(ld)tot/rate+ti);
        return -(ld)tot/rate+ti;
    }
    
    ld fst(pt x, ll v) {
        if (!x) return 2*INF;
        if (v+getmn(x->c[0]) <= 0) return fst(x->c[0],v);
        ll tot = 0;
        if (x->c[0]) {
            tot += x->c[0]->tot;
            tot += x->c[0]->S*(x->ct-x->c[0]->T.s);
        }
        if (v+tot <= 0) return solve(x->c[0]->T.s,x->c[0]->S,x->c[0]->tot+v);
        if (x->c[1]) {
            ll tmp = tot; tot += x->cs*(x->c[1]->T.f-x->ct);
            if (tot+v <= 0) return solve(x->ct,x->cs,tmp+v);
            if (tot+v+x->c[1]->mn <= 0) return fst(x->c[1],tot+v);
        }
        return 2*INF;
    }
}

using namespace treap;

pt root = NULL;
int q;

ld query(int l, int r, int v) {
    if (v == 0) return l;
    auto a = split(root,l); auto b = split(a.s,r+1);
    ld ans = fst(b.f,v);
    if (b.f && ans > r) {
        ll fin = v+b.f->tot+b.f->S*(r-b.f->T.s);
        if (fin <= 0) ckmin(ans,solve(b.f->T.s,b.f->S,v+b.f->tot));
    }
    root = merge(a.f,merge(b.f,b.s));
    if (ans > r) ans = -1;
    return ans;
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(q);
    cout << fixed << setprecision(8);
    F0R(i,q) {
        int z; re(z);
        if (z == 1) {
            int t,s; re(t,s);
            root = ins(root,t,s);
        } else if (z == 2) {
            int t; re(t);
            root = del(root,t);
        } else {
            // ps(getmn(root));
            int l,r,v; re(l,r,v);
            ps(query(l,r,v));
        }
    }
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/