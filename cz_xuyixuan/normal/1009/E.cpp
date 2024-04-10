#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
const int P = 998244353;
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
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
int bit[MAXN];
int main() {
	int n; read(n);
	bit[0] = 1;
	for (int i = 1; i <= n; i++)
		bit[i] = bit[i - 1] * 2 % P;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		ans = (ans + 1ll * x * bit[n - i]) % P;
		if (i != n) ans = (ans + 1ll * x * bit[n - i - 1] % P * (n - i)) % P;
	}
	writeln(ans);
	return 0;
}