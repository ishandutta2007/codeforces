#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, K, A[200009], B[200009]; long long dp[200009][5], dp2[200009][5];
vector<int>X[200009], Y[200009]; bool used[200009];

void dfs(int pos) {
	used[pos] = true; dp[pos][0] = 0; dp2[pos][0] = 1;
	for (int i = 0; i < X[pos].size(); i++) {
		if (used[X[pos][i]] == true) continue;
		Y[pos].push_back(X[pos][i]);
		dfs(X[pos][i]);
	}

	for (int i = 0; i < Y[pos].size(); i++) {
		int to = Y[pos][i];
		for (int j = 0; j < K; j++) {
			long long r = dp[to][j]; if (j == 0) r += dp2[to][j];
			dp[pos][(j + 1) % K] += r;
			dp2[pos][(j + 1) % K] += dp2[to][j];
		}
	}
}

long long solve(vector<long long>G1, vector<long long>G2) {
	long long V1 = 0;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			long long R = 1LL * G1[i] * G2[j] + 1LL * G1[j] * G2[i];

			long long X = i, Y = j; if (i == 0) X = K; if (j == 0) Y = K;
			if (X + Y <= K) R -= 1LL * G2[i] * G2[j];
			if (i == j) { R -= 2LL * G1[i]; if (X + Y <= K) R += G2[i]; }
			V1 += R;
		}
	}
	return V1 / 2;
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d%d", &A[i], &B[i]);
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}
	dfs(1);

	long long rem = 0;
	for (int i = 1; i <= N; i++) {
		vector<long long>E(K, 0), E2(K, 0);
		for (int j = 0; j < K; j++) { E[j] = dp[i][j]; E2[j] = dp2[i][j]; }
		E2[0]--;
		rem += solve(E, E2);

		for (int j = 0; j < Y[i].size(); j++) {
			vector<long long>F(K, 0), F2(K, 0);
			for (int k = 0; k < K; k++) { F[(k + 1) % K] = dp[Y[i][j]][k]; F2[(k + 1) % K] = dp2[Y[i][j]][k]; if (k == 0) F[(k + 1) % K] += dp2[Y[i][j]][k]; }
			rem -= solve(F, F2);
		}
		for (int j = 0; j < K; j++) rem += dp[i][j];
	}
	cout << rem << endl;
	return 0;
}