#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, K, Q, A[13][100019], T[100019], X[100019], Y[100019];
bool G[4096][100019];

int main() {
	scanf("%d%d%d", &N, &K, &Q);
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d%d%d", &T[i], &X[i], &Y[i]);
		X[i]--; Y[i]--;
	}
	for (int i = 0; i < (1 << K); i++) {
		for (int j = 0; j < K; j++) {
			if ((i / (1 << j)) % 2 == 0) G[i][j] = false;
			else G[i][j] = true;
		}
		int num = K;
		for (int j = 0; j < Q; j++) {
			if (T[j] == 1) { G[i][num] = max(G[i][X[j]], G[i][Y[j]]); num++; }
			if (T[j] == 2) { G[i][num] = min(G[i][X[j]], G[i][Y[j]]); num++; }
		}
	}
	for (int i = 0; i < Q; i++) {
		if (T[i] == 1 || T[i] == 2) continue;
		vector<pair<int, int>> E;
		for (int j = 0; j < K; j++) E.push_back(make_pair(A[j][Y[i]], j));
		sort(E.begin(), E.end());

		int mask = 0;
		for (int j = E.size() - 1; j >= 0; j--) {
			mask ^= (1 << E[j].second);
			if (G[mask][X[i]] == true) { printf("%d\n", E[j].first); break; }
		}
	}
	return 0;
}