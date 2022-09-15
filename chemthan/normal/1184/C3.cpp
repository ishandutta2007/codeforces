#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() {return abs((int) mt());}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

#define double double
#define EPS 1e-9
struct point_t {
    double x, y;
    point_t() : x(0), y(0) {}
    point_t(double x, double y) : x(x), y(y) {}
    point_t(const point_t& p) : x(p.x), y(p.y) {}
    int operator < (const point_t& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
    int operator == (const point_t& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
    point_t operator + (const point_t& p) const {return point_t(x + p.x, y + p.y);}
    point_t operator - (const point_t& p) const {return point_t(x - p.x, y - p.y);}
    point_t operator * (double c) const {return point_t(x * c, y * c);}
    point_t operator / (double c) const {return point_t(x / c, y / c);}
};
double cross(point_t p, point_t q) {return p.x * q.y - p.y * q.x;}
double area(point_t a, point_t b, point_t c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
double area2(point_t a, point_t b, point_t c) {return cross(a, b) + cross(b, c) + cross(c, a);}
double dot(point_t p, point_t q) {return p.x * q.x + p.y * q.y;}
double dist(point_t p, point_t q) {return sqrt(dot(p - q, p - q));}
double dist2(point_t p, point_t q) {return dot(p - q, p - q);}
point_t RotateCCW90(point_t p) {return point_t(-p.y, p.x);}
point_t RotateCW90(point_t p) {return point_t(p.y, -p.x);}
point_t RotateCCW(point_t p, double t) {return point_t(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));}
int sign(double x) {return x < -EPS ? -1 : x > EPS;}
int sign(double x, double y) {return sign(x - y);}
ostream& operator << (ostream& os, const point_t& p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}
point_t ProjectPointLine(point_t a, point_t b, point_t c) {
    return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
double DistancePointLine(point_t a, point_t b, point_t c) {
    return dist(c, ProjectPointLine(a, b, c));
}
point_t ComputeLineIntersection(point_t a, point_t b, point_t c, point_t d) {
    b = b - a; d = c - d; c = c - a;
    return a + b * cross(c, d) / cross(b, d);
}
struct Line {
    point_t l, r;
    Line() {}
    Line(point_t l, point_t r) : l(l), r(r) {}
    Line(const Line& rhs) : l(rhs.l), r(rhs.r) {}
};
Line Bisector(point_t a, point_t b) {
    point_t c = (a + b) / 2;
    return Line(c, c + RotateCCW90(b - c));
}
struct Circle {
    point_t cen;
    double rad;
    Circle() : rad(0) {}
    Circle(point_t cen, double rad) : cen(cen), rad(rad) {}
    Circle(const Circle& rhs) : cen(rhs.cen), rad(rhs.rad) {}
    int operator < (const Circle& rhs) const {
        return rad < rhs.rad;
    }
};
Circle CircumCircle(point_t a, point_t b, point_t c) {
    if (sign(cross(a - c, b - c)) == 0) {
        Circle res = Circle((a + b) / 2, dist(a, b) / 2);
        res = max(res, Circle((b + c) / 2, dist(b, c) / 2));
        res = max(res, Circle((c + a) / 2, dist(c, a) / 2));
        return res;
    }
    Line ln1 = Bisector(a, b);
    Line ln2 = Bisector(b, c);
    point_t cen = ComputeLineIntersection(ln1.l, ln1.r, ln2.l, ln2.r);
    return Circle(cen, dist(cen, a));
}

void chemthan() {
    int k, n; cin >> k >> n;
    vector<point_t> pts(n * k);
    for (point_t& p : pts) cin >> p.x >> p.y;
    vector<Circle> res;
    auto calc = [&] (Circle c) {
        int cnt = 0;
        FOR(i, 0, sz(pts)) {
            double d = dist(c.cen, pts[i]);
            if (abs(d - c.rad) < 5e4) {
                cnt++;
            }
        }
        if (!cnt) return 1e9;
        return abs(cnt - (double) sz(pts) / (k - sz(res)));
    };
    FOR(it, 0, k) {
        vector<pair<double, Circle>> candidates;
        FOR(it, 0, 1000) {
            int u = mrand() % sz(pts);
            int v = mrand() % sz(pts);
            int w = mrand() % sz(pts);
            if (5e4 < dist(pts[u], pts[v]) &&
                    5e4 < dist(pts[v], pts[w]) &&
                    5e4 < dist(pts[w], pts[u])) {
                Circle c = CircumCircle(pts[u], pts[v], pts[w]);
                candidates.pb(mp(calc(c), c));
            }
        }
        sort(all(candidates));
        Circle tmp;
        for (auto e : candidates) {
            Circle c = e.se;
            int found = 0;
            for (Circle cc : res) {
                double d = dist(c.cen, cc.cen);
                if (d < 0.1 * 600000) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                tmp = c;
                break;
            }
        }
        res.pb(tmp);
        FORd(i, sz(pts), 0) {
            double d = dist(pts[i], res.back().cen);
            if (abs(d - res.back().rad) < 5e4) {
                pts.erase(pts.begin() + i);
            }
        }
        db(sz(pts)) endln;
    }
    assert(sz(res) == k);
    for (Circle c : res) {
        cout << prec(9) << c.cen.x << " " << c.cen.y << " " << c.rad << "\n";
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}