#include <stdio.h>
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= M; j++) {
			if(i % 2 == 1 || (i%4 == 0 && j == 1) || (i%4 == 2 && j == M)) printf("#");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}