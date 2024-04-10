#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

const int maxn = 1e5 + 5;
const int maxx = 11;
int n, m;
vi adj[maxn];
int k, x;

int dp[maxn][3][maxx];

void dfs(int u, int p) {
    int f[1 << 3][maxx];
    ms(f, 0);
    f[0][0] = 1;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (v != p) {
            dfs(v, u);
            int g[1 << 3][maxx];
            ms(g, 0);
            FOR(k, 0, x + 1) FOR(l, 0, x + 1 - k) FOR(msk, 0, 1 << 3) FOR(j, 0, 3) {
                addmod(g[msk | (1 << j)][k + l], mult(f[msk][k], dp[v][j][l]));
            }
            FOR(msk, 0, 1 << 3) FOR(k, 0, x + 1) f[msk][k] = g[msk][k];
        }
    }
    FOR(i, 0, x + 1) {
        FOR(msk, 0, 1 << 3) {
            addmod(dp[u][0][i], mult(f[msk][i], k - 1));
            if (!bit(msk, 1)) {
                addmod(dp[u][2][i], mult(f[msk][i], m - k));
            }
            if (!bit(msk, 1) && !bit(msk, 2)) {
                if (i) {
                    addmod(dp[u][1][i], f[msk][i - 1]);
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    cin >> k >> x;
    dfs(0, -1);
    int ans = 0;
    FOR(i, 0, 3) FOR(j, 0, x + 1) {
        addmod(ans, dp[0][i][j]);
    }
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