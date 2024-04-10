// Create your own template by modifying this file!
#include <bits/stdc++.h>
using namespace std;

set<int> G[500000];
int Color[500000];

int most = 0;
void DFS(int node, int par, int col, int colp) {
	Color[node] = col;
		
	int xcol = 0;
	for(auto vec : G[node]) {
		if(vec != par) {
			while(xcol == col || xcol == colp) ++xcol;
			most = max(most, xcol);
			DFS(vec, node, xcol++, col);
		}
	}
}

int main() {
	int n;
	cin >> n;

	for(int i = 2; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		G[a].insert(b);
		G[b].insert(a);
	}

	int root = 0;
	for(int node = 1; node < n; ++node)
		if(G[node].size() > G[root].size())
			root = node;

	DFS(root, -1, 0, -1);

	cout << most + 1 << endl;
	for(int i = 0; i < n; ++i)
		cout << Color[i] + 1 << " ";
	cout << endl;

	return 0;
}