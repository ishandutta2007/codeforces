#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
int main() {
	int n, a, b, ans = 0;
	read(n), read(a), read(b);
	while (a != b) {
		ans++;
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		n /= 2;
	}
	if (n == 1) printf("Final!\n");
	else printf("%d\n", ans);
	return 0;
}