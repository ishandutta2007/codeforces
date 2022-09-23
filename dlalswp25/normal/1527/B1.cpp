#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N;
char A[1010];
int D[505][505][2][2][2];

int f(int a, int b, int c, int r, int odd) {
	if(!a && !b && c) return 0;
	if(D[a][b][c][r][odd] != -INF) return D[a][b][c][r][odd];
	int& ret = D[a][b][c][r][odd];
	if(a && !r) ret = max(ret, -f(a, b, c, 1, odd));
	if(odd && !c) ret = max(ret, -1 - f(a, b, 1, 0, odd));
	if(b) ret = max(ret, -1 - f(a + 1, b - 1, c, 0, odd));
	if(a) ret = max(ret, -1 - f(a - 1, b, c, 0, odd));
	// printf("%d %d %d %d %d ret %d\n", a, b, c, r, odd, ret);
	return ret;
}

int main() {
	for(int i = 0; i <= 500; i++) for(int j = 0; j <= 500; j++) {
		for(int k = 0; k < 2; k++) for(int l = 0; l < 2; l++) for(int m = 0; m < 2; m++) {
			D[i][j][k][l][m] = -INF;
		}
	}

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		int a = 0, b = 0, c = 0;
		for(int i = 1; i < N - i + 1; i++) {
			if(A[i] != A[N - i + 1]) a++;
			else if(A[i] == '0') b++;
		}
		if(N & 1) {
			if(A[N / 2 + 1] == '1') c++;
		}
		else c++;
		// printf("%d %d %d\n", a, b, c);
		int t = f(a, b, c, 0, N & 1);
		if(t > 0) puts("ALICE");
		else if(t == 0) puts("DRAW");
		else puts("BOB");
	}
	return 0;
}