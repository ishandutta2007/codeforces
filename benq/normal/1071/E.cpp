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

namespace point {
    typedef pd P;
    typedef vector<P> vP;

    P dir(ld ang) {
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
    
    P& operator+=(P& l, const P& r) { return l = l+r; }
    P& operator-=(P& l, const P& r) { return l = l-r; }
    P& operator*=(P& l, const ld& r) { return l = l*r; }
    P& operator/=(P& l, const ld& r) { return l = l/r; }
    P& operator*=(P& l, const P& r) { return l = l*r; }
    P& operator/=(P& l, const P& r) { return l = l/r; }
    
    P unit(P x) { return x/abs(x); }
    
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
    }
};

using namespace point;

vP convex_hull(vP P) {
    sort(all(P)); P.erase(unique(all(P)),P.end());
    int n = sz(P); if (n <= 1) return P;
    
    vP bot = {P[0]};
    FOR(i,1,n) {
        while (sz(bot) > 1 && cross(bot[sz(bot)-2], bot.back(), P[i]) <= 0) bot.pop_back();
        bot.pb(P[i]);
    }
    bot.pop_back();
    
    vP up = {P[n-1]};
    F0Rd(i,n-1) {
        while (sz(up) > 1 && cross(up[sz(up)-2], up.back(), P[i]) <= 0) up.pop_back();
        up.pb(P[i]);
    }
    up.pop_back();
    
    bot.insert(bot.end(),all(up)); return bot;
}

int n,w,h;
vP cur;
vP need[MX];
P e;
int ad;
ld speed;

vP getLine(ld a, ld b, ld c) {
    if (a == 0) return {{0,c/b},{1,c/b}};
    if (b == 0) return {{c/a,0},{c/a,1}};
    return {{c/a,0},{0,c/b}};
}

bool valid(ld x) {
    return 0 <= x && x <= w;
}

ld sim(ld a, ld b, ld c, ld d) {
    // a/b = (c-x)/(d-x)
    // a*(d-x) = b*(c-x)
    return (b*c-a*d)/(b-a);
}

bool getPoint(vP& a, P b, P c) {
    if (b.s == c.s) return 0;
    // x, 0 b.f, b.s c.f, c.s 
    // b.s/c.s=(b.f-x)/(c.f-x)
    // b.s*c.f-b.s*x = b.f*c.s-c.s*x 
    // (b.s-H)/(c.s-H) = (b.f-x)/(c.f-x)
    a = {{sim(b.s,c.s,b.f,c.f),sim(b.s-h,c.s-h,b.f,c.f)}};
    if (!valid(a[0].f) || !valid(a[0].s)) return 0;
    return 1;
}

const ld EPS = 1e-8;

bool in(vP a, P b) {
    ld x = area(a), y = 0;
    F0R(i,sz(a)) y += area({a[i],a[(i+1)%sz(a)],b});
    return y/x <= 1+EPS;
}

int sgn(ld x) {
    return x > 0;
}

void dumb(vP& v) {
    if (sz(v) <= 1) return;
    ld minX = INF, maxX = -INF, minY = INF, maxY = -INF;
    trav(t,v) {
        ckmin(minX,t.f); ckmax(maxX,t.f);
        ckmin(minY,t.s); ckmax(maxY,t.s);
    }
    if (maxY-minY > maxX-minX) {
        sort(all(v),[](auto a, auto b) { return a.s < b.s; });
    } else {
        sort(all(v),[](auto a, auto b) { return a.f < b.f; });
    }
}

P FOOT(P a, P b, P c) {
    if (b.f == c.f) return {b.f,a.s};
    return foot(a,b,c);
}

vP intersect(vP a, vP b) {
    assert(sz(b) == 2);
    vP res;
    F0R(i,sz(a)) {
        int j = (i+1)%sz(a);
        P z0 = FOOT(a[i],b[0],b[1]), z1 = FOOT(a[j],b[0],b[1]);
        if (abs(a[i]-z0) <= EPS) res.pb(z0);
        else if (abs(a[j]-z1) > EPS && sgn(cross(b[0],b[1],a[i])) != sgn(cross(b[0],b[1],a[j])))
            res.pb(extension(a[i],a[j],b[0],b[1]));
    }
    // ps("A",res);
    // ps("??",a,b,res); exit(0);
    dumb(res);
    // ps("B",res);
    while (sz(res) > 2) res.erase(res.begin()+1);
    return res;
}

P adjY(P a, P b, int c) {
    return {sim(c-a.s,c-b.s,a.f,b.f),c};
}

P adjX(P a, P b, int c) {
    swap(a.f,a.s); swap(b.f,b.s);
    auto z = adjY(a,b,c); swap(z.f,z.s);
    return z;
}

vP adjust(vP cur) {
    if (sz(cur) == 0) return cur;
    if (sz(cur) == 1) cur.pb(cur[0]);
    sort(all(cur));
    // ps("AA",cur);
    if (cur[0].f < 0) {
        if (cur[1].f < 0) return {};
        cur[0] = adjX(cur[0],cur[1],0);
    }
    // ps("BB",cur);
    if (cur[1].f > w) {
        if (cur[0].f > w) return {};
        cur[1] = adjX(cur[0],cur[1],w);
    }
    // ps("CC",cur);
    sort(all(cur),[](auto a, auto b) { return a.s < b.s; });
    if (cur[0].s < 0) {
        if (cur[1].s < 0) return {};
        // ps("??",cur[0],cur[1]);
        cur[0] = adjY(cur[0],cur[1],0);
        // ps("??",cur[0]);
    }
    // ps("DD",cur);
    if (cur[1].s > h) {
        if (cur[0].s > h) return {};
        cur[1] = adjY(cur[0],cur[1],h);
    }
    // ps("EE",cur);
    return cur;
}

bool process(vP v) {
    // a*(h-y)+b*y=h*x
    // 0 <= a,b <= w 
    if (!sz(v)) return 1;
    vP ok;
    if (sz(v) == 1) {
        if ((v[0].f == 0 || v[0].f == w) && v[0].s != 0 && v[0].s != h) ok.pb({v[0].f,v[0].f});
        else ok = getLine(h-v[0].s,v[0].s,h*v[0].f);
    } else {
        FOR(i,2,sz(v)) if (cross(v[0],v[1],v[i]) != 0) return 0;
        if (!getPoint(ok,v[0],v[1])) return 0; 
    }
    vP V; 
    trav(t,cur) {
        V.pb({t.f-ad*speed,t.s-ad*speed}); 
        V.pb({t.f-ad*speed,t.s+ad*speed});  
        V.pb({t.f+ad*speed,t.s-ad*speed}); 
        V.pb({t.f+ad*speed,t.s+ad*speed});   
    }
    // ps(speed,v,V);
    V = convex_hull(V); ad = 0;
    if (sz(ok) == 1) {
        if (!in(V,ok[0])) return 0;
        cur = {ok[0]}; return 1;
    }
    // ps(v,V);
    // ps("??",v,V,ok,cur); exit(0);
    // ps(cur);
    cur = intersect(V,ok); 
    // ps(cur);
    // ps("??",v,V,ok,cur); exit(0);
    cur = adjust(cur);
    // ps(cur); // exit(0);
    return sz(cur);
}

bool ok(ld _speed) {
    cur = {e}; speed = _speed; ad = 0;
    FOR(i,1,MX) {
        ad ++;
        if (!process(need[i])) return 0;
    }
    // ps("HA");
    return 1;
}

int main() {
	re(n,w,h,e); 
	F0R(i,n) {
	    int t,x,y; re(t,x,y);
	    need[t].pb({x,y});
	}
	/*ps(ok(0.01),ok(0.05),ok(1));
	exit(0);*/
	// ps(ok(2.2),ok(2.4),ok(2.6)); exit(0);
	// ok(1.05); exit(0);
	// ps(need[1],need[2],need[3]);
	
	/*ps(ok(2));
	exit(0);*/
	FOR(i,1,MX) {
	    sort(all(need[i]));
	    need[i].erase(unique(all(need[i])),need[i].end());
	}
	if (!ok(w+1)) {
	    ps(-1);
	    exit(0);
	}
	/*ps(ok(2));
	exit(0);*/
	// exit(0);
	/*ps(ok(2));
	exit(0);*/
	ld lo = 0, hi = w;
	F0R(i,30) {
	    ld mid = (lo+hi)/2;
	    // ps("??",mid,ok(mid));
	    if (ok(mid)) hi = mid;
	    else lo = mid;
	}
	cout << fixed << setprecision(6) << (lo+hi)/2;
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/