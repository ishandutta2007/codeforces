#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
int a[MAXN];
int main() {
	int n; read(n);
	int x, y; read(x), read(y);
	int m = x + y;
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		a[i] = abs(a[i] - x);
	}
	while (m--) {
		int pos = 1;
		for (int i = 1; i <= n; i++)
			if (a[i] > a[pos]) pos = i;
		a[pos] = abs(a[pos] - 1);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += 1ll * a[i] * a[i];
	writeln(ans);
	return 0;
}