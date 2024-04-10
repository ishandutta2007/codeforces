#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N, K; scanf("%d%d", &N, &K);
		if(N < K) { puts("NO"); continue; }
		if(K & 1) {
			if(N & 1) {
				puts("YES");
				for(int i = 1; i <= K - 1; i++) printf("1 ");
				printf("%d\n", N - (K - 1));
			}
			else {
				if(N < K * 2) { puts("NO"); continue; }
				else {
					puts("YES");
					for(int i = 1; i <= K - 1; i++) printf("2 ");
					printf("%d\n", N - 2 * (K - 1));
				}
			}
		}
		else {
			if(N & 1) { puts("NO"); continue; }
			else {
				puts("YES");
				for(int i = 1; i <= K - 1; i++) printf("1 ");
				printf("%d\n", N - (K - 1));
			}
		}
	}
	return 0;
}