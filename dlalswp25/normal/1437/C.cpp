#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N;
int A[202];
int D[202][404];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);

		for(int i = 1; i <= N; i++) D[1][i] = abs(A[1] - i);
		for(int i = 2; i <= N; i++) {
			for(int j = 1; j <= 2 * N; j++) {
				D[i][j] = INF;
				for(int k = 1; k < j; k++) {
					D[i][j] = min(D[i][j], D[i - 1][k] + abs(A[i] - j));
				}
			}
		}
		int ans = INF;
		for(int i = 1; i <= 2 * N; i++) ans = min(ans, D[N][i]);
		printf("%d\n", ans);
	}
	return 0;
}