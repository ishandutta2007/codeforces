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

#define double long double
const int maxn = 100;
int n, m;
int a[maxn][maxn];
double f[maxn][maxn];
double dp[maxn][maxn][maxn];

double calc(int game, int bran, int who) {
    if (!game) return 0.0;
    double& res = dp[game][bran][who];
    if (res != -1.0) return res;
    res = 0.0;
    int x = (bran << game);
    int y = (bran << game) + (1 << game - 1);
    int z = (bran << game) + (1 << game);
    if (who < y) {
        FOR(i, y, z) {
            chkmax(res, calc(game - 1, bran << 1, who) + calc(game - 1, bran << 1 | 1, i));
        }
    }
    else {
        FOR(i, x, y) {
            chkmax(res, calc(game - 1, bran << 1, i) + calc(game - 1, bran << 1 | 1, who));
        }
    }
    res += f[game][who] * pow(2, game - 1);
    return res;
}

void solve() {
    cin >> n;
    m = 1 << n;
    FOR(i, 0, m) FOR(j, 0, m) cin >> a[i][j];
    FOR(i, 0, m) f[0][i] = 1.0;
    FOR(k, 1, n + 1) {
        for (int i = 0; i < m; i += (1 << k)) {
            FOR(x, 0, 1 << k - 1) FOR(y, 0, 1 << k - 1) {
                int u = i + x;
                int v = i + (1 << k - 1) + y;
                f[k][u] += f[k - 1][u] * f[k - 1][v] * a[u][v] / 100.0;
                f[k][v] += f[k - 1][u] * f[k - 1][v] * a[v][u] / 100.0;
            }
        }
    }
    FOR(i, 0, maxn) FOR(j, 0, maxn) FOR(k, 0, maxn) dp[i][j][k] = -1.0;
    double ans = 0.0;
    FOR(i, 0, m) {
        chkmax(ans, calc(n, 0, i));
    }
    cout << prec(9) << ans << "\n";
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