#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n, k;
	scanf("%d%d", &n, &k);
	if (n < 4) {
		puts("-1");
	} else if (n == 4) {
		if (k == 3) {
			puts("3");
			puts("1 2");
			puts("2 3");
			puts("3 4");
		} else {
			puts("-1");
		}
	} else {
		if (k == 2) {
			printf("%d\n", n - 1);
			for (int i = 1; i < n; i++) {
				printf("%d %d\n", i, i + 1);
			}
		} else if (k == 3) {
			printf("%d\n", 2 * n - 5);
			puts("1 2");
			puts("2 3");
			puts("3 4");
			for (int i = 5; i <= n; i++) printf("2 %d\n3 %d\n", i, i);
		} else puts("-1");
	}
	
	return 0;
}