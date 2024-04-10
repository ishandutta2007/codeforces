#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int P = 1e9 + 7;
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
int a[MAXN], f[MAXN];
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
int main() {
	int n; read(n);
	int sum = 0, Max = 0;
	for (int i = 1; i <= n; i++)
		read(a[i]), sum += a[i], chkmax(Max, a[i]);
	f[1] = (sum - 1ll) * (sum - 1ll) % P * power(sum, P - 2) % P;
	for (int i = 1; i < Max; i++)
		f[i + 1] = (2ll * f[i] - f[i - 1] - (sum - 1ll) * power(sum - i, P - 2) % P + 2 * P) % P;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + f[a[i]]) % P;
	writeln(ans);
	return 0;
}