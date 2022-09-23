#include <bits/stdc++.h>

using namespace std;

int D[1010101][5][4];
int N, M;
int A[1010101];

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		A[x]++;
	}

	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 3; j++) {
			int x = A[M - 1] - i;
			int y = A[M] - j;
			if(x < 0 || y < 0) continue;
			D[M - 1][i][j] = x / 3 + y / 3;
		}
	}

	for(int i = M - 2; i >= 1; i--) {
		for(int j = 0; j < 5; j++) {
			if(A[i] < j) continue;
			for(int k = 0; k < 3; k++) {
				int x = A[i] - j;
				D[i][j][k] = D[i + 1][k][0];
				for(int l = 0; l <= min(2, x); l++) {
					if(l + k > A[i + 1]) break;
					if(l > A[i + 2]) break;
					D[i][j][k] = max(D[i][j][k], D[i + 1][k + l][l] + l + (x - l) / 3);
				}
			}
		}
	}
	printf("%d\n", D[1][0][0]);
	return 0;
}