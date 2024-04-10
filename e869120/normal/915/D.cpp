#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
#pragma warning (disable: 4996)

int n, m, a[100009], b[100009], dist[100009], deg[100009];
bool used[100009]; vector<int>x[100009], y[100009], G, I;

void dfs(int ret, int pos) {
	if (ret == pos && G.size() >= 2) { I = G; return; }
	if (used[pos] == true) return;
	used[pos] = true;
	for (int i = 0; i < x[pos].size(); i++) {
		G.push_back(x[pos][i]);
		dfs(ret, x[pos][i]);
		G.pop_back();
	}
}

bool TopologicalSort() {
	queue<int>Q; vector<int>I;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) { Q.push(i); I.push_back(i); }
	}
	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		for (int i = 0; i < x[pos].size(); i++) {
			deg[x[pos][i]]--;
			if (deg[x[pos][i]] == 0) { Q.push(x[pos][i]); I.push_back(x[pos][i]); }
		}
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] >= 1) return false;
	}
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a[i], &b[i]);
		x[a[i]].push_back(b[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) used[j] = false;
		G.push_back(i);
		dfs(i, i);
		G.clear();
		if (I.size() >= 1) break;
	}
	if (I.size() == 0) { cout << "YES" << endl; return 0; }

	for (int i = 0; i < (int)I.size() - 1; i++) {
		for (int j = 1; j <= n; j++) { y[j].clear(); deg[j] = 0; dist[j] = -1; }
		for (int j = 1; j <= m; j++) {
			if (a[j] == I[i] && b[j] == I[i + 1]) continue;
			y[a[j]].push_back(b[j]); deg[b[j]]++;
		}
		bool OK = TopologicalSort();
		if (OK == true) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}