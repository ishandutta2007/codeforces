#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 100010;
int n, m;
int cat[maxn];
vi adj[maxn];
int cnt[maxn];
bool vis[maxn];
int ans;

void dfs(int u) {
    vis[u] = 1;
    if (cat[u]) cnt[u]++; else cnt[u] = 0;
    if (cnt[u] > m) return;
    if (sz(adj[u]) == 1 && u) ans++;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (!vis[v]) {
            cnt[v] = cnt[u];
            dfs(v);
        }
    }
}

void solve() {
    ms(cnt, 0); ms(vis, 0);
    scanf("%d%d", &n, &m);
    FOR(i, 0, n) scanf("%d", cat + i);
    FOR(i, 0, n - 1) {
        int x, y; scanf("%d%d", &x, &y); x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ans = 0; dfs(0);
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