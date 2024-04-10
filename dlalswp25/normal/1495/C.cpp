#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[505][505];
char B[505][505];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		if(N == 1 || M == 1) {
			for(int i = 1; i <= N; i++) {
				for(int j = 1; j <= M; j++) {
					printf("X");
				}
				puts("");
			}
			continue;
		}
		for(int i = 1; i <= M; i++) B[1][i] = 'X';
		for(int i = 2; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(j % 3 == 1) B[i][j] = 'X';
				else B[i][j] = '.';
			}
		}

		for(int j = 2; j <= M; j += 3) {
			if(A[2][j] == 'X' || (j < M && A[2][j + 1] == 'X')) {
				B[1][j] = '.'; B[2][j] = 'X';
				if(j < M) {
					B[1][j + 1] = '.';
					B[2][j + 1] = 'X';
				}
			}
		}

		if(M % 3 == 0) {
			for(int i = 3; i <= N; i++) {
				if(A[i][M] != 'X') continue;
				if(B[i - 1][M] == 'X') continue;
				B[i][M - 1] = B[i][M] = 'X';
			}
		}

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(A[i][j] == 'X') B[i][j] = 'X';
			}
		}

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				printf("%c", B[i][j]);
			}
			puts("");
		}
	}
	return 0;
}