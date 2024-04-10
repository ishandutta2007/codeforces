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
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}

void chemthan() {
    long long n, l, r, k;
    cin >> n >> l >> r >> k;
    long long d = r - l + 1;
    if (d <= 0) d += n;
    if (d == n) {
        long long res = -1;
        for (long long x = 1; x * x <= k; x++) {
            if (k % x == 0) {
                long long y = k / x;
                for (long long z : {x, y}) {
                    if (n <= z && z <= n + n) {
                        chkmax(res, z - n);
                    }
                }
            }
        }
        for (long long x = 1; x * x <= k + 1; x++) {
            if ((k + 1) % x == 0) {
                long long y = (k + 1) / x;
                for (long long z : {x, y}) {
                    if (n < z && z <= n + n) {
                        chkmax(res, z - n);
                    }
                }
            }
        }
        cout << res << "\n";
        return;
    }
    int lim = 1e6;
    if (n <= lim) {
        for (long long t = n; t >= 0; t--) {
            long long rr = k % (n + t);
            if (d + max(1LL, t - n + d) - 1 <= rr && rr <= d + min(d, t)) {
                cout << t << "\n";
                return;
            }
        }
        cout << -1 << "\n";
        return;
    }
    long long res = -1;
    FOR(i, 0, lim + 1) {
        long long lo = max(n, k / (i + 1) + 1) - n;
        long long hi = (i ? min(n + n, k / i) : n + n) - n;
        if (lo <= hi) {
            long long u = lo - 1;
            long long v = hi;
            while (u < v) {
                long long w = u + v + 1 >> 1;
                if (d + max(1LL, w - n + d) - 1 <= k - (n + w) * i) {
                    u = w;
                }
                else {
                    v = w - 1;
                }
            }
            long long w = u + v >> 1;
            if (w > lo - 1 && k - (n + w) * i <= d + min(d, w)) {
                chkmax(res, w);
            }
        }
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