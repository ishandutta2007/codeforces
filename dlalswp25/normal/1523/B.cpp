#include <bits/stdc++.h>

using namespace std;

int N;
int A[1010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		printf("%d\n", N * 3);
		for(int i = 1; i <= N / 2; i++) {
			int a = 2 * i - 1, b = 2 * i;
			printf("1 %d %d\n", a, b);
			printf("2 %d %d\n", a, b);
			printf("1 %d %d\n", a, b);
			printf("2 %d %d\n", a, b);
			printf("1 %d %d\n", a, b);
			printf("2 %d %d\n", a, b);
		}	
	}
	return 0;
}