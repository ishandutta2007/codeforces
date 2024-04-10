#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

vector<int> X[100009], G, I;
int N, P[100009], dp[100009], idx[100009];

void dfs(int pos) {
	dp[pos] = 0;
	for (int i = 0; i < X[pos].size(); i++) dfs(X[pos][i]);
	for (int i = 0; i < X[pos].size(); i++) dp[pos] = max(dp[pos], dp[X[pos][i]] + 1);
}

void solve(int pos) {
	G.push_back(pos);

	vector<pair<int, int>> L;
	for (int i = 0; i < X[pos].size(); i++) L.push_back(make_pair(dp[X[pos][i]], X[pos][i]));
	sort(L.begin(), L.end());

	for (int i = 0; i < L.size(); i++) solve(L[i].second);
	I.push_back(pos);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		scanf("%d", &P[i]);
		X[P[i]].push_back(i);
	}
	dfs(0);
	solve(0);

	for (int i = 0; i < N; i++) { if (i) printf(" "); printf("%d", G[i]); idx[G[i]] = i; } printf("\n");
	printf("%d\n", (int)I.size() - dp[0] - 1);

	int maxn = 0;
	for (int i = 0; i < I.size() - dp[0] - 1; i++) {
		maxn = max(maxn, idx[I[i]]);
		if (i) printf(" "); printf("%d", G[maxn + 1]);
	}
	printf("\n");
	return 0;
}