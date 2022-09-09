#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
int a[MAXN], p[MAXN];
int phi(int x) {
	int ans = x, tmp = x, i = 2;
	while (i * i <= tmp) {
		if (tmp % i == 0) {
			ans = ans / i * (i - 1);
			while (tmp % i == 0) tmp /= i;
		}
		i++;
	}
	if (tmp != 1) ans = ans / tmp * (tmp - 1);
	return ans;
}
int power(int x, int y, int P, bool &flg) {
	if (y == 0) {
		if (1 >= P) {flg = true; return 0; }
		else return 1;
	}
	int tmp = power(x, y / 2, P, flg);
	if (1ll * tmp * tmp >= P) flg = true;
	tmp = 1ll * tmp * tmp % P;
	if (y % 2 == 0) return tmp;
	else {
		if (1ll * tmp * x >= P) flg = true;
		return 1ll * tmp * x % P;
	}
}
int main() {
	read(n), read(p[tot = 1]);
	while (p[tot] != 1) {p[tot + 1] = phi(p[tot]); tot++; }
	for (int i = 1; i <= n; i++)
		read(a[i]);
	read(m);
	for (int i = 1; i <= m; i++) {
		int l, r;
		read(l), read(r);
		int len = r - l + 1;
		chkmin(len, tot);
		int ans = 1;
		while (len--) {
			bool flg = false;
			ans = power(a[l + len], ans, p[len + 1], flg);
			if (flg) ans += p[len + 1];
		}
		writeln(ans % p[1]);
	}
	return 0;
}