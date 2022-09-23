#include <bits/stdc++.h>

using namespace std;

char A[2020];
char B[2020];

int ca[2020][30];
int cb[2020][30];

int D[2020][2020];
int N;

int f(int x, int y) {
	if(y > N) return N - x + 1;
	if(D[x][y] != -1) return D[x][y];

	int& ret = D[x][y];
	ret = 1010101010;

	int t = A[x] - 'a';
	if(cb[y - 1][t] - ca[x - 1][t] > 0) ret = min(ret, 1 + f(x + 1, y));
	if(A[x] == B[y]) ret = min(ret, f(x + 1, y + 1));
	ret = min(ret, f(x, y + 1));
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		scanf("%s", B + 1);

		for(int i = 1; i <= N; i++) {
			for(int j = 0; j < 26; j++) {
				if('a' + j == A[i]) ca[i][j] = ca[i - 1][j] + 1;
				else ca[i][j] = ca[i - 1][j];

				if('a' + j == B[i]) cb[i][j] = cb[i - 1][j] + 1;
				else cb[i][j] = cb[i - 1][j];
			}
		}

		bool ok = true;
		for(int i = 0; i < 26; i++) {
			if(ca[N][i] != cb[N][i]) ok = false;
		}
		if(!ok) { puts("-1"); continue; }

		for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) D[i][j] = -1;

		printf("%d\n", f(1, 1));

		// for(int i = 1; i <= N; i++) {
		// 	for(int j = 1; j <= N; j++) {
		// 		printf("%d ", f(i, j));
		// 	}
		// 	puts("");
		// }
	}

	return 0;
}