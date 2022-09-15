#include <bits/stdc++.h>
using namespace std; //#pragma GCC optimize("Ofast")
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

const int maxn = 1e5 + 5;
const int maxk = 100 + 5;
int n, k, len;
int a[maxn];
int dp[maxn][maxk];

int st[2][maxn << 1];
void upd(int st[], int p, int val) {
    for (st[p += maxn] = val; p > 1; ) p >>= 1, st[p] = min(st[p << 1], st[p << 1 | 1]);
}
int query(int st[], int l, int r) {
    int res = INF;
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) chkmin(res, st[l++]);
        if (r & 1) chkmin(res, st[--r]);
    }
    return res;
}

int find1(int u) {
    int lo = 1, hi = u + 1;
    while (lo < hi) {
        int mi = lo + hi >> 1;
        if (query(st[0], mi, u) < INF) {
            lo = mi + 1;
        }
        else {
            hi = mi;
        }
    }
    return lo + hi >> 1;
}

int find2(int u) {
    int lo = 1, hi = u + 1;
    while (lo < hi) {
        int mi = lo + hi >> 1;
        if (query(st[0], mi, u) != INF && query(st[0], mi, u) != -query(st[1], mi, u)) {
            lo = mi + 1;
        }
        else {
            hi = mi;
        }
    }
    return lo + hi >> 1;
}

void chemthan() {
    cin >> n >> k >> len; len--;
    FOR(i, 1, n + 1) {
        cin >> a[i];
        if (a[i] != -1) {
            upd(st[0], i, +a[i]);
            upd(st[1], i, -a[i]);
        }
        else {
            upd(st[0], i, +INF);
            upd(st[1], i, +INF);
        }
    }
    static int g[maxn][maxk];
    static int h[maxn];
    dp[0][k + 1] = 1, h[0] = 1;
    FOR(i, 1, n + 1) {
        int v = find1(i);
        int u = find2(i);
        chkmax(v, i - len + 1);
        chkmax(u, i - len + 1);
        if (v <= i) {
            FOR(j, 1, k + 1) {
                addmod(dp[i][j], h[i - 1]);
                if (v >= 2) {
                    submod(dp[i][j], h[v - 2]);
                }
                submod(dp[i][j], g[i - 1][j]);
                if (v >= 2) {
                    addmod(dp[i][j], g[v - 2][j]);
                }
            }
        }
        if (u < v) {
            v--;
            int ix = query(st[0], u, i);
            addmod(dp[i][ix], h[v - 1]);
            if (u >= 2) {
                submod(dp[i][ix], h[u - 2]);
            }
            submod(dp[i][ix], g[v - 1][ix]);
            if (u >= 2) {
                addmod(dp[i][ix], g[u - 2][ix]);
            }
        }
        h[i] = h[i - 1];
        FOR(j, 0, maxk) {
            g[i][j] = g[i - 1][j];
            addmod(g[i][j], dp[i][j]);
            addmod(h[i], dp[i][j]);
        }
    }
    int res = 0;
    FOR(i, 1, k + 1) addmod(res, dp[n][i]);
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