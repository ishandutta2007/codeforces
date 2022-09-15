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

template<class num_t, class cmp = less<num_t> >
struct RMQ2D {
    static const int maxn = 5e2 + 5;
    static const int maxm = 5e2 + 5;
    static const int logn = 10 + 1;
    static const int logm = 10 + 1;
    int n, m;
    num_t a[maxn][maxm];
    num_t f[logm][maxn][maxm];
    num_t g[logm][logn][maxm][maxn];

    inline num_t best(const num_t& a, const num_t& b) {
        return cmp()(a, b) ? a : b;
    }
    void init(int _n, int _m) {
        n = _n, m = _m;
    }
    num_t* operator [] (int u) {
        assert(u < n);
        return a[u];
    }
    void build() {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= m; i++) {
                f[0][k][i] = a[k - 1][i - 1];
            }
            for (int j = 1; 1 << j <= m; j++) {
                for (int i = 0; i + (1 << j) - 1 <= m; i++) {
                    f[j][k][i] = best(f[j - 1][k][i], f[j - 1][k][i + (1 << (j - 1))]);
                }
            }
        }
        for (int k = 1; k <= m; k++) {
            for (int l = 0; k + (1 << l) - 1 <= m; l++) {
                for (int i = 1; i <= n; i++) {
                    g[l][0][k][i] = f[l][i][k];
                }
                for (int j = 1; 1 << j <= n; j++) {
                    for (int i = 0; i + (1 << j) - 1 <= n; i++) {
                        g[l][j][k][i] = best(g[l][j - 1][k][i], g[l][j - 1][k][i + (1 << (j - 1))]);
                    }
                }
            }
        }
    }
    num_t query(int x, int y, int z, int t) {
        x++, y++, z++, t++;
        int a = z - x + 1, b = t - y + 1;
        int lga = __lg(a);
        int lgb = __lg(b);
        int res = g[lgb][lga][y][x];
        res = best(res, g[lgb][lga][y + b - (1 << (lgb))][x + a - (1 << (lga))]);
        res = best(res, g[lgb][lga][y][x + a - (1 << (lga))]);
        res = best(res, g[lgb][lga][y + b - (1 << (lgb))][x]);
        return res;
    }
};
RMQ2D<int, greater<int>> rmq;

void chemthan( ) {
    int n, m, q; cin >> n >> m >> q;
    vector<string> a(n);
    vector<vi> vr(n + 1, vi(m + 1));
    vector<vi> vg(n + 1, vi(m + 1));
    vector<vi> vb(n + 1, vi(m + 1));
    vector<vi> vy(n + 1, vi(m + 1));
    FOR(i, 0, n) {
        string s; cin >> s;
        a[i] = s;
        FOR(j, 0, m) {
            if (s[j] == 'R') {
                vr[i + 1][j + 1] = 1;
            }
            if (s[j] == 'G') {
                vg[i + 1][j + 1] = 1;
            }
            if (s[j] == 'B') {
                vb[i + 1][j + 1] = 1;
            }
            if (s[j] == 'Y') {
                vy[i + 1][j + 1] = 1;
            }
        }
    }
    FOR(i, 1, n + 1) FOR(j, 1, m + 1) {
        vr[i][j] += vr[i - 1][j] + vr[i][j - 1] - vr[i - 1][j - 1];
        vg[i][j] += vg[i - 1][j] + vg[i][j - 1] - vg[i - 1][j - 1];
        vb[i][j] += vb[i - 1][j] + vb[i][j - 1] - vb[i - 1][j - 1];
        vy[i][j] += vy[i - 1][j] + vy[i][j - 1] - vy[i - 1][j - 1];
    }
    auto query = [&] (vector<vi>& A, int x0, int y0, int x1, int y1) {
        x0++, y0++, x1++, y1++;
        int res = A[x1][y1];
        if (x0) res -= A[x0 - 1][y1];
        if (y0) res -= A[x1][y0 - 1];
        if (x0 && y0) res += A[x0 - 1][y0 - 1];
        return res;
    };
    rmq.init(n, m);
    FOR(i, 0, n - 1) FOR(j, 0, m - 1) {
        if (a[i][j] == 'R' && a[i][j + 1] == 'G' && a[i + 1][j] == 'Y' && a[i + 1][j + 1] == 'B') {
            int lo = 1, hi = min(i + 1, min(j + 1, min(n - i - 1, m - j - 1)));
            while (lo < hi) {
                int mi = lo + hi + 1 >> 1;
                if (query(vr, i - mi + 1, j - mi + 1, i, j) == mi * mi &&
                        query(vg, i - mi + 1, j + 1, i, j + mi) == mi * mi &&
                        query(vy, i + 1, j - mi + 1, i + mi, j) == mi * mi &&
                        query(vb, i + 1, j + 1, i + mi, j + mi) == mi * mi) {
                    lo = mi;
                }
                else {
                    hi = mi - 1;
                }
            }
            rmq[i][j] = lo + hi >> 1;
        }
    }
    rmq.build();
    while (q--) {
        int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1; x0--, y0--, x1--, y1--;
        int d = min(x1 - x0 + 1, y1 - y0 + 1);
        d /= 2;
        int lo = 0, hi = d;
        while (lo < hi) {
            int mi = lo + hi + 1 >> 1;
            if (mi <= rmq.query(x0 + mi - 1, y0 + mi - 1, x1 - mi, y1 - mi)) {
                lo = mi;
            }
            else {
                hi = mi - 1;
            }
        }
        int mi = lo + hi >> 1;
        cout << 4 * mi * mi << "\n";
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