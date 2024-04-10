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

const int maxn = 5010;
int n;
vi adj[maxn];
bool vis[maxn];
int size[maxn];
int f[maxn][2][maxn];
int g[maxn][2][maxn];

void dfs1(int u) {
    vis[u] = size[u] = 1;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (!vis[v]) {
            dfs1(v);
            size[u] += size[v];
        }
    }
}

void dfs2(int u) {
    vis[u] = 1;
    if (sz(adj[u]) == 1) {
        f[u][0][0] = f[u][1][1] = 0;
        return;
    }
    f[u][0][0] = f[u][1][0] = 0;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (!vis[v]) {
            dfs2(v);
            FOR(j, 0, 2) FOR(k, 0, size[u] + 1) g[u][j][k] = 0x3f3f3f3f;
            FOR(j, 0, size[v] + 1) FOR(k, 0, 2) FOR(l, 0, size[u] - j + 1) {
                g[u][k][l + j] = min(g[u][k][l + j], f[u][k][l] + f[v][0][j] + (k ^ 0));
                g[u][k][l + j] = min(g[u][k][l + j], f[u][k][l] + f[v][1][j] + (k ^ 1));
            }
            FOR(j, 0, 2) FOR(k, 0, size[u] + 1) f[u][j][k] = g[u][j][k];
        }
    }
}

void solve() {
    ms(vis, 0); ms(f, 0x3f); ms(g, 0x3f);
    scanf("%d", &n);
    FOR(i, 0, n - 1) {
        int x, y; scanf("%d%d", &x, &y); x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int nDes = 0;
    FOR(i, 0, n) if (sz(adj[i]) == 1) nDes++;
    FOR(i, 0, n) if (sz(adj[i]) > 1) {
        dfs1(i); ms(vis, 0); dfs2(i);
        printf("%d", min(f[i][0][nDes >> 1], f[i][1][nDes >> 1]));
        break;
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