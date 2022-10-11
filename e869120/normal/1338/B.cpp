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
int N;
int A[1 << 18], B[1 << 18];
vector<int> X[1 << 18];

// DFS
bool used[1 << 18];
int col[1 << 18];
int cnt[1 << 18];

void dfs(int pos, int dep) {
	used[pos] = true;
	col[pos] = dep;
	for (int i : X[pos]) {
		if (used[i] == true) continue;
		dfs(i, dep ^ 1);
	}
}

int main() {
	// 
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d%d", &A[i], &B[i]);
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}
	dfs(1, 0);

	// 
	int Answer1 = 3;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= N; i++) {
		if (X[i].size() >= 2) continue;
		if (col[i] == 0) cnt1 += 1;
		if (col[i] == 1) cnt2 += 1;
	}
	if (cnt1 == 0 || cnt2 == 0) Answer1 = 1;

	// 
	int Answer2 = N - 1;
	for (int i = 1; i <= N; i++) {
		if (X[i].size() >= 2) continue;
		cnt[X[i][0]] += 1;
	}
	for (int i = 1; i <= N; i++) {
		if (cnt[i] >= 2) Answer2 -= (cnt[i] - 1);
	}

	// 
	cout << Answer1 << " " << Answer2 << endl;
	return 0;
}