#include <bits/stdc++.h>

using namespace std;

const int INF = 10101;

int D[101][101][101];
int E[101][101][101];
int A[101];
int N;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 0; i <= N; i++) for(int j = 0; j <= N; j++) for(int k = 0; k <= N; k++) D[i][j][k] = E[i][j][k] = INF;

	if(A[1] == 0) { D[1][(N + 1) / 2 - 1][N / 2] = E[1][(N + 1) / 2][N / 2 - 1] = 0; }
	else if(A[1] & 1) D[1][(N + 1) / 2 - 1][N / 2] = 0;
	else E[1][(N + 1) / 2][N / 2 - 1] = 0;

	for(int i = 2; i <= N; i++) {
		if(A[i] == 0) {
			for(int j = 0; j <= N; j++) {
				for(int k = 0; k <= N; k++) {
					if(j < N) D[i][j][k] = min(E[i - 1][j + 1][k] + 1, D[i - 1][j + 1][k]);
					if(k < N) E[i][j][k] = min(D[i - 1][j][k + 1] + 1, E[i - 1][j][k + 1]);
				}
			}
		}
		else if(A[i] & 1) {
			for(int j = 0; j <= N; j++) {
				for(int k = 0; k <= N; k++) {
					if(j < N) D[i][j][k] = min(E[i - 1][j + 1][k] + 1, D[i - 1][j + 1][k]);
				}
			}
		}
		else {
			for(int j = 0; j <= N; j++) {
				for(int k = 0; k <= N; k++) {
					if(k < N) E[i][j][k] = min(D[i - 1][j][k + 1] + 1, E[i - 1][j][k + 1]);
				}
			}
		}

		// for(int j = 0; j <= N; j++) for(int k = 0; k <= N; k++) printf("%d %d %d %d\n", i, j, k, D[i][j][k]);
	}

	printf("%d\n", min(D[N][0][0], E[N][0][0]));

	return 0;
}