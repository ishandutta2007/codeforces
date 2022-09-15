#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;

const int maxn = 2010;
int n, d;
int a[maxn];
vi adj[maxn];
ll f[maxn][maxn];
ll g[maxn][maxn];
bool vis[maxn];
bool flag[maxn][maxn];

int dfs(int u, int p) {
    vis[u] = 1;
    if (a[u] > a[p] || a[u] < a[p] - d) return 0;
    if (a[u] == a[p]) {
        if (flag[u][p] || flag[p][u]) return 0;
        flag[u][p] = flag[p][u] = 1;
    }
    ll res = 1;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (!vis[v]) res = (res * (dfs(v, p) + 1)) % mod;
    }
    return res;
}

void solve() {
    ms(f, 0); ms(g, 0); ms(vis, 0); ms(flag, 0);
    scanf("%d%d", &d, &n);
    FOR(i, 0, n) scanf("%d", a + i);
    FOR(i, 0, n - 1) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    int ans = 0;
    FOR(i, 0, n) {
        ms(vis, 0);
        ans = (ans + dfs(i, i)) % mod;
    }
    printf("%d", ans);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}