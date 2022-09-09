#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXLOG = 62;
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
long long x, d, now;
int n; long long ans[MAXN], cnt[MAXN];
void pushin(int x) {
	now += 1;
	while (x--) ans[++n] = now;
	now += d;
}
int main() {
	read(x), read(d);
	for (int i = 1; i < MAXLOG; i++)
		cnt[i] = (1ll << i) - 1;
	for (int i = MAXLOG - 1; i >= 1; i--) {
		while (x >= cnt[i]) {
			x -= cnt[i];
			pushin(i);
		}
	}
	writeln(n);
	for (int i = 1; i <= n; i++)
		printf("%lld ", ans[i]);
	return 0;
}