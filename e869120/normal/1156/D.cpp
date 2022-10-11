#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 18], B[1 << 18], C[1 << 18];
int col1[1 << 18], col2[1 << 18], cnt1[1 << 18], cnt2[1 << 18], cnts;
vector<int>G1[1 << 18], G2[1 << 18];

void dfs1(int pos) {
	if (col2[pos] >= 1) return;
	cnt2[cnts]++; col2[pos] = cnts;
	for (int i = 0; i < G2[pos].size(); i++) dfs1(G2[pos][i]);
}

void dfs2(int pos) {
	if (col1[pos] >= 1) return;
	cnt1[cnts] += cnt2[col2[pos]]; col1[pos] = cnts;
	for (int i = 0; i < G1[pos].size(); i++) dfs2(G1[pos][i]);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
		if (C[i] == 0) {
			G1[A[i]].push_back(B[i]);
			G1[B[i]].push_back(A[i]);
		}
		if (C[i] == 1) {
			G2[A[i]].push_back(B[i]);
			G2[B[i]].push_back(A[i]);
		}
	}
	cnts = 0;
	for (int i = 1; i <= N; i++) {
		if (col2[i] >= 1) continue;
		cnts++; dfs1(i);
	}
	cnts = 0;
	for (int i = 1; i <= N; i++) {
		if (col1[i] >= 1) continue;
		cnts++; dfs2(i);
	}

	long long ans = 0;
	for (int i = 1; i <= N; i++) ans += cnt1[col1[i]];
	cout << ans - N << endl;
	return 0;
}