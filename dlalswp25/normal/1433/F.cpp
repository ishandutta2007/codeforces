#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N, M, K;

int A[77][77];
int D[77][77][77];
int tmp[77][77];
int D2[77][77];
int E[77][77];

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) scanf("%d", &A[i][j]);
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j <= M / 2; j++) for(int k = 0; k < K; k++) D[i][j][k] = -INF;
		D[i][0][0] = 0;
		for(int j = 1; j <= M; j++) {
			for(int k = 1; k <= M / 2; k++) {
				for(int l = 0; l < K; l++) {
					tmp[k][l] = max(D[i][k][l], D[i][k - 1][(l + 70 * K - A[i][j]) % K] + A[i][j]);
				}
			}
			for(int k = 1; k <= M / 2; k++) for(int l = 0; l < K; l++) {
				D[i][k][l] = tmp[k][l];
				// printf("%d %d %d %d %d\n", i, j, k, l, D[i][k][l]);
			}
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < K; j++) {
			D2[i][j] = -INF;
			for(int k = 0; k <= M / 2; k++) D2[i][j] = max(D2[i][j], D[i][k][j]);
			// printf("%d %d %d\n", i, j, D2[i][j]);
		}
	}

	for(int i = 1; i < K; i++) E[0][i] = -INF;
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < K; j++) {
			E[i][j] = E[i - 1][j];
			for(int k = 0; k < K; k++) {
				E[i][j] = max(E[i][j], E[i - 1][(j + 70 * K - k) % K] + D2[i][k]);
			}
		}
	}
	printf("%d\n", E[N][0]);

	return 0;
}