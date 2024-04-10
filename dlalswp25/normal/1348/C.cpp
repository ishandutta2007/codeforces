#include <bits/stdc++.h>

using namespace std;

char A[101010];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N, K; scanf("%d%d", &N, &K);

		scanf("%s", A + 1);
		sort(A + 1, A + N + 1);

		if(A[1] != A[K]) {
			printf("%c\n", A[K]);
			continue;
		}

		if(A[K + 1] == A[N]) {
			printf("%c", A[1]);
			for(int i = 1; i <= ((N - K) - 1) / K + 1; i++) {
				printf("%c", A[K + 1]);
			}
			puts("");
			continue;
		}

		printf("%c", A[1]);
		for(int i = K + 1; i <= N; i++) printf("%c", A[i]); puts("");
	}
	return 0;
}