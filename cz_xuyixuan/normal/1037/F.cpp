#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
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
bool vis[MAXN];
int n, k, a[MAXN], f[MAXN], home[MAXN], l[MAXN], r[MAXN];
bool cmp(int x, int y) {
	return a[x] < a[y];
}
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
void merge(int x, int y) {
	x = F(x), y = F(y);
	if (x == y) return;
	f[x] = y;
	chkmax(r[y], r[x]);
	chkmin(l[y], l[x]);
}
int calc(int len) {
	int lim = len / (k - 1);
	int cnt = 1ll * len * lim % P;
	cnt -= lim * (lim + 1ll) / 2 % P * (k - 1) % P;
	cnt = (cnt + P) % P;
	return cnt;
}
int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++) {
		read(a[i]), home[i] = i;
		f[i] = i; l[i] = r[i] = i;
	}
	sort(home + 1, home + n + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = home[i];
		vis[tmp] = true;
		if (vis[tmp - 1]) merge(tmp, tmp - 1);
		if (vis[tmp + 1]) merge(tmp, tmp + 1);
		int tnp = F(tmp), cnt = calc(r[tnp] - l[tnp] + 1);
		cnt = (cnt - calc(tmp - l[tnp]) + P) % P;
		cnt = (cnt - calc(r[tnp] - tmp) + P) % P;
		ans = (ans + 1ll * cnt * a[tmp]) % P;
	}
	writeln(ans);
	return 0;
}