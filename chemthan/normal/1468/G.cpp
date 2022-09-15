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
inline int mrand(int k) {return abs((int) mt()) % k;}
#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";

#define double long double
#define EPS 1e-9
struct point_t {
    double x, y;
    point_t() : x(0), y(0) {}
    point_t(double x, double y) : x(x), y(y) {}
    point_t(const point_t& p) : x(p.x), y(p.y) {}
    //int operator < (const point_t& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
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
ostream& operator << (ostream& os, const point_t& p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

//Project c on Line(a, b)
point_t ProjectPointLine(point_t a, point_t b, point_t c) {
    return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
point_t ProjectPointSegment(point_t a, point_t b, point_t c) {
    double r = dot(b - a, b - a);
    if (fabs(r) < EPS) return a;
    r = dot(c - a, b - a) / r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b - a) * r;
}
double DistancePointSegment(point_t a, point_t b, point_t c) {
    return dist(c, ProjectPointSegment(a, b, c));
}
//Compute distance between point_t (x, y, z) and plane ax + by + cz = d
double DistancePointPlane(double x, double y, double z, double a, double b, double c, double d) {
    return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}
//Determine if lines from a to b and c to d are parallel or collinear
int LinesParallel(point_t a, point_t b, point_t c, point_t d) {
    return fabs(cross(b - a, c - d)) < EPS;
}
int LinesCollinear(point_t a, point_t b, point_t c, point_t d) {
    return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS && fabs(cross(c - d, c - a)) < EPS;
}
//Determine if line segment from a to b intersects with line segment from c to d
int SegmentsIntersect(point_t a, point_t b, point_t c, point_t d) {
    if (LinesCollinear(a, b, c, d)) {
        if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS || dist2(b, d) < EPS) return 1;
        if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0) return 0;
        return 1;
    }
    if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return 0;
    if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return 0;
    return 1;
}
//Compute intersection of line passing through a and b
//with line passing through c and d, assuming that unique
//intersection exists; for segment intersection, check if
//segments intersect first
point_t ComputeLineIntersection(point_t a, point_t b, point_t c, point_t d) {
    b = b - a; d = c - d; c = c - a;
    return a + b * cross(c, d) / cross(b, d);
}
//Compute center of circle given three points
point_t ComputeCircleCenter(point_t a, point_t b, point_t c) {
    b = (a + b) / 2;
    c = (a + c) / 2;
    return ComputeLineIntersection(b, b + RotateCW90(a - b), c, c + RotateCW90(a - c));
}
//Determine if point is in a possibly non-convex polygon
//returns 1 for strictly interior points, 0 for
//strictly exterior points, and 0 or 1 for the remaining points.
int PointInPolygonSlow(const vector<point_t>& p, point_t q) {
    int c = 0;
    for (int i = 0; i < p.size(); i++) {
        int j = (i + 1) % p.size();
        if ((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) && q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y)) c = !c;
    }
    return c;
}
//Strictly inside convex Polygon
#define Det(a, b, c) ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x))
int PointInPolygon(vector<point_t>& p, point_t q) {
    int a = 1, b = p.size() - 1, c;
    if (Det(p[0], p[a], p[b]) > 0) swap(a, b);
    //Allow on edge --> if (Det... > 0 || Det ... < 0)
    if (Det(p[0], p[a], q) >= 0 || Det(p[0], p[b], q) <= 0) return 0;
    while(abs(a - b) > 1) {
        c = (a + b) / 2;
        if (Det(p[0], p[c], q) > 0) b = c; else a = c;
    }
    //Alow on edge --> return Det... <= 0
    return Det(p[a], p[b], q) < 0;
}
//Determine if point is on the boundary of a polygon
int PointOnPolygon(const vector<point_t>& p, point_t q) {
    for (int i = 0; i < p.size(); i++) if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < EPS) return 1;
    return 0;
}
//Compute intersection of line through points a and b with circle centered at c with radius r > 0
vector<point_t> CircleLineIntersection(point_t a, point_t b, point_t c, double r) {
    vector<point_t> res;
    b = b - a; a = a - c;
    double A = dot(b, b);
    double B = dot(a, b);
    double C = dot(a, a) - r * r;
    double D = B * B - A * C;
    if (D < -EPS) return res;
    res.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
    if (D > EPS) res.push_back(c + a + b * (-B - sqrt(D)) / A);
    return res;
}
//Compute intersection of circle centered at a with radius r with circle centered at b with radius R
vector<point_t> CircleCircleIntersection(point_t a, point_t b, double r, double R) {
    vector<point_t> res;
    double d = sqrt(dist2(a, b));
    if (d > r + R || d + min(r, R) < max(r, R)) return res;
    double x = (d * d - R * R + r * r) / (2 * d);
    double y = sqrt(r * r - x * x);
    point_t v = (b - a) / d;
    res.push_back(a + v * x + RotateCCW90(v) * y);
    if (y > 0) res.push_back(a + v * x - RotateCCW90(v) * y);
    return res;
}
//This code computes the area or centroid of a (possibly nonconvex)
//polygon, assuming that the coordinates are listed in a clockwise or
//counterclockwise fashion.  Note that the centroid is often known as
//the "center of gravity" or "center of mass".
double ComputeSignedArea(const vector<point_t>& p) {
    double area = 0;
    for(int i = 0; i < p.size(); i++) {
        int j = (i + 1) % p.size();
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return area / 2.0;
}
double ComputeArea(const vector<point_t>& p) {
    return fabs(ComputeSignedArea(p));
}
point_t ComputeCentroid(const vector<point_t>& p) {
    point_t c(0, 0);
    double scale = 6.0 * ComputeSignedArea(p);
    for (int i = 0; i < p.size(); i++) {
        int j = (i + 1) % p.size();
        c = c + (p[i] + p[j]) * (p[i].x * p[j].y - p[j].x * p[i].y);
    }
    return c / scale;
}
//Tests whether or not a given polygon (in CW or CCW order) is simple
int IsSimple(const vector<point_t>& p) {
    for (int i = 0; i < p.size(); i++) {
        for (int k = i + 1; k < p.size(); k++) {
            int j = (i + 1) % p.size();
            int l = (k + 1) % p.size();
            if (i == l || j == k) continue;
            if (SegmentsIntersect(p[i], p[j], p[k], p[l])) return 0;
        }
    }
    return 1;
}
double Angle(point_t a) {
    double PI = acos((double) - 1);
    if (a.x == 0) {
        if (a.y > 0) return PI / 2;
        return 3 * PI / 2;
    }
    if (a.y == 0) {
        if (a.x > 0) return 0;
        return PI;
    }
    double res = atan(a.y / a.x);
    if (a.x < 0) return res + PI;
    if (a.y < 0) return res + 2 * PI;
    return res;
}

point_t cen;

int operator < (point_t a, point_t b) {
    a = a - cen, b = b - cen;
    return mp((double) 0, (double) 0) < mp(cross(a, b), b.x - a.x);
}

void chemthan() {
    int n, h; cin >> n >> h;
    vector<point_t> pts(n);
    FOR(i, 0, n) {
        int x, y; cin >> x >> y;
        pts[i] = point_t(x, y);
    }
    set<point_t> st;
    cen = pts[n - 1] + point_t(0, h);
    st.insert(pts[n - 1]);
    double res = 0;
    FORd(i, n - 1, 0) {
        st.insert(pts[i]);
        while (sz(st) && 2 < sz(st)) {
            st.erase(*st.rbegin());
        }
        auto q = st.begin();
        if (*q == pts[i]) {
            auto q2 = ComputeLineIntersection(cen, *q, pts[i], pts[i + 1]);
            q++;
            auto q3 = ComputeLineIntersection(cen, *q, pts[i], pts[i + 1]);
            if (LinesParallel(cen, *q, pts[i], pts[i + 1])) {
                res += dist(pts[i], pts[i + 1]);
            }
            else {
                res += min(dist(q2, q3), dist(pts[i], pts[i + 1]));
            }
        }
    }
    cout << prec(9) << res << "\n";
}

int32_t main(int32_t argc, char* argv[]) {
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