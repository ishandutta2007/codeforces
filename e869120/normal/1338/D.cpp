#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

// 
int N;
int A[1 << 18], B[1 << 18];

// 
bool used[1 << 18];
vector<int> X[1 << 18];
vector<int> Y[1 << 18];
vector<int> ord;
int dp[1 << 18][2];

// 
int FinalAns = 1;

void dfs(int pos) {
	used[pos] = true;
	for (int i : X[pos]) {
		if (used[i] == true) continue;
		dfs(i);
		Y[pos].push_back(i);
	}
	ord.push_back(pos);
}

int main() {
	// 
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d%d", &A[i], &B[i]);
	}

	// 
	for (int i = 1; i <= N - 1; i++) {
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}
	dfs(1);

	//  DP
	for (int i = 1; i <= N; i++) {
		dp[i][0] = -(1 << 29);
		dp[i][1] = -(1 << 29);
	}
	for (int i = 1; i <= N; i++) {
		dp[i][1] = X[i].size() - 1;
		dp[i][0] = 1;
	}
	for (int i : ord) {
		for (int j : Y[i]) {
			dp[i][0] = max(dp[i][0], dp[j][1] + 1);
			dp[i][1] = max(dp[i][1], dp[j][0] + (int)X[i].size() - 2);
			dp[i][1] = max(dp[i][1], dp[j][1] + (int)X[i].size() - 2);
		}
	}
	for (int i = 1; i <= N; i++) dp[i][1] += 1;
	for (int i = 1; i <= N; i++) {
		FinalAns = max(FinalAns, dp[i][0]);
		FinalAns = max(FinalAns, dp[i][1]);
	}

	// 
	for (int i = 1; i <= N; i++) {
		vector<pair<int, int>> V0, V1;
		for (int j : Y[i]) V0.push_back(make_pair(dp[j][0], j));
		for (int j : Y[i]) V1.push_back(make_pair(dp[j][1], j));
		sort(V0.begin(), V0.end()); reverse(V0.begin(), V0.end());
		sort(V1.begin(), V1.end()); reverse(V1.begin(), V1.end());
		if (V0.size() >= 2) FinalAns = max(FinalAns, V0[0].first + V0[1].first + (int)X[i].size() - 2);
		if (V1.size() >= 2) FinalAns = max(FinalAns, V1[0].first + V1[1].first + max((int)X[i].size(), 3) - 4);
		if (V0.size() >= 1 && V1.size() >= 1 && V0[0].second != V1[0].second) FinalAns = max(FinalAns, V0[0].first + V1[0].first + (int)X[i].size() - 3);
		if (V0.size() >= 1 && V1.size() >= 2 && V0[0].second != V1[1].second) FinalAns = max(FinalAns, V0[0].first + V1[1].first + (int)X[i].size() - 3);
		if (V0.size() >= 2 && V1.size() >= 1 && V0[1].second != V1[0].second) FinalAns = max(FinalAns, V0[1].first + V1[0].first + (int)X[i].size() - 3);
	}

	// 
	cout << FinalAns << endl;
	return 0;
}