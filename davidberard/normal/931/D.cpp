#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int>> edges;
vector<int> level;
vector<int> levelSizes;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	edges.resize(n);
	level = vector<int>(n, 0);
	levelSizes = vector<int>(n, 0);
	int v;
	for(int i=1;i<n;++i) {
		cin >> v;
		--v;
		edges[v].push_back(i);
	}
	queue<pii> q;
	q.push(pii(0, 0));
	while(!q.empty()) {
		pii pr = q.front();
		q.pop();
		int u = pr.first;
		int lvl = pr.second;
		levelSizes[lvl]++;
		level[u] = lvl;
		for(int vv : edges[u]) {
			q.push(pii(vv, lvl+1));
		}
	}
	int amt = 0;
	for(int i=0;i<n;++i) {
		amt += levelSizes[i]%2;
	}
	cout << amt << endl;

	return 0;
}