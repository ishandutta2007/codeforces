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
int n, a[MAXN];
char s[MAXN];
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	scanf("\n%s", s + 1);
	int l = -1e9, r = 1e9;
	for (int i = 5; i <= n; i++) {
		if (s[i] == s[i - 1]) continue;
		if (s[i] == '1') {
			for (int j = 0; j <= 4; j++)
				l = max(l, a[i - j] + 1);
		} else {
			for (int j = 0; j <= 4; j++)
				r = min(r, a[i - j] - 1);
		}
	}
	printf("%d %d\n", l, r);
	return 0;
}