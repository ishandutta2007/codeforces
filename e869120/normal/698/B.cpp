#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int n, a[1 << 18], col[1 << 18], cnts; vector<int>G[1 << 18], I[1 << 18];

void dfs(int pos) {
	if (col[pos] >= 1) return;
	col[pos] = cnts; I[cnts].push_back(pos);
	for (int i = 0; i < G[pos].size(); i++) {
		dfs(G[pos][i]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++) { G[i].push_back(a[i]); G[a[i]].push_back(i); }

	vector<int>V;
	for (int i = 1; i <= n; i++) {
		if (col[i] >= 1) continue;
		cnts++; dfs(i);

		int pos = I[cnts][0];
		for (int j = 0; j < I[cnts].size(); j++) pos = a[pos];
		V.push_back(pos);
	}

	int s = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == i) { cnts--; s = i; break; }
	}
	if (s == -1) { s = V[0]; a[s] = s; }
	for (int i = 0; i < V.size(); i++) { if (V[i] != s) { a[V[i]] = s; } }

	cout << cnts << endl;
	for (int i = 1; i <= n; i++) { if (i >= 2) printf(" "); printf("%d", a[i]); }
	printf("\n");
	return 0;
}