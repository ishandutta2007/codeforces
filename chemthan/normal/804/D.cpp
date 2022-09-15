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
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

const int maxn = 1e5 + 5;
int n, m, q;
vi adj[maxn];
int ptr;
int f[maxn];
int from[maxn];
int size[maxn];
long long sum[maxn];
int g[maxn];
vi v[maxn];
vector<long long> vv[maxn];

pi best;
void dfs(int u, int p, int d) {
    chkmax(best, mp(d, u));
    f[u] = ptr;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (v != p) {
            from[v] = u;
            dfs(v, u, d + 1);
        }
    }
}

void upd(int u, int p, int d) {
    size[ptr]++;
    sum[ptr] += d + g[ptr] / 2;
    v[ptr].pb(d + g[ptr] / 2);
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (v != p) {
            upd(v, u, d + 1);
        }
    }
}

void findcenter(int u) {
    best = mp(0, 0), dfs(u, -1, 0);
    int st = best.se;
    best = mp(0, 0), dfs(st, -1, 0);
    int ed = best.se;
    vi path;
    while (ed != st) {
        path.pb(ed);
        ed = from[ed];
    }
    path.pb(st);
    g[ptr] = sz(path) - 1;
    if (sz(path) & 1) {
        upd(path[sz(path) / 2], -1, 0);
    }
    else {
        int x = path[sz(path) / 2 - 1];
        int y = path[sz(path) / 2];
        upd(x, y, 1), upd(y, x, 1);
    }
}

map<int, ld> hs[maxn];

ld func(int x, int y) {
    if (hs[x].count(y)) return hs[x][y];
    ld& res = hs[x][y];
    FOR(i, 0, sz(v[x])) {
        int val = v[x][i];
        int mx = max(g[x], g[y]);
        int k = upper_bound(all(v[y]), mx - val - 1) - v[y].begin();
        if (k) {
            res -= (ld) val * k;
            res -= vv[y][k - 1];
            res += (ld) k * (mx - 1);
        }
    }
    return res;
}

void solve() {
    cin >> n >> m >> q;
    FOR(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    FOR(i, 0, n) if (!f[i]) {
        ptr++;
        findcenter(i);
        sort(all(v[ptr]));
        long long tot = 0;
        FOR(j, 0, sz(v[ptr])) {
            tot += v[ptr][j];
            vv[ptr].pb(tot);
        }
    }
    FOR(i, 0, q) {
        int x, y; cin >> x >> y; x--, y--;
        x = f[x], y = f[y];
        if (x != y) {
            ld ans = (ld) sum[x] / size[x] + (ld) sum[y] / size[y];
            if (mp(sz(v[x]), x) > mp(sz(v[y]), y)) {
                swap(x, y);
            }
            ans += func(x, y) / size[x] / size[y];
            cout << prec(9) << ans + 1 << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
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