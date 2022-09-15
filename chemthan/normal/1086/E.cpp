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
const int MOD = 998244353;
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

const int maxn = 2000 + 5;
int fac[maxn];
int ifac[maxn];
int n;
int dp[maxn][maxn];

int calc(int n, int m) {
    if (!n) return !m;
    int& res = dp[n][m];
    if (~res) return res;
    res = 0;
    if (n > m) {
        int coef = mult(n - m, n - m);
        addmod(res, mult(coef, calc(n - 1, m)));
    }
    if (m >= 2) {
        int coef = mult(m, m - 1);
        addmod(res, mult(coef, calc(n - 1, m - 2)));
    }
    if (n > m && m) {
        int coef = mult(n - m, m);
        addmod(res, mult(coef, calc(n - 1, m - 1)));
        addmod(res, mult(coef, calc(n - 1, m - 1)));
    }
    return res;
}

int fen[2][maxn];
void upd(int fen[], int p, int val) {
    p++;
    for (; p < maxn; p += p & -p) {
        fen[p] += val;
    }
}
int query(int fen[], int p) {
    p++;
    int res = 0;
    for (; p > 0; p -= p & -p) {
        res += fen[p];
    }
    return res;
}

void chemthan() {
    fac[0] = 1; FOR(i, 1, maxn) fac[i] = mult(fac[i - 1], i);
    FOR(i, 0, maxn) ifac[i] = inv(fac[i]);
    ms(dp, -1);
    cin >> n;
    vector<vi> a(n, vi(n));
    FOR(i, 0, n) {
        for (int& x : a[i]) cin >> x, x--;
    }
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
    static int p[maxn];
    int x = mult(calc(n, n), ifac[n]);
    p[0] = 1; FOR(i, 1, maxn) p[i] = mult(p[i - 1], x);
    int res = 0;
    FOR(i, 0, n) {
        if (!i) {
            int coef = 0;
            static int f[maxn];
            ms(f, 0);
            FOR(t, 0, n - 1) {
                int tot = 0;
                FOR(j, 0, n) if (j < a[i][t] && !f[j]) {
                    tot++;
                }
                f[a[i][t]] = 1;
                addmod(coef, mult(tot, fac[n - t - 1]));
            }
            addmod(res, mult(coef, p[n - i - 1]));
        }
        else {
            static int f[maxn];
            static int g[maxn];
            ms(f, 0), ms(g, 0), ms(fen, 0);
            int num = 0;
            FORd(t, n, 0) {
                int x = a[i][t];
                int y = a[i - 1][t];
                num += f[x] + g[y];
                f[y] = g[x] = 1;
                upd(fen[0], x, 1);
                if (f[x]) {
                    upd(fen[1], x, 1);
                }
                if (g[y]) {
                    upd(fen[1], y, 1);
                }
                int u = query(fen[0], x - 1);
                int v = query(fen[1], x - 1);
                assert(v <= u);
                if (t < n - 1) {
                    int nnum = num;
                    int nv = v;
                    if (g[y]) {
                        assert(nnum);
                        nnum--;
                    }
                    if (g[y] && y < x) {
                        assert(nv);
                        nv--;
                    }
                    if (nnum && nv) {
                        int coef = mult(calc(n - t - 1, nnum - 1), ifac[n - t - 1]);
                        addmod(res, mult(nv, mult(p[n - i - 1], coef)));
                    }
                    int coef = mult(calc(n - t - 1, nnum), ifac[n - t - 1]);
                    addmod(res, mult(u - v, mult(p[n - i - 1], coef)));
                }
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