#include <stdio.h>
int main() {
	int N, i;
	scanf("%d", &N);
	if(N <= 2) printf("1\n1");
	else if(N == 3) printf("2\n1 3");
	else if(N == 4) printf("4\n3 1 4 2");
	else {
		printf("%d\n", N);
		for(i = 1; i <= N; i++) {
			if(i%2 == 1) printf("%d ", (i+1)/2);
			else printf("%d ", (N+1)/2+i/2);
		}
	}
	return 0;
}