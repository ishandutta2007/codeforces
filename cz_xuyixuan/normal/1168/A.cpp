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
int n, m, a[MAXN];
bool valid(int mid) {
	int now = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = (now - a[i] + m) % m;
		if (tmp <= mid) now = now;
		else if (a[i] >= now) now = a[i];
		else return false;
	}
	return true;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	int l = 0, r = m;
	while (l < r) {
		int mid = (l + r) / 2;
		if (valid(mid)) r = mid;
		else l = mid + 1;
	}
	writeln(l);
	return 0;
}