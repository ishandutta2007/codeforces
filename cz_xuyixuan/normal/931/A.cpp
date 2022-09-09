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
	int n, m, x;
	read(n), read(m);
	x = abs(n - m);
	int ans = 0;
	for (int i = 1; x != 0; i++) {
		if (x >= 2) ans += i * 2, x -= 2;
		else ans += i, x -= 1;
	}
	writeln(ans);
	return 0;
}