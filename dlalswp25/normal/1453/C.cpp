#include <bits/stdc++.h>

using namespace std;

int N;
char A[2020][2020];
char B[2020][2020];
int ans[15];

void rot() {
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) B[i][j] = A[i][j];
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) A[i][j] = B[N - j + 1][i];
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);

		for(int d = 0; d <= 9; d++) {
			ans[d] = 0;
			for(int z = 0; z < 4; z++) {
				int fir = N + 1;
				for(int i = 1; i <= N; i++) {
					int mn = N + 1;
					for(int j = 1; j <= N; j++) {
						if(A[i][j] != d + '0') continue;
						if(fir > N) fir = i;
						if(mn > N) mn = j;
						ans[d] = max(ans[d], (i - fir) * max(j - 1, N - j));
						ans[d] = max(ans[d], (j - mn) * (i - 1));
					}
				}
				rot();
			}
		}
		for(int d = 0; d <= 9; d++) printf("%d ", ans[d]); puts("");
	}
	return 0;
}