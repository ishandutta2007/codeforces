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

struct DominatorTree {
    static const int maxn = 200 + 5;
    int n, rt;
    vector<int> adj1[maxn];
    vector<int> adj2[maxn];
    vector<int> tree[maxn];
    vector<int> bucket[maxn];
    int par[maxn];
    int sdm[maxn];
    int dom[maxn];
    int dsu[maxn];
    int lbl[maxn];
    int arr[maxn];
    int rev[maxn];
    int tms;
    
    void init(int n, int rt) {
        this->n = n;
        this->rt = rt;
        for (int i = 0; i < n; i++) {
            adj1[i].clear();
            adj2[i].clear();
            tree[i].clear();
            bucket[i].clear();
        }
        fill_n(arr, n, -1);
        tms = 0;
    }
    void add(int u, int v) {
        adj1[u].push_back(v);
    }
    void dfs(int u) {
        arr[u] = tms, rev[tms] = u;
        lbl[tms] = tms, sdm[tms] = tms, dsu[tms] = tms;
        tms++;
        for (int i = 0; i < (int) adj1[u].size(); i++) {
            int w = adj1[u][i];
            if (!~arr[w]) dfs(w), par[arr[w]] = arr[u];
            adj2[arr[w]].push_back(arr[u]);
        }
    }
    int find(int u, int x = 0) {
        if (u == dsu[u]) return x ? -1 : u;
        int v = find(dsu[u], x + 1);
        if (v < 0) return u;
        if (sdm[lbl[dsu[u]]] < sdm[lbl[u]]) {
            lbl[u] = lbl[dsu[u]];
        }
        dsu[u] = v;
        return x ? v : lbl[u];
    }
    void join(int u, int v) {
        dsu[v] = u;
    }
    void build() {
        dfs(rt);
        for (int i = tms - 1; i >= 0; i--) {
            for (int j = 0; j < (int) adj2[i].size(); j++) {
                sdm[i] = min(sdm[i], sdm[find(adj2[i][j])]);
            }
            if (i > 1) bucket[sdm[i]].push_back(i);
            for (int j = 0; j < (int) bucket[i].size(); j++) {
                int w = bucket[i][j], v = find(w);
                if (sdm[v] == sdm[w]) dom[w] = sdm[w];
                else dom[w] = v;
            }
            if (i > 0) join(par[i], i);
        }
        for (int i = 1; i < tms; i++) {
            if (dom[i] != sdm[i]) dom[i] = dom[dom[i]];
            tree[rev[i]].push_back(rev[dom[i]]);
            tree[rev[dom[i]]].push_back(rev[i]);
        }
    }
} domtree;

const int maxn = 100 + 5;
int n, m, s, t;
vi adj[maxn];
int k;
int x[maxn];
int y[maxn];
vi g[maxn];
int d[maxn][maxn];
vi adj2[maxn];
int must[maxn][maxn];

int num[maxn];
int out[maxn];
int ptr;

void dfs(int u, int p) {
    num[u] = ptr++;
    FOR(i, 0, sz(adj2[u])) {
        int v = adj2[u][i];
        if (v != p) {
            dfs(v, u);
        }
    }
    out[u] = ptr - 1;
}

int isanc(int u, int v) {
    if (num[u] == -1 || num[v] == -1) return 0;
    return num[u] <= num[v] && out[u] >= out[v];
}

void work(int u) {
    domtree.init(n, u);
    FOR(v, 0, n) {
        FOR(i, 0, sz(adj[v])) {
            int w = adj[v][i];
            if (d[u][w] == d[u][v] + 1) {
                domtree.add(v, w);
            }
        }
    }
    domtree.build();
    FOR(i, 0, n) {
        adj2[i] = domtree.tree[i];
    }
    FOR(i, 0, n) num[i] = out[i] = -1;
    ptr = 0, dfs(u, -1);
    FOR(i, 0, sz(g[u])) {
        int ix = g[u][i];
        FOR(v, 0, n) {
            must[ix][v] = isanc(v, y[ix]);
//            if (ix == 1) {
//                db(x[ix]) db(y[ix]) endln
//            }
//            if (must[ix][v]) {
//                db(ix) db(v) endln
//            }
        }
    }
}

int dp[maxn][maxn];

void solve() {
    cin >> n >> m >> s >> t; s--, t--;
    FOR(i, 0, n) FOR(j, 0, n) d[i][j] = i == j ? 0 : INF;
    FOR(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v);
        d[u][v] = 1;
    }
    FOR(k, 0, n) FOR(i, 0, n) FOR(j, 0, n) chkmin(d[i][j], d[i][k] + d[k][j]);
    cin >> k;
    FOR(i, 0, k) {
        cin >> x[i] >> y[i], x[i]--, y[i]--;
        g[x[i]].pb(i);
    }
    FOR(u, 0, n) work(u);
    FOR(i, 0, n) FOR(j, 0, k + 1) dp[i][j] = INF;
    FOR(i, 0, k) dp[t][i] = 0;
    while (1) {
        int found = 0;
        
        FOR(u, 0, n) FOR(ix, 0, k + 1) {
            if (ix < k && u != y[ix]) {
                int tmp = 0;
                FOR(v, 0, n) if (d[u][v] == 1 && d[u][v] + d[v][y[ix]] == d[u][y[ix]]) {
                    chkmax(tmp, dp[v][ix]);
                }
                if (chkmin(dp[u][ix], tmp)) {
                    found = 1;
                }
            }
            
            int tmp = INF;
            FOR(i, 0, k) if (i != ix && must[i][u]) {
                chkmin(tmp, dp[u][i] + 1);
            }
            if (ix < k) {
                FOR(v, 0, n) if (d[u][v] + d[v][y[ix]] == d[u][y[ix]] && must[ix][v]) {
                    chkmin(tmp, dp[v][ix]);
                }
            }
            if (chkmin(dp[u][ix], tmp)) {
                found = 1;
            }
        }
        
        if (!found) break;
    }
    int res = dp[s][k];
    if (res == INF) res = -1;
    cout << res << "\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int JUDGE_ONLINE = 1;
    if (argc > 1) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[2], "w", stdout));
    }
    solve();
    if (!JUDGE_ONLINE) {
        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}