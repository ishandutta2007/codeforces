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

typedef long double num_t;
const num_t oo = (num_t) 1e100;
struct LineHull {
    struct Line {
        num_t a, b;
        Line(num_t a, num_t b) : a(a), b(b) {}
    };
    long double intersect(Line ln1, Line ln2) {
        return (long double) (ln2.b - ln1.b) / (ln1.a - ln2.a);
    }
    int bad(Line ln1, Line ln2, Line ln3) {
        return (long double) (ln1.a - ln2.a) * (ln2.b - ln3.b) >= (long double) (ln2.a - ln3.a) * (ln1.b - ln2.b);
    }
    vector<Line> hull;
    vector<long double> pos;
    LineHull() {
        pos.push_back(-oo);
        pos.push_back(+oo);
    }
    void add(num_t a, num_t b) {
        Line ln(a, b);
        pos.pop_back();
        while (hull.size() >= 2 && bad(hull[hull.size() - 2], hull[hull.size() - 1], ln)) {
            hull.pop_back();
            pos.pop_back();
        }
        hull.push_back(ln);
        if (hull.size() >= 2) pos.push_back(intersect(hull[hull.size() - 2], hull[hull.size() - 1]));
        pos.push_back(+oo);
    }
    pair<pair<num_t, num_t>, num_t> query(num_t x) {
        int k = lower_bound(pos.begin(), pos.end(), x) - pos.begin() - 1;
        return mp(mp(hull[k].a, hull[k].b), pos[k]);
    }
} lh;

#define double long double
const int maxn = 1e5 + 5;
int n;
long long t;
int a[maxn];
int b[maxn];
double p[maxn];

void chemthan() {
    cin >> n >> t;
    vector<pair<double, double> > vals;
    double mxa = -1e18, mxb = -1e18;
    FOR(i, 0, n) {
        cin >> a[i] >> b[i] >> p[i];
        chkmax(mxb, p[i] * b[i]);
    }
    FOR(i, 0, n) {
        vals.pb(mp(1 - p[i], -(p[i] * a[i] - mxb)));
        chkmax(mxa, p[i] * a[i] - mxb);
    }
    sort(all(vals));
    FOR(i, 0, n) {
        if (!i || abs(vals[i].fi - vals[i - 1].fi) > 1e-12) {
            lh.add(-vals[i].fi, vals[i].se);
        }
    }
    long long st = 1;
    double res = mxa;
    while (st < t) {
        long long lo = st + 1, hi = t;
        pair<pair<double, double>, double> line = lh.query(res);
        line.fi.fi *= -1, line.fi.se *= -1;
        while (lo < hi) {
            long long mi = lo + hi + 1 >> 1;
            double pa = pow(line.fi.fi, mi - st);
            double nres = pa * res + line.fi.se / (1 - line.fi.fi) * (1 - pa);
            if (nres > line.se) {
                lo = mi;
            }
            else {
                hi = mi - 1;
            }
        }
        long long mi = lo + hi >> 1;
        double pa = pow(line.fi.fi, mi - st);
        res = pa * res + line.fi.se / (1 - line.fi.fi) * (1 - pa);
        st = mi;
    }
    cout << prec(9) << t * mxb + res << "\n";
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