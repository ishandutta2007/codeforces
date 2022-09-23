#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N, X;
int A[50505];
int D[50505][2][2];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		scanf("%d", &X);
		for(int i = 1; i <= N; i++) {
			D[i][0][0] = max(D[i - 1][0][0], D[i - 1][0][1]);
			D[i][0][1] = max(D[i - 1][1][0], D[i - 1][1][1]);
			D[i][1][0] = max(D[i - 1][0][0], D[i - 1][0][1]) + 1;
			D[i][1][1] = -INF;
			if(A[i] + A[i - 1] >= 2 * X) {
				D[i][1][1] = max(D[i][1][1], D[i - 1][1][0] + 1);
			}
			if(A[i] + A[i - 1] >= 2 * X && A[i] + A[i - 1] + A[i - 2] >= 3 * X) {
				D[i][1][1] = max(D[i][1][1], D[i - 1][1][1] + 1);
			}
		}
		printf("%d\n", max(max(D[N][0][0], D[N][0][1]), max(D[N][1][0], D[N][1][1])));
	}
	return 0;
}