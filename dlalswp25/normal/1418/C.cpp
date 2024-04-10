#include <bits/stdc++.h>

using namespace std;

int N;
int D[2][202020];
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		D[0][N] = A[N];
		D[1][N] = 0;
		D[0][N + 1] = D[1][N + 1] = 0;
		for(int i = N - 1; i >= 1; i--) {
			D[0][i] = min(D[1][i + 1] + A[i], D[1][i + 2] + A[i] + A[i + 1]);
			D[1][i] = min(D[0][i + 1], D[0][i + 2]);
		}
		printf("%d\n", D[0][1]);
	}
	return 0;
}