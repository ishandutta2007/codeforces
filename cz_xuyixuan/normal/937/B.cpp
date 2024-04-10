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
	int n, m;
	read(n), read(m);
	for (int i = m; i >= n + 1; i--) {
		bool flg = true;
		for (int j = 2; j <= n && j * j <= i; j++)
			if (i % j == 0) {
				flg = false;
				break;
			}
		if (flg) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}