#include <bits/stdc++.h>
using namespace std;

char a[100005];
int q, n;

int main() {
	scanf("%d", &q);
	while (q--) {
		scanf("%d\n", &n);
		for (int i = 1; i <= n; i++) scanf("%c", &a[i]);
		if (n == 2 && a[1] >= a[2]) {
			puts("NO"); continue;
		}
		puts("YES\n2");
		putchar(a[1]), putchar(' ');
		for (int i = 2; i <= n; i++)
			putchar(a[i]);
		putchar('\n');
	}
	return 0;
}