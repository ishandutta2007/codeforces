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
int n, m, tot;
string ans[MAXN], a[MAXN], b[MAXN];
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	int x = 0, y = 0;
	for (int i = 1; i <= n * m; i++) {
		x++, y++;
		if (x > n) x -= n;
		if (y > m) y -= m;
		ans[i] = a[x] + b[y];
	}
	int q; read(q);
	while (q--) {
		int x; read(x);
		x %= n * m;
		if (x == 0) x = n * m;
		cout << ans[x] << endl;
	}
	return 0;
}