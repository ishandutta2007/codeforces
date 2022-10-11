#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, M, Q, P[200009], A[200009], R[200009], dp[200009][22], next_value[200009];
vector<int>vec[200009];

int prevs(int pos, int x) {
	for (int i = 21; i >= 0; i--) {
		if (x >= (1 << i)) { x -= (1 << i); pos = dp[pos][i]; }
	}
	return pos;
}

int main() {
	cin >> N >> M >> Q;
	for (int i = 0; i < N; i++) scanf("%d", &P[i]);
	for (int i = 0; i < N; i++) next_value[P[i]] = P[(i + 1) % N];
	for (int i = 0; i < M; i++) { scanf("%d", &A[i]); vec[A[i]].push_back(i); }

	for (int i = 0; i < M; i++) {
		int pos1 = lower_bound(vec[next_value[A[i]]].begin(), vec[next_value[A[i]]].end(), i) - vec[next_value[A[i]]].begin();
		if (pos1 < vec[next_value[A[i]]].size()) dp[i][0] = vec[next_value[A[i]]][pos1];
		else dp[i][0] = M;
	}
	for (int i = 0; i < 22; i++) dp[M][i] = M;
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < M; j++) dp[j][i + 1] = dp[dp[j][i]][i];
	}

	for (int i = 0; i < M; i++) R[i] = prevs(i, N - 1);
	for (int i = M - 2; i >= 0; i--) R[i] = min(R[i], R[i + 1]);

	for (int i = 0; i < Q; i++) {
		int cl, cr; scanf("%d%d", &cl, &cr); cl--; cr--;
		if (R[cl] <= cr) printf("1");
		else printf("0");
	}
	printf("\n");
	return 0;
}