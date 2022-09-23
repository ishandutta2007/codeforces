#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N;
int A[2][202020];
int D[2][202020];
int E[2][202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 0; i < 2; i++) for(int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			if(i > 0 || j > 1) A[i][j]++;
		}
		for(int i = 0; i < 2; i++) {
			D[i][N + 1] = E[i][N + 1] = -INF;
			for(int j = N; j >= 1; j--) {
				D[i][j] = max(D[i][j + 1], A[i][j] - j);
				E[i][j] = max(E[i][j + 1], A[i][j] + j);
			}
		}

		int cur = 0, y = 0;
		int ans = INF;
		for(int i = 1; i <= N; i++) {
			ans = min(ans, max({cur + (N - i) + 1 + (N - i), D[y][i] + N + 1 + N - i, E[1 - y][i] - i}));
			if(D[y][i] <= cur - i && E[1 - y][i] <= cur + N - i + 1 + N) {
				ans = min(ans, cur + N - i + 1 + N - i);
			}
			cur = max(cur + 1, A[1 - y][i]);
			cur = max(cur + 1, A[1 - y][i + 1]);
			y = 1 - y;
		}
		printf("%d\n", ans);
	}
	return 0;
}