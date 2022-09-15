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
#define pb push_back #define pf push_front
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
//const int MOD = (int) 1e9 + 7;
const int MOD = 31607;
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

void ORFFT(vector<short>& a, short p, int invert) {
    int n = sz(a);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k = 0; k < i; k++) {
                short u = a[j + k];
                short v = a[i + j + k];
                a[j + k] = (p - u < v) ? v - (p - u) : (u + v);
                a[i + j + k] = u;
            }
        }
    }
}

void IORFFT(vector<short>& a, short p, int invert) {
    int n = sz(a);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += i << 1) {
            for (int k = 0; k < i; k++) {
                short u = a[j + k];
                short v = a[i + j + k];
                a[j + k] = v;
                a[i + j + k] = (v <= u) ? (u - v) : (u + (p - v));
            }
        }
    }
}

void chemthan() {
    int n; cin >> n;
    vector<vi> a(n, vi(n));
    vector<vi> b(n, vi(n));
    vector<vi> ia(n, vi(n));
    vector<vi> ib(n, vi(n));
    FOR(i, 0, n) FOR(j, 0, n) {
        cin >> a[i][j];
        a[i][j] = mult(a[i][j], inv(10000));
        b[i][j] = (1 - a[i][j] + MOD) % MOD;
        ia[i][j] = inv(a[i][j]);
        ib[i][j] = inv(b[i][j]);
    }
    vi f(1 << n);
    vi g(1 << n);
    vector<short> res;
    vector<short> x(1 << n + 2);
    FOR(i, 0, n) {
        int p = 1;
        FOR(j, 0, n) p = mult(p, a[i][j]);
        f[0] = p;
        g[0] = 0;
        fill(all(x), 0);
        FOR(msk, 1, 1 << n) {
            int k = __lg(msk);
            int pmsk = msk ^ (1 << k);
            f[msk] = (long long) f[pmsk] * ia[i][k] * b[i][k] % MOD;
            g[msk] = g[pmsk] | (1 << k);
            if (k == i) {
                g[msk] |= 1 << n;
            }
            if (k == n - i - 1) {
                g[msk] |= 1 << n + 1;
            }
            x[g[msk]] += f[msk];
            if (MOD <= x[g[msk]]) {
                x[g[msk]] -= MOD;
            }
        }
        ORFFT(x, MOD, 0);
        if (!sz(res)) {
            res = x;
        }
        else {
            FOR(i, 0, sz(res)) res[i] = (int) res[i] * x[i] % MOD;
        }
    }
    IORFFT(res, MOD, 1);
    int ans = 1;
    submod(ans, res[(1 << n + 2) - 1]);
    cout << ans << "\n";
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