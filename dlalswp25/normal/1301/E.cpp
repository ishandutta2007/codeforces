#include <bits/stdc++.h>
 
using namespace std;
 
char C[505][505];
int A[505][505];
int D[4][505][505];
int S[252][505][505];
int N, M, Q;
 
char X[4] = {'R', 'G', 'Y', 'B'};
 
int sum(int k, int x1, int y1, int x2, int y2) {
	if(x2 < x1 || y2 < y1) return 0;
	if(!x1) x1++;
	if(!y1) y1++;
	return S[k][x2][y2] - S[k][x1 - 1][y2] - S[k][x2][y1 - 1] + S[k][x1 - 1][y1 - 1];
}
 
int main() {
	scanf("%d%d%d", &N, &M, &Q);
	for(int i = 1; i <= N; i++) scanf("%s", C[i] + 1);
 
	for(int k = 0; k < 4; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(C[i][j] != X[k]) D[k][i][j] = 0;
				else if(D[k][i - 1][j] == D[k][i][j - 1]) {
					int t = D[k][i - 1][j];
					D[k][i][j] = D[k][i - 1][j] + (C[i - t][j - t] == X[k]);
				}
				else D[k][i][j] = min(D[k][i - 1][j], D[k][i][j - 1]) + 1;
			}
		}
	}
 
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			A[i][j] = 0;
			for(int k = 1; ; k++) {
				if(D[0][i][j] < k) break;
				if(D[1][i][j + k] < k) break;
				if(D[2][i + k][j] < k) break;
				if(D[3][i + k][j + k] < k) break;
				A[i][j]++;
			}
		}
	}
 
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) {
		for(int k = 0; k <= A[i][j]; k++) S[k][i][j]++;
	}
 
	for(int k = 0; k <= 250; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				S[k][i][j] += (S[k][i - 1][j] + S[k][i][j - 1] - S[k][i - 1][j - 1]);
			}
		}
	}
 
	// for(int i = 1; i <= N; i++) {
	// 	for(int j = 1; j <= M; j++) printf("%d ", A[i][j]); puts("");
	// }
 
	while(Q--) {
		int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(N == 1 || M == 1) { puts("0"); continue; }
 
		int l = 0, r = 250;
		while(l <= r) {
			int m = l + r >> 1;
 
			// printf("%d %d %d %d %d\n", m, x1 + m - 1, y1 + m - 1, x2 - m, y2 - m);
			if(sum(m, x1 + m - 1, y1 + m - 1, x2 - m, y2 - m) > 0) l = m + 1;
			else r = m - 1;
		}
		printf("%d\n", 4 * r * r);
	}
 
	return 0;
}