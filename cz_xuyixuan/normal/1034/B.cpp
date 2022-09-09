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
int main() {
	ll n, m; read(n), read(m);
	if (n > m) swap(n, m);
	if (n == 1) {
		ll ans = m / 6 * 6;
		ll tmp = m % 6;
		ans += max(0ll, tmp - 3) * 2;
		writeln(ans);
	} else if (n == 2) {
		ll ans = n * m;
		if (m == 2) ans -= 4;
		if (m == 3) ans -= 2;
		if (m == 7) ans -= 2;
		writeln(ans);
	} else writeln(n * m - n * m % 2);
	return 0;
}