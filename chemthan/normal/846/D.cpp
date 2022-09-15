#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
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
const int MOD2 = 1007681537;
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

template<class T, class cmp = less<T> > struct RMQ2D {
    static const int MAXN = 500 + 5;
    static const int MAXM = 500 + 5;
    static const int LOGN = 10 + 1;
    static const int LOGM = 10 + 1;
    int n, m;
    T a[MAXN][MAXM];
    T f[LOGM][MAXN][MAXM];
    T g[LOGM][LOGN][MAXM][MAXN];
    
    T best(T a, T b) {
        if (cmp()(a, b)) return a;
        return b;
    }
    void init(int n, int m) {
        this->n = n, this->m = m;
    }
    void upd(int u, int v, T x) {
        a[u][v] = x;
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
    T query(int x, int y, int z, int t) {
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
RMQ2D<int, greater<int> > rmq;

const int maxn = 500 + 5;
int n, m, k, q;
int x[maxn * maxn];
int y[maxn * maxn];
int t[maxn * maxn];

void solve() {
    cin >> n >> m >> k >> q;
    rmq.init(n, m);
    FOR(i, 0, n) FOR(j, 0, m) rmq.upd(i, j, INF + INF);
    FOR(i, 0, q) {
        cin >> x[i] >> y[i] >> t[i], x[i]--, y[i]--;
        rmq.upd(x[i], y[i], t[i]);
    }
    rmq.build();
    int ans = INF + INF;
    FOR(i, 0, n - k + 1) FOR(j, 0, m - k + 1) {
        chkmin(ans, rmq.query(i, j, i + k - 1, j + k - 1));
    }
    if (ans == INF + INF) ans = -1;
    cout << ans << "\n";
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}