#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, int>> E, Q;
vector<pair<int, int>> adj[200000];
int SZ, node_cnt, color[200000], num[200000], W[200000], hld[200000], parent[200000], depth[200000], tree[1 << 19];

int find_(int a) { return color[a] = color[a] == a ? a : find_(color[a]); }
void union_(int a, int b) { color[find_(a)] = find_(b); }

void dfs(int c)
{
	W[c] = 1;
	for (auto[n, w] : adj[c]) if (W[n] == 0) {
		parent[n] = c;
		depth[n] = depth[c] + 1;
		dfs(n);
		W[c] += W[n];
	}
}

void dfs2(int c)
{
	int mx = -1, mw;
	num[c] = node_cnt++;
	for (auto [n, w] : adj[c]) if (W[n] < W[c] && (mx == -1 || W[mx] < W[n])) mx = n, mw = w;
	if (mx == -1) return;
	hld[mx] = hld[c];
	dfs2(mx);
	tree[SZ + num[mx]] = mw;
	for (auto [n, w] : adj[c]) if (W[n] < W[c] && mx != n) {
		dfs2(hld[n] = n);
		tree[SZ + num[n]] = w;
	}
}

int get_max(int s, int e)
{
	int ret = -1;
	for (s += SZ, e += SZ; s <= e; s >>= 1, e >>= 1) {
		if (s & 1) ret = max(ret, tree[s++]);
		if (~e & 1) ret = max(ret, tree[e--]);
	}
	return ret;
}

int query(int a, int b)
{
	int ret = -1;
	while (hld[a] != hld[b]) {
		if (depth[hld[a]] < depth[hld[b]]) swap(a, b);
		ret = max(ret, get_max(num[hld[a]], num[a]));
		a = parent[hld[a]];
	}
	if (num[a] > num[b]) swap(a, b);
	return max(ret, get_max(num[a] + 1, num[b]));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T, N, M, K;
	for (cin >> T; T--;) {
		long long ans, sum = 0;
		int mx = 0; Q.clear();
		cin >> N >> M >> K; E.resize(M);
		for (SZ = 1; SZ < N; SZ <<= 1);
		for (int i = 0; i < N; i++) {
			W[color[i] = i] = 0;
			adj[i].clear();
		}
		for (auto& [w, u, v] : E) cin >> u >> v >> w, --u, --v;
		sort(E.begin(), E.end());
		for (auto [w, u, v] : E) {
			if (find_(u) != find_(v)) {
				union_(u, v); sum += max(w - K, 0);
				adj[u].emplace_back(v, max(w - K, 0));
				adj[v].emplace_back(u, max(w - K, 0));
				mx = w;
			}
			else Q.emplace_back(w, u, v);
		}
		ans = sum - max(mx - K, 0) + abs(K - mx);
		dfs(node_cnt = 0); dfs2(0);
		for (int i = SZ; --i;) tree[i] = max(tree[2 * i], tree[2 * i + 1]);
		for (auto [w, u, v] : Q) ans = min(ans, sum - query(u, v) + abs(w - K));
		cout << ans << '\n';
	}
	return 0;
}