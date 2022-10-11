#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1509][1509];

int solves(int N, int M, vector<pair<int, int>>G) {
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) dp[i][j] = -(1 << 30);
	}
	dp[0][0] = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) dp[i - 1][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
		for (int j = 0; j < G.size(); j++) {
			dp[i][G[j].second] = max(dp[i][G[j].second], dp[i - 1][G[j].first - 1] + (G[j].second - G[j].first + 1));
		}
		for (int j = N - 1; j >= 0; j--) dp[i][j] = max(dp[i][j], dp[i][j + 1] - 1);
	}
	int maxn = 0;
	for (int i = 0; i <= N; i++) maxn = max(maxn, dp[M][i]);
	return maxn;
}

int N, S, M, K, A[1509], L[1509], R[1509], T[1509];

bool solve(int pos) {
	int cnts = 0;
	for (int i = 0; i <= N; i++) T[i] = 0;
	for (int i = 1; i <= N; i++) { T[i] = T[i - 1]; if (A[i] <= pos) { T[i]++; cnts++; } }

	vector<pair<int, int>>Z;
	for (int i = 1; i <= S; i++) {
		Z.push_back(make_pair(T[L[i] - 1] + 1, T[R[i]]));
	}
	int F = solves(cnts, M, Z);
	if (F >= K) return true;
	return false;
}

int main() {
	cin >> N >> S >> M >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= S; i++) cin >> L[i] >> R[i];

	int cl = 0, cr = (1 << 30), cm, minx = (1 << 30);
	for (int i = 0; i < 32; i++) {
		cm = (cl + cr) / 2;
		bool I = solve(cm);
		if (I == true) { cr = cm; minx = min(minx, cm); }
		else cl = cm;
	}
	if (minx == (1 << 30)) cout << "-1" << endl;
	else cout << minx << endl;
	return 0;
}