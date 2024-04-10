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
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

struct point_t {
    int x, y, ix, c;
    point_t(int x = 0, int y = 0, int ix = 0, int c = 0) : x(x), y(y), ix(ix), c(c) {}
    int operator < (const point_t& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
    int operator == (const point_t& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
    point_t operator - (const point_t& rhs) const {return point_t(x - rhs.x, y - rhs.y);}
};
long long cross(point_t a, point_t b) {
    return (long long) a.x * b.y - (long long) a.y * b.x;
}
long long area(point_t a, point_t b, point_t c) {
    return cross(a, b) + cross(b, c) + cross(c, a);
}
int inside(point_t a, point_t b, point_t c, point_t p) {
    return abs(area(a, b, c)) == abs(area(p, a, b)) + abs(area(p, b, c)) + abs(area(p, c, a));
}
void ConvexHull(vector<point_t>& pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<point_t> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area(up[up.size() - 2], up.back(), pts[i]) > 0) up.pop_back();
        while (dn.size() > 1 && area(dn[dn.size() - 2], dn.back(), pts[i]) < 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

const int maxn = 1e3 + 5;
int n;
vector<point_t> p;
int used[maxn];
vii res;

void solve(point_t a, point_t b, point_t c, vector<point_t> pts) {
    for (point_t p : {a, b, c}) used[p.ix] = 1;
    vector<point_t> npts;
    for (point_t p : pts) {
        if (inside(a, b, c, p) && !used[p.ix]) {
            npts.pb(p);
        }
    }
    pts = npts;
    vector<point_t> g[2];
    for (point_t p : {a, b, c}) {
        g[p.c].pb(p);
    }
    if (sz(g[0]) > sz(g[1])) {
        swap(g[0], g[1]);
    }
    if (sz(g[0])) {
        for (point_t p : pts) {
            if (p.c == g[0][0].c) {
                res.pb(mp(p.ix, g[0][0].ix));
                solve(p, a, b, pts);
                solve(p, b, c, pts);
                solve(p, c, a, pts);
                return;
            }
        }
    }
    for (point_t p : pts) {
        for (point_t q : {a, b, c}) {
            if (p.c == q.c) {
                res.pb(mp(p.ix, q.ix));
                break;
            }
        }
        solve(p, a, b, pts);
        solve(p, b, c, pts);
        solve(p, c, a, pts);
        return;
    }
}

void chemthan() {
    cin >> n;
    p.resize(n);
    vector<point_t> pts;
    FOR(i, 0, n) {
        cin >> p[i].x >> p[i].y >> p[i].c;
        p[i].ix = i;
        pts.pb(p[i]);
    }
    ConvexHull(pts);
    for (point_t p : pts) used[p.ix] = 1;
    int st = 0;
    FOR(i, 0, sz(pts)) {
        int j = (i + sz(pts) - 1) % sz(pts);
        if (pts[i].c != pts[j].c) {
            st = i;
        }
    }
    vector<point_t> npts;
    FOR(i, 0, sz(pts)) {
        int j = (i + st) % sz(pts);
        npts.pb(pts[j]);
    }
    pts = npts;
    int ed = 0;
    while (ed < sz(pts) && pts[ed].c == pts[0].c) ed++;
    FOR(i, ed, sz(pts)) if (pts[i].c == pts[0].c) {
        cout << "Impossible\n";
        return;
    }
    FOR(i, 0, ed - 1) {
        res.pb(mp(pts[i].ix, pts[i + 1].ix));
    }
    FOR(i, ed, sz(pts) - 1) {
        res.pb(mp(pts[i].ix, pts[i + 1].ix));
    }
    if (ed == sz(pts)) {
        int found = 0;
        for (point_t q : p) {
            if (q.c != pts[0].c) {
                FOR(i, 0, sz(pts)) {
                    int j = (i + 1) % sz(pts);
                    solve(q, pts[i], pts[j], p);
                }
                found = 1;
                break;
            }
        }
        if (!found) {
            FOR(i, 1, sz(pts) - 1) {
                solve(pts[0], pts[i], pts[i + 1], p);
            }
        }
        for (pi& e : res) {
            if (e.fi > e.se) {
                swap(e.fi, e.se);
            }
        }
        sort(all(res)), uni(res);
        cout << sz(res) << "\n";
        for (pi e : res) {
            cout << e.fi << " " << e.se << "\n";
        }
        return;
    }
    FOR(i, 0, ed - 1) {
        solve(pts[ed], pts[i], pts[i + 1], p);
    }
    FOR(i, ed, sz(pts) - 1) {
        solve(pts[0], pts[i], pts[i + 1], p);
    }
    for (pi& e : res) {
        if (e.fi > e.se) {
            swap(e.fi, e.se);
        }
    }
    sort(all(res)), uni(res);
    cout << sz(res) << "\n";
    for (pi e : res) {
        cout << e.fi << " " << e.se << "\n";
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