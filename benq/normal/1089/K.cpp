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
typedef complex<double> cd;

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
const int MX = 300001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }


namespace treap {
    typedef struct tnode* pt;
    
    struct tnode {
        int pri; pt c[2]; // essential
        int sz; // for range queries
        int t, d; 
        ll ans, sum;
    
        tnode (int _t, int _d) {
            pri = rand()+(rand()<<15); c[0] = c[1] = NULL;
            sz = 1; 
            t = _t, d = _d, ans = t+d, sum = d;
        }
    };
    
    int getsz(pt x) { return x?x->sz:0; }
    ll getSum(pt x) { return x?x->sum:0; }
    ll getAns(pt x) { return x?x->ans:-INF; }
    
    /*void trav(pt x, vi& v) {
        if (!x) return;
        trav(x->c[0],v); v.pb(x->val); trav(x->c[1],v);
    }*/
    
    pt recalc(pt x) {
        x->sz = 1+getsz(x->c[0])+getsz(x->c[1]);
        x->sum = getSum(x->c[0])+x->d+getSum(x->c[1]);
        x->ans = max(getAns(x->c[0]),(ll)x->t)+x->d+getSum(x->c[1]);
        ckmax(x->ans,getAns(x->c[1]));
        return x;
    }
    
    pair<pt,pt> split(pt t, int v) { // >= v goes to the right
        if (!t) return {t,t};
        if (t->t >= v) {
            auto p = split(t->c[0], v); t->c[0] = p.s;
            return {p.f, recalc(t)};
        } else {
            auto p = split(t->c[1], v); t->c[1] = p.f;
            return {recalc(t), p.s};
        }
    }
    
    pair<pt,pt> splitsz(pt t, int sz) {
        if (!t) return {t,t};
        if (getsz(t->c[0]) >= sz) {
            auto p = splitsz(t->c[0], sz); t->c[0] = p.s;
            return {p.f, recalc(t)};
        } else {
            auto p = splitsz(t->c[1], sz-getsz(t->c[0])-1); t->c[1] = p.f;
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
    
    pt ins(pt x, int v, int d) { // insert v
        auto a = split(x,v), b = split(a.s,v+1);
        return merge(a.f,merge(new tnode(v,d),b.s));
    }
    
    pt del(pt x, int v) { // delete v
        auto a = split(x,v), b = split(a.s,v+1);
        return merge(a.f,b.s);
    }
}

using namespace treap;

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

int q, ti[MX];
pt root = NULL;

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(q);
    F0R(i,q) {
        char c; re(c);
        if (c == '+') {
            int t,d; re(t,d);
            root = ins(root,t,d);
            ti[i+1] = t;
        } else if (c == '-') {
            int t; re(t);
            root = del(root,ti[t]);
        } else {
            int t; re(t);
            auto a = split(root,t+1);
            cout << max((ll)t,getAns(a.f))-t << "\n";
            root = merge(a.f,a.s);
        }
    }
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/