#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;

int n, m;
long long tot = 0;
vector<int> adj[N];
vector<int> go[N];
set<pair<int, int>> edges;

vector<int> s;
int father[N], counter = 0, col[N], size[N];

void dfs(int u, int from = -1) {
	col[u] = ++counter;
	tot += 1LL * size[u] * (size[u] - 1) / 2;
	bool pass = false;
	for (auto v : go[u]) {
		if (v == from) continue;
		if (pass) { tot = m + 1; return ; }
		tot += 1LL * size[u] * size[v];
		dfs(v, u);
		pass = true;
	}
}

int find(int u) {
	return u == father[u] ? u : father[u] = find(father[u]);
}

int main() {
	scanf("%d %d", &n, &m);
	// n = 3e5, m = 3e5;
	for (int i = 0; i < n; i++) father[i] = i;
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		// u = rand() % n + 1, v = rand() % n + 1;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		adj[i].push_back(i);
		sort(adj[i].begin(), adj[i].end());
	}
	for (int i = 0; i < n; i++) s.push_back(i);
	sort(s.begin(), s.end(), [](const int i, const int j) { return adj[i] < adj[j]; });
	for (int i = 0, j; i < n; i = j) {
		int u = s[i];
		for (j = i; j < n && adj[s[j]] == adj[s[i]]; j++) {
			int v = s[j];
			u = find(u);
			v = find(v);
			father[u] = v;
		}
	}
	for (int u = 0; u < n; u++) {
		int uu = find(u);
		size[uu]++;
		for (auto v : adj[u]) {
			int vv = find(v);
			if (edges.count({uu, vv})) continue;
			edges.insert({uu, vv});
			edges.insert({vv, uu});
			if (uu != vv) {
				go[uu].push_back(vv);
				go[vv].push_back(uu);
			}
		}
	}
	for (int u = 0; u < n; u++) {
		if (go[u].size() > 2) {
			cout << "NO" << endl;
			return 0;
		}
	}
	for (int u = 0; u < n; u++) {
		if (find(u) != u) continue;
		if (go[u].size() == 1 || go[u].size() == 0) {
			dfs(u);
			break;
		}
	}
	if (tot != m) cout << "NO" << endl;
	else {
		puts("YES");
		for (int i = 0; i < n; i++) {
			printf("%d ", col[find(i)]);
		}
		puts("");
	}
}