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

const int maxn = 2e5 + 5;
int n, m;
int a[maxn];
int b[maxn];
int pr, base;
int p[maxn];
int f[maxn];
int g[maxn];

int ispr(int k) {
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            return 0;
        }
    }
    return 1;
}

int calc1(int l, int r) {
    if (l >= r) return 0;
    r--;
    int res = f[r];
    if (l) {
        submod(res, f[l - 1], pr);
    }
    return mult(res, p[maxn - l - 1], pr);
}

int calc2(int l, int r) {
    if (l >= r) return 0;
    r--;
    swap(l, r);
    l = n - l - 2, r = n - r - 2;
    int res = g[r];
    if (l) {
        submod(res, g[l - 1], pr);
    }
    return mult(res, p[maxn - l - 1], pr);
}

void chemthan() {
    pr = INF + myrand() % (INF / 100);
    while (!ispr(pr)) pr++;
    base = 2311;
    p[0] = 1; FOR(i, 1, maxn) p[i] = mult(p[i - 1], base, pr);

    cin >> n >> m;
    FOR(i, 0, n) cin >> a[i];
    sort(a, a + n);
    FOR(i, 0, n - 1) b[i] = a[i + 1] - a[i];
    FOR(i, 0, n - 1) {
        if (i) {
            f[i] = f[i - 1];
        }
        addmod(f[i], mult(b[i], p[i], pr), pr);
    }
    reverse(b, b + n - 1);
    FOR(i, 0, n - 1) {
        if (i) {
            g[i] = g[i - 1];
        }
        addmod(g[i], mult(b[i], p[i], pr), pr);
    }
    vi res;
    FOR(i, 0, n) {
        if (calc1(0, i) == calc2(0, i) && calc1(i + 1, n - 1) == calc2(i + 1, n - 1)) {
            if (i == n - 1) {
                res.pb((a[0] + a[n - 1]) % m);
            }
            else {
                if ((a[0] + a[i]) % m == (a[i + 1] + a[n - 1]) % m) {
                    res.pb((a[0] + a[i]) % m);
                }
            }
        }
    }
    sort(all(res)), uni(res);
    cout << sz(res) << "\n";
    FOR(i, 0, sz(res)) cout << res[i] << " \n"[i == sz(res) - 1];
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