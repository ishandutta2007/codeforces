#include <stdio.h>
int main() {
	int N1, N2, K1, K2;
	scanf("%d %d %d %d", &N1, &N2, &K1, &K2);
	if(N1 <= N2) printf("Second");
	else printf("First");
	return 0;
}