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

long long TT;
long long N, A[1 << 20], B[1 << 20], T[1 << 20];
vector<long long> X[1 << 20];

long long dp[1 << 20];

void init(int V) {
	for (int i = 1; i <= V * 2; i++) {
		X[i].clear(); dp[i] = 0;
	}
}

void dfs(int pos) {
	dp[pos] = 1;
	for (int i = 0; i < X[pos].size(); i++) {
		if (dp[X[pos][i]] >= 1) continue;
		dfs(X[pos][i]);
		dp[pos] += dp[X[pos][i]];
	}
}

int main() {
	scanf("%lld", &TT);
	for (int i = 1; i <= TT; i++) {
		scanf("%lld", &N);
		for (int j = 1; j <= 2 * N - 1; j++) {
			scanf("%lld%lld%lld", &A[j], &B[j], &T[j]);
			X[A[j]].push_back(B[j]);
			X[B[j]].push_back(A[j]);
		}
		dfs(1);

		long long cl = 0, cr = 0;
		for (int j = 1; j <= 2 * N - 1; j++) {
			long long val = min(dp[A[j]], dp[B[j]]);
			if (val % 2 == 1) cl += 1LL * T[j];
			cr += 1LL * min(val, 2LL * N - val) * T[j];
		}
		cout << cl << " " << cr << endl;
		init(N);
	}
	return 0;
}