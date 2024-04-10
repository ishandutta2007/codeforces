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
const ld EPS = 1e-12;
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

const int maxn = 50 + 5;
int n, s;
int a[maxn];
vii adj[maxn];
int size[maxn];
int d[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];

void dfs(int u, int p) {
    size[u] = a[u];
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i].fi;
        if (v != p) {
            dfs(v, u);
            size[u] += size[v];
        }
    }
}

int calc(int u, int p, int t1, int t2) {
    if (p == n) t1 += t2, t2 = 0;
    int& res = dp[u][p][t1][t2];
    if (~res) return res;
    res = INF;
    vector<pair<pi, int> > vals;
    vi fmn(n, 0), fmx(n, 0);
    FOR(v, 0, n) if (v != u && v != p && sz(adj[v]) == 1 && (p == n || d[p][u] + d[u][v] == d[p][v])) {
        FOR(tt, 1, t1 + 1) {
            vals.pb(mp(mp(calc(v, u, tt, t2 + t1 - tt) + d[u][v], tt), v));
        }
    }
    if (!sz(vals)) {
        if (!t2) return res = 0;
        return res = calc(u, n, t2, 0);
    }
    sort(all(vals)), reverse(all(vals));
    int totmn = 0, totmx = 0;
    FOR(i, 0, sz(vals)) {
        int v = vals[i].se;
        int tt = vals[i].fi.se;
        totmn -= fmn[v];
        totmx -= fmx[v];
        if (!fmn[v]) fmn[v] = tt;
        else chkmin(fmn[v], tt);
        if (!fmx[v]) fmx[v] = tt;
        else chkmax(fmx[v], tt);
        if (fmn[v] == 1) fmn[v] = 0;
        totmn += fmn[v];
        totmx += fmx[v];
        if (totmn <= t1 && t1 <= totmx) {
            return res = vals[i].fi.fi;
        }
    }
    return res;
}

void solve() {
    cin >> n;
    FOR(i, 0, n) FOR(j, 0, n) d[i][j] = i == j ? 0 : INF;
    FOR(i, 0, n - 1) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        chkmin(d[u][v], w);
        chkmin(d[v][u], w);
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
    FOR(k, 0, n) FOR(i, 0, n) FOR(j, 0, n) chkmin(d[i][j], d[i][k] + d[k][j]);
    cin >> s; s--;
    int m; cin >> m;
    FOR(i, 0, m) {
        int x; cin >> x; x--;
        a[x]++;
    }
    dfs(s, -1);
    ms(dp, -1);
    int res = INF;
    FOR(i, 0, sz(adj[s])) {
        int u = adj[s][i].fi;
        int w = adj[s][i].se;
        if (size[u]) {
            chkmin(res, calc(u, s, size[u], m - size[u]) + w);
        }
    }
    cout << res << "\n";
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