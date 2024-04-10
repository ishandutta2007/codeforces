#include <bits/stdc++.h>
using namespace std;

#ifdef _LOCAL_
    #define cout cerr
#endif
#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
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
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

const int maxn = 1000 + 5;
int n, m;
vi adj1[maxn];
vi adj2[maxn];
map<int, int> g[maxn];
int ifac[maxn];
map<vi, int> hs;
unordered_map<int, int> dp[13][13][maxn];

inline int query(vi v) {
    if (hs.count(v)) return hs[v];
    int res = sz(hs);
    return hs[v] = res;
}

pi best;
int from[maxn];
int c1, c2;
void dfs(int u, int p = -1, int lev = 0) {
    chkmax(best, mp(lev, u));
    FOR(i, 0, sz(adj2[u])) {
        int v = adj2[u][i];
        if (v != p) {
            from[v] = u;
            dfs(v, u, lev + 1);
        }
    }
}
void center() {
    best = mp(0, 0);
    dfs(0);
    int u = best.se;
    best = mp(0, u);
    dfs(u);
    int v = best.se;
    vi path;
    int ptr = v;
    while (ptr != u) {
        path.pb(ptr);
        ptr = from[ptr];
    }
    path.pb(u);
    if (sz(path) & 1) {
        ptr = v;
        FOR(i, 0, sz(path) - 1 >> 1) {
            ptr = from[ptr];
        }
        c1 = ptr, c2 = m;
    }
    else {
        ptr = v;
        FOR(i, 0, sz(path) - 1 >> 1) {
            ptr = from[ptr];
        }
        c1 = ptr, c2 = from[ptr];
    }
}

int func(int u1, int p1, int u2, int p2) {
    if (dp[u2][p2][u1].count(p1)) return dp[u2][p2][u1][p1];
    int& res = dp[u2][p2][u1][p1];
    vi ver1;
    FOR(i, 0, sz(adj1[u1])) {
        int v1 = adj1[u1][i];
        if (v1 != p1) {
            ver1.pb(v1);
        }
    }
    vi ver2;
    unordered_map<int, int> hs;
    FOR(i, 0, sz(adj2[u2])) {
        int v2 = adj2[u2][i];
        if (v2 != p2) {
            ver2.pb(v2);
            hs[g[v2][u2]]++;
        }
    }
    int f[sz(ver1) + 1][1 << sz(ver2)] = {};
    f[0][0] = 1;
    FOR(i, 0, sz(ver1)) FOR(j, 0, 1 << sz(ver2)) {
        addmod(f[i + 1][j], f[i][j]);
        FOR(k, 0, sz(ver2)) if (!bit(j, k)) {
            addmod(f[i + 1][j | (1 << k)], mult(f[i][j], func(ver1[i], u1, ver2[k], u2)));
        }
    }
    res = f[sz(ver1)][(1 << sz(ver2)) - 1];
    FORall(it, hs) {
        res = mult(res, ifac[it->se]);
    }
    return res;
}

int dfs2(int u, int p = -1) {
    vi vx;
    FOR(i, 0, sz(adj2[u])) {
        int v = adj2[u][i];
        if (v != p) {
            vx.pb(dfs2(v, u));
        }
    }
    sort(all(vx));
    return g[u][p] = query(vx);
}

void solve() {
    ifac[0] = 1; FOR(i, 1, maxn) ifac[i] = mult(ifac[i - 1], inv(i));
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj1[u].pb(v), adj1[v].pb(u);
    }
    cin >> m;
    FOR(i, 0, m - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj2[u].pb(v), adj2[v].pb(u);
    }
    center();
    int ans = 0;
    if (c2 == m) {
        dfs2(c1, c2);
        FOR(u, 0, n) {
            addmod(ans, func(u, n, c1, m));
        }
    }
    else {
        int x1 = dfs2(c1, c2);
        int x2 = dfs2(c2, c1);
        FOR(u, 0, n) {
            FOR(i, 0, sz(adj1[u])) {
                int v = adj1[u][i];
                if (u > v) continue;
                addmod(ans, mult(func(u, v, c1, c2), func(v, u, c2, c1)));
                if (x1 != x2) {
                    addmod(ans, mult(func(u, v, c2, c1), func(v, u, c1, c2)));
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    printf("\nTime elapsed: %dms\n", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}