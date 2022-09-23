#include <stdio.h>

int main() {
	long long N; scanf("%lld", &N);
	N++;
	if(N == 1) printf("0");
	else if(N % 2 == 0) printf("%lld", N / 2);
	else printf("%lld", N);
	return 0;
}