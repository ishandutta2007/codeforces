#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[1010][1010];
int mn[1010][1010];
int mx[1010][1010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) scanf("%d", &A[i][j]);
		if(N + M + 1 & 1) { puts("NO"); continue; }
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(i == 1) {
					mn[i][j] = mn[i][j - 1] + A[i][j];
					mx[i][j] = mx[i][j - 1] + A[i][j];
				}
				else if(j == 1) {
					mn[i][j] = mn[i - 1][j] + A[i][j];
					mx[i][j] = mx[i - 1][j] + A[i][j];
				}
				else {
					mn[i][j] = min(mn[i - 1][j], mn[i][j - 1]) + A[i][j];
					mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]) + A[i][j];
				}
			}
		}
		puts(mn[N][M] <= 0 && mx[N][M] >= 0 ? "YES" : "NO");
	}
	return 0;
}