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

const int maxn = 200010;
int n, m;
vii pos[maxn];
vii adj[maxn];
bool vis1[maxn];
bool vis2[maxn];
int root;
int ans[maxn];

void add(int u, int v, int w) {
	adj[u].push_back(make_pair(v, w));
	if (u != v) adj[v].push_back(make_pair(u, -w));
}

void dfs1(int u, int p) {
	vis1[u] = 1;
	bool flag = false;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].first;
		if (!vis1[v]) dfs1(v, u);
		else if (v != p || flag) root = v;
		if (v == p) flag = true;
	}
}

void dfs2(int u, int p) {
	vis2[u] = 1;
	bool flag = false;
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i].first;
		int k = adj[u][i].second;
		if (!vis2[v]) {
			ans[abs(k)] = k > 0 ? 0 : 1;
			dfs2(v, u);
		}
		else if (v == root) {
			if (u == root) ans[abs(k)] = k > 0 ? 1 : 0;
			else if (v != p || flag) ans[abs(k)] = k > 0 ? 0 : 1;
			flag = true;
		}
	}
}

void solve() {
	ms(vis1, 0); ms(vis2, 0); ms(ans, 0);
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {
		int k; scanf("%d", &k);
		FOR(j, 0, k) {
			int v; scanf("%d", &v);
			pos[abs(v)].push_back(make_pair(i, v));
		}
	}
	FOR(i, 1, m + 1) {
		if (!sz(pos[i])) continue;
		else if (sz(pos[i]) == 1) add(pos[i][0].first, pos[i][0].first, pos[i][0].second);
		else if (pos[i][0].second == pos[i][1].second) {
			add(pos[i][0].first, pos[i][0].first, pos[i][0].second);
			add(pos[i][1].first, pos[i][1].first, pos[i][1].second);
		}
		else add(pos[i][0].first, pos[i][1].first, pos[i][0].second);
	}
	FOR(i, 0, n) if (!vis1[i]) {
		root = -1; dfs1(i, -1);
		if (root == -1) {printf("NO"); return;}
		dfs2(root, -1);
	}
	printf("YES\n");
	FOR(i, 1, m + 1) printf("%d", ans[i]);
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