#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, M, Q, col[1 << 19], cnts; vector<int>X[1 << 19];

void dfs(int pos) {
	if (col[pos] >= 1) return;
	col[pos] = cnts;
	for (int i = 0; i < X[pos].size(); i++) dfs(X[pos][i]);
}

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 1; i <= Q; i++) {
		int cx, cy; scanf("%d%d", &cx, &cy);
		X[cx].push_back(cy + N);
		X[cy + N].push_back(cx);
	}
	for (int i = 1; i <= N + M; i++) {
		if (col[i] >= 1) continue;
		cnts++; dfs(i);
	}
	cout << cnts - 1 << endl;
	return 0;
}