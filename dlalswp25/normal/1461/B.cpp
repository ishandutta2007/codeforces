#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[505][505];
int D[505][505];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		for(int i = 1; i <= M; i++) D[N][i] = (A[N][i] == '*');
		for(int i = 1; i <= N; i++) D[i][M + 1] = 0;
		for(int i = N - 1; i >= 1; i--) {
			for(int j = 1; j <= M; j++) {
				if(A[i][j] == '.') { D[i][j] = 0; continue; }
				D[i][j] = min(D[i + 1][j], min(D[i + 1][j - 1], D[i + 1][j + 1])) + 1;
			}
		}
		int ans = 0;
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) ans += D[i][j];
		printf("%d\n", ans);
	}
	return 0;
}