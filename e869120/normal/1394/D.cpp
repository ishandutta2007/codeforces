#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

// 
long long N;
long long T[1 << 18], H[1 << 18];
long long A[1 << 18], B[1 << 18];

// 
vector<int> X[1 << 18];
vector<int> Y[1 << 18];
bool used[1 << 18];
long long par[1 << 18];
long long a[1 << 18];
long long dp[1 << 18][2];

void dfs1(int pos) {
	used[pos] = true;
	for (int i : X[pos]) {
		if (used[i] == true) continue;
		Y[pos].push_back(i);
		par[i] = pos;
		dfs1(i);
	}
}

void dfs2(int pos) {
	for (int i : Y[pos]) dfs2(i);

	vector<long long> VPlus;
	vector<long long> VMinus;
	long long cnts = 0, minx = 0;
	for (int i : Y[pos]) {
		if (dp[i][0] > dp[i][1]) { cnts += 1; VMinus.push_back(dp[i][0] - dp[i][1]); }
		if (dp[i][0] <= dp[i][1]) { cnts += 0; VPlus.push_back(dp[i][1] - dp[i][0]); }
		minx += min(dp[i][0], dp[i][1]);
	}

	sort(VPlus.begin(), VPlus.end());
	sort(VMinus.begin(), VMinus.end());

	long long s1 = minx, s2 = minx;
	a[cnts] = minx;
	for (int i = 0; i < VMinus.size(); i++) { s1 += VMinus[i]; a[cnts - (i + 1)] = s1; }
	for (int i = 0; i < VPlus.size(); i++) { s2 += VPlus[i]; a[cnts + (i + 1)] = s2; }

	// 
	if (pos == 1) {
		for (int i = 0; i <= Y[pos].size(); i++) {
			long long cost = a[i] + 1LL * max(i, (int)X[pos].size() - i) * T[pos];
			dp[pos][0] = min(dp[pos][0], cost);
		}
	}
	else {
		if (H[par[pos]] >= H[pos]) {
			for (int i = 0; i <= Y[pos].size(); i++) {
				long long cost = a[i] + 1LL * max((i + 1), (int)X[pos].size() - (i + 1)) * T[pos];
				dp[pos][0] = min(dp[pos][0], cost);
			}
		}
		if (H[par[pos]] <= H[pos]) {
			for (int i = 0; i <= Y[pos].size(); i++) {
				long long cost = a[i] + 1LL * max(i, (int)X[pos].size() - i) * T[pos];
				dp[pos][1] = min(dp[pos][1], cost);
			}
		}
	}
}

int main() {
	// 
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &T[i]);
	for (int i = 1; i <= N; i++) scanf("%lld", &H[i]);
	for (int i = 1; i <= N - 1; i++) scanf("%lld%lld", &A[i], &B[i]);
	for (int i = 1; i <= N; i++) {
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}

	// 
	dfs1(1);
	for (int i = 1; i <= N; i++) {
		dp[i][0] = (1LL << 40);
		dp[i][1] = (1LL << 40);
	}

	// DP 
	dfs2(1);

	// 
	cout << dp[1][0] << endl;
	return 0;
}