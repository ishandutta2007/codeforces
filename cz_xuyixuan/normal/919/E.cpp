#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;
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
long long a, b, P, x;
long long inv[MAXN], val[MAXN];
int main() {
	read(a), read(b), read(P), read(x);
	inv[1] = 1;
	for (int i = 2; i <= P - 1; i++) {
		long long q = P / i, r = P % i;
		inv[i] = (P - q) * inv[r] % P;
	}
	val[0] = 1;
	for (int i = 1; i <= P - 1; i++)
		val[i] = val[i - 1] * a % P;
	for (int i = 1; i <= P - 1; i++)
		val[i] = b * inv[val[i]] % P;
	long long ans = 0;
	for (int i = 1; i <= P - 1; i++) {
		long long tmp = i + (P - 1) * ((i + P - val[i]) % P);
		if (tmp <= x) ans += 1 + (x - tmp) / (P * (P - 1));
	}
	writeln(ans);
	return 0;
}