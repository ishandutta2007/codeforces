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
//const int MOD = (int) 1e9 + 7;
const int MOD = 119 << 23 | 1;
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

namespace IP {
    const int mod = MOD;
    const int maxn = 1e5 + 5;
    int a[maxn];
    int fac[maxn];
    int ifac[maxn];
    int prf[maxn];
    int suf[maxn];

    int fpow(int n, int k) {
        int r = 1;
        for (; k; k >>= 1) {
            if (k & 1) r = (long long) r * n % mod;
            n = (long long) n * n % mod;
        }
        return r;
    }
    void upd(int u, int v) {
        a[u] = v;
    }
    void build() {
        fac[0] = ifac[0] = 1;
        for (int i = 1; i < maxn; i++) {
            fac[i] = (long long) fac[i - 1] * i % mod;
            ifac[i] = fpow(fac[i], mod - 2);
        }
    }
    //Calculate P(x) of degree k - 1, k values form 1 to k
    //P(i) = a[i]
    int calc(int x, int k) {
        prf[0] = suf[k + 1] = 1;
        for (int i = 1; i <= k; i++) {
            prf[i] = (long long) prf[i - 1] * (x - i + mod) % mod;
        }
        for (int i = k; i >= 1; i--) {
            suf[i] = (long long) suf[i + 1] * (x - i + mod) % mod;
        }
        int res = 0;
        for (int i = 1; i <= k; i++) {
            if (!((k - i) & 1)) {
                res = (res + (long long) prf[i - 1] * suf[i + 1] % mod
                        * ifac[i - 1] % mod * ifac[k - i] % mod * a[i]) % mod;
            }
            else {
                res = (res - (long long) prf[i - 1] * suf[i + 1] % mod
                        * ifac[i - 1] % mod * ifac[k - i] % mod * a[i] % mod + mod) % mod;
            }
        }
        return res;
    }
}

void chemthan() {
    int n, m, k; cin >> n >> m >> k;
    vi fac(k + 10);
    vi ifac(k + 10);
    fac[0] = 1; FOR(i, 1, sz(fac)) fac[i] = mult(fac[i - 1], i);
    FOR(i, 0, sz(ifac)) ifac[i] = inv(fac[i]);
    auto binom = [&] (int n, int k) {
        return mult(fac[n], mult(ifac[k], ifac[n - k]));
    };
    vector<vi> s(k + 10, vi(k + 10));
    s[0][0] = 1;
    FOR(i, 0, k + 9) FOR(j, 0, k + 10) {
        addmod(s[i + 1][j], mult(j, s[i][j]));
        if (j) {
            addmod(s[i + 1][j], s[i][j - 1]);
        }
    }
    int im = inv(m);

    auto calc = [&] (int n) {
        vi f(k + 1);
        FOR(i, 0, k + 1) {
            if (i <= n) {
                f[i] = mult(binom(n, i), fpow(im, i));
            }
        }
        int res = 0;
        FOR(i, 0, k + 1) {
            f[i] = mult(f[i], fac[i]);
            addmod(res, mult(s[k][i], f[i]));
        }
        return res;
    };
    IP::build();
    FOR(i, 0, k + 5) {
        IP::a[i] = calc(i);
    }
    cout << IP::calc(n, k + 4) << "\n";
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