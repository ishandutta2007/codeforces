#include <bits/stdc++.h>

using namespace std;

char A[1010101];
int tot;
int N, K;

int B[1010101];
int S[1010101];

int solve(int M) {
	for(int i = 1; i <= M; i++) S[i] = S[i - 1] + B[i];
	int m = 1;
	int ret = max(0, S[M] - 1);
	for(int i = 1; i <= M; i++) {
		ret = min(ret, (i - m + 1) - S[i] + 2 * S[m - 1] + (S[M] - S[i]));
		if(2 * S[m - 1] - m > 2 * S[i - 1] - i) m = i;
	}
	// for(int i = 1; i <= M; i++) printf("%d ", B[i]); puts("");
	// printf("ret %d\n", ret);
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &K);
		scanf("%s", A + 1);
		tot = 0;
		for(int i = 1; i <= N; i++) tot += A[i] - '0';

		int ans = 1010101010;
		for(int i = 1; i <= K; i++) {
			int cnt = 0;
			int b = 0;
			for(int j = i; j <= N; j += K) {
				b++;
				B[b] = A[j] - '0';
				cnt += B[b];
			}
			ans = min(ans, tot - cnt + solve(b));
		}
		printf("%d\n", ans);
	}
	return 0;
}