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
map <int, int> mp;
int main() {
	ll ans = 0;
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		int x, y; read(x), read(y);
		ans += y; mp[x] = y;
	}
	int m; read(m);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		ans += y; ans -= min(mp[x], y);
	}
	writeln(ans);
	return 0;
}