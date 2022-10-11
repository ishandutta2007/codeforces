#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 18], B[1 << 18];
int dist[3009][3009], dr[3009][3009], num[3009][3009];
long long dp[3009][3009];
vector<int> X[3009];
vector<pair<int, int>> E[3009];

int dfs(int stt, int pos, int dep) {
	dr[stt][pos] = 1;
	dist[stt][pos] = dep;
	for (int to : X[pos]) {
		if (dr[stt][to] >= 1) continue;
		int z = dfs(stt, to, dep + 1);
		dr[stt][pos] += z;
	}
	return dr[stt][pos];
}

int main() {
	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		cin >> A[i] >> B[i];
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}
	for (int i = 1; i <= N; i++) {
		dfs(i, i, 0);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			num[i][j] = dr[i][j] * dr[j][i];
		}
	}
	for (int i = 1; i <= N - 1; i++) {
		dp[A[i]][B[i]] = num[A[i]][B[i]];
		dp[B[i]][A[i]] = num[B[i]][A[i]];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			E[dist[i][j]].push_back(make_pair(i, j));
		}
	}

	for (int i = 1; i <= N; i++) {
		for (pair<int, int> val : E[i]) {
			int a1 = val.first, a2 = val.second;
			for (int to : X[a1]) {
				if (dist[a1][a2] > dist[to][a2]) continue;
				dp[to][a2] = max(dp[to][a2], dp[a1][a2] + 1LL * num[to][a2]);
			}
			for (int to : X[a2]) {
				if (dist[a1][a2] > dist[a1][to]) continue;
				dp[a1][to] = max(dp[a1][to], dp[a1][a2] + 1LL * num[a1][to]);
			}
		}
	}

	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) ans = max(ans, dp[i][j]);
	}
	cout << ans << endl;
	return 0;
}