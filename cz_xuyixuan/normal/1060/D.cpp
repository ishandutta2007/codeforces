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
int a[MAXN], b[MAXN];
int main() {
	int n; read(n);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		read(a[i]), read(b[i]);
		ans += 1 + a[i] + b[i];
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++)
		ans -= min(a[i], b[i]);
	writeln(ans);
	return 0;
}