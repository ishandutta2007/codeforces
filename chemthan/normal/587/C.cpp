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
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 100010;
const int maxe = 20;
int n, m, q;
vi adj[maxn];
bool vis[maxn];
int lev[maxn];
int p[maxn][maxe];
vi d[maxn][maxe];
int tms;
int tin[maxn];
int tou[maxn];

vi merge(vi& v1, vi& v2) {
    vi res; int cur1 = 0, cur2 = 0;
    while (cur1 < sz(v1) || cur2 < sz(v2)) {
        if (cur1 == sz(v1)) res.push_back(v2[cur2++]);
        else if (cur2 == sz(v2)) res.push_back(v1[cur1++]);
        else if (v1[cur1] < v2[cur2]) res.push_back(v1[cur1++]);
        else res.push_back(v2[cur2++]);
        if (sz(res) == 10) return res;
    }
    return res;
}

void dfs(int u) {
    tin[u] = tms++;
    vis[u] = 1;
    FOR(i, 1, maxe) {
        p[u][i] = p[p[u][i - 1]][i - 1];
        d[u][i] = merge(d[u][i - 1], d[p[u][i - 1]][i - 1]);
    }
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (!vis[v]) {
            lev[v] = lev[u] + 1;
            p[v][0] = u; dfs(v);
        }
    }
    tou[u] = tms++;
}

vi query(int u, int v) {
    if (lev[u] < lev[v]) swap(u, v);
    vi res;
    FORd(i, maxe, 0) if (lev[u] - (1 << i) >= lev[v]) {
        res = merge(res, d[u][i]);
        u = p[u][i];
    }
    FORd(i, maxe, 0) if (p[u][i] != p[v][i]) {
        res = merge(res, d[u][i]);
        res = merge(res, d[v][i]);
        u = p[u][i];
        v = p[v][i];
    }
    if (tin[v] <= tin[u] && tou[v] >= tou[u]) return merge(res, d[v][0]);
    res = merge(res, d[u][0]);
    res = merge(res, d[v][0]);
    return merge(res, d[p[u][0]][0]);
}

void solve() {
    ms(vis, 0); ms(p, 0); ms(lev, 0); tms = 0;
    scanf("%d%d%d", &n, &m, &q);
    FOR(i, 0, n - 1) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    FOR(i, 0, m) {int c; scanf("%d", &c); c--; d[c][0].push_back(i);}
    dfs(0);
    while (q--) {
        int u, v, a; scanf("%d%d%d", &u, &v, &a); u--; v--;
        vi res = query(u, v);
        a = min(a, sz(res));
        printf("%d", a); FOR(i, 0, a) printf(" %d", res[i] + 1); printf("\n");
    }
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