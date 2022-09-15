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
    int operator < (const point_t& rhs) const {return make_pair(x, y) < make_pair(rhs.x, rhs.y);}
    int operator == (const point_t& rhs) const {return make_pair(x, y) == make_pair(rhs.x, rhs.y);}
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
        while (up.size() > 1 && area(up[up.size() - 2], up.back(), pts[i]) >= 0) {
            up.pop_back();
        }
        while (dn.size() > 1 && area(dn[dn.size() - 2], dn.back(), pts[i]) <= 0) {
            dn.pop_back();
        }
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

const int maxn = 2e5 + 5;
int n;
point_t p[maxn];
int used[maxn];

void chemthan() {
    cin >> n;
    vector<point_t> pts;
    int zero = 0;
    FOR(i, 0, n) {
        cin >> p[i].x >> p[i].y;
        p[i].ix = i;
        if ((p[i].x & 1) || (p[i].y & 1)) {
            p[i].c = 1;
        }
        pts.pb(p[i]);
        if (p[i] == point_t()) {
            zero = 1;
        }
    }
    if (!zero) {
        p[n] = point_t();
        p[n].ix = n;
        pts.pb(p[n++]);
    }
    ConvexHull(pts);
    for (point_t q : pts) {
        if (q.c) {
            cout << "Ani\n";
            return;
        }
        used[q.ix] = 1;
    }
    vector<point_t> unusedpts;
    FOR(i, 0, n) if (!used[i]) {
        unusedpts.pb(p[i]);
    }
    sort(all(unusedpts));
    FOR(i, 0, sz(pts)) if (!(pts[i] == point_t())) {
        int j = (i + sz(pts) - 1) % sz(pts);
        int k = (i + 1) % sz(pts);
        int lo = min(pts[i].x, min(pts[j].x, pts[k].x));
        int hi = max(pts[i].x, max(pts[j].x, pts[k].x));
        int u = lower_bound(all(unusedpts), point_t(lo, -INF)) - unusedpts.begin();
        int v = upper_bound(all(unusedpts), point_t(hi, +INF)) - unusedpts.begin();
        vector<point_t> subpts;
        FOR(l, u, v) {
            if (inside(pts[i], pts[j], pts[k], unusedpts[l])) {
                subpts.pb(unusedpts[l]);
            }
        }
        subpts.pb(pts[j]);
        subpts.pb(pts[k]);
        ConvexHull(subpts);
        for (point_t q : subpts) {
            if (q.c) {
                cout << "Ani\n";
                return;
            }
        }
    }
    cout << "Borna\n";
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