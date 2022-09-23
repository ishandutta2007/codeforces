#include <stdio.h>



int main() {
	int n, m; scanf("%d %d", &n, &m);
	if(n >= 30) {
		printf("%d", m); return 0;
	}
	int x = 1; for(int i = 1; i <= n; i++) x <<= 1;
	printf("%d", m % x);
	return 0;
}