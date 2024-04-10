#include <bits/stdc++.h>

using namespace std;

int N, M;

int A[505][505];

int main() {
	scanf("%d%d", &N, &M);
	if(N == 1 && M == 1) { puts("0"); return 0; }

	if(N < M) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				A[i][j] = i * (N + j);
			}
		}
	}
	else {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				A[i][j] = (M + i) * j;
			}
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			printf("%d ", A[i][j]);
		}
		puts("");
	}

	return 0;
}