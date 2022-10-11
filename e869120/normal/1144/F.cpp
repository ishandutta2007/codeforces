#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, M, u[1 << 18], v[1 << 18], col[1 << 18]; bool flag = false;
vector<int>X[1 << 18];

void dfs(int pos, int dep) {
	if (col[pos] >= 0) {
		if (col[pos] != dep) flag = true;
		return;
	}
	col[pos] = dep;
	for (int i = 0; i < X[pos].size(); i++) dfs(X[pos][i], dep ^ 1);
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &u[i], &v[i]);
		X[u[i]].push_back(v[i]);
		X[v[i]].push_back(u[i]);
	}

	for (int i = 1; i <= N; i++) col[i] = -1;
	dfs(1, 0);

	if (flag == true) {
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
	for (int i = 1; i <= M; i++) {
		if (col[u[i]] == 0 && col[v[i]] == 1) printf("0");
		else printf("1");
	}
	printf("\n");
	return 0;
}