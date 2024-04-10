#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[10][10];

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
	int x = 1, y = 1;
	int ans = ('*' == A[y][x]);

	while(y < N || x < M) {
		int ny = N, nx = M, d = N + M;

		for(int i = y; i <= N; i++) for(int j = x; j <= M; j++) {
			if(i == y && j == x) continue;
			if(A[i][j] == '*') {
				int tmp = i - y + j - x;
				if(tmp < d || d == tmp && i < ny) {
					d = tmp;
					ny = i;
					nx = j;
				}
			}
		}

		if(N + M <= d) break;

		ans++;
		y = ny; x = nx;
	}

	printf("%d\n", ans);
	return 0;
}