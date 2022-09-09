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
int n, len;
int a[MAXN], b[MAXN];
int calc(int pos) {
	int ans = 0;
	if (pos < 1) pos += n, ans -= len;
	if (pos > n) pos -= n, ans += len;
	ans += b[pos];
	return ans;
}
bool check(int mid) {
	int ql = -n, qr = n;
	for (int i = 1; i <= n; i++) {
		while (qr >= ql && abs(a[i] - calc(i + ql)) > mid) ql++;
		while (qr >= ql && abs(a[i] - calc(i + qr)) > mid) qr--;
		if (qr < ql) return false;
	}
	return true;
}
int main() {
	read(n), read(len);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		read(b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	int l = 0, r = len;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	writeln(l);
	return 0;
}