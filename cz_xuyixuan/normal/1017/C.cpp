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
	int ans = 1e9, x = 0;
	for (int i = 1; i <= n; i++) {
		int y = n / i + (n % i != 0);
		if (i + y < ans) {
			ans = i + y;
			x = i;
		}
		a[i] = i;
	}
	for (int i = 1; i <= n; i += x) {
		int j = min(i + x - 1, n);
		reverse(a + i, a + j + 1);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}