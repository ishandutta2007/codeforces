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
bool a[2][MAXN];
int main() {
	int n, m; read(n), read(m);
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y), x--;
		if (a[x][y]) {
			a[x][y] = false;
			for (int j = -1; j <= 1; j++)
				ans -= a[x ^ 1][y + j];
		} else {
			a[x][y] = true;
			for (int j = -1; j <= 1; j++)
				ans += a[x ^ 1][y + j];
		}
		if (ans) puts("No");
		else puts("Yes");
	}
	return 0;
}