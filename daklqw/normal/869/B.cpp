#include <stdio.h>
#define Love long long
#define Live int
Love Live a, b, pi = 1;
Live main() {
	scanf("%I64d%I64d", &a, &b);
	if (b - a >= 9) puts("0");
	else {
		for (Love Live i = a + 1; i <= b; i++)
			pi = pi * (i % 10) % 10;
		printf("%I64d\n", pi);
	}
	return 0;
	
}