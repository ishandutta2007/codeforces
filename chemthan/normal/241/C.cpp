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

int scross(point_t a, point_t b) {
    long long cr = cross(a, b);
    return cr < 0 ? -1 : 0 < cr;
}

int insect(point_t a, point_t b, point_t c, point_t d) {
    return scross(c - a, c - b) * scross(d - a, d - b) <= 0 &&
        scross(a - c, a - d) * scross(b - c, b - d) <= 0;
}

void chemthan() {
    int hl, hr, n; cin >> hl >> hr >> n;
    vi v(n);
    vector<char> c(n);
    vi a(n), b(n);
    FOR(i, 0, n) cin >> v[i] >> c[i] >> a[i] >> b[i];
    int res = 0;
    FOR(it, 0, 2) {
        FOR(t, 0, 200) {
            point_t st(0, hl);
            point_t ed(1e5, 100 * t + hr);
            if (t & 1) {
                ed.y = 100 * t + 100 - hr;
            }
            int found = 0;
            int cost = 0;
            vi f(t + 5);
            FOR(i, 0, n) {
                int num = 0;
                FOR(u, 0, t + 1) {
                    point_t q1(a[i], 100 * u);
                    point_t q2(b[i], 100 * u);
                    int uu = u;
                    int skip = 0;
                    if (!(u & 1)) {
                        if (c[i] == 'T') {
                            uu++;
                            q1.y += 100;
                            q2.y += 100;
                        }
                        else {
                            skip = 1;
                        }
                    }
                    else {
                        if (c[i] == 'F') {
                            uu++;
                            q1.y += 100;
                            q2.y += 100;
                        }
                        else {
                            skip = 1;
                        }
                    }
                    if (!skip && insect(st, ed, q1, q2)) {
                        num++;
                        f[uu] = 1;
                    }
                }
                if (1 < num) {
                    found = 1;
                    break;
                }
                if (num) {
                    cost += v[i];
                }
            }
            FOR(i, 1, t + 1) {
                if (!f[i]) {
                    found = 1;
                }
            }
            if (!found) {
                chkmax(res, cost);
            }
        }
        FOR(i, 0, n) {
            if (c[i] == 'F') {
                c[i] = 'T';
            }
            else {
                c[i] = 'F';
            }
        }
        hl = 100 - hl;
        hr = 100 - hr;
    }
    cout << res << "\n";
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