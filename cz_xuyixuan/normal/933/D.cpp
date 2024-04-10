#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int P = 1e9 + 7;
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
long long power(long long x, long long y) {
	if (y == 0) return 1;
	long long tmp = power(x, y / 2);
	if (y % 2 == 0) return tmp * tmp % P;
	else return tmp * tmp % P * x % P;
}
long long inv(long long x) {
	static long long mem[MAXN];
	if (mem[x] != 0) return mem[x];
	else return mem[x] = power(x, P - 2);
}
long long sum(long long lim, int k) {
	if (k == 0) return 2 * lim + 1;
	else if (k == 2) return 2 * lim * (lim + 1) % P * (2 * lim + 1) % P * inv(6) % P;
	else if (k == 4) return 2 * lim * (lim + 1) % P * (2 * lim + 1) % P * (3 * power(lim, 2) + 3 * lim - 1) % P * inv(30) % P;
	else return 2 * lim * (lim + 1) % P * (2 * lim + 1) % P * (3 * power(lim, 4) + 6 * power(lim, 3) - 3 * lim + 1) % P * inv(42) % P;
}
int main() {
	long long ans = 0;
	long long M, m, n;
	read(M); n = sqrt(M); m = M % P;
	for (long long x = -n; x <= n; x++) {
		long long y = sqrt(M - x * x);
		ans += (2) * sum(y, 6) % P;
		ans += (6 * power(x, 2) % P - (3 * m + 6) % P) % P * sum(y, 4) % P;
		ans += (6 * power(x, 4) % P - (6 * m + 12) % P * power(x, 2) + (3 * m + 4)) % P * sum(y, 2) % P;
		ans += (2 * power(x, 6) % P - (3 * m + 6) % P * power(x, 4) % P + (3 * m + 4) % P * power(x, 2) % P + m * (m + 1) % P * (m + 2) % P) % P * sum(y, 0) % P;
		ans %= P;
	}
	ans = (ans + P) % P;
	ans = ans * inv(6) % P;
	writeln(ans);
	return 0;
}