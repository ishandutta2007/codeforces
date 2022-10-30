#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 11;

int n, m;
vector<int> g[N];
vector<pair<int, int>> e;

bool bipartite;
vector<int> color;

void dfs(int v, int c) {
	color[v] = c;
	for (auto to : g[v]) {
		if (color[to] == -1) {
			dfs(to, c ^ 1);
		} else {
			if (color[to] == color[v]) {
				bipartite = false;
			}
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
		e.push_back(make_pair(x, y));
	}
	
	bipartite = true;
	color = vector<int>(n, -1);
	dfs(0, 0);
	
	if (!bipartite) {
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	for (int i = 0; i < m; ++i) {
		cout << (color[e[i].first] < color[e[i].second]);
	}
	cout << endl;
	
	return 0;
}