#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, W[1 << 19], WW[1 << 19], par[1 << 19], dp[1 << 19]; bool used[1 << 19];
vector<pair<int, long long>>X[300009]; vector<int> G[300009], L;

void dfs(int pos) {
	used[pos] = true;
	for (int i = 0; i < X[pos].size(); i++) {
		if (used[X[pos][i].first] == true) continue;
		par[X[pos][i].first] = pos;
		W[X[pos][i].first] -= X[pos][i].second;
		G[pos].push_back(X[pos][i].first);
		dfs(X[pos][i].first);
	}
	L.push_back(pos);
}

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) { scanf("%lld", &W[i]); WW[i] = W[i]; }
	for (int i = 1; i <= N - 1; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		X[u].push_back(make_pair(v, w));
		X[v].push_back(make_pair(u, w));
	}
	dfs(1);
	for (int i = 0; i < L.size(); i++) {
		dp[L[i]] = max(dp[L[i]], W[L[i]]);
		for (int j = 0; j < G[L[i]].size(); j++) {
			dp[L[i]] = max(dp[L[i]], dp[G[L[i]][j]] + W[L[i]]);
		}
	}
	long long maxn = 0;
	for (int i = 1; i <= N; i++) {
		vector<long long>A;
		for (int j = 0; j < G[i].size(); j++) A.push_back(dp[G[i][j]]);
		sort(A.begin(), A.end());
		reverse(A.begin(), A.end());

		long long S = WW[i];
		if (A.size() >= 1) S += A[0];
		if (A.size() >= 2) S += A[1];
		maxn = max(maxn, S);
	}
	cout << maxn << endl;
	return 0;
}