#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) (int) ((a).size())
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
const ld EPS = 1e-15;
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
int _mult(int x, int y) {return (long long) x * y % MOD;}
template<typename ...Y> int _mult(int x, Y... y) { return (long long) x * _mult(y...) % MOD; }
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() {return abs((int) mt());}
inline int mrand(int k) {return abs((int) mt()) % k;}
template<typename X> void debug(X x) { cerr << x << "] "; }
template<typename X, typename ...Y> void debug(X x, Y... y) { cerr << x << " "; debug(y...); }
#define db(...) cerr << "[" << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#define endln cerr << "\n";
#define LIKELY(x)   (__builtin_expect(!!(x), 1))
#define UNLIKELY(x) (__builtin_expect(!!(x), 0))

#define double long double
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

#define REMOVE_REDUNDANT
#ifdef REMOVE_REDUNDANT
bool between(const point_t& a, const point_t& b, const point_t& c) {
    return (fabs(area2(a, b, c)) < EPS && (a.x - b.x) * (c.x - b.x) <= 0 && (a.y - b.y) * (c.y - b.y) <= 0);
}
#endif
void ConvexHull(vector<point_t>& pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<point_t> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area2(up[up.size() - 2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size() - 2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
#ifdef REMOVE_REDUNDANT
    if (pts.size() <= 2) return;
    dn.clear();
    dn.push_back(pts[0]);
    dn.push_back(pts[1]);
    for (int i = 2; i < pts.size(); i++) {
        if (between(dn[dn.size() - 2], dn[dn.size() - 1], pts[i])) dn.pop_back();
        dn.push_back(pts[i]);
    }
    if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
        dn[0] = dn.back();
        dn.pop_back();
    }
    pts = dn;
#endif
}


double _calc(vector<point_t> poly1, vector<point_t> poly2) {
  vector<point_t> pts;
  for (auto p : poly1) pts.pb(p);
  for (auto p : poly2) pts.pb(p);
  FOR(i, 0, sz(poly1)) FOR(j, 0, sz(poly2)) {
    int ni = (i + 1) % sz(poly1);
    int nj = (j + 1) % sz(poly2);
    if (SegmentsIntersect(poly1[i], poly1[ni], poly2[j], poly2[nj])) {
      auto q = ComputeLineIntersection(poly1[i], poly1[ni], poly2[j], poly2[nj]);
      pts.pb(q);
    }
  }
  double x1 = 1e9, y1 = 1e9;
  for (auto p : poly1) {
    chkmin(x1, p.x);
    chkmin(y1, p.y);
  }
  {
    vector<point_t> npts;
    for (auto p : pts) {
      if (0 <= sign(p.x, x1) && sign(p.x, x1 + 1) <= 0 &&
          0 <= sign(p.y, y1) && sign(p.y, y1 + 1) <= 0) {
        if (PointInPolygonSlow(poly2, p) || PointOnPolygon(poly2, p)) {
          npts.pb(p);
        }
      }
    }
    pts = npts;
  }
  if (sz(pts) < 3) return 0;
  ConvexHull(pts);
  double res = 0;
  FOR(i, 0, sz(pts)) {
    int j = (i + 1) % sz(pts);
    res += cross(pts[i], pts[j]) / 2;
  }
  return abs(res);
}

double calc(vector<point_t> poly1, vector<vector<point_t>> pp) {
  double res = 0;
  for (auto poly2 : pp) {
    res += _calc(poly1, poly2);
  }
  return res;
}

//#define LOCAL

void chemthan() {
#ifdef LOCAL
  double u = 1, v = 2;
#endif
  int n, m; cin >> n >> m;
  vector<point_t> poly1;
  vector<vector<point_t>> pp1;
  {
    poly1.pb(point_t(0, 0));
    for (int i = 0; i < m; i++) {
      poly1.pb(point_t(n - 0.5, i + 0.5));
      poly1.pb(point_t(0, i + 1));
    }
    poly1.pb(point_t(n, m));
    poly1.pb(point_t(n, 0));
    reverse(all(poly1));

    for (int i = 0; i < m; i++) {
      {
        vector<point_t> tr;
        tr.pb(point_t(0, i));
        tr.pb(point_t(n, i));
        tr.pb(point_t(n, i + 0.5));
        tr.pb(point_t(n - 0.5, i + 0.5));
        pp1.pb(tr);
      }
      {
        vector<point_t> tr;
        tr.pb(point_t(n - 0.5, i + 0.5));
        tr.pb(point_t(n, i + 0.5));
        tr.pb(point_t(n, i + 1));
        tr.pb(point_t(0, i + 1));
        pp1.pb(tr);
      }
    }
  }
  vector<point_t> poly2;
  vector<vector<point_t>> pp2;
  {
    poly2.pb(point_t(0, 0));
    for (int i = 0; i < n; i++) {
      poly2.pb(point_t(i + 0.5, m - 0.5));
      poly2.pb(point_t(i + 1, 0));
    }
    poly2.pb(point_t(n, m));
    poly2.pb(point_t(0, m));
    for (int i = 0; i < n; i++) {
      {
        vector<point_t> tr;
        tr.pb(point_t(i, 0));
        tr.pb(point_t(i, m));
        tr.pb(point_t(i + 0.5, m));
        tr.pb(point_t(i + 0.5, m - 0.5));
        pp2.pb(tr);
      }
      {
        vector<point_t> tr;
        tr.pb(point_t(i + 0.5, m - 0.5));
        tr.pb(point_t(i + 0.5, m));
        tr.pb(point_t(i + 1, m));
        tr.pb(point_t(i + 1, 0));
        pp2.pb(tr);
      }
    }
  }

  auto gen = [&] (double x1, double y1) {
    vector<point_t> poly;
    poly.pb({x1, y1});
    poly.pb({x1 + 1, y1});
    poly.pb({x1 + 1, y1 + 1});
    poly.pb({x1, y1 + 1});
    return poly;
  };

  cout << "? " << sz(poly1) << "\n";
  for (auto p : poly1) {
    cout << prec(15) << p.x << " " << p.y << "\n";
  }
  cout.flush();
#ifdef LOCAL
  double s1 = calc(gen(u, v), pp1);
#else
  double s1; cin >> s1;
#endif
  cout << "? " << sz(poly2) << "\n";
  for (auto p : poly2) {
    cout << prec(15) << p.x << " " << p.y << "\n";
  }
  cout.flush();
#ifdef LOCAL
  double s2 = calc(gen(u, v), pp2);
#else
  double s2; cin >> s2;
#endif

  auto findx = [&] (double y) {
    double lo = 0, hi = n - 1;
    FOR(_, 0, 100) {
      double mi = (lo + hi) / 2;
      if (calc(gen(mi, y), pp1) < s1) {
        lo = mi;
      }
      else {
        hi = mi;
      }
    }
    return (lo + hi) / 2;
  };
  auto findy = [&] (double x) {
    double lo = 0, hi = m - 1;
    FOR(_, 0, 100) {
      double mi = (lo + hi) / 2;
      if (calc(gen(x, mi), pp2) < s2) {
        lo = mi;
      }
      else {
        hi = mi;
      }
    }
    return (lo + hi) / 2;
  };
  double x = 0;
  double y = findy(x);
  while (1.0 * clock() / CLOCKS_PER_SEC < 0.8) {
    x = findx(y);
    y = findy(x);
  }
  cout << prec(15) << "! " << x << " " << y << "\n";
  cout.flush();
  //db(calc(gen(x, y), pp1), s1) endln;
  //db(calc(gen(x, y), pp2), s2) endln;
}

int32_t main(int32_t argc, char* argv[]) {
  //ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  int test = 1;
  //cin >> test;
  while (test--)
    chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}