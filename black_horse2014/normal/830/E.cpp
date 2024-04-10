#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int r[N];

int find(int x) {
	if (r[x] == x) return x;
	return r[x] = find(r[x]);
}

vector<int> adj[N];
vector<int> com[N];

int val[N], cnt[N], root[N];

int n, m;

void find_dfs(int u, int r) {
	root[u] = r;
	for (int x : adj[u]) {
		if (x == r) continue;
		find_dfs(x, u);
	}
}

bool check(vector<int> pts) {
	if (pts.empty()) return 0;
	for (int x : pts) val[x] = 0;
	for (int x : pts) {
		if (cnt[x] >= 4) {
			val[x] = 2;
			for (int i = 0; i < 4; i++) {
				val[adj[x][i]] = 1;
			}
			return 1;
		}
	}
	int c3 = 0;
	vector<int> v3;
	for (int x : pts) if (cnt[x] == 3) c3++, v3.push_back(x);
	if (c3 >= 2) {
		int a = v3[0], b = v3[1];
		find_dfs(a, 0);
		vector<int> path;
		path.push_back(b);
		while (b != a) {
			b = root[b];
			path.push_back(b);
		}
		b = v3[1];
		for (int x : adj[a]) val[x] = 1;
		for (int x : adj[b]) val[x] = 1;
		for (int x : path) val[x] = 2;
		return 1;
	}
	if (c3 == 0) return 0;
	int rt = v3[0];
	vector<int> path[3];
	for (int i = 0; i < 3; i++) {
		int cur = adj[rt][i], prv = rt;
		while (1) {
			path[i].push_back(cur);
			if (cnt[cur] == 1) break;
			assert(cnt[cur] == 2);
			int nxt = adj[cur][0];
			if (nxt == prv) nxt = adj[cur][1];
			prv = cur;
			cur = nxt;
		}
	}
	sort(path, path+3, [](vector<int> v1, vector<int> v2) {
		return v1.size() < v2.size();
	});
	assert(path[0].size() <= path[1].size());
	assert(path[1].size() <= path[2].size());
	if (path[0].size() >= 2) {
		val[rt] = 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) {
				val[path[i][j]] = 2-j;
			}
		}
		return 1;
	}
	if (path[1].size() == 1) return 0;
	if (path[1].size() >= 3) {
		val[rt] = 4;
		val[path[0][0]] = 2;
		for (int i = 1; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				val[path[i][j]] = 3-j;
			}
		}
		return 1;
	}
	if (path[2].size() >= 5) {
		val[rt] = 6;
		val[path[0][0]] = 3;
		val[path[1][0]] = 4;
		val[path[1][1]] = 2;
		for (int i = 0; i < 5; i++) {
			val[path[2][i]] = 5-i;
		}
		return 1;
	}
	return 0;
}

bool solve() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		com[i].clear();
		cnt[i] = 0;
		r[i] = i;
	}
	int flg = -1;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		cnt[u]++, cnt[v]++;
		int x = find(u), y = find(v);
		if (x != y) r[x] = y;
		else flg = u;
	}
	if (flg >= 1) {
		flg = find(flg);
		for (int i = 1; i <= n; i++) {
			if (find(i) == flg) val[i] = 1;
			else val[i] = 0; 
		}
		return 1;
	}
	for (int i = 1; i <= n; i++) {
		com[find(i)].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		if (check(com[i])) {
			for (int j = 1; j <= n; j++) {
				if (find(j) != i) val[j] = 0;
			}
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		if (solve()) {
			cout << "YES" << endl;
			for (int i = 1; i <= n; i++) cout << val[i] << ' ';
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}