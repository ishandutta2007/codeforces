#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
typedef long long ll;
using namespace std;
const int N = 1 << 20;
int t[2 * N], tree[N];
void upd(int a, int b, int c, int u = 1, int l = 0, int r = N - 1) {
	if (a <= l && r <= b) {
		t[u] = max(t[u], c);
		return;
	}
	if (b < l || r < a)
		return;
	int m = (l + r) / 2;
	upd(a, b, c, 2 * u, l, m);
	upd(a, b, c, 2 * u + 1, m + 1, r);
}
int query(int a, int u = 1, int l = 0, int r = N - 1) {
	if (a <= l && r <= a) 
		return t[u];
	if (a < l || r < a)
		return 0;
	int m = (l + r) / 2;
	return max({query(a, 2 * u, l, m), query(a, 2 * u + 1, m + 1, r), t[u]});
}
int n, m, in[N], out[N], tim, dp[N], jj[N][20], a[N], b[N], c[N], dep[N], p[N];
vector<pair<int, int>> e[N];
int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}
void dfs(int u, int p) {
	jj[u][0] = p;
	for (int i = 0; i + 1 < 20; i++)
		jj[u][i + 1] = jj[jj[u][i]][i];
	in[u] = ++tim;
	dep[u] = dep[p] + 1;
	for (auto [v, w] : e[u])
		if (v != p) {
			dp[v] = dp[u] ^ w;
			dfs(v, u);
		}
	out[u] = tim;
}
int lca(int a, int b) {
	if (dep[a] < dep[b])
		swap(a, b);
	for (int i = 19; 0 <= i; i--)
		if (dep[a] - (1 << i) >= dep[b])
			a = jj[a][i];
	if (a == b)
		return a;
	for (int i = 19; 0 <= i; i--)
		if (jj[a][i] != jj[b][i])
			a = jj[a][i], b = jj[b][i];
	return jj[a][0];
}
void add_edge(int a, int b, int c) {
	e[a].emplace_back(b, c);
	e[b].emplace_back(a, c);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> c[i];
		int x = find(a[i]);
		int y = find(b[i]);
		if (x != y) {
			tree[i] = 1;
			p[x] = y;
			add_edge(a[i], b[i], c[i]);
		}
	}
	int root = n + 1;
	for (int i = 1; i <= n; i++)
		if (find(i) == i)
			add_edge(root, i, 0);
	dfs(root, 0);
	for (int i = 0; i < m; i++) {
		if (tree[i]) {
			cout << "YES\n";
			continue;
		}
		int A = a[i];
		int B = b[i];
		int L = lca(A, B);
		if ((dp[A] ^ dp[B] ^ c[i]) == 0) {
			cout << "NO\n";
			continue;
		}
		if (query(in[A]) > dep[L] || query(in[B]) > dep[L]) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		auto work = [&](int u) {
			while (u != L) {
				upd(in[u], out[u], dep[u]);
				u = jj[u][0];
			}
		};
		work(A);
		work(B);
	}
	return 0;
}