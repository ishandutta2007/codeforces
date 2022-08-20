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

int MOD = 1000000007; // 998244353
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
    // int inv (int b, int mod = MOD) { return po(b,mod-2,mod); }
    
    int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
        a %= b; if (a == 0) return b == 1 ? 0 : -1;
        int x = invGeneral(b,a); 
        return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
    }
}

using namespace modOp;

vi stor[10], STOR[10];
vi pri;

typedef pair<int,vi> T;

T operator+=(T& l, const T& r) {
    MUL(l.f,r.f);
    F0R(i,sz(l.s)) l.s[i] += r.s[i];
    return l;
}

void reset(T& x) {
    x.f = 1;
    x.s.resz(sz(pri));
    trav(i,x.s) i = 0;
}

bool done(T& x) {
    if (x.f != 1) return 0;
    trav(i,x.s) if (i != 0) return 0;
    return 1;
}

T cat(int x) {
    T t; reset(t);
    F0R(i,sz(pri)) while (x % pri[i] == 0) {
        t.s[i] ++;
        x /= pri[i];
    }
    t.f = x%MOD;
    return t;
}

T flip(T t) {
    assert(__gcd(t.f,MOD) == 1);
    t.f = invGeneral(t.f,MOD);
    assert(t.f > 0);
    trav(i,t.s) i *= -1;
    return t;
}

int getPo(int a, int b) {
    return STOR[a][b];
    if (!sz(stor[a])) exit(13);
    if (b < 0) exit(99);
    
    while (sz(stor[a]) <= b) stor[a].pb(mul(stor[a].back(),pri[a]));
    assert(b < sz(stor[a]));
    if (stor[a][b] != STOR[a][b]) {
        ps("WHAT",a,b,pri[a],stor[a][b],STOR[a][b]);
        exit(0);
    }
    return stor[a][b];
}

template<int SZ> struct LazySegTree {
    int sum[2*SZ];
    T lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        memset (sum,0,sizeof sum);
        F0R(i,2*SZ) lazy[i].f = 0;
    }
    
    void push(int ind, int L, int R) { // multiply each
        if (L == R || done(lazy[ind])) return;
        MUL(sum[ind],lazy[ind].f); 
        if (sum[ind] < 0) pr("?????",ind,sum[ind],lazy[ind].f);
        F0R(i,sz(lazy[ind].s)) MUL(sum[ind],getPo(i,lazy[ind].s[i]));
        if (sum[ind] < 0) pr("?????",ind,sum[ind],lazy[ind].f);
        lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];
        reset(lazy[ind]);
    }
    
    int eval(int ind, int L, int R) {
        if (sum[ind] < 0) {
            ps("EVAL",ind,L,R,sum[ind]);
            exit(0);
        }
        if (L != R) return sum[ind];
        int t = lazy[ind].f; if (t < 0) exit(9);
        assert(sz(lazy[ind].s));
        F0R(i,sz(lazy[ind].s)) {
            MUL(t,getPo(i,lazy[ind].s[i]));
        }
        return t;
    }
    
    void pull(int ind, int L, int R) {
        int M = (L+R)/2;
        sum[ind] = ad(eval(2*ind,L,M),eval(2*ind+1,M+1,R));
        if (sum[ind] < 0) {
            ps("??",ind,sum[ind],eval(2*ind,L,M),eval(2*ind+1,M+1,R));
            exit(0);
        }
    }
    
    void build(vi& a, int ind, int L, int R) {
        reset(lazy[ind]);
        if (L == R) {
            if (L < sz(a)) lazy[ind] = cat(a[L]);
            else lazy[ind].f = 0;
            return;
        }
        int M = (L+R)/2;
        build(a,2*ind,L,M); build(a,2*ind+1,M+1,R);
        pull(ind,L,R);
        // if (sum[ind] != 0) ps("HUH",ind,L,R,sum[ind]);
    } // FIX
    
    int qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) {
            int t = eval(ind,L,R);
            if (t < 0) exit(5);
            return t;
        }
        int M = (L+R)/2;
        return ad(qsum(lo,hi,2*ind,L,M),qsum(lo,hi,2*ind+1,M+1,R));
    }
    
    void upd(int lo, int hi, const T& inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] += inc;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind,L,R);
    }
};

LazySegTree<1<<17> L;
vi a;
int n;

int getPo(int x) {
    int r = 100000,s = 0;
    while (r > 0) {
        r /= x; s ++;
    }
    return s;
}
int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n,MOD); a.resz(n); re(a);
    int tmp = MOD;
    for (int i = 2; i*i <= tmp; ++i) if (tmp % i == 0) {
        pri.pb(i); 
        while (tmp % i == 0) tmp /= i;
    }
    if (tmp > 1) pri.pb(tmp);
    F0R(i,sz(pri)) {
        stor[i] = {1};
        STOR[i] = {1}; FOR(j,1,2000001) STOR[i].pb(mul(pri[i],STOR[i].back()));
    }
    L.build(a,1,0,(1<<17)-1); 
    F0R(i,1<<18) if (L.sum[i] < 0) exit(1);
    int q; re(q);
    vi ans;
    F0R(i,q) {
        int t; re(t);
        if (t == 1) {
            int l,r,x; re(l,r,x);
            L.upd(l-1,r-1,cat(x));
        } else if (t == 2) {
            int p,x; re(p,x);
            L.upd(p-1,p-1,flip(cat(x)));
        } else {
            int l,r; re(l,r);
            ans.pb(L.qsum(l-1,r-1));
        }
    }
    trav(i,ans) cout << i << " ";
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/