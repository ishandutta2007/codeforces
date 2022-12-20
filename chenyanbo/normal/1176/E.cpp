#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m;
vector<int> d;
vector<vector<int>> g;

void bfs(int s) {
	d = vector<int>(n, INF);
	d[s] = 0;
	
	queue<int> q;
	q.push(s);
	
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		
		for (auto to : g[v]) {
			if (d[to] == INF) {
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	
	for (int tc = 0; tc < t; ++tc){
		cin >> n >> m;
		g = vector<vector<int>>(n);
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			--x, --y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
	
		bfs(0);
		vector<int> even, odd;
		for (int i = 0; i < n; ++i) {
			if (d[i] & 1) odd.push_back(i);
			else even.push_back(i);
		}
	
		if (even.size() < odd.size()) {
			cout << even.size() << endl;
			for (auto v : even) cout << v + 1 << " ";
		} else {
			cout << odd.size() << endl;
			for (auto v : odd) cout << v + 1 << " ";
		}
		cout << endl;
	}
	
	return 0;
}