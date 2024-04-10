// Create your own template by modifying this file!
#include <bits/stdc++.h>
using namespace std;

int have = 0, maxx;
vector<int> G[500000];
int Viz[500000];
	
vector<vector<int>> Sol;
void Assign(int node) {
	if(have == maxx) {
		have = 0; 
		Sol.push_back(vector<int>());
	}

	++have;
	Sol.back().push_back(node);
}

void DFS(int node) {
	Viz[node] = 1;
	
	Assign(node);
	for(auto vec : G[node]) {
		if(!Viz[vec]) {
			DFS(vec);
			Assign(node);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;

	have = maxx = (2 * n + k - 1) / k;
	while(m--) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}


	DFS(1);
	assert(Sol.size() <= k);

	while(Sol.size() < k) 
		Sol.push_back(vector<int>(1, 1));

	for(auto v : Sol) {
		cout << v.size() << " ";
		for(auto x : v) 
			cout << x << " ";
		cout << '\n';
	}


	return 0;
}