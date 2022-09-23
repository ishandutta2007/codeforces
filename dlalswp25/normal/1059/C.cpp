#include <stdio.h>

int main() {
	int N; scanf("%d", &N);
	int X = 1;
	while(1) {
		if(N == 1) { printf("%d\n", X); break; }
		if(N == 2) { printf("%d %d\n", X, X * 2); break; }
		if(N == 3) { printf("%d %d %d\n", X, X, X * 3); break; }
		for(int i = 0; i < (N + 1) / 2; i++) printf("%d ", X);
		X <<= 1; N >>= 1;
	}
	return 0;
}