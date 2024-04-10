#include <stdio.h>
int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);
	for(i = 1; N != 0; i++) {
		if(i % M != 0) N--;
	}
	printf("%d", i-1);
	return 0;
}