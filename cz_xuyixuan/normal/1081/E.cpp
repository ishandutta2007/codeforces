#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
int n, a[MAXN];
int main() {
	read(n), n /= 2;
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		for (int j = 1; j * j <= x; j++)
			if (x % j == 0) {
				int k = x / j;
				if ((j + k) & 1) continue;
				if ((k - j) / 2 > a[i * 2 - 2]) {
					a[i * 2 - 1] = (k - j) / 2;
					a[i * 2] = (k + j) / 2;
				}
			}
	}
	for (int i = 1; i <= 2 * n; i++)
		if (a[i] <= a[i - 1]) {
			puts("No");
			return 0;
		}
	puts("Yes");
	for (int i = 1; i <= 2 * n; i++)
		printf("%I64d ", 1ll * a[i] * a[i] - 1ll * a[i - 1] * a[i - 1]); 
	return 0;
}