#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, K, A[1 << 17], B[1 << 17], dist[1 << 17]; vector<int>X[1 << 17];
bool used[1 << 17];

void dfs(int pos, int dep) {
	if (dist[pos] >= 0) return;
	dist[pos] = dep;
	for (int i = 0; i < X[pos].size(); i++) dfs(X[pos][i], dep + 1);
}

int main() {
	scanf("%d%d", &N, &K);
	
	if (N == 1) {
		cout << "No" << endl;
		return 0;
	}

	for (int i = 1; i <= N - 1; i++) {
		scanf("%d%d", &A[i], &B[i]);
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}
	queue<int>Q; vector<int>V;
	for (int i = 1; i <= N; i++) { if (X[i].size() <= 1) { used[i] = true; Q.push(i); } }

	while (!Q.empty()) {
		int pos = Q.front(); Q.pop(); V.push_back(pos);
		for (int i = 0; i < X[pos].size(); i++) {
			if (used[X[pos][i]] == false) { Q.push(X[pos][i]); used[X[pos][i]] = true; }
		}
	}

	for (int i = 1; i <= N; i++) dist[i] = -1;
	int root = V[V.size() - 1];
	dfs(root, 0);

	bool flag = true;
	for (int i = 1; i <= N; i++) {
		if (X[i].size() == 1 && dist[i] != K) flag = false;
		if (X[i].size() >= 2) {
			if (i != root && X[i].size() <= 3) flag = false;
			if (i == root && X[i].size() <= 2) flag = false;
		}
	}
	if (flag == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}