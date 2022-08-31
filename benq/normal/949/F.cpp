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

pi BAD = {583918,105930};

namespace point {
    typedef pi P;
    typedef vector<P> vP;

    /*P dir(ld ang) {
        cd c = exp(ang*cd(0,1));
        return P(c.real(),c.imag());
    }
    
    ld norm(P x) { return x.f*x.f+x.s*x.s; }
    ld abs(P x) { return sqrt(norm(x)); }
    ld angle(P x) { return atan2(x.s,x.f); }
    P conj(P x) { return P(x.f,-x.s); }*/
    
    P operator+(const P& l, const P& r) { return P(l.f+r.f,l.s+r.s); }
    P operator-(const P& l, const P& r) { return P(l.f-r.f,l.s-r.s); }
    P& operator+=(P& l, const P& r) { return l = l+r; }
    P& operator-=(P& l, const P& r) { return l = l-r; }
    /*P operator*(const P& l, const ld& r) { return P(l.f*r,l.s*r); }
    P operator*(const ld& l, const P& r) { return r*l; }
    P operator/(const P& l, const ld& r) { return P(l.f/r,l.s/r); }
    P operator*(const P& l, const P& r) { return P((ll)l.f*r.f-l.s*r.s,l.s*r.f+l.f*r.s); }
    P operator/(const P& l, const P& r) { return l*conj(r)/norm(r); }
    
    P& operator*=(P& l, const ld& r) { return l = l*r; }
    P& operator/=(P& l, const ld& r) { return l = l/r; }
    P& operator*=(P& l, const P& r) { return l = l*r; }
    P& operator/=(P& l, const P& r) { return l = l/r; }
    
    P unit(P x) { return x/abs(x); }*/
    
    ll cross(P a, P b) { return (ll)a.f*b.s-(ll)a.s*b.f; }
    ll cross(P p, P a, P b) { return cross(a-p,b-p); }
    
    /*P rotate(P a, ld b) { return a*P(cos(b),sin(b)); }
    P reflect(P p, P a, P b) { return a+conj((p-a)/(b-a))*(b-a); }
    P foot(P p, P a, P b) { return (p+reflect(p,a,b))/(ld)2; }*/
    
    P extension(P a, P b, P c, P d) {
        ll x = cross(a,b,c), y = cross(a,b,d);
        ll dif = x-y; if (dif == 0) return BAD;
        ll z0 = (ll)d.f*x-(ll)c.f*y, z1 = (ll)d.s*x-(ll)c.s*y;
        if (z0%dif != 0 || z1%dif != 0) return BAD;
        z0 /= dif, z1 /= dif;
        if (std::abs(z0) > 1000000 || std::abs(z1) > 1000000) return BAD;
        return {z0,z1};
    }
    
    // computes the intersection of line segments AB, CD
    // verification: https://open.kattis.com/problems/segmentintersection
    /*vP segIntersect(P a, P b, P c, P d) {
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
    bool cmp(P a, P b) { 
        int A = half(a), B = half(b);
        if (A != B) return A < B;
        return cross(a,b) > 0;
    }
    
    // computes the center of mass of a polygon with constant mass per unit area
    // verification: kattis polygonarea, VT HSPC 2018 Holiday Stars
    ld area(const vP& v) {
        ld area = 0;
        F0R(i,sz(v)) {
            int j = (i+1)%sz(v); ld a = cross(v[i],v[j]);
            area += a;
        }
        return std::abs(area)/2;
    }
    P centroid(const vP& v) { 
        P cen(0,0); ld area = 0; // 2*signed area
        F0R(i,sz(v)) {
            int j = (i+1)%sz(v); ld a = cross(v[i],v[j]);
            cen += a*(v[i]+v[j]); area += a;
        }
        return cen/area/(ld)3;
    }
    
    // tests whether a point is inside, on, or outside the perimeter of any polygon
    // verification: https://open.kattis.com/problems/pointinpolygon
    string inPoly(const vP& p, P z) {
        int n = sz(p), ans = 0;
        F0R(i,n) {
            P x = p[i], y = p[(i+1)%n];
            if (cross(x,y,z) == 0 && min(x,y) <= z && z <= max(x,y)) return "on";
            if (x.s > y.s) swap(x,y);
            if (x.s <= z.s && y.s > z.s && cross(z,x,y) > 0) ans ^= 1;
        }
        return ans ? "in" : "out";
    }*/
};

using namespace point;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(ll x) const {
        return splitmix64(x);
    }
};

// typedef map<ll,int> ht; // ,custom_hash

ll nor(P b) {
    assert(abs(b.f) <= 2000000 && abs(b.s) <= 2000000);
    int g = __gcd(b.f,b.s); b.f /= g, b.s /= g;
    ckmin(b,{-b.f,-b.s});
    return 2000005*b.f+b.s;
}

bool ok(vl& a, P b) {
    ll B = nor(b);
    int lo = 0, hi = sz(a);
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (a[mid] >= B) hi = mid;
        else lo = mid+1;
    }
    if ((lo < sz(a) && a[lo] == B) && (lo == sz(a) || a[lo+1] != B)) return 1;
    return 0;
}

int n;
vi v[5200];
vpi p;
clock_t beg = clock();

P dif(P a, P b) {
    a -= b; ckmin(a,{-a.f,-a.s});
    return a;
}

bool cmp(const P& a, const P& b) {
    if (a == mp(0,0)) return 1;
    if (b == mp(0,0)) return 0;
    return (ll)a.f*b.s > (ll)a.s*b.f;
}

P DIF[5200];

void init() {
    srand(18953); 
    // n = 2600; 
    re(n); 
    p.resz(2*n); F0R(i,2*n) p[i] = {rand() % 1000000, rand() % 1000000};
    re(p);
    v[0].resz(2*n); F0R(i,2*n) v[0][i] = i;
    FOR(i,1,2*n) v[i] = v[0];
    F0R(i,2*n) {
        F0R(j,2*n) DIF[j] = dif(p[i],p[j]);
        sort(all(v[i]),[](int a, int b) {
            return cmp(DIF[a],DIF[b]);
        });
    }
}

bool eq(pi a, pi b) {
    return (ll)a.f*b.s == (ll)a.s*b.f;
}

bool ok (int a, P b) {
    if (b == mp(0,0)) return 0;
    int l = 0, r = 2*n-1;
    while (l < r) {
        int m = (l+r)/2;
        if (cmp(dif(p[a],p[v[a][m]]),b)) l = m+1;
        else r = m; // 1,1,1,0,0,0 
    }
    return l && eq(dif(p[a],p[v[a][l]]),b) && (l+1 == 2*n || !eq(dif(p[a],p[v[a][l+1]]),b));
    // return ????;
}

void tri(int a, int b, int c, int d) {
    auto z = extension(p[a],p[b],p[c],p[d]); if (z == BAD) return;
    F0R(i,sz(p)) if (!ok(i,dif(z,p[i]))) return;
    ps("Yes"); ps(z.f,z.s); exit(0);
}

int main() {
    init();
    FOR(i,2,2*n) FOR(j,2,2*n) if (i != j) tri(0,i,1,j);
    FOR(i,3,2*n) tri(0,1,2,i);
    ps("No");
    // ps(double(clock()-beg)/CLOCKS_PER_SEC);
    // you should actually read the stuff at the bottom
}