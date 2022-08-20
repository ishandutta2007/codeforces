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
const int MX = 1<<17;
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
    modular(const ll& v) { 
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular pow(modular a, ll p) {
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vl v = {1};
ll get(ll x) {
    auto it = lb(all(v),x);
    return (*it)-x;
}

ll ad(ll a, ll b) {
    if (max(a,b) == INF) return INF;
    return a+b;
}

ll sub(ll a, ll b) {
    if (a == INF) return a;
    return a-b;
}

template<class T, int SZ> struct LazySegTree {
    T val[SZ], lazy[2*SZ]; // set SZ to a power of 2
    pair<T,int> dif[2*SZ];
    
    void push(int ind, int L, int R) {
        if (!lazy[ind]) return;
        if (lazy[ind] == INF) dif[ind] = {INF,-1};
        else dif[ind].f = sub(dif[ind].f,lazy[ind]);
        if (L == R) {
            val[L] = ad(val[L],lazy[ind]);
        } else {
            lazy[2*ind] = ad(lazy[2*ind],lazy[ind]);
            lazy[2*ind+1] = ad(lazy[2*ind+1],lazy[ind]);
        }
        lazy[ind] = 0;
    }
    
    void pull(int ind) {
        dif[ind] = min(dif[2*ind],dif[2*ind+1]);
    }
    
    void build() {
        FORd(i,1,SZ) pull(i);
    }
    
    void inc(int lo, int hi, ll x, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = x;
            push(ind,L,R);
            return;
        }
        int M = (L+R)/2;
        inc(lo,hi,x,2*ind,L,M); inc(lo,hi,x,2*ind+1,M+1,R);
        pull(ind);
    }
    
    pair<T,int> qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return {INF,-1};
        if (lo <= L && R <= hi) return dif[ind];
        int M = (L+R)/2;
        return min(qmin(lo,hi,2*ind,L,M), qmin(lo,hi,2*ind+1,M+1,R));
    }
    
    void adjust(int pos, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (pos < L || R < pos) return;
        if (L == pos && R == pos) {
            assert(dif[ind].f < 0 && dif[ind].s == L);
            dif[ind].f = get(val[L]);
            return;
        }
        int M = (L+R)/2;
        adjust(pos,2*ind,L,M); adjust(pos,2*ind+1,M+1,R);
        pull(ind);
    }
    ll getVal(int pos, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (pos < L || dif[ind].f == INF) return INF;
        if (L == R) return val[L];
        int M = (L+R)/2;
        ll t = getVal(pos,2*ind+1,M+1,R); if (t != INF) return t;
        return getVal(pos,2*ind,L,M);
    }
    void upd(int pos, ll x, int ind = 1, int L = 0, int R = SZ-1) { // set value at pos equal to x
        assert(x != INF);
        push(ind,L,R); if (pos < L || R < pos) return;
        if (L == R) {
            val[L] = x;
            dif[ind] = {get(val[L]),L};
            return;
        }
        int M = (L+R)/2;
        upd(pos,x,2*ind,L,M); upd(pos,x,2*ind+1,M+1,R);
        pull(ind);
    }
};

LazySegTree<ll,MX> L;
int n,q;

void inc(int a, int b, int x) {
    L.inc(a,b,x);
    while (1) {
        pair<ll,int> t = L.qmin(a,b); assert(t.f != INF);
        if (t.f > 0) return;
        if (t.f < 0) L.adjust(t.s);
        else L.inc(a,b,x);
    }
}

void init() {
    setIO(); re(n,q);
    while ((ld)42*v.back() <= INF) v.pb(42*v.back());
    v.pop_back(); // ps(v);
    F0R(i,n) {
        int t; re(t);
        L.val[i] = t;
        L.dif[i^MX] = {get(t),i}; // store min seg, min dif 
    }
    L.build();
}

int main() {
    init();
    F0R(i,q) {
        int t; re(t);
        if (t == 1) {
            int ind; re(ind); ind --;
            ps(L.getVal(ind));
        } else if (t == 2) {
            int a,b,x; re(a,b,x); a--,b--;
            if (b+1 < n) L.upd(b+1,L.getVal(b+1));
            L.upd(a,x); L.inc(a+1,b,INF);
        } else {
            int a,b,x; re(a,b,x); a--,b--;
            if (b+1 < n) L.upd(b+1,L.getVal(b+1));
            L.upd(a,L.getVal(a));
            inc(a,b,x);
        }
    }
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/