#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int D[15][505][505];
int A[505][505];
int B[505][505];

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j < M; j++) scanf("%d", &A[i][j]);
	}
	for(int i = 1; i < N; i++) {
		for(int j = 1; j <= M; j++) scanf("%d", &B[i][j]);
	}
	if(K & 1) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) printf("-1 ");
			puts("");
		}
		return 0;
	}
	for(int i = 1; i <= K / 2; i++) {
		for(int j = 1; j <= N; j++) {
			for(int k = 1; k <= M; k++) {
				D[i][j][k] = 1010101010;
				if(j > 1) D[i][j][k] = min(D[i][j][k], D[i - 1][j - 1][k] + 2 * B[j - 1][k]);
				if(j < N) D[i][j][k] = min(D[i][j][k], D[i - 1][j + 1][k] + 2 * B[j][k]);
				if(k > 1) D[i][j][k] = min(D[i][j][k], D[i - 1][j][k - 1] + 2 * A[j][k - 1]);
				if(k < M) D[i][j][k] = min(D[i][j][k], D[i - 1][j][k + 1] + 2 * A[j][k]);
			}
		}
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			printf("%d ", D[K / 2][i][j]);
		}
		puts("");
	}
	return 0;
}