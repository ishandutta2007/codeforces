#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, K1, K2; vector<int>G[1009], I, J;
bool used1[1009], used2[1009], used[1009];

void init() {
	for (int i = 0; i < 1009; i++) G[i].clear();
	for (int i = 0; i < 1009; i++) { used1[i] = false; used2[i] = false; used[i] = false; }
	I.clear(); J.clear(); K1 = 0; K2 = 0; N = 0;
}

void dfs(int pos, int goal) {
	if (pos == goal) { J = I; }
	used[pos] = true;
	for (int i = 0; i < G[pos].size(); i++) {
		if (used[G[pos][i]] == true) continue;
		I.push_back(G[pos][i]);
		dfs(G[pos][i], goal);
		I.pop_back();
	}
}

void make_path(int v1, int v2) {
	I.push_back(v1);
	dfs(v1, v2);
}

void solve() {
	init();
	cin >> N;
	for (int i = 1; i <= N - 1; i++) { int a, b; scanf("%d%d", &a, &b); G[a].push_back(b); G[b].push_back(a); }
	cin >> K1; for (int i = 1; i <= K1; i++) { int v; scanf("%d", &v); used1[v] = true; }
	cin >> K2; for (int i = 1; i <= K2; i++) { int v; scanf("%d", &v); used2[v] = true; }

	int root1 = -1, root2 = -1;
	for (int i = 1; i <= N; i++) { if (used1[i] == true) { root1 = i; break; } }
	for (int i = 1; i <= N; i++) { if (used2[i] == true) { root2 = i; break; } }

	cout << "B " << root2 << endl;
	cin >> root2;

	make_path(root1, root2);
	int pos = -1;
	for (int i = 0; i < J.size(); i++) {
		if (used1[J[i]] == true) { pos = J[i]; }
	}

	cout << "A " << pos << endl;
	int mid; cin >> mid;

	if (used2[mid] == false) { cout << "C -1" << endl; }
	else { cout << "C " << pos << endl; }
	return;
}

int main() {
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
	return 0;
}