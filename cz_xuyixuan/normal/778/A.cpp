#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
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
int n, m, a[MAXN];
char s[MAXN], t[MAXN];
bool flg[MAXN];
bool check(int mid) {
	memset(flg, 0, sizeof(flg));
	for (int i = 1; i <= mid; i++)
		flg[a[i]] = true;
	int pos = 1;
	for (int i = 1; i <= m; i++) {
		while (pos <= n && !(!flg[pos] && s[pos] == t[i])) pos++;
		if (pos > n) return false; pos++;
	}
	return true;
}
int main() {
	scanf("\n%s\n%s", s + 1, t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	int l = 0, r = n - m;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	writeln(l);
	return 0;
}