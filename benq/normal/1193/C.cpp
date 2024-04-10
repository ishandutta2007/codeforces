//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

#define NDEBUG

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
        auto i = invGeneral(a.val,MOD); // assert(i != -1);
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

typedef ld T;

const T EPS = 1e-9;

namespace Point {
    typedef pair<T,T> P;
    typedef vector<P> vP;

    P dir(T ang) {
        auto c = exp(ang*complex<T>(0,1));
        return P(c.real(),c.imag());
    }
    
    T norm(P x) { return x.f*x.f+x.s*x.s; }
    T abs(P x) { return sqrt(norm(x)); }
    T angle(P x) { return atan2(x.s,x.f); }
    P conj(P x) { return P(x.f,-x.s); }
    
    P operator+(const P& l, const P& r) { return P(l.f+r.f,l.s+r.s); }
    P operator-(const P& l, const P& r) { return P(l.f-r.f,l.s-r.s); }
    P operator*(const P& l, const T& r) { return P(l.f*r,l.s*r); }
    P operator*(const T& l, const P& r) { return r*l; }
    P operator/(const P& l, const T& r) { return P(l.f/r,l.s/r); }
    P operator*(const P& l, const P& r) { return P(l.f*r.f-l.s*r.s,l.s*r.f+l.f*r.s); }
    P operator/(const P& l, const P& r) { return l*conj(r)/norm(r); }
    
    P& operator+=(P& l, const P& r) { return l = l+r; }
    P& operator-=(P& l, const P& r) { return l = l-r; }
    P& operator*=(P& l, const T& r) { return l = l*r; }
    P& operator/=(P& l, const T& r) { return l = l/r; }
    P& operator*=(P& l, const P& r) { return l = l*r; }
    P& operator/=(P& l, const P& r) { return l = l/r; }
    
    P unit(P x) { return x/abs(x); }
    T dot(P a, P b) { return (conj(a)*b).f; }
    T cross(P a, P b) { return (conj(a)*b).s; }
    T cross(P p, P a, P b) { return cross(a-p,b-p); }
    T dist(P p, P a, P b) { return std::abs(cross(p,a,b))/abs(a-b); }
    
    P rotate(P a, T b) { return a*P(cos(b),sin(b)); }
    P reflect(P p, P a, P b) { return a+conj((p-a)/(b-a))*(b-a); }
    P foot(P p, P a, P b) { return (p+reflect(p,a,b))/(T)2; }
    P extension(P a, P b, P c, P d) {
        T x = cross(a,b,c), y = cross(a,b,d);
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
    T area(const vP& v) {
        T area = 0;
        F0R(i,sz(v)) {
            int j = (i+1)%sz(v); T a = cross(v[i],v[j]);
            area += a;
        }
        return area/2;
    }
    P centroid(const vP& v) { 
        P cen(0,0); T area = 0; // 2*signed area
        F0R(i,sz(v)) {
            int j = (i+1)%sz(v); T a = cross(v[i],v[j]);
            cen += a*(v[i]+v[j]); area += a;
        }
        return cen/area/(T)3;
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

    pair<P,double> ccCenter(P a, P b, P c) { // circumcenter
        b -= a; c -= a;
        P res = b*c*(conj(c)-conj(b))/(b*conj(c)-conj(b)*c);
        return {a+res,abs(res)};
    }
     
    pair<P, double> mec(vP ps) { // minimum enclosing circle, ex. USACO Camp 2019 Contest 2 #4
        shuffle(all(ps), mt19937(time(0)));
        P o = ps[0]; double r = 0, EPS = 1 + 1e-8;
        F0R(i,sz(ps)) if (abs(o-ps[i]) > r*EPS) {
            o = ps[i], r = 0;
            F0R(j,i) if (abs(o-ps[j]) > r*EPS) {
                o = (ps[i]+ps[j])/2, r = abs(o-ps[i]);
                F0R(k,j) if (abs(o-ps[k]) > r*EPS) 
                    tie(o,r) = ccCenter(ps[i],ps[j],ps[k]);
            }
        }
        return {o,r};
    }
};

using namespace Point;

void inp(vP& v) {
    int x; re(x); v.rsz(x); re(v);
}

bool ccw(P a, P b, P c) {
    return cross(a,b,c) > 0;
}

vector<vP> triangulate(vP v) {
    if (sz(v) <= 2) return {};
    /*ps("HUH",area(v));
    int co = 0;
    trav(t,v) ps(t.f,t.s,co++);
    ps();*/
    F0R(i,sz(v)) {
        P a = v[i], b = v[(i+1)%sz(v)], c = v[(i+2)%sz(v)];
        if (ccw(a,b,c)) {
            bool bad = 0;
            trav(t,v) if (cross(a,b,t) > 0 && cross(b,c,t) > 0 && cross(c,a,t) > 0) 
                bad = 1;
            if (!bad) {
                auto V = v; V.erase(V.begin()+((i+1)%sz(v)));
                auto t = triangulate(V); t.pb({a,b,c});
                return t;
            }
        }
    }
    ps("BAD",v,ccw(v[0],v[1],v[2])); exit(0);
    exit(5);
}

vector<vP> v;
vP EN;
vector<bool> active;

void outp(vP& v) {
    pr(sz(v),' ');
    trav(t,v) pr(t.f,' ',t.s,' ');
    ps();
}

void init() {
    setIO(); cout << fixed << setprecision(12);
    v.rsz(1); inp(v[0]);
    active.pb(1);
    inp(EN); 
}

    
bool close(ld a, ld b) { return abs(a-b) <= EPS || min(abs(a),abs(b))/max(abs(a),abs(b)) >= 1-EPS; }

void scissors(int id, vector<vP> z) {
    // assert(id < sz(active) && active[id]);
    ps("scissors");
    ps(id,sz(z));
    active[id] = 0;
    ld tot = area(v[id]); // assert(tot > 0);
    trav(t,z) {
        tot -= area(t);
        outp(t);
        v.pb(t), active.pb(1);
    }
    // assert(abs(tot) <= EPS);
}

void testEquiv(vP a, vP b) {
    if (sz(a) != sz(b) || !close(area(a),area(b))) {
        ps("NOT EQUIV 1",area(a),area(b));
        ps(a);
        ps(b);
        exit(0);
    }
    F0R(i,sz(a)) {
        ld x = abs(a[i]-a[(i+1)%sz(a)]);
        ld y = abs(b[i]-b[(i+1)%sz(b)]);
        if (!close(x,y)) {
            ps("NOT EQUIV");
            ps(a); ps(b);
            exit(0);
        }
    }
}
int tape(vi id, vector<vP> c, vP z) {
    ps("tape");
    pr(sz(id),' '); 
    ld tot = 0;
    F0R(i,sz(id)) {
        int t = id[i];
        // assert(active[t]); active[t] = 0;
        pr(t,' ');
        
        testEquiv(v[t],c[i]);
        tot += area(v[t]);
    }
    ps();
    trav(t,c) outp(t);
    outp(z);
    v.pb(z), active.pb(1); 
    tot -= area(z);
    //// assert(abs(tot) <= EPS);
    return sz(active)-1;
}

set<int> done;

vP nor(vP V) {
    // ps("NOR");
    auto ori = V;
    // assert(sz(V) == 3);
    ld mx = max(abs(V[0]-V[1]),max(abs(V[1]-V[2]),abs(V[2]-V[0])));
    if (mx == abs(V[1]-V[2])) rotate(V.begin(),V.begin()+1,V.end());
    else if (mx == abs(V[2]-V[0])) rotate(V.begin(),V.begin()+2,V.end());
    FOR(i,1,3) V[i] -= V[0];
    V[0] = P(0,0);
    
    P x = P(abs(V[1]),0)/V[1];
    V[1] *= x, V[2] *= x; 
    
    //// assert(0 <= V[2].f && V[2].f <= V[1].f);
    //// assert(close(V[0].s,0) && close(V[1].s,0) && V[2].s > 0);
    return V;
}

ld equiv(vP a, vP b) {
    // assert(sz(a) == 3 && sz(b) == 3);
    ld dif = 0;
    F0R(i,3) {
        ld A = abs(a[i]-a[(i+1)%3]);
        ld B = abs(b[i]-b[(i+1)%3]);
        dif += abs(A-B);
    }
    return dif;
}

int same(int id, vP V) {
    ld dif0 = equiv(v[id],{V[0],V[1],V[2]});
    ld dif1 = equiv(v[id],{V[1],V[2],V[0]});
    ld dif2 = equiv(v[id],{V[2],V[0],V[1]});
    ld mn = min(dif0,min(dif1,dif2));
    if (dif0 == mn) id = tape({id},{{V[0],V[1],V[2]}},V);
    else if (dif1 == mn) id = tape({id},{{V[1],V[2],V[0]}},V);
    else id = tape({id},{{V[2],V[0],V[1]}},V);
    return id;
}

ld totArea,BLOCK;

int adjust(int id, ld dx, ld dy) {
    while (v[id][1].f >= 2*dx) {
        auto x = v[id][1].f, y = v[id][2].s;
        scissors(id,{{{0,0},{x/2,0},{x/2,y},{0,y}},
                    {{x/2,0},{x,0},{x,y},{x/2,y}}});
        id = tape({sz(active)-2,sz(active)-1},{
            {{0,0},{x/2,0},{x/2,y},{0,y}},
            {{0,y},{x/2,y},{x/2,2*y},{0,2*y}}
        },{{0,0},{x/2,0},{x/2,2*y},{0,2*y}});
    }
    if (v[id][1].f > dx) {
        auto x = v[id][1].f, y = v[id][2].s; 
        swap(dx,x); swap(dy,y); // // assert(y > dy);
        // ps("??",v[id],dx,dy);
        scissors(id,{
            {{{0,0},{x,0},{x,y-dy},{dx-x,dy},{0,dy}},
            {{x,0},{dx,0},{x,y-dy}},
            {{dx,0},{dx,dy},{dx-x,dy}}}
        });
        id = tape({sz(active)-3,sz(active)-2,sz(active)-1},
            {{{0,0},{x,0},{x,y-dy},{dx-x,dy},{0,dy}},
            {{0,dy},{dx-x,dy},{0,y}},
            {{x,y-dy},{x,y},{0,y}}},
            {{0,0},{x,0},{x,y},{0,y}}
        );
        swap(dx,x); swap(dy,y); 
    }
	while (2*v[id][1].f <= dx) {
        auto x = v[id][1].f, y = v[id][2].s;
        scissors(id,{{{0,0},{x,0},{x,y/2},{0,y/2}},
                    {{0,y/2},{x,y/2},{x,y},{0,y}}});
        id = tape({sz(active)-2,sz(active)-1},{
            {{0,0},{x,0},{x,y/2},{0,y/2}},
            {{x,0},{2*x,0},{2*x,y/2},{x,y/2}}
        },{{0,0},{2*x,0},{2*x,y/2},{0,y/2}});
	}
	if (v[id][1].f < dx) {
        auto x = v[id][1].f, y = v[id][2].s;
        scissors(id,{
            {{0,0},{x,0},{x,y-dy},{dx-x,dy},{0,dy}},
            {{0,dy},{dx-x,dy},{0,y}},
            {{x,y-dy},{x,y},{0,y}}
        });
        id = tape({sz(active)-3,sz(active)-2,sz(active)-1},{
            {{0,0},{x,0},{x,y-dy},{dx-x,dy},{0,dy}},
            {{x,0},{dx,0},{x,y-dy}},
            {{dx,0},{dx,dy},{dx-x,dy}}},
            {{0,0},{dx,0},{dx,dy},{0,dy}}
        );
	}
	return id;
}

int makeRect(int id) {
    //ps("MAKE RECT",id);
    auto V = nor(v[id]); id = same(id,V);
    
    vector<vP> w;
    P mid = P(V[2].f,V[2].s/2);
    w.pb({V[0],V[1],(V[1]+V[2])/2,(V[2]+V[0])/2});
    w.pb({(V[1]+V[2])/2,V[2],mid});
    w.pb({V[2],(V[2]+V[0])/2,mid});
    scissors(id,w);
    
    id = tape({sz(active)-3,sz(active)-2,sz(active)-1},
        {w[0],{(V[1]+V[2])/2,V[1],P(V[1].f,mid.s)},{V[0],(V[0]+V[2])/2,P(V[0].f,mid.s)}},
        {V[0],V[1],P(V[1].f,mid.s),P(V[0].f,mid.s)});
    
    //ps("ADJUST RECT");
    id = adjust(id,BLOCK,area(V)/BLOCK);
    return id;
}

int makeTri(int id, vP des) {
	auto V = nor(des);
	id = adjust(id,V[1].f,V[2].s/2);
	// assert(abs(v[id][1].f-V[1].f) <= EPS);
    P mid = P(V[2].f,V[2].s/2);
    vector<vP> w = {{V[0],V[1],(V[1]+V[2])/2,(V[2]+V[0])/2},
                    {(V[1]+V[2])/2,V[1],P(V[1].f,mid.s)},
                    {(V[0]+V[2])/2,P(V[0].f,mid.s),V[0]}};
    scissors(id,w);
    id = tape({sz(active)-3,sz(active)-2,sz(active)-1},
        {w[0],{(V[1]+V[2])/2,V[2],mid},{(V[2]+V[0])/2,mid,V[2]}},
        {V[0],V[1],V[2]});
	id = same(id,des); return id;
}

int main() {
    init();
    auto t0 = triangulate(v[0]), t1 = triangulate(EN);
    totArea = area(v[0]); BLOCK = sqrt(totArea);
    scissors(0,t0);
    
    ld totY = 0; int lst = -1;
    FOR(i,1,sz(t0)+1) {
        int t = makeRect(i); // assert(v[t][0] == P(0,0)); // assert(close(v[t][1].f,BLOCK));
        ld y = v[t][2].s;
        if (lst == -1) lst = t;
        else {
            lst = tape({lst,t},
            		{v[lst],{{0,totY},{BLOCK,totY},{BLOCK,totY+y},{0,totY+y}}},
            		{{0,0},{BLOCK,0},{BLOCK,totY+y},{0,totY+y}});
            lst = sz(active)-1;
        }
        totY += y;
    }
    vi sol;
    F0R(i,sz(t1)) {
        int id = -1;
        if (i == sz(t1)-1) {
            id = lst;
        } else {
            ld z = area(t1[i])/BLOCK; // assert(z > 0);
            scissors(lst,{{{0,0},{BLOCK,0},{BLOCK,totY-z},{0,totY-z}},
                            {{0,totY-z},{BLOCK,totY-z},{BLOCK,totY},{0,totY}}});
            lst = sz(active)-2; id = sz(active)-1; totY -= z;
            vP des = {{0,0},{BLOCK,0},{BLOCK,z},{0,z}};
            id = tape({id},{des},des);
        }
        sol.pb(makeTri(id,t1[i]));
    }
    vector<vP> SOL; trav(t,sol) SOL.pb(v[t]);
    tape(sol,SOL,EN);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/