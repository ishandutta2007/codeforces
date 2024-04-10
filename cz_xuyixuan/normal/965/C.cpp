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
long long n, k, m, d;
int main() {
	read(n), read(k), read(m), read(d);
	long long tot = k * m, tmp = n / tot;
	long long ans = m * tmp;
	if (n % tot >= m) ans += m;
	for (int i = 1; i <= d; i++) {
		long long cnt = 1 + k * (i - 1);
		if (n / cnt > m) continue;
		else if (n / cnt == 0) break;
		long long x = n / cnt;
		chkmax(ans, x * i);
	}
	writeln(ans);
	return 0;
}