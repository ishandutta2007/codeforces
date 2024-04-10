#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
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

void chemthan() {
    int n, d; cin >> n >> d;
    static int a[234567];
    FOR(i, 0, n) cin >> a[i];
    int m; cin >> m;
    while (m--) {
        int x; cin >> x;
        int k = lower_bound(a, a + n, x) - a;
        if (k < n && a[k] == x) {
            if (k && a[k - 1] == x - 1) {
                cout << prec(9) << PI << "\n";
            }
            else {
                cout << prec(9) << PI / 2 << "\n";
            }
            continue;
        }
        if (k == 0) {
            cout << prec(9) << atan(1.0 / (a[k] - x)) << "\n";
        }
        else if (k == n) {
            if (x == a[n - 1] + 1) {
                cout << prec(9) << PI / 2 << "\n";
            }
            else {
                cout << prec(9) << atan(1.0 / (x - a[n - 1] - 1)) << "\n";
            }
        }
        else {
            int e = min(a[k] - x, x - a[k - 1] - 1);
            double res = e ? atan(1.0 / e) : PI / 2;
            static bitset<7000> f, g;
            f.reset(), g.reset();
            for (int i = k; i < k + 7000 && i < n && a[i] - x < 7000; ++i) {
                f[a[i] - x] = 1;
            }
            for (int i = k - 1; i > k - 7000 && i >= 0 && x - a[i] - 1 < 7000; --i) {
                g[x - a[i] - 1] = 1;
            }
            static vector<double> dp(7005, -1);
            auto func = [&] (int d) {
                double& res = dp[d];
                if (res != -1) return res;
                point_t p(d, -1);
                double l = 0, r = PI / 2;
                FOR(it, 0, 100) {
                    double m = (l + r) / 2;
                    point_t q = RotateCCW(p, m);
                    if (q.y < 1) {
                        l = m;
                    }
                    else {
                        r = m;
                    }
                }
                return res = (l + r) / 2;
            };
            int t = (f & g)._Find_first();
            if (t != -1) {
                chkmax(res, (double) atan(1.0 / t) * 2);
            }
            t = (f & (g << 1))._Find_first();
            if (t != 7000) {
                chkmax(res, func(t));
            }
            t = ((f << 1) & g)._Find_first();
            if (t != 7000) {
                chkmax(res, func(t));
            }
            cout << prec(9) << res << "\n";
        }
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