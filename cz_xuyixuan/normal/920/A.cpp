#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
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
int a[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		int n, k;
		read(n), read(k);
		for (int i = 1; i <= k; i++)
			read(a[i]);
		int ans = max(a[1], n + 1 - a[k]);
		for (int i = 1; i <= k - 1; i++) {
			int tmp = a[i + 1] - a[i];
			ans = max(ans, 1 + tmp / 2);
		}
		writeln(ans);
	}
	return 0;
}