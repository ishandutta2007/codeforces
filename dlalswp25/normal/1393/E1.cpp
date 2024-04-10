#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int N;
char S[1010][20202];
int len[1010];

int cmp[20202];
int tmp[20202];
int D[2][20202];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%s", S[i] + 1);
		len[i] = strlen(S[i] + 1);
	}

	for(int i = 0; i <= len[1]; i++) D[1][i] = 1;
	for(int i = 2; i <= N; i++) {
		for(int j = 0; j <= len[i]; j++) D[i & 1][j] = 0;

		tmp[len[i] + 1] = 0;
		for(int j = max(len[i], len[i - 1]); j >= 1; j--) {
			if(S[i - 1][j] < S[i][j]) tmp[j] = 1;
			else if(S[i - 1][j] > S[i][j]) tmp[j] = -1;
			else tmp[j] = tmp[j + 1];
		}

		cmp[len[i] + 1] = cmp[len[i] + 2] = 0;
		for(int j = len[i]; j > len[i - 1]; j--) {
			if(S[i - 1][j] < S[i][j + 1]) cmp[j] = 1;
			else if(S[i - 1][j] > S[i][j + 1]) cmp[j] = -1;
			else cmp[j] = cmp[j + 1];
		}

		for(int jj = len[i - 1] + 1; jj > 0; jj--) {
			int j = (jj > len[i - 1] ? 0 : jj);

			if(jj <= len[i]) {
				if(S[i - 1][j + 1] < S[i][j + 1]) cmp[j] = 1;
				else if(S[i - 1][j + 1] > S[i][j + 1]) cmp[j] = -1;
				else cmp[j] = tmp[j + 1];
			}

			for(int k = jj - 1; k >= 1; k--) {
				if(S[i - 1][k] < S[i][k + 1]) cmp[k] = 1;
				else if(S[i - 1][k] > S[i][k + 1]) cmp[k] = -1;
				else cmp[k] = cmp[k + 1];
			}

			// printf("cmp : i j %d %d\n", i, j);
			// for(int k = 0; k <= len[i]; k++) printf("%d ", cmp[k]); puts("");

			int state = 0;
			int p = 1;
			if(j == p) p++;
			for(int k = 1; k <= len[i]; k++) {
				if(state == 0) {
					if(cmp[k] >= 0) D[i & 1][k] = (D[i & 1][k] + D[i + 1 & 1][j]) % MOD;
				}
				else if(state == 1) {
					D[i & 1][k] = (D[i & 1][k] + D[i + 1 & 1][j]) % MOD;
				}

				if(!state) {
					if(S[i - 1][p] < S[i][k]) state = 1;
					else if(S[i - 1][p] > S[i][k]) state = -1;
				}
				p++;
				if(p == j) p++;
			}

			if(state == 1 || (state == 0 && (len[i - 1] - !!j) == len[i])) D[i & 1][0] = (D[i & 1][0] + D[i + 1 & 1][j]) % MOD;

			// printf("dp : i j %d %d\n", i, j);
			// for(int k = 0; k <= len[i]; k++) printf("%d ", D[i & 1][k]); puts("");
		}

		// for(int j = 0; j <= 5; j++) printf("%d ", D[i & 1][j]); puts("");
	}

	int ans = 0;
	for(int i = 0; i <= len[N]; i++) ans = (ans + D[N & 1][i]) % MOD;
	printf("%d\n", ans);
	
	return 0;
}