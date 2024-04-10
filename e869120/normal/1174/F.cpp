#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = (1 << 18);

vector<int>X[MAX_N], G[MAX_N];
int N, A[MAX_N], B[MAX_N], par[MAX_N], dist[MAX_N], dp[MAX_N], dat1[MAX_N], dat2[MAX_N]; bool used[MAX_N];
int nex[MAX_N];

void dfs(int pos, int dep) {
	used[pos] = true; dp[pos] = 1; dist[pos] = dep;
	for (int i = 0; i < X[pos].size(); i++) {
		if (used[X[pos][i]] == true) continue;
		par[X[pos][i]] = pos;
		G[pos].push_back(X[pos][i]);

		dfs(X[pos][i], dep + 1);
		dp[pos] += dp[X[pos][i]];
	}
}

int ask_d(int pos) {
	if (dat1[pos] >= 1) return dat1[pos] - 1;
	cout << "d " << pos << endl;
	int t; cin >> t;
	dat1[pos] = t + 1;
	return t;
}

int ask_s(int pos) {
	if (dat2[pos] >= 1) return dat2[pos] - 1;
	cout << "s " << pos << endl;
	int t; cin >> t;
	dat2[pos] = t + 1;
	return t;
}

int solve() {
	int D = ask_d(1); if (D == 0) return 1;

	int cx = 1, dst = 0;
	while (true) {
		while (nex[cx] != -1) { cx = nex[cx]; dst++; }

		int D2 = ask_d(cx), E = (D2 + dst - D) / 2;
		for (int i = 0; i < E; i++) { cx = par[cx]; dst--; }
		if (dst == D) return cx;

		int S = ask_s(cx);
		cx = S; dst++;
	}
	return -1;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d%d", &A[i], &B[i]);
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}
	dfs(1, 0);

	for (int i = 1; i <= N; i++) nex[i] = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < G[i].size(); j++) {
			if (dp[G[i][j]] > dp[i] / 2) nex[i] = G[i][j];
		}
	}

	int Z = solve();
	cout << "! " << Z << endl;
	return 0;
}