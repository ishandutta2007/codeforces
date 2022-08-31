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

template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modInt {
    T val;
    T mod = 0;
    // static const T mod = MOD;

    void normalize() {
        if (mod == 0) return;
        val %= mod; if (val < 0) val += mod;
    }
    modInt(T v = 0, T m = 0) : val(v), mod(m) { normalize(); }
    // modInt(T v = 0, T m = 0) : val(v) { normalize(); }

    explicit operator T() const { return val; }
    friend ostream& operator<<(ostream& os, const modInt& a) { return os << a.val; }
    friend bool operator==(const modInt& a, const modInt& b) { return a.val == b.val; }
    friend bool operator!=(const modInt& a, const modInt& b) { return !(a == b); }

    friend void check(modInt& a, modInt& b) { // make sure all operations are valid
        // comment out if mod is static const
        if (a.mod > 0 && b.mod > 0) { assert(a.mod == b.mod); return; }
        T mod = max(a.mod,b.mod); if (mod == 0) mod = MOD;
        if (a.mod != mod) { a.mod = mod; a.normalize(); }
        if (b.mod != mod) { b.mod = mod; b.normalize(); }
    }
    friend modInt operator+(modInt a, modInt b) {
        check(a,b); a.val += (T)b;
        if (a.val >= a.mod) a.val -= a.mod;
        return a;
    }
    friend modInt operator-(modInt a, modInt b) {
        check(a,b); a.val -= (T)b; 
        if (a.val < 0) a.val += a.mod; 
        return a;
    }
    friend modInt operator-(const modInt& a) { return modInt(0)-a; }

    friend modInt operator*(modInt a, modInt b) {
        check(a,b); a.val = (ll)a.val*(T)b%a.mod; return a;
    }
    friend modInt exp(modInt a, ll p) {
        modInt ans(1,a.mod);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modInt inv(const modInt& a) {
        return {invGeneral(a.val,a.mod),a.mod};
        // return exp(b,b.mod-2) if prime
    }
    friend modInt operator/(modInt a, modInt b) { 
        check(a,b); return a*inv(b); 
    }
};

typedef modInt<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

int n;
ll ans;

namespace point {
    typedef pl P;
    typedef vector<P> vP;

    P cis(ld ang) {
        cd c = exp(ang*cd(0,1));
        return P(c.real(),c.imag());
    }
    
    ld norm(P x) { return x.f*x.f+x.s*x.s; }
    ld abs(P x) { return sqrt(norm(x)); }
    ld angle(P x) { return atan2(x.s,x.f); }
    P conj(P x) { return P(x.f,-x.s); }
    
    P operator+(const P& l, const P& r) { return P(l.f+r.f,l.s+r.s); }
    P operator-(const P& l, const P& r) { return P(l.f-r.f,l.s-r.s); }
    P operator*(const P& l, const ld& r) { return P(l.f*r,l.s*r); }
    P operator*(const ld& l, const P& r) { return r*l; }
    P operator/(const P& l, const ld& r) { return P(l.f/r,l.s/r); }
    
    P operator*(const P& l, const P& r) { return P(l.f*r.f-l.s*r.s,l.s*r.f+l.f*r.s); }
    P operator/(const P& l, const P& r) { return l*conj(r)/norm(r); }
    
    P dir(P x) { return x/abs(x); }
    
    ld dot(P a, P b) { return (conj(a)*b).f; }
    ld cross(P a, P b) { return (conj(a)*b).s; }
    ld cross(P p, P a, P b) { return cross(a-p,b-p); }
    ld dist(P p, P a, P b) { return std::abs(cross(p,a,b))/abs(a-b); }
    
    P rotate(P a, ld b) { return a*P(cos(b),sin(b)); }
    P reflect(P p, P a, P b) { return a+conj((p-a)/(b-a))*(b-a); }
    P foot(P p, P a, P b) { return (p+reflect(p,a,b))/(ld)2; }
    P extension(P a, P b, P c, P d) {
        ld x = cross(a,b,c), y = cross(a,b,d);
        return (d*x-c*y)/(x-y);
    }
    // computes the intersection of line segments AB, CD
    // verification: https://open.kattis.com/problems/segmentintersection
    vP segIntersect(P a, P b, P c, P d) {
        if (a > b) swap(a,b);
        if (c > d) swap(c,d);
    
        auto a1 = cross(a,b,c), a2 = cross(a,b,d);
        if (a1 > a2) swap(a1,a2);
        if (!(a1 <= 0 && a2 >= 0)) return {};
    
        if (a1 == 0 && a2 == 0) {
            if (cross(a,c,d) != 0) return {};
            auto x1 = max(a,c), x2 = min(b,d);
            if (x1 > x2) return {};
            if (x1 == x2) return {x1};
            return {x1,x2};
        }
        
        auto z = extension(a,b,c,d);
        if (a <= z && z <= b) return {z};
        return {};
    }
    
    // sorts points according to atan2
    // verification: ?
    template<class T> int half(pair<T,T> x) { return mp(x.s,x.f) > mp((T)0,(T)0); }
    bool tri(P a, P b) { 
        return cross(a,b) > 0;
    }
    
    // computes the center of mass of a polygon with constant mass per unit area
    // verification: kattis polygonarea, VT HSPC 2018 Holiday Stars
    P centroid(vP v) { 
        P cen(0,0); ld area = 0;
        F0R(i,sz(v)) {
            int j = (i+1)%sz(v);
            ld a = cross(v[i],v[j]);
            cen += a*(v[i]+v[j]); area += a;
        }
        area /= (ld)2; // positive if ccw
        return cen/area/(ld)6;
    }

    // tests whether a point is inside, on, or outside the perimeter of any polygon
    // verification: https://open.kattis.com/problems/pointinpolygon
    string inPoly(vP p, P z) {
        int n = sz(p), ans = 0;
        F0R(i,n) {
            P x = p[i], y = p[(i+1)%n];
            if (cross(x,y,z) == 0 && min(x,y) <= z && z <= max(x,y)) return "on";
            if (x.s > y.s) swap(x,y);
            if (x.s <= z.s && y.s > z.s && cross(z,x,y) > 0) ans ^= 1;
        }
        return ans ? "in" : "out";
    }
};

using namespace point;

typedef array<ll,4> T;

T dp[2][300][300];
vP v;
vi ind[300];

T operator+(const T& l, const T& r) {
    T res = T();
    F0R(i,4) res[i] = l[i]+r[i];
    return res;
}

T shift(const T& x) {
    T res = T();
    F0R(i,3) res[i+1] = x[i];
    return res;
}

void conv(const T& l, const T& r) {
    F0R(i,4) ans += l[i]*r[3-i];
}

void solve(int x) {
    F0R(i,2) F0R(j,n) F0R(k,n) dp[i][j][k] = T();
    F0Rd(j,sz(ind[x])) {
        int t = ind[x][j];
        if (x < t) {
            dp[0][x][t][0] = 1;
            break;
        }
    }
    F0R(j,sz(ind[x])) {
        int t = ind[x][j];
        if (x < t) {
            dp[1][x][t][0] = 1;
            break;
        }
    }
    // if (x == 0) ps("??",dp[1][0][3]);
    FOR(i,x,sz(v)) {
        array<ll,4> a = array<ll,4>();
        F0Rd(j,sz(ind[i])) {
            int t = ind[i][j];
            if (t < i) a += shift(dp[0][t][i]);
            else {
                a += dp[0][i][t];
                dp[0][i][t] = a;
            }
        }
        a = array<ll,4>();
        F0R(j,sz(ind[i])) {
            int t = ind[i][j];
            // if (x == 0 && i == 0) ps("WWW",dp[1][i][t]);
            if (t < i) a += shift(dp[1][t][i]);
            else {
                a += dp[1][i][t];
                dp[1][i][t] = a;
            }
        }
        //if (x == 0 && i == 0) ps("WHATWHTA",dp[1][0][3]);
        T sum = T();
        F0Rd(j,sz(ind[i])) {
            int t = ind[i][j];
            if (t < i) {
                conv(sum,dp[0][t][i]);
                sum += dp[1][t][i];
            }
            // if (x == 0 && i == sz(v)-1) ps("WWR",i,t,dp[0][t][i],dp[1][t][i]);
        }
    }
    // if (x == 0) ps("WHAT",dp[1][0][3],dp[1][3][4],dp[0][0][1],dp[0][1][2],dp[0][2][4]);
}

P getVec(int a, int b) {
    if (a > b) swap(a,b);
    return v[b]-v[a];
}

int main() {
    setIO(); re(n); v.resz(n); re(v); sort(all(v));
    F0R(i,sz(v)) {
        F0R(j,sz(v)) if (i != j) ind[i].pb(j);
        sort(all(ind[i]),[&i](int a, int b) {
            return tri(getVec(i,a),getVec(i,b));
        });
    }
    /*ps(v);
    F0R(i,sz(v)) ps(ind[i]);*/
    F0R(i,sz(v)) solve(i);
    // exit(0);
    ps(ans);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/