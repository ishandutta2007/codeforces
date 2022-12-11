#include <stdio.h>
int n, x, ans;
int main() {
	scanf("%d", &n);
	while (n--) scanf("%d", &x), ans = ans | x & 1;
	puts(ans ? "First" : "Second");
	return 0;
}