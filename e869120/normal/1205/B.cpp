#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 18];
vector<int> V[129];
vector<int> G[129];
vector<int> X;

int dp[129][129];

int solve(int stt) {
	for (int i = 0; i < 129; i++) {
		for (int j = 0; j < 129; j++) dp[i][j] = (1 << 30);
	}

	queue<pair<int, int>> Q;
	Q.push(make_pair(stt, X.size()));
	dp[stt][X.size()] = 0;

	while (!Q.empty()) {
		int pos1 = Q.front().first, pos2 = Q.front().second; Q.pop();
		for (int i : G[pos1]) {
			if (i == pos2) continue;
			if (dp[i][pos1] > dp[pos1][pos2] + 1) {
				dp[i][pos1] = dp[pos1][pos2] + 1;
				Q.push(make_pair(i, pos1));
			}
		}
	}
	
	int val = (1 << 30);
	for (int i = 0; i < X.size(); i++) {
		val = min(val, dp[stt][i]);
	}
	return val;
}

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
	}
	
	// 
	for (int i = 0; i < 60; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if ((A[j] / (1LL << i)) % 2 == 0) continue;
			V[i].push_back(j);
			cnt++;
		}
		if (cnt >= 3) {
			printf("3\n");
			return 0;
		}
		if (cnt == 2) {
			X.push_back(V[i][0]);
			X.push_back(V[i][1]);
		}
	}
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());

	// 
	for (int i = 0; i < 60; i++) {
		if (V[i].size() != 2) continue;
		int pos1 = lower_bound(X.begin(), X.end(), V[i][0]) - X.begin();
		int pos2 = lower_bound(X.begin(), X.end(), V[i][1]) - X.begin();
		G[pos1].push_back(pos2);
		G[pos2].push_back(pos1);
	}

	// DP
	int minx = (1 << 30);
	for (int stt = 0; stt < X.size(); stt++) {
		minx = min(minx, solve(stt));
	}
	if (minx == (1 << 30)) cout << "-1" << endl;
	else cout << minx << endl;
	return 0;
}