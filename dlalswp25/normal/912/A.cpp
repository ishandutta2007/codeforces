#include <stdio.h>

long long a, b, x, y, z;

int main() {
	scanf("%lld%lld%lld%lld%lld", &a, &b, &x, &y, &z);
	long long A = (a < 2 * x + y ? 2 * x + y - a : 0);
	long long B = (b < y + 3 * z ? y + 3 * z - b : 0);
	printf("%lld", A + B);
	return 0;
}