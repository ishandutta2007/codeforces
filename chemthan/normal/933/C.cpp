#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())
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
const int FFTMOD = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

#define double long double
struct PT {
    double x, y;
    PT() : x(0), y(0) {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT& p) : x(p.x), y(p.y) {}
    int operator < (const PT& rhs) const {
        if (sign(y, rhs.y)) return sign(y, rhs.y) < 0;
        if (sign(x, rhs.x)) return sign(x, rhs.x) < 0;
        return make_pair(y, x) < make_pair(rhs.y, rhs.x);
    }
    int operator == (const PT& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
    PT operator + (const PT& p) const {return PT(x + p.x, y + p.y);}
    PT operator - (const PT& p) const {return PT(x - p.x, y - p.y);}
    PT operator * (double c) const {return PT(x * c, y * c);}
    PT operator / (double c) const {return PT(x / c, y / c);}
};
inline double sqr(double x) {return x * x;}
double cross(PT p, PT q) {return p.x * q.y - p.y * q.x;}
double area(PT a, PT b, PT c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
double area2(PT a, PT b, PT c) {return cross(a, b) + cross(b, c) + cross(c, a);}
double dot(PT p, PT q) {return p.x * q.x + p.y * q.y;}
double dist(PT p, PT q) {return sqrt(dot(p - q, p - q));}
double dist2(PT p, PT q) {return dot(p - q, p - q);}
PT RotateCCW90(PT p) {return PT(-p.y, p.x);}
PT RotateCW90(PT p) {return PT(p.y, -p.x);}
PT RotateCCW(PT p, double t) {return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));}
vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R) {
    vector<PT> res;
    double d = sqrt(dist2(a, b));
    double x = (d * d - R * R + r * r) / (2 * d);
    double y = sqrt(max((double) 0.0, r * r - x * x));
    PT v = (b - a) / d;
    res.push_back(a + v * x + RotateCCW90(v) * y);
    if (y > 0) res.push_back(a + v * x - RotateCCW90(v) * y);
    return res;
}

const int maxn = 500 + 5;
int n;
int x[maxn];
int y[maxn];
int r[maxn];
int f[maxn];
vector<PT> pts[maxn];

int dj[maxn];

int find(int u) {
    return dj[u] == u ? dj[u] : dj[u] = find(dj[u]);
}
void join(int u, int v) {
    dj[find(u)] = find(v);
}

void chemthan() {
    cin >> n;
    FOR(i, 0, n) cin >> x[i] >> y[i] >> r[i];
    FOR(i, 0, n) dj[i] = i;
    vector<PT> tmp;
    FOR(i, 0, n) FOR(j, i + 1, n) {
        if (make_tuple(x[i], y[i], r[i]) == make_tuple(x[j], y[j], r[j])) {
            f[j] = 1;
        }
    }
    FOR(i, 0, n) FOR(j, i + 1, n) if (!f[i] && !f[j]) {
        auto isqr = [&] (int x) {
            return (long long) x * x;
        };
        long long d = isqr(x[i] - x[j]) + isqr(y[i] - y[j]);
        if (isqr(r[i] - r[j]) <= d && d <= isqr(r[i] + r[j])) {
            join(i, j);
            vector<PT> vps = CircleCircleIntersection(PT(x[i], y[i]), PT(x[j], y[j]), r[i], r[j]);
            for (PT q : vps) {
                pts[i].pb(q);
                pts[j].pb(q);
                tmp.pb(q);
            }
        }
    }
    int res = 1;
    sort(all(tmp));
    FOR(i, 0, sz(tmp)) {
        if (!i || sign(dist(tmp[i], tmp[i - 1]))) {
            res--;
        }
    }
    FOR(i, 0, n) if (!f[i]) {
        sort(all(pts[i]));
        FOR(j, 0, sz(pts[i])) {
            if (!j || sign(dist(pts[i][j], pts[i][j - 1]))) {
                res++;
            }
        }
    }
    FOR(i, 0, n) if (!f[i] && dj[i] == i) {
        res++;
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
    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}