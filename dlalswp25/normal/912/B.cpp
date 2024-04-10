#include <stdio.h>

int main() {
	long long n, k; scanf("%lld%lld", &n, &k);
	if(k == 1) printf("%lld", n);
	else {
		long long base = 1;
		while(base <= n) base <<= 1;
		printf("%lld", base - 1);
	}
	return 0;
}