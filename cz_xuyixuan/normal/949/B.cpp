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
long long func(long long n, long long x) {
	if (x % 2 == 1) return (x + 1) / 2;
	else if (n % 2 == 0) return func(n / 2, x / 2) + n / 2;
	else {
		int tn = n / 2;
		int tx = x / 2 - 1;
		if (tx == 0) tx = tn;
		return func(tn, tx) + (n + 1) / 2;
	}
}
int main() {
	long long m;
	read(m);
	int q; read(q);
	while (q--) {
		long long x, ans = 0, n = m;
		read(x);
		while (true) {
			if (x % 2 == 1) {ans += (x + 1) / 2; break; }
			else if (n % 2 == 0) ans += n / 2, n /= 2, x /= 2;
			else {
				long long tn = n / 2;
				long long tx = x / 2 - 1;
				if (tx == 0) tx = tn;
				ans += (n + 1) / 2, n = tn, x = tx;
			}
		}
		writeln(ans);
	}
	return 0;
}