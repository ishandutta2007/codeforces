#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		if(N > M) { puts("No"); continue; }
		if(N % 2 == 0 && M % 2) { puts("No"); continue; }
		puts("Yes");
		if(N % 2) {
			for(int i = 1; i < N; i++) printf("1 ");
			printf("%d\n", M - (N - 1));
		}
		else {
			for(int i = 1; i < N - 1; i++) printf("1 ");
			printf("%d %d\n", (M - (N - 2)) / 2, (M - (N - 2)) / 2);
		}
	}
	return 0;
}