#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
int n;
ll a[MAXN], mask[MAXN], s;
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]), read(mask[i]);
		s += a[i];
	}
	if (s < 0) {
		for (int i = 1; i <= n; i++)
			a[i] = -a[i];
	}
	ll ans = 0;
	for (int p = 0; p <= 61; p++) {
		ll bit = 1ll << p, cur = 0;
		for (int i = 1; i <= n; i++)
			if ((mask[i] & bit) && (mask[i] < (2 * bit))) cur += a[i];
		if (cur > 0) {
			ans ^= bit;
			for (int i = 1; i <= n; i++)
				if (mask[i] & bit) a[i] = -a[i];
		}
	}
	writeln(ans);
	return 0;
}