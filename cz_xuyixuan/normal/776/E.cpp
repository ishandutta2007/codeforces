#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
long long phi(long long x) {
	long long ans = x;
	for (int i = 2; 1ll * i * i <= x; i++) {
		if (x % i == 0) {
			ans = ans / i * (i - 1);
			while (x % i == 0) x /= i;
		}
	}
	if (x != 1) ans = ans / x * (x - 1);
	return ans;
}
int main() {
	long long n, k;
	read(n), read(k);
	if (k % 2 == 1) k = (k + 1) / 2;
	else k /= 2;
	while (k--) {
		n = phi(n);
		if (n == 1) break;
	}
	writeln(n % P);
	return 0;
}