#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning (disable: 4996)

int N, M; bool used[100009], flag = false;
vector<int>X[100009], G[100009];

void dfs(int dep, int cl, int cr) {
	if (cl == cr) return;

	int cx = cl;
	for (int i = cl; i <= cr; i++) {
		int v1 = -1; if (X[i].size() > dep) v1 = X[i][dep];
		int v2 = -1; if (X[i + 1].size() > dep) v2 = X[i + 1][dep];
		if (v1 != v2 || i == cr || v1 == -1) {
			dfs(dep + 1, cx, i);
			cx = i + 1;

			if (v1 >= 0 && v2 >= 0 && v1 > v2 && i != cr) used[v1] = true;
			if (v1 >= 0 && v2 >= 0 && i != cr) G[v2].push_back(v1);
		}
	}
}

void dfs2(int dep, int cl, int cr) {
	if (cl == cr) return;

	int cx = cl;
	for (int i = cl; i <= cr; i++) {
		int v1 = -1; if (X[i].size() > dep) v1 = X[i][dep];
		int v2 = -1; if (X[i + 1].size() > dep) v2 = X[i + 1][dep];
		if (v1 != v2 || i == cr || v1 == -1) {
			dfs2(dep + 1, cx, i);
			cx = i + 1;
			if (v1 > v2 && i != cr) flag = true;
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		int s; scanf("%d", &s);
		for (int j = 0; j < s; j++) { int ss; scanf("%d", &ss); X[i].push_back(ss); }
	}
	dfs(0, 1, N);

	queue<int>Q; for (int i = 1; i <= M; i++) { if (used[i] == true) Q.push(i); }

	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		for (int i = 0; i < G[pos].size(); i++) {
			if (used[G[pos][i]] == false) { used[G[pos][i]] = true; Q.push(G[pos][i]); }
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < X[i].size(); j++) {
			if (used[X[i][j]] == false) X[i][j] += 1000000;
		}
	}

	dfs2(0, 1, N);

	if (flag == true) printf("No\n");
	else {
		printf("Yes\n");
		vector<int>ret; for (int i = 1; i <= M; i++) { if (used[i] == true) ret.push_back(i); }

		printf("%d\n", (int)ret.size());
		for (int i = 0; i < ret.size(); i++) { if (i) printf(" "); printf("%d", ret[i]); }
		printf("\n");
	}
	return 0;
}