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
int n; ll a[MAXN];
char s[MAXN];
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	scanf("%s", s + 1);
	ll pre = 0; int pos = 1;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'W' && s[pos] == 'G') pos = i;
		if (s[i] == 'L') pre -= a[i];
		else pre += a[i];
		if (pre <= 0) a[pos] -= pre, pre = 0;
	}
	ll ans = 0, w = 0;
	for (int i = 1; i <= n; i++) {
		ll tmp = a[i];
		if (s[i] == 'W') w += tmp, ans += 2 * tmp;
		else {
			ll tnp = min(tmp, w);
			w -= tnp, ans += 2 * tnp + 3 * (tmp - tnp); 
		}
	}
	writeln(ans);
	return 0;
}