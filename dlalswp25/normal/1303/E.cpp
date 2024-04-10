#include <bits/stdc++.h>

using namespace std;

char S[404];
char T[404];
int nxt[30][404];
int N, M;

int D[404][404];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", S + 1);
		scanf("%s", T + 1);
		N = strlen(S + 1); M = strlen(T + 1);

		for(int i = 0; i < 26; i++) {
			int bef = N + 1;
			for(int j = N; j >= 0; j--) {
				nxt[i][j] = bef;
				if(S[j] - 'a' == i) bef = j;
			}
			nxt[i][N + 1] = N + 1;
		}

		bool ok = false;
		for(int k = 1; k <= M; k++) {
			for(int i = 1; i <= M; i++) for(int j = 1; j <= M; j++) D[i][j] = N + 1;

			D[0][0] = 0;
			for(int i = 1; i <= k; i++) {
				D[i][0] = nxt[(int)(T[i] - 'a')][D[i - 1][0]];
			}
			for(int j = 1; j <= M - k; j++) {
				D[0][j] = nxt[(int)(T[j + k] - 'a')][D[0][j - 1]];
			}

			for(int i = 1; i <= k; i++) {
				for(int j = 1; j <= M - k; j++) {
					D[i][j] = min(nxt[(int)(T[i] - 'a')][D[i - 1][j]], nxt[(int)(T[j + k] - 'a')][D[i][j - 1]]);
				}
			}

			// printf("%d\n", k);
			// for(int i = 0; i <= k; i++) {
			// 	for(int j = 0; j <= M - k; j++) {
			// 		printf("%d ", D[i][j]);
			// 	}
			// 	puts("");
			// }

			if(D[k][M - k] <= N) ok = true;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}