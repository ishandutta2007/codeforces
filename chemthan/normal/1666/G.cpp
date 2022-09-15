#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3")
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
template<typename X> void debug(X x) { cerr << x << "] "; }
template<typename X, typename ...Y> void debug(X x, Y... y) { cerr << x << " "; debug(y...); }
#define db(...) cerr << "[" << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#define endln cerr << "\n";
#define LIKELY(x)   (__builtin_expect(!!(x), 1))
#define UNLIKELY(x) (__builtin_expect(!!(x), 0))

#define double long double
template<class num_t>
struct point_t {
    inline int sign(num_t x) {return x < -EPS ? -1 : x > +EPS;}
    inline int sign(num_t x, num_t y) {return sign(x - y);}

    num_t x, y, z;
    point_t(num_t x = 0, num_t y = 0, num_t z = 0) : x(x), y(y), z(z) {}
    point_t operator + (const point_t& rhs) const {
        return point_t(x + rhs.x, y + rhs.y, z + rhs.z);
    }
    point_t operator - (const point_t& rhs) const {
        return point_t(x - rhs.x, y - rhs.y, z - rhs.z);
    }
    point_t operator * (const num_t& k) const {
        return point_t(x * k, y * k, z * k);
    }
    point_t operator / (const num_t& k) const {
        return point_t(x / k, y / k, z / k);
    }
    int operator < (const point_t& rhs) const {
      return make_tuple(x, y, z) < make_tuple(rhs.x, rhs.y, rhs.z);
    }
    inline num_t len() {
        return hypot(hypot(x, y), z);
    }
};

void chemthan() {
  int n; cin >> n;
  vector<point_t<double>> pts;
  FOR(i, 0, n) {
    int x, y, z; cin >> x >> y >> z;
    pts.pb({(double) x, (double) y, (double) z});
  }
  auto find = [&] (point_t<double> u, point_t<double> v, double h) {
    double hu = u.z;
    double hv = v.z;
    double r = (h - hu) / (hv - hu);
    return u + (v - u) * r;
  };
  auto area = [&] (point_t<double> a, point_t<double> b, point_t<double> c) {
    auto x = (a - b).len();
    auto y = (b - c).len();
    auto z = (c - a).len();
    auto p = (x + y + z) / 2;
    return sqrt(p * (p - x) * (p - y) * (p - z));
  };
  auto solve = [&] (vector<pair<double, double>> vals) {
    sort(all(vals));
    if (vals[0].fi == vals[2].fi) {
      return point_t<double>();
    }
    vector<vector<double>> a(3, vector<double>(4));
    FOR(i, 0, 3) {
      auto x = vals[i].fi;
      auto y = vals[i].se;
      FOR(j, 0, 3) a[i][j] = pow(x, j);
      a[i][3] = y;
    }
    FOR(i, 0, 3) {
      auto t = a[i][i];
      FOR(j, 0, 4) a[i][j] /= t;
      FOR(j, 0, 3) if (i != j) {
        t = a[j][i];
        FOR(k, 0, 4) {
          a[j][k] -= a[i][k] * t;
        }
      }
    }
    return point_t<double>(a[0][3], a[1][3], a[2][3]);
  };
  auto calc = [&] (int u, int v, int w) {
    vi vv({u, v, w});
    sort(all(vv), [&] (int i, int j) {
        return pts[i].z < pts[j].z;
        }
        );
    u = vv[0], v = vv[1], w = vv[2];
    auto p1 = find(pts[u], pts[w], pts[v].z);
    auto p2 = find(pts[u], pts[w], (pts[u] + pts[v]).z / 2);
    auto p3 = find(pts[u], pts[w], (pts[v] + pts[w]).z / 2);

    auto q1 = (pts[u] + pts[v]) * 0.5;
    auto q2 = (pts[v] + pts[w]) * 0.5;

    auto s1 = area(pts[u], pts[v], pts[w]);
    auto s2 = s1 - area(pts[u], pts[v], p1);
    auto s3 = s1 - area(pts[u], p2, q1);
    auto s4 = area(pts[w], p3, q2);
    auto s5 = area(pts[w], pts[v], p1);
    
    auto coef1 = solve({mp(p1.z, s2), mp(p3.z, s4), mp(pts[w].z, 0)});
    auto coef2 = solve({mp(p1.z, s2 - s5), mp(p2.z, s3 - s5), mp(pts[u].z, s1 - s5)});
    coef2.x += s5;
    if (pts[u].z == pts[w].z) {
      coef1 = coef2 = point_t<double>(s1, 0, 0);
    }
    return make_tuple(coef1, coef2, pts[u].z, pts[v].z, pts[w].z);
  };
  int m; cin >> m;
  map<pi, vi> hs;
  vector<vi> faces;
  vi f(n);
  FOR(i, 0, m) {
    vi v(3);
    FOR(j, 0, 3) cin >> v[j], v[j]--, f[v[j]] = i;
    sort(all(v));
    faces.pb({v[0], v[1], v[2]});
    hs[mp(v[0], v[1])].pb(i);
    hs[mp(v[1], v[2])].pb(i);
    hs[mp(v[0], v[2])].pb(i);
  }
  vector<tuple<int, int, int>> events;
  for (auto [e, v] : hs) {
    auto [p, q] = e;
    FOR(i, 0, sz(v)) FOR(j, i + 1, sz(v)) {
      int x = v[i];
      int y = v[j];
      events.pb({max(pts[p].z, pts[q].z), x, y});
    }
  }
  int q; cin >> q;
  vector<tuple<int, int, int>> queries;
  FOR(i, 0, q) {
    int h, p; cin >> h >> p; p--;
    queries.pb({h, p, i});
  }
  vi dj(m);
  vector<point_t<double>> g(m);
  FOR(i, 0, m) dj[i] = i;
  function<int(int)> dj_find = [&] (int u) {
    return dj[u] == u ? dj[u] : dj[u] = dj_find(dj[u]);
  };
  auto join = [&] (int u, int v) {
    u = dj_find(u), v = dj_find(v);
    if (u != v) {
      g[u] = g[u] + g[v];
      dj[v] = u;
    }
  };
  vector<tuple<int, int, point_t<double>>> events2;
  double sum = 0;
  FOR(i, 0, m) {
    auto [coef1, coef2, a, b, c] = calc(faces[i][0], faces[i][1], faces[i][2]);
    events2.pb({c, i, coef1});
    events2.pb({b, i, coef1 * -1.0});
    events2.pb({b, i, coef2});
    events2.pb({a, i, coef2 * -1.0});
    events2.pb({a, i, point_t<double>(coef2.x + coef2.y * a + coef2.z * a * a, 0, 0)});
  }

  vector<double> res(q);
  sort(all(events));
  sort(all(events2));
  sort(all(queries));
  int ptr = sz(events) - 1;
  FORd(i, sz(queries), 0) {
    while (sz(events) && get<0>(queries[i]) < get<0>(events.back())) {
      auto [h, x, y] = events.back();
      join(x, y);
      events.pop_back();
    }
    while (sz(events2) && get<0>(queries[i]) <= get<0>(events2.back())) {
      auto [h, ix, coef] = events2.back();
      int face_id = dj_find(ix);
      g[face_id] = g[face_id] + coef;
      events2.pop_back();
    }
    auto [h, p, ix] = queries[i];
    if (pts[p].z <= h) {
      res[ix] = -1;
      continue;
    }
    int face_id = dj_find(f[p]);
    res[ix] = g[face_id].x + g[face_id].y * h + g[face_id].z * h * h;
  }
  FOR(i, 0, q) {
    if (res[i] == -1) {
      cout << -1 << "\n";
    }
    else {
      cout << prec(9) << res[i] << "\n";
    }
  }
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