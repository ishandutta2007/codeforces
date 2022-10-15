#include <stdio.h>

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		int a, b, c;

		scanf("%d%d%d", &a, &b, &c);
		printf(a + b == c || b + c == a || c + a == b ? "YES\n" : "NO\n");
	}
	return 0;
}