#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[505][505];
int S[505][505];
int L[505];
int mn[505];

int sum(int x1, int y1, int x2, int y2) {
	return S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1];
}

int black(int x1, int y1, int x2, int y2) {
	return sum(x1, y1, x2, y2);
}

int white(int x1, int y1, int x2, int y2) {
	return (x2 - x1 + 1) * (y2 - y1 + 1) - sum(x1, y1, x2, y2);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + (A[i][j] == '1');
		}

		int ans = 1010101010;
		for(int i = 1; i <= N; i++) {
			for(int j = i + 4; j <= N; j++) {
				mn[0] = 1010101010;
				for(int k = 1; k <= M; k++) {
					L[k] = white(i + 1, k, j - 1, k) - white(i, 1, i, k) - white(j, 1, j, k) - black(i + 1, 1, j - 1, k);
					mn[k] = min(mn[k - 1], L[k]);
				}
				for(int k = 1; k <= M; k++) {
					int r = white(i + 1, k, j - 1, k) + white(i, 1, i, k - 1) + white(j, 1, j, k - 1) + black(i + 1, 1, j - 1, k - 1);
					if(k >= 4) ans = min(ans, mn[k - 3] + r);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}