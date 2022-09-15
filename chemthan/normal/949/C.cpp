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

const int maxn = 1e5 + 5;
int n, m, h;
int u[maxn];
vi adj[maxn];
vi radj[maxn];
int vis[maxn];
int num[maxn];
vi adj2[maxn];
int sum[maxn];
vi ver;

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    ver.pb(u);
}

void rdfs(int u, int id) {
    num[u] = id;
    sum[id - 1]++;
    for (int v : radj[u]) {
        if (!num[v]) {
            rdfs(v, id);
        }
    }
}

int dp[maxn];
int calc(int u) {
    int& res = dp[u];
    if (~res) return res;
    res = sum[u];
    for (int v : adj2[u]) {
        res += calc(v);
        chkmin(res, INF);
    }
    return res;
}

void chemthan() {
    ms(dp, -1);
    cin >> n >> m >> h;
    FOR(i, 0, n) cin >> u[i];
    FOR(i, 0, m) {
        int x, y; cin >> x >> y; x--, y--;
        auto check = [&] (int i, int j) {
            return (u[i] + 1) % h == u[j];
        };
        if (check(x, y)) {
            adj[x].pb(y);
            radj[y].pb(x);
        }
        if (check(y, x)) {
            adj[y].pb(x);
            radj[x].pb(y);
        }
    }
    FOR(i, 0, n) if (!vis[i]) dfs(i);
    int id = 1;
    FORd(i, n, 0) {
        int u = ver[i];
        if (!num[u]) {
            rdfs(u, id++);
        }
    }
    map<pi, int> hs;
    FOR(u, 0, n) {
        for (int v : adj[u]) {
            int uu = num[u] - 1;
            int vv = num[v] - 1;
            if (!hs.count(mp(uu, vv)) && uu != vv) {
                hs[mp(uu, vv)] = 1;
                adj2[uu].pb(vv);
            }
        }
    }
    pi best = mp(INF, INF);
    FOR(u, 0, id - 1) {
        chkmin(best, mp(calc(u), u));
    }
    cout << best.fi << "\n";
    ms(vis, 0);
    FOR(u, 0, n) if (num[u] == best.se + 1) {
        dfs(u);
        break;
    }
    vi vals; FOR(u, 0, n) if (vis[u]) vals.pb(u);
    FOR(i, 0, sz(vals)) cout << vals[i] + 1 << " \n"[i == sz(vals) - 1];
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