#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 500000;
vector<int> G[kMaxN], Col[kMaxN];
int Truu[kMaxN];

void DFS(int node, int par) {
	set<int> BadSet;
	for(auto x : Col[node])
		if(Truu[x] != 0) {
			assert(BadSet.find(Truu[x]) == BadSet.end());
			BadSet.insert(Truu[x]);
		}

	int mexx = 1;
	for(auto x : Col[node])
		if(Truu[x] == 0) {
			while(BadSet.find(mexx) != BadSet.end())
				++mexx;
			BadSet.insert(mexx);
			Truu[x] = mexx;
		}

	for(auto vec : G[node]) {
		if(vec != par)
			DFS(vec, node);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int root = -1;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		Col[i].resize(x);
		for(auto &x : Col[i])
			cin >> x;

		if(root == -1 || Col[root].size() < Col[i].size())
			root = i;
	}

	for(int i = 2; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	cerr << "Starting from: " << root << endl;
	DFS(root, -1);

	int ans = 1;
	for(int i = 1; i <= m; ++i) {
		ans = max(ans, Truu[i]);
	}
	// assert(ans == G[root].size());
	cout << ans << endl;
	for(int i = 1; i <= m; ++i)
		cout << max(Truu[i], 1) << " ";
	cout << endl;



	
	return 0;
}