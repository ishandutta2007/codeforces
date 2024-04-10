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

int n, a, b, c, d;
int res;

inline int ff(int n) {
    return d + n * (c + n * (b + n * a));
}

void upd(int p) {
    int cnt = 0, t = p;
    while (t <= n) {
        cnt += n / t;
        if (t > n / p) break;
        t *= p;
    }
    res += cnt * ff(p);
}

struct Sieve {
    static const int maxn = 123456;
    static void work(int n) {
        int k = sqrt(n) + 2;
        while (k * k > n) k--;
        static int ispr[maxn];
        static int prs[maxn];
        fill_n(ispr + 2, k - 1, 1);
        int npr = 0;
        for (int i = 2; i <= k; i++) if (ispr[i]) {
            for (int j = i * i; j <= k; j += i) {
                ispr[j] = 0;
            }
            prs[npr++] = i;
            upd(i);
        }
        static int f[maxn];
        fill_n(f, k + 1, 0);
        for (int i = k + 1; i <= n; i += k) {
            int j = min(i + k - 1, n);
            for (int u = 0; u < npr; u++) {
                int p = prs[u];
                for (int q = (i + p - 1) / p * p; q <= j; q += p) {
                    f[q - i] = i;
                }
            }
            for (int u = i; u <= j; u++) if (f[u - i] < i) {
                upd(u);
            }
        }
    }
};

void chemthan() {
    cin >> n >> a >> b >> c >> d;
    Sieve::work(n);
    if (res < 0) cout << (long long) res + (1LL << 32) << "\n";
    else cout << res << "\n";
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