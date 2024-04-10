#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <functional>

using namespace std;

const int N = 1e5 + 7, M = 1e5 + 7;

int n, m;
struct Graph {
	int to[M << 1], head[N], next[M << 1], color[M << 1], tot;
	void clear() {
		fill(head, head + n, -1);
		tot = 0;
	}
	void _add_edge(int a, int b, int c) {
		to[tot] = b, next[tot] = head[a], color[tot] = c, head[a] = tot++;
	}

	void add_edge(int a, int b, int c) {
		_add_edge(a, b, c);
		_add_edge(b, a, c);
	}
}g;

int father[N], f_color[N], visit_edge[M], visit_node[N];
vector<vector<int> > cycles;

void dfs(int u) {
	visit_node[u] = 1;
	for (int i = g.head[u]; ~i; i = g.next[i]) {
		if (visit_edge[i >> 1]) continue;
		visit_edge[i >> 1] = 1;
		int v = g.to[i];
		if (visit_node[v]) {
			vector<int> cycle;
			int t = u;
			while (t != v) {
				cycle.push_back(f_color[t]);
				visit_node[t] ++;
				t = father[t];
			}
			cycle.push_back(g.color[i]);
			cycles.push_back(cycle);
		} else {
			father[v] = u;
			f_color[v] = g.color[i];
			dfs(v);
		}
	}
	if (visit_node[u] == 1 && u != 0) {
		vector<int> cycle;
		cycle.push_back(f_color[u]);
		cycle.push_back(f_color[u]);
		cycles.push_back(cycle);
	}
}

vector<int> colors[M];
int character[N], bel[N];
int ans = 0;

int main() {
	scanf("%d %d", &n, &m);
	g.clear();
	for (int i = 0; i < m; i++) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		u--, v--;
		g.add_edge(u, v, c);
	}
	dfs(0);
	for (int i = 0; i < cycles.size(); i++) {
		character[i] = 0;
		bel[i] = i;
		for (auto c : cycles[i]) {
			//printf("c = %d\n", c);
			colors[c].push_back(i);
		}
		//puts("");
	}
	ans = -cycles.size();
	function<int(int)> get_bel = [&](int u) {
		int t = u;
		for (; bel[t] != t; t = bel[t]);
		//int tar = t;
		for (int tar = t; u != tar; t = bel[u], bel[u] = tar, u = t);
		return u;
	};
	for (int i = 1; i <= m; i++) {
		if (colors[i].size() == 0) {
			continue;
		} else {
			ans++;
			for (int j = 0; j + 1 < colors[i].size(); j++) {
				int a = get_bel(colors[i][j]);
				int b = get_bel(colors[i][j + 1]);
				if (a != b) {
					ans++;
					bel[a] = b;
					if (character[a] && character[b]) {
						ans--;
					}
					character[b] |= character[a];
				} else {
					if (character[a] == 0) {
						ans++;
						character[a] = 1;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
}