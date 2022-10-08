#include <stdio.h>
long long gcd(long long a, long long b) {
	if(a>b) return gcd(b,a);
	if(b%a==0) return b/a;
	else return b/a+gcd(b%a, a);
}
int main() {
	long long x, y;
	scanf("%I64d %I64d", &x, &y);
	printf("%I64d", gcd(x, y));
	return 0;
}