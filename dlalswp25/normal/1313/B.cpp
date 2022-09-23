#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n, a, b; scanf("%d%d%d", &n, &a, &b);
		if(a > b) swap(a, b);

		if(a + b < n + 1) {
			printf("1 %d\n", a + b - 1);
		}
		else if(a + b < 2 * n) {
			printf("%d %d\n", (a + b - n) + 1, n);
		}
		else printf("%d %d\n", n, n);
	}
	return 0;
}