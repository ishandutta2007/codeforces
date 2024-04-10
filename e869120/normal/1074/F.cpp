#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#pragma warning (disable: 4996)

int Backet = 1000, BASE = 200000;
int D[209][400009], L[209], S[209009];

void init() {
	for (int i = 0; i < 209; i++) D[i][BASE] = Backet;
}

void add_guchoku(int l, int r, int x) {
	int C = l / Backet;
	for (int i = C * Backet; i < (C + 1) * Backet; i++) D[C][S[i] + BASE] = 0;
	for (int i = l; i < r; i++) S[i] += x;

	for (int i = C * Backet; i < (C + 1)*Backet; i++) D[C][S[i] + BASE]++;
}

void add(int l, int r, int x) {
	int L1 = l / Backet, L2 = r / Backet;
	if (L1 == L2) add_guchoku(l, r, x);
	else {
		add_guchoku(l, (L1 + 1) * Backet, x);
		add_guchoku(L2 * Backet, r, x);
		for (int i = L1 + 1; i < L2; i++) L[i] += x;
	}
}

int get_zero() {
	int sum = 0;
	for (int i = 0; i < 209; i++) sum += D[i][BASE - L[i]];
	return sum;
}

int N, Q, A[1 << 18], B[1 << 18], dist[1 << 18]; vector<int>X[1 << 18], Y[1 << 18];
int cl[1 << 18], cr[1 << 18], dp[1 << 18][23], cnts, ret; bool used[1 << 18];
map<pair<int, int>, int>Map;

int prevs(int pos, int x) {
	for (int i = 22; i >= 0; i--) {
		if (x >= (1 << i)) { x -= (1 << i); pos = dp[pos][i]; }
	}
	return pos;
}

void dfs(int pos, int dst) {
	used[pos] = true; cnts++; cl[pos] = cnts; dist[pos] = dst;
	for (int i = 0; i < X[pos].size(); i++) {
		if (used[X[pos][i]] == true) continue;
		dp[X[pos][i]][0] = pos;
		Y[pos].push_back(X[pos][i]);
		dfs(X[pos][i], dst + 1);
	}
	cr[pos] = cnts;
}

void adds(int u, int v, int x) {
	if (cl[u] > cl[v]) swap(u, v);

	if (cl[u] <= cl[v] && cr[v] <= cr[u]) {
		// u  v 
		int pos = prevs(v, dist[v] - dist[u] - 1);
		add(cl[pos], cr[pos] + 1, x);
		add(cl[v], cr[v] + 1, -x);
	}
	else {
		// u  v 
		add(cl[1], cr[1] + 1, x);
		add(cl[u], cr[u] + 1, -x);
		add(cl[v], cr[v] + 1, -x);
	}
}

int main() {
	scanf("%d%d", &N, &Q); init();
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d%d", &A[i], &B[i]);
		X[A[i]].push_back(B[i]); X[B[i]].push_back(A[i]);
	}
	dfs(1, 0);

	for (int i = 0; i < 22; i++) {
		for (int j = 1; j <= N; j++) dp[j][i + 1] = dp[dp[j][i]][i];
	}

	for (int i = 1; i <= Q; i++) {
		int u, v; scanf("%d%d", &u, &v); if (u > v) swap(u, v);

		if (Map[make_pair(u, v)] == 0) {
			adds(u, v, 1);
			Map[make_pair(u, v)] = 1;
		}
		else if (Map[make_pair(u, v)] == 1) {
			adds(u, v, -1);
			Map[make_pair(u, v)] = 0;
		}
		printf("%d\n", get_zero() - (209 * Backet - N));
	}
	return 0;
}