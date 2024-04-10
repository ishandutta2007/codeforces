#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 4e5 + 7;
const int INF = 1e9;

int half;
vector<int> adj[N];
int n, size[N], down[N];

void dfs(int x, int fa) {
	down[x] = 0;
	size[x] = 1;
	for (auto son : adj[x]) {
		if (son == fa) continue;
		dfs(son, x);
		size[x] += size[son];
		down[x] = max(down[son], down[x]);
	}
	if (size[x] <= half) down[x] = size[x];
}

int answer[N];

void dfs2(int x, int fa, int up) {

	pair<int, int> max_d, sec_d;
	max_d = make_pair(up, -1), sec_d = make_pair(0, -1);
	if (n - size[x] <= half) {
		sec_d = max_d;
		max_d = make_pair(n - size[x], -1);
	}

	answer[x] = 1;
	for (auto son : adj[x]) {
		if (son == fa) continue;
		if (size[son] > half && size[son] - down[son] > half) {
			answer[x] = 0;
		}
		pair<int, int> tmp = make_pair(down[son], son);
		if (tmp > max_d) {
			sec_d = max_d;
			max_d = tmp;
		} else if (tmp > sec_d) {
			sec_d = tmp;
		}
	}
	if (n - size[x] > half && n - size[x] - up > half) {
		answer[x] = 0;
	}

	for (auto son : adj[x]) {
		if (son == fa) continue;
		if (max_d.second == son) {
			dfs2(son, x, sec_d.first);
		} else {
			dfs2(son, x, max_d.first);
		}
	}
}

int main() {
	scanf("%d", &n);
	half = n / 2;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	dfs2(1, 0, 0);
	for (int i = 1; i <= n; i++) {
		printf("%d%c", answer[i], i == n ? '\n' : ' ');
	}
	return 0;
}