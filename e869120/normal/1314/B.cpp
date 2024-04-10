#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, K;
int A[1 << 19];
int used[1 << 19];

int dp[1 << 19][2][2];

void solve(int u, int s1, int s2, int t1, int t2) {
	if (dp[u * 2][s1][s2] < 0 || dp[u * 2 + 1][t1][t2] < 0) return;

	// 8 Pattern Exists.

	//  1:  s1 
	if (true) {
		int cnt1 = 0;
		if (s1 + t1 >= 1) cnt1++;
		if (s2 + t2 >= 1) cnt1++;
		if (t1 + s2 >= 1) cnt1++;
		dp[u][s1][t1] = max(dp[u][s1][t1], dp[u * 2][s1][s2] + dp[u * 2 + 1][t1][t2] + cnt1);
		dp[u][s1][s2] = max(dp[u][s1][s2], dp[u * 2][s1][s2] + dp[u * 2 + 1][t1][t2] + cnt1);
	}
	if (true) {
		int cnt1 = 0;
		if (s1 + t1 >= 1) cnt1++;
		if (s2 + t2 >= 1) cnt1++;
		if (t1 + t2 >= 1) cnt1++;
		dp[u][s1][t1] = max(dp[u][s1][t1], dp[u * 2][s1][s2] + dp[u * 2 + 1][t1][t2] + cnt1);
		dp[u][s1][t2] = max(dp[u][s1][t2], dp[u * 2][s1][s2] + dp[u * 2 + 1][t1][t2] + cnt1);
	}

	//  2:  t1 
	if (true) {
		int cnt1 = 0;
		if (s1 + t1 >= 1) cnt1++;
		if (s2 + t2 >= 1) cnt1++;
		if (s1 + s2 >= 1) cnt1++;
		dp[u][t1][s1] = max(dp[u][t1][s1], dp[u * 2][s1][s2] + dp[u * 2 + 1][t1][t2] + cnt1);
		dp[u][t1][s2] = max(dp[u][t1][s2], dp[u * 2][s1][s2] + dp[u * 2 + 1][t1][t2] + cnt1);
	}
	if (true) {
		int cnt1 = 0;
		if (s1 + t1 >= 1) cnt1++;
		if (s2 + t2 >= 1) cnt1++;
		if (s1 + t2 >= 1) cnt1++;
		dp[u][t1][s1] = max(dp[u][t1][s1], dp[u * 2][s1][s2] + dp[u * 2 + 1][t1][t2] + cnt1);
		dp[u][t1][t2] = max(dp[u][t1][t2], dp[u * 2][s1][s2] + dp[u * 2 + 1][t1][t2] + cnt1);
	}
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= K; i++) {
		scanf("%d", &A[i]); A[i]--;
		used[A[i]] = 1;
	}

	for (int i = 0; i < (1 << N); i++) {
		dp[i][0][0] = -100000000;
		dp[i][0][1] = -100000000;
		dp[i][1][0] = -100000000;
		dp[i][1][1] = -100000000;
	}

	for (int i = 0; i < (1 << (N - 1)); i++) {
		if (used[i * 2] + used[i * 2 + 1] == 0) {
			dp[i + (1 << (N - 1))][0][0] = 0;
		}
		if (used[i * 2] + used[i * 2 + 1] == 1) {
			dp[i + (1 << (N - 1))][0][1] = 1;
			dp[i + (1 << (N - 1))][1][0] = 1;
		}
		if (used[i * 2] + used[i * 2 + 1] == 2) {
			dp[i + (1 << (N - 1))][1][1] = 1;
		}
	}

	for (int i = (1 << (N - 1)) - 1; i >= 1; i--) {
		for (int s1 = 0; s1 < 2; s1++) {
			for (int s2 = 0; s2 < 2; s2++) {
				for (int t1 = 0; t1 < 2; t1++) {
					for (int t2 = 0; t2 < 2; t2++) {
						solve(i, s1, s2, t1, t2);
					}
				}
			}
		}
	}

	int FinalAns = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			FinalAns = max(FinalAns, dp[1][i][j] + (i | j));
		}
	}
	cout << FinalAns << endl;
	return 0;
}