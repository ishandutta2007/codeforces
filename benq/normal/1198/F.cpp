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

namespace factorBasic {
    template<class T> vector<pair<T,int>> factor(T x) { // x <= 10^{14} is fine
        vector<pair<T,int>> pri;

        for (T i = 2; i*i <= x; ++i) if (x % i == 0) {
            int t = 0;
            while (x % i == 0) x /= i, t ++;
            pri.pb({i,t});
        }

        if (x > 1) pri.pb({x,1});
        return pri;
    }

    /* Note:
     * number of operations needed s.t.
     *                phi(phi(...phi(n)...))=1
     * is O(log n).
     * Euler's theorem: a^{\phi(p)}\equiv 1 (mod p), gcd(a,p)=1
     */

    ll phi(ll x) {
        trav(a,factor(x)) x /= a.f, x *= a.f-1;
        return x;
    }

    template<class T> void tour(vector<pair<T,int>>& v, vector<T>& V, int ind, T cur) {
        if (ind == sz(v)) V.pb(cur);
        else {
            T mul = 1;
            F0R(i,v[ind].s+1) {
                tour(v,V,ind+1,cur*mul);
                mul *= v[ind].f;
            }
        }
    }

    template<class T> vector<T> getDivi(T x) {
        auto v = factor(x);
        vector<T> V; tour(v,V,0,(T)1); sort(all(V));
        return V;
    }
}

using namespace factorBasic;

int n;

template<class T, int SZ> struct RMQ {
    constexpr static int level(int x) { return 31-__builtin_clz(x); } // floor(log_2(x))
    int stor[SZ][level(SZ)+1];
    vector<T> v;
    
    int comb(int a, int b) { return __gcd(a,b); } 
    
    void init(const vector<T>& _v) {
        v = _v; F0R(i,sz(v)) stor[i][0] = v[i];
        FOR(j,1,level(sz(v))+1) F0R(i,sz(v)-(1<<(j-1))) 
            stor[i][j] = comb(stor[i][j-1],stor[i+(1<<(j-1))][j-1]);
    }
    
    int getNex(int ind, int x) {
        F0Rd(j,17) if (ind+(1<<j) <= n && stor[ind][j]%x == 0) ind += 1<<j;
        if (ind == n) return ind;
        assert(stor[ind][0]%x != 0);
        return ind;
    }
};

RMQ<int,MX> RM;

void dumb(int& x) {
    auto a = factor(x);
    x = 1; trav(t,a) x *= t.f;
}

vi a;
vi L, R;

void fin() {
    //
    //ps("??",L,R);
    set<int> LL, RR;
    trav(t,L) LL.insert(t);
    trav(t,R) RR.insert(t);
    ps("YES");
    F0R(i,n) {
        if (LL.count(i)) pr(1);
        else pr(2);
        pr(' ');
    }
    exit(0);
}

void dfs(int x, int y, int ind) {
    if (x == 1 && y == 1) fin();
    if (ind == n) return;
    ind = min(RM.getNex(ind,x),RM.getNex(ind,y)); if (ind == n) return;
    int gx = __gcd(x,a[ind]), gy = __gcd(y,a[ind]); 
    assert(x != gx || y != gy);
    if (x != gx) {
        L.pb(ind);
        dfs(gx,y,ind+1);
        L.pop_back();
    }
    if (y != gy) {
        R.pb(ind);
        dfs(x,gy,ind+1);
        R.pop_back();
    }
}

void cool(int x, int y, int ind) {
    R.pb(ind); dfs(x,y,ind+1); R.pop_back();
}

int main() {
    setIO(); re(n); a.rsz(n); re(a); RM.init(a);
    dumb(a[0]); 
    int x = a[0]; L.pb(0);
    FOR(i,1,n) {
        dumb(a[i]);
        cool(x,a[i],i);
        if (a[i] % x == 0) break;
        x = __gcd(x,a[i]); L.pb(i);
    }
    ps("NO");
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/