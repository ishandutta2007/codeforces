#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int N, M, p[5][100009], cost[100009], dp[100009][2], L[100009]; string S;

int range(int t, int l, int r) {
	return p[t][r] - p[t][l - 1];
}

int main() {
	cin >> N >> S >> M; if (N < M) { cout << "0" << endl; return 0; }
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'a') { if (i % 2 == 0) p[0][i + 1]++; else p[1][i + 1]++; }
		if (S[i] == 'b') { if (i % 2 == 0) p[2][i + 1]++; else p[3][i + 1]++; }
		if (S[i] == '?') { p[4][i + 1]++; }
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 1; j <= N; j++) p[i][j] += p[i][j - 1];
	}
	for (int i = 1; i <= N - M + 1; i++) {
		if (i % 2 == 1) {
			if (range(2, i, i + M - 1) >= 1 || range(1, i, i + M - 1) >= 1) cost[i] = (1 << 29);
		}
		if (i % 2 == 0) {
			if (range(0, i, i + M - 1) >= 1 || range(3, i, i + M - 1) >= 1) cost[i] = (1 << 29);
		}
		if (cost[i] != (1 << 29)) cost[i] = range(4, i, i + M - 1);
	}

	// DP : 0 -> , 1 -> 
	for (int i = 0; i <= N; i++) { dp[i][0] = (1 << 29); dp[i][1] = (1 << 29); }
	dp[0][0] = 0; L[0] = 0;
	for (int i = 1; i <= N; i++) {
		vector<pair<int, int>>vec;
		if (dp[i - 1][0] != (1 << 29)) vec.push_back(make_pair(L[i - 1] + 0, dp[i - 1][0]));
		if (dp[i - 1][1] != (1 << 29)) vec.push_back(make_pair(L[i - 1] - 1, dp[i - 1][1]));
		if (i >= M && cost[i - M + 1] != (1 << 29)) {
			if (dp[i - M][0] != (1 << 29)) vec.push_back(make_pair(L[i - M] + 1, dp[i - M][0] + cost[i - M + 1]));
			if (dp[i - M][1] != (1 << 29)) vec.push_back(make_pair(L[i - M] + 0, dp[i - M][1] + cost[i - M + 1]));
		}
		sort(vec.begin(), vec.end(), greater<pair<int, int>>()); int s = vec[0].first;
		for (int j = 0; j < vec.size(); j++) vec[j].first -= s;
		for (int j = 0; j < vec.size(); j++) {
			if (-vec[j].first <= 1) dp[i][-vec[j].first] = min(dp[i][-vec[j].first], vec[j].second);
		}
		L[i] = s;
	}
	if (dp[N][0] == (1 << 29)) dp[N][0] = 0;
	cout << dp[N][0] << endl;
	return 0;
}