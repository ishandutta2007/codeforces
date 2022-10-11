#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = (1 << 20);
int N, M, A[MAX_N], B[MAX_N], col[MAX_N], cnts, deg[MAX_N];
vector<int> G[MAX_N], H[MAX_N], I;
bool used[MAX_N];

void init() {
	I.clear(); cnts = 0;
	for (int i = 0; i <= N + 2; i++) {
		G[i].clear(); H[i].clear(); used[i] = false; col[i] = 0; deg[i] = 0;
	}
	for (int i = 0; i <= M + 2; i++) {
		A[i] = 0; B[i] = 0;
	}
}

void dfs(int pos) {
	used[pos] = true;
	for (int i = 0; i < G[pos].size(); i++) {
		if (used[G[pos][i]] == true) continue;
		dfs(G[pos][i]);
	}
	I.push_back(pos);
}

void dfs2(int pos) {
	col[pos] = cnts;
	for (int i = 0; i < H[pos].size(); i++) {
		if (col[H[pos][i]] >= 1) continue;
		dfs2(H[pos][i]);
	}
}

void solve() {
	init();

	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &A[i], &B[i]);
		if (A[i] == B[i]) continue;
		G[A[i]].push_back(B[i]);
		H[B[i]].push_back(A[i]);
	}

	for (int i = 1; i <= N; i++) {
		if (used[i] == false) dfs(i);
	}

	reverse(I.begin(), I.end());
	for (int pos : I) {
		if (col[pos] == 0) {
			cnts++; dfs2(pos);
		}
	}

	if (cnts == 1) {
		printf("No\n");
		return;
	}

	for (int i = 1; i <= M; i++) {
		int u1 = col[A[i]], u2 = col[B[i]];
		if (u1 != u2) deg[u2]++;
	}

	for (int i = 1; i <= cnts; i++) {
		if (deg[i] == 0) {
			vector<int> V1, V2;
			for (int j = 1; j <= N; j++) {
				if (col[j] == i) V2.push_back(j);
				else V1.push_back(j);
			}

			printf("Yes\n");
			printf("%d %d\n", (int)V1.size(), (int)V2.size());
			for (int j = 0; j < V1.size(); j++) { if (j) printf(" "); printf("%d", V1[j]); } printf("\n");
			for (int j = 0; j < V2.size(); j++) { if (j) printf(" "); printf("%d", V2[j]); } printf("\n");
			return;
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		solve();
	}
	return 0;
}