#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M, K;

int sz[3];
int A[3][202];

ll D[202][202][202];

int main() {
	for(int i = 0; i < 3; i++) scanf("%d", &sz[i]);
	for(int i = 0; i < 3; i++) {
		for(int j = 1; j <= sz[i]; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for(int i = 0; i < 3; i++) {
		sort(A[i] + 1, A[i] + sz[i] + 1);
		reverse(A[i] + 1, A[i] + sz[i] + 1);
	}

	for(int i = 0; i <= sz[0]; i++) {
		for(int j = 0; j <= sz[1]; j++) {
			for(int k = 0; k <= sz[2]; k++) {
				if(i) D[i][j][k] = max(D[i][j][k], D[i - 1][j][k]);
				if(j) D[i][j][k] = max(D[i][j][k], D[i][j - 1][k]);
				if(k) D[i][j][k] = max(D[i][j][k], D[i][j][k - 1]);

				int a = A[0][i], b = A[1][j], c = A[2][k];

				if(i && j) D[i][j][k] = max(D[i][j][k], D[i - 1][j - 1][k] + a * b);
				if(j && k) D[i][j][k] = max(D[i][j][k], D[i][j - 1][k - 1] + b * c);
				if(k && i) D[i][j][k] = max(D[i][j][k], D[i - 1][j][k - 1] + c * a);
			}
		}
	}

	printf("%lld\n", D[sz[0]][sz[1]][sz[2]]);

	return 0;
}