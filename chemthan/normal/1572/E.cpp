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
long long dist(point_t a, point_t b) {
    return (long long) (a.x - b.x) * (a.x - b.x) + (long long) (a.y - b.y) * (a.y - b.y);
}

void chemthan() {
    int n, k; cin >> n >> k;
    vector<point_t> pts(n);
    FOR(i, 0, n) cin >> pts[i].x >> pts[i].y;
    vector<vector<long long>> f(n, vector<long long>(n));
    FOR(i, 0, n) {
        long long sum = 0;
        FOR(jj, 1, n) {
            int u = (i + jj - 1) % n;
            int v = (u + 1) % n;
            sum += cross(pts[u], pts[v]);
            f[i][v] = sum;
        }
    }
    long long area = 0;
    FOR(i, 0, n) {
        int j = (i + 1) % n;
        area += cross(pts[i], pts[j]);
    }
    auto func = [&] (int x, int y, int z, int t) {
        long long res = area;
        res -= f[x][y];
        res -= cross(pts[y], pts[x]);
        res -= f[z][t];
        res -= cross(pts[t], pts[z]);
        return res;
    };
    auto check = [&] (long long mi) {
        vector<vector<pair<int, long long>>> dp(n, vector<pair<int, long long>>(n, mp(-1, 0)));
        function<pair<int, long long>(int, int)> calc = [&] (int x, int y) {
            if (f[y][x] + cross(pts[x], pts[y]) < mi) {
                return mp(0, f[y][x] + cross(pts[x], pts[y]));
            }
            auto& res = dp[x][y];
            if (~res.fi) return res;
            res = mp(0, f[y][x] + cross(pts[x], pts[y]));
            if (mi <= res.se) {
                res.fi++;
                res.se = 0;
            }
            auto smart = [&] (int x) {
                return x < n ? x : x - n;
            };
            {
                for (int i = smart(y + 1); i != x; i = smart(i + 1)) {
                    auto tmp1 = calc(x, i);
                    auto tmp2 = calc(i, y);
                    auto tmp = mp(tmp1.fi + tmp2.fi, tmp1.se + tmp2.se + cross(pts[x], pts[y]) + cross(pts[y], pts[i]) + cross(pts[i], pts[x]));
                    if (mi <= tmp.se) {
                        tmp.fi++;
                        tmp.se = 0;
                    }
                    chkmax(res, tmp);
                }
            }

            return res;
        };
        return k + 1 <= calc(0, 1).fi;
    };
    long long lo = 0, hi = area / (k + 1);
    while (lo < hi) {
        long long mi = lo + hi + 1 >> 1;
        if (check(mi)) {
            lo = mi;
        }
        else {
            hi = mi - 1;
        }
    }
    cout << (lo + hi >> 1) << "\n";
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