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

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

int n;
ll ans = 0;

struct tnode {
    int val, pri, sz;
    ll sum;
    tnode* c[2];

    tnode (int v) {
        val = sum = v, sz = 1, pri = rand()+(rand()<<15);
        c[0] = c[1] = NULL;
    }
};

typedef tnode* pt;

int getsz(pt x) { return x?x->sz:0; }
ll getsum(pt x) { return x?x->sum:0; }

void trav(pt x, vi& v) {
    if (!x) return;
    trav(x->c[0],v); v.pb(x->val); trav(x->c[1],v);
}

pt recalc(pt x) {
    x->sz = 1+getsz(x->c[0])+getsz(x->c[1]);
    x->sum = x->val+getsum(x->c[0])+getsum(x->c[1]);
    return x;
}

pair<pt,pt> split(pt t, int v) { // >= v goes to the right
    if (!t) return {t,t};
    
    if (v >= t->val) {
        auto p = split(t->c[0], v); 
        t->c[0] = p.s;
        return {p.f, recalc(t)};
    } else {
        auto p = split(t->c[1], v); 
        t->c[1] = p.f;
        return {recalc(t), p.s};
    }
}
    
pt merge(pt l, pt r) {
    if (!l) return r; 
    if (!r) return l;
    
    if (l->pri > r->pri) {
        l->c[1] = merge(l->c[1],r);
        return recalc(l);
    } else {
        r->c[0] = merge(l,r->c[0]);
        return recalc(r);
    }
}

pt root;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    
    // pair
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s;
        return is;
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}';
        return os;
    }
    
    // vector
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        int sz; is >> sz; a.resize(sz);
        F0R(i,sz) is >> a[i];
        return is;
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        os << "{";
        F0R(i,sz(a)) {
            if (i) os << ", ";
            os << a[i];
        }
        os << "}";
        return os;
    }
}

using namespace io;

map<int,pt> m;

pt ins(int a, pt b, int c) {
    auto t = split(b,c);
    ans += (ll)(a+getsz(t.f))*c+getsum(t.s);
    return merge(t.f,merge(new tnode(c),t.s));
}

pair<int,pt> merge(pair<int,pt> a, pair<int,pt> b) {
    //cout << "BOOO " << a.f << " " << b.f << " " << getsz(a.s) << " " << getsz(b.s) << "\n";
    if (getsz(a.s) < getsz(b.s)) {
        ans -= (b.f-a.f)*getsum(b.s);
        b.f = a.f;
        swap(a,b);
    }
    
    vi v; trav(b.s,v);
    F0R(i,sz(v)) ans -= (ll)v[i]*(b.f+i);
    
    for (int i: v) a.s = ins(a.f,a.s,i);
    return a;
}

void ad(int a, int b) {
    auto it = m.ub(a);
    pair<int,pt> cur = {a, new tnode(b)};
    
    if (it != m.begin()) {
        it = prev(it);
        if (it->f+getsz(it->s) >= a) {
            //cout << "HA " << it->f << " " << cur.f << "\n";
            cur = merge(*it,cur);
            //cout << getsz(cur.s) << "\n";
            //exit(0);
            m.erase(it);
            
        }
    }
    
    it = m.ub(a);
    if (it != m.end() && cur.f+getsz(cur.s) == it->f) {
        cur = merge(cur,*it);
        m.erase(it);
    }
    
    // cout << "AH " << cur.f << " " << getsz(cur.s) << "\n";
    m[cur.f] = cur.s;
    /*for (auto a: m) cout << a.f << " " << getsz(a.s) << " | ";
    cout << "\n";*/
}

int main() {
    setIO(); re(n);
    F0R(i,n) {
        int a,b; re(a,b);
        ad(a,b);
        cout << ans << "\n";
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/