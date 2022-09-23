#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q;
ll A[30][30];
ll mn[30][30];
ll mx[30][30];

int main() {
	scanf("%d", &N);

	for(int i = 1; i <= N; i++) {
		A[i][N] = A[1][i] = 0;
		mn[i][N] = mn[1][i] = 0;
	}

	for(int j = N - 1; j >= 1; j--) {
		for(int i = 2; i <= N; i++) {
			if(i == 2) {
				A[i][j] = mx[i][j + 1] - mn[i][j + 1] + 1;
			}
			else {
				A[i][j] = mx[i - 1][j + 1] - mn[i][j + 1] + 1;
			}
			mn[i][j] = A[i][j] + mn[i][j + 1];
		}

		mx[N][j] = A[N][j] + mx[N][j + 1];
		for(int i = N - 1; i >= 1; i--) mx[i][j] = mx[i + 1][j] + A[i][j];
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			printf("%lld ", A[i][j]);
		}
		puts("");
	}

	fflush(stdout);

	scanf("%d", &Q);
	while(Q--) {
		ll k; scanf("%lld", &k);
		int x = 1, y = 1;
		while(1) {
			printf("%d %d\n", x, y);
			if(x == N && y == N) break;
			k -= A[x][y];
			if(y == N) { x++; continue; }
			if(x == N) { y++; continue; }
			if(mx[x][y + 1] < k) { x++; continue; }
			y++;
		}

		fflush(stdout);
	}

	return 0;
}