#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, M, D, col[100009], dp[100009][59], cnts; char c[100009][55]; bool used[100009];
vector<int>X[100009], Y[100009], G[100009], I[100009], L;

void dfs(int pos) {
	used[pos] = true;
	for (int i = 0; i < X[pos].size(); i++) {
		if (used[X[pos][i]] == true) continue;
		dfs(X[pos][i]);
	}
	L.push_back(pos);
}

void dfs2(int pos) {
	if (col[pos] >= 1) return;
	col[pos] = cnts; G[cnts].push_back(pos);
	for (int i = 0; i < Y[pos].size(); i++) dfs2(Y[pos][i]);
}

int col2[100009], V; bool flag = false;

void dfs3(int pos, int dep) {
	if (dep == V) dep = 0;
	if (col2[pos] >= 0) {
		if (dep != col2[pos]) flag = true;
		return;
	}

	col2[pos] = dep;
	for (int i = 0; i < I[pos].size(); i++) dfs3(I[pos][i], dep + 1);
}

int main() {
	// Input
	scanf("%d%d%d", &N, &M, &D);
	for (int i = 0; i < M; i++) {
		int u = 0, v = 0; scanf("%d%d", &u, &v);
		X[u].push_back(v); Y[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%s", &c[i]);
	}

	// Doing SCC
	for (int i = 1; i <= N; i++) {
		if (used[i] == false) dfs(i);
	}
	for (int i = L.size() - 1; i >= 0; i--) {
		if (col[L[i]] >= 1) continue;
		cnts++; dfs2(L[i]);
	}
	
	for (int i = 1; i <= N; i++) { for (int j = 0; j < D; j++) dp[i][j] = -(1 << 30); }

	dp[1][0] = 0;
	for (int i = 1; i <= cnts; i++) {
		// 1. Moving in group
		for (int j : G[i]) {
			for (int k : X[j]) { if (col[k] == i) I[j].push_back(k); }
		}

		int S = 0;

		for (int j = D; j >= 1; j--) {
			if (D%j != 0) continue;
			for (int k : G[i]) col2[k] = -1; flag = false;
			V = j;
			dfs3(G[i][0], 0);
			if (flag == false) { S = j; break; }
		}

		for (int j : G[i]) I[j].clear();

		int u[55], v[55]; for (int j = 0; j <= D; j++) { u[j] = 0; v[j] = -(1 << 30); }

		for (int j : G[i]) {
			for (int k = 0; k < S; k++) {
				for (int l = k; l < D; l += S) { if (c[j][l] == '1') { u[(k - col2[j] + S) % S]++; break; } }
			}
		}

		for (int j : G[i]) {
			for (int k = 0; k < D; k++) { if (dp[j][k] >= 0) v[(k - col2[j] + S) % S] = max(v[(k - col2[j] + S) % S], dp[j][k]); }
		}
		for (int j : G[i]) {
			for (int k = 0; k < S; k++) {
				if (v[k] == -(1 << 30)) continue;

				int Z = (k + col2[j]) % S;
				for (int l = Z; l < D; l += S) dp[j][l] = max(dp[j][l], u[k] + v[k]);
			}
		}

		// 2. Moving to Another Group
		for (int j : G[i]) {
			for (int k : X[j]) {
				if (col[j] != col[k]) {
					for (int l = 0; l < D; l++) dp[k][(l + 1) % D] = max(dp[k][(l + 1) % D], dp[j][l]);
				}
			}
		}
	}

	int ret = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < D; j++) ret = max(ret, dp[i][j]);
	}
	cout << ret << endl;
	return 0;
}