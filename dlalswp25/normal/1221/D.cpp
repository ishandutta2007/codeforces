#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = (1LL << 60);

int N;
int A[303030];
int B[303030];

ll D[303030][3];

int main() {
	int Q; scanf("%d", &Q);
	while(Q--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d%d", &A[i], &B[i]);

		D[1][0] = 0; D[1][1] = B[1]; D[1][2] = B[1] * 2;
		for(int i = 2; i <= N; i++) {
			for(int j = 0; j < 3; j++) {
				D[i][j] = INF;
				for(int k = 0; k < 3; k++) {
					if(A[i - 1] + k == A[i] + j) continue;
					D[i][j] = min(D[i][j], D[i - 1][k] + j * B[i]);
				}
			}
		}
		printf("%lld\n", min(D[N][0], min(D[N][1], D[N][2])));
	}
	return 0;
}