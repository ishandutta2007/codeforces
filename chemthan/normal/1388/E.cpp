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
namespace real {
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
    point_t ComputeLineIntersection(point_t a, point_t b, point_t c, point_t d) {
        b = b - a; d = c - d; c = c - a;
        return a + b * cross(c, d) / cross(b, d);
    }
};

struct point_t {
    int x, y;
    point_t() : x(0), y(0) {}
    point_t(int x, int y) : x(x), y(y) {}
    point_t(const point_t& rhs) : x(rhs.x), y(rhs.y) {}
    int operator < (const point_t& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
    int operator == (const point_t& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
    int operator != (const point_t& rhs) const {return make_pair(y, x) != make_pair(rhs.y, rhs.x);}
    point_t operator - (const point_t& rhs) const {return point_t(x - rhs.x, y - rhs.y);}
};
long long cross(point_t a, point_t b) {
    return (long long) a.x * b.y - (long long) a.y * b.x;
}
long long area(point_t a, point_t b, point_t c) {
    return cross(a, b) + cross(b, c) + cross(c, a);
}

void chemthan() {
    int n; cin >> n;
    vector<point_t> v;
    FOR(i, 0, n) {
        int x0, x1, y; cin >> x0 >> x1 >> y;
        v.pb({x0, y});
        v.pb({x1, y});
    }
    vector<vi> g(n + n, vi(n + n));
    FOR(i, 0, n) {
        FOR(j, 0, n) if (v[2 * j].y < v[2 * i].y) {
            g[2 * i + 1][2 * j] = 1;
            g[2 * i][2 * j + 1] = -1;
        }
    }
    n = sz(v);
    vector<tuple<point_t, int, int>> segs;
    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
            auto q = v[i] - v[j];
            if (!q.y) continue;
            if (0 < q.y) { q.x *= -1;
                q.y *= -1;
            }
            int g = __gcd(abs(q.x), abs(q.y));
            q.x /= g, q.y /= g;
            segs.pb({q, i, j});
        }
    }
    sort(all(segs), [&] (tuple<point_t, int, int> a, tuple<point_t, int, int> b) {
            return 0 < cross(get<0>(a), get<0>(b));
            }
        );
    vi ver;
    FOR(i, 0, n) ver.pb(i);
    auto cmp = [&] (int a, int b, point_t d) {
        if (v[a].y == v[b].y) return v[a].x < v[b].x;
        return 0 < cross(v[a] - v[b], d);
    };
    sort(all(ver), [&] (int a, int b) {
            if (v[a].y == v[b].y) return v[a].x < v[b].x;
            return 0 < cross(v[a] - v[b], point_t((int) -1e9, -1));
            }
        );
    vi f(n);
    FOR(i, 0, n) f[ver[i]] = i;
    auto calc = [&] (double l, double r, point_t a, point_t b) {
        auto ff = [&] (double m) {
            double xa = real::ComputeLineIntersection({(double) a.x, (double) a.y}, {(double) a.x + m, (double) a.y + 1}, {(double) 0, (double) 0}, {(double) 1, (double) 0}).x;
            double xb = real::ComputeLineIntersection({(double) b.x, (double) b.y}, {(double) b.x + m, (double) b.y + 1}, {(double) 0, (double) 0}, {(double) 1, (double) 0}).x;
            return abs(xa - xb);
        };
        double res = min(ff(l), ff(r));
        return res;
    };
    double res = 1e99;
    point_t e = point_t((int) -1e9, -1);
    point_t e2 = sz(segs) ? get<0>(segs[0]) : point_t((int) 1e9, -1);
    int a = ver[0];
    int b = ver[n - 1];
    chkmin(res, calc((double) e.x / e.y, (double) e2.x / e2.y, v[a], v[b]));
    vector<point_t> vals;
    for (auto e : segs) {
        vals.pb(get<0>(e));
    }
    uni(vals);
    int ptr = 0;
    int sum = 0;
    FOR(i, 0, sz(vals)) {
        point_t e = vals[i];
        point_t e2 = i + 1 < sz(vals) ? vals[i + 1] : point_t((int) 1e9, -1);
        int add = 0;
        while (ptr < sz(segs) && get<0>(segs[ptr]) == e) {
            int a = get<1>(segs[ptr]);
            int b = get<2>(segs[ptr]);
            if (f[b] < f[a]) swap(a, b);
            if (g[a][b] + g[b][a] < 0) {
                sum += g[a][b] + g[b][a];
            }
            else {
                add += g[a][b] + g[b][a];
            }
            assert(!cmp(a, b, e) && !cmp(b, a, e));
            int pa = f[a];
            int pb = f[b];
            if (v[b].y < v[a].y) {
                assert(ver[pa] == a && ver[pb] == b);
                swap(ver[pa], ver[pb]);
                swap(f[a], f[b]);
                assert(ver[f[a]] == a && ver[f[b]] == b);
            }
            ptr++;
        }
        if (!sum) {
            int a = ver[0];
            int b = ver[n - 1];
            chkmin(res, calc((double) e.x / e.y, (double) e.x / e.y, v[a], v[b]));
        }
        sum += add;
        if (!sum) {
            int a = ver[0];
            int b = ver[n - 1];
            chkmin(res, calc((double) e.x / e.y, (double) e2.x / e2.y, v[a], v[b]));
        }
    }
    cout << prec(9) << res << "\n";
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