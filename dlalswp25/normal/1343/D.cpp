#include <bits/stdc++.h>

using namespace std;

int A[202020];
int D[404040];
int N, K;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N, K; scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		for(int i = 1; i <= N / 2; i++) {
			int a = A[i], b = A[N - i + 1];
			if(a > b) swap(a, b);
			D[1]++;
			D[a + b]--;
			D[a + b + 1]++;

			D[K + b + 1]++;
			D[1]++;
			D[a + 1]--;

			// for(int j = 1; j <= 2 * K; j++) printf("%d ", D[j]); puts("");
		}

		int ans = 1010101010;
		for(int i = 2; i <= 2 * K; i++) {
			D[i] += D[i - 1];
			ans = min(ans, D[i]);
		}
		// for(int i = 1; i <= 2 * K + 1; i++) printf("%d ", D[i]); puts("");
		printf("%d\n", ans);


		for(int i = 1; i <= 2 * K + 1; i++) D[i] = 0;
	}
	return 0;
}