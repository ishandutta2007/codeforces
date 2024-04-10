#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int T, N, M;
int U[3089], V[3089], sz[3089];
long long A1[3089], A2[3089], X[3089];

vector<int> G[3089], H[3089];
pair<int, long long> dp[3089][3089];
pair<int, long long> dp2[3089][3089];

void init() {
	for (int i = 1; i <= 3000; i++) {
		sz[i] = 0;
		G[i].clear(); H[i].clear();
	}
}

void dfs1(int pos) {
	sz[pos] = 1;
	for (int i : G[pos]) {
		if (sz[i] >= 1) continue;
		H[pos].push_back(i);
		dfs1(i);
		sz[pos] += sz[i];
	}
}

void solve(int pos) {
	for (int i : H[pos]) solve(i);

	for (int i = 0; i <= H[pos].size(); i++) {
		for (int j = 0; j <= sz[pos]; j++) dp2[i][j] = make_pair(-10000, -(1LL << 60));
	}
	dp2[0][0] = make_pair(0, X[pos]); int cnts = 0;
	for (int i = 0; i < H[pos].size(); i++) {
		int to = H[pos][i];
		for (int j = 0; j <= cnts; j++) {
			for (int k = 0; k <= sz[to]; k++) {
				dp2[i + 1][j + k] = max(dp2[i + 1][j + k], make_pair(dp2[i][j].first + dp[to][k].first, dp2[i][j].second + dp[to][k].second));
			}
		}
		cnts += sz[to];
	}

	// pos 
	for (int i = 0; i <= sz[pos]; i++) dp[pos][i] = make_pair(-10000, -(1LL << 60));
	for (int i = 0; i <= cnts; i++) {
		if (dp2[H[pos].size()][i].second >= 1LL) dp[pos][i + 1] = max(dp[pos][i + 1], make_pair(dp2[H[pos].size()][i].first + 1, 0LL));
		if (dp2[H[pos].size()][i].second <= 0LL) dp[pos][i + 1] = max(dp[pos][i + 1], make_pair(dp2[H[pos].size()][i].first + 0, 0LL));
	}

	// 
	if (pos >= 2) {
		for (int i = 0; i <= cnts; i++) {
			dp[pos][i] = max(dp[pos][i], dp2[H[pos].size()][i]);
		}
	}
}

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		init();
		scanf("%d%d", &N, &M);
		for (int j = 1; j <= N; j++) scanf("%lld", &A1[j]);
		for (int j = 1; j <= N; j++) scanf("%lld", &A2[j]);
		for (int j = 1; j <= N; j++) X[j] = A2[j] - A1[j];
		for (int j = 1; j <= N - 1; j++) {
			scanf("%d%d", &U[j], &V[j]);
			G[U[j]].push_back(V[j]);
			G[V[j]].push_back(U[j]);
		}
		dfs1(1);
		solve(1);
		cout << dp[1][M].first << endl;
	}
	return 0;
}