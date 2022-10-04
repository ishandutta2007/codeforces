#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

vector<vector<int> > g;
vector<vector<int> > comp;
vector<bool> used;

void dfs(int u) {
	used[u] = true;
	comp.back().push_back(u);
	for (int v : g[u]) {
		if (!used[v]) {
			dfs(v);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	g.resize(n);
	used.resize(n);
	set<pair<int, int> > edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
		edges.insert({ u - 1, v - 1 });
		edges.insert({ v - 1, u - 1 });
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			comp.push_back({});
			dfs(i);
		}
	}
	for (int k = 0; k < (int)comp.size(); k++) {
		int sz = (int)comp[k].size();
		for (int i = 0; i < sz; i++) {
			for (int j = i + 1; j < sz; j++) {
				if (edges.find({ comp[k][i], comp[k][j] }) == edges.end()) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}