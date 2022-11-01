#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

const int C = 22;
const int N = 5e5 + 7;
const int INF = 1e8 + 7;

int ans[N];
int n;
vector<pair<int, int> > adj[N];
int size[N], best[N], best_c[N];
int h[1 << 22], dep[N];

void dfs_size(int u) {
	size[u] = 1;
	best[u] = -1;
	for (auto vv : adj[u]) {
		dep[vv.first] = dep[u] + 1;
		dfs_size(vv.first);
		size[u] += size[vv.first];
		if (best[u] == -1 || size[vv.first] > size[best[u]]) {
			best[u] = vv.first;
			best_c[u] = vv.second;
		}
	}
}

int delta;
vector<int> record;

void clear() {
	delta = 0;
	while (record.size()) {
		h[record.back()] = -INF;
		record.pop_back();
	}
}

void insert(int pos, int v) {
	pos ^= delta;
	h[pos] = max(h[pos], v);
	record.push_back(pos);
}

int get_val(int pos) {
	return h[pos ^ delta];
}

vector<pair<int, int> > vec;

void collect(int u, int mask) {
	vec.push_back(make_pair(mask, dep[u]));
	for (auto vv : adj[u]) {
		int v = vv.first;
		collect(v, mask ^ (1 << vv.second));
	}
}

void dfs(int u) {
	ans[u] = 0;
	for (auto vv : adj[u]) {
		int v = vv.first;
		if (v != best[u]) {
			dfs(v);
			ans[u] = max(ans[u], ans[v]);
			clear();
		}
	}
	if (best[u] == -1) {
		insert(0, dep[u]);
		return ;
	}
	dfs(best[u]);
	ans[u] = max(ans[u], ans[best[u]]);
	delta ^= (1 << best_c[u]);
	insert(0, dep[u]);
	ans[u] = max(ans[u], get_val(0) - dep[u]);

	// printf("root = %d\n", u);
	for (int c = 0; c < C; c++) {
		ans[u] = max(ans[u], get_val(1 << c) - dep[u]);
		// printf("%d %d\n", c, get_val(1 << c));
	}
	// printf("%d %d xxxxxxxx\n", best_c[u], get_val((1 << 18) | (1 << 0)));

	for (auto vv : adj[u]) {
		int v = vv.first;
		if (v == best[u]) continue;
		vec.clear();
		collect(v, 1 << vv.second);
		for (auto p : vec) {
			ans[u] = max(ans[u], p.second + get_val(p.first) - 2 * dep[u]);
			for (int c = 0; c < C; c++) {
				ans[u] = max(ans[u], p.second + get_val(p.first ^ (1 << c)) - 2 * dep[u]);
			}
		}
		for (auto p : vec) {
			insert(p.first, p.second);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int parent;
		char c;
		scanf("%d %c", &parent, &c);
		adj[parent].push_back(make_pair(i, c - 'a'));
	}
	fill(h, h + (1 << C), -INF);
	dfs_size(1);
	clear();
	dfs(1);
	for (int i = 1; i <= n; i++) {
		printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
	return 0;
}