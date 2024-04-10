#include <cstdio>
int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main(){
	int i, j, he = 0, n;
	scanf("%d", &n);
	for (j = 2; j < n; j++) {
		int k = n;
		for (i = 0; k > 0; i++) {
			he += k % j;
			k /= j;
		}
	}
	printf("%d/%d\n", he / gcd(he, n - 2), (n - 2) / gcd(he, n - 2));
	return 0;
}