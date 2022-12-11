#include <stdio.h>
#include <stdlib.h>
int n, x;
int main() {
	scanf("%d%d", &n, &x);
	if (n == 2 && x == 0) printf("NO\n");
	else {
		switch (n & 3) {
			case 0:
				printf("YES\n");
				if (x == 1) printf("0 3 4 6 ");
				else if (x == 2) printf("0 3 4 5 ");
				else if (x == 3) printf("0 1 4 6 ");
				else printf("0 1 2 %d ", x ^ 3);
				n -= 4;
				break;
			case 1:
				printf("YES\n%d ", x);
				break;
			case 2:
				if (x == 0) {
					printf("YES\n2 3 5 8 16 28 ");
					n -= 6;
				}
				else printf("YES\n0 %d ", x);
				break;
			case 3:
				printf("YES\n");
				if (x == 0) printf("1 2 3 ");
				else if (x == 1) printf("0 2 3 ");
				else printf("0 1 %d ", x ^ 1);
				break;
		}
		for (int i = 100004, cnt = 4; cnt <= n; cnt += 4, i += 4)
			printf("%d %d %d %d ",i, i + 1, i + 2, i + 3);
	}
	return 0;
}