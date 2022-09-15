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

const int maxn = 100010;
int n;
vi adj[maxn];
int vis[maxn];
int cnt[maxn];

void dfs(int u, int p) {
	vis[u] = 1;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p && sz(adj[v]) == 2) dfs(v, u);
	}
}

void solve() {
	ms(vis, 0); ms(cnt, 0);
	scanf("%d", &n);
	FOR(i, 0, n - 1) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	FOR(i, 0, n) if (sz(adj[i]) == 1) dfs(i, -1);
	FOR(i, 0, n) FOR(j, 0, sz(adj[i])) {int k = adj[i][j]; if (vis[k]) cnt[i]++;}
	FOR(i, 0, n) {
		int tmp = 0;
		FOR(j, 0, sz(adj[i])) {int k = adj[i][j]; if (sz(adj[k]) - min(2, cnt[k]) > 1) tmp++;}
		if (tmp > 2) {printf("No"); return;}
	}
	printf("Yes");
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}