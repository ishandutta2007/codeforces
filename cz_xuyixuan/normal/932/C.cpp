#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int ans[MAXN];
int main() {
	int n, a, b;
	read(n), read(a), read(b);
	for (int i = 0; i <= n; i += a) {
		if ((n - i) % b) continue;
		for (int j = 1; j <= i; j += a) {
			for (int k = j; k <= j + a - 2; k++)
				printf("%d ", k + 1);
			printf("%d ", j);
		}
		for (int j = i + 1; j <= n; j += b) {
			for (int k = j; k <= j + b - 2; k++)
				printf("%d ", k + 1);
			printf("%d ", j);
		}
		printf("\n");
		return 0;
	}
	printf("-1\n");
	return 0;
}