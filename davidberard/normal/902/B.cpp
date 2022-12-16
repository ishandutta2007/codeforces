#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

vector<bool> visited;
vector<int> c;
vector<vector<int>> edges;

int cnt;

void dfs(int v, int color) {
	if(c[v] != color) {
		++cnt;
		//cerr << "Gotta color vertex " << v << " as " << c[v] <<endl;
	}
	visited[v] = true;
	for(int i=0;i<edges[v].size();++i) {
		if(!visited[edges[v][i]])
			dfs(edges[v][i], c[v]);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	cnt = 0;
	int N;
	cin >> N;
	c.resize(N);
	edges.resize(N);
	visited = vector<bool>(N, false);
	int val;
	for(int i=1;i<N;++i) {
		cin >> val;
		--val;
		edges[i].push_back(val);
		edges[val].push_back(i);
	}
	for(int i=0;i<N;++i) {
		cin >> c[i];
	}
	
	dfs(0, 0);
	cout << cnt << endl;
	
	return 0;
}