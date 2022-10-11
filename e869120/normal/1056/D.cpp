#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, P[1 << 18], dp[1 << 18]; vector<int>X[1 << 18];

void dfs(int pos) {
	if (X[pos].size() == 0) dp[pos] = 1;
	for (int i = 0; i < X[pos].size(); i++) {
		dfs(X[pos][i]);
		dp[pos] += dp[X[pos][i]];
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		scanf("%d", &P[i]);
		X[P[i]].push_back(i);
	}
	dfs(1);
	sort(dp + 1, dp + N + 1);
	for (int i = 1; i <= N; i++) { if (i >= 2) printf(" "); printf("%d", dp[i]); }
	printf("\n");
	return 0;
}