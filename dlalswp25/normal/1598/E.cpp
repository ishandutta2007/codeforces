#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
int A[1010][1010];
int D[1010][1010];
int E[1010][1010];
int F;
int ans;

void upd(int x, int y) {
	if(A[x][y]) return;
	ans -= (D[x][y] + E[x][y]);
	D[x][y] = 1 + E[x + 1][y];
	E[x][y] = 1 + D[x][y + 1];
	ans += (D[x][y] + E[x][y]);
}

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	F = N * M;

	ans = 0;
	for(int i = N; i >= 1; i--) {
		for(int j = M; j >= 1; j--) {
			D[i][j] = 1 + E[i + 1][j];
			E[i][j] = 1 + D[i][j + 1];
			ans += D[i][j] + E[i][j];
		}
	}

	while(Q--) {
		int x, y; scanf("%d%d", &x, &y);
		A[x][y] = 1 - A[x][y];
		if(!A[x][y]) {
			F++;
			upd(x, y);
			if(y > 1) upd(x, y - 1);
		}
		else {
			F--;
			ans -= (D[x][y] + E[x][y]);
			D[x][y] = E[x][y] = 0;
			if(y > 1) upd(x, y - 1);
		}

		for(int i = x - 1; i >= 1; i--) {
			for(int j = y - (x - i - 1); j >= y - (x - i - 1) - 2; j--) {
				if(j <= 0) break;
				upd(i, j);
			}
		}

		printf("%d\n", ans - F);
	}
	return 0;
}