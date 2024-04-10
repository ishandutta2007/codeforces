#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
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
int a[MAXN], s, n;
int main() {
	read(n), read(s);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	sort(a + 1, a + n + 1);
	int m = (n + 1) / 2;
	long long ans = 0;
	if (a[m] >= s) {
		for (int i = m; i >= 1; i--)
			if (a[i] >= s) ans += a[i] - s;
	} else {
		for (int i = m; i <= n; i++)
			if (a[i] <= s) ans += s - a[i];
	}
	writeln(ans);
	return 0;
}