#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, M, P[1 << 19], A[1 << 19], B[1 << 19], id[1 << 19], cnt[1 << 19];
vector<int>G[1 << 19];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) { scanf("%d", &P[i]); id[P[i]] = i; }
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &A[i], &B[i]); A[i] = id[A[i]]; B[i] = id[B[i]];
		if (B[i] > A[i]) { G[B[i]].push_back(A[i]); cnt[A[i]]++; }
	}
	int goal = N;
	for (int i = N - 1; i >= 1; i--) {
		if (cnt[i] + i == goal) {
			goal--;
			for (int j = 0; j < G[i].size(); j++) cnt[G[i][j]]--;
		}
	}
	cout << N - goal << endl;
	return 0;
}