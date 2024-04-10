#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int P = 1e9 + 9;
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
long long power(long long x, long long y) {
	if (y == 0) return 1;
	long long tmp = power(x, y / 2);
	if (y % 2 == 0) return tmp * tmp % P;
	else return tmp * tmp % P * x % P;
}
char s[MAXN];
long long n, a, b, k, first, r;
int main() {
	read(n), read(a), read(b), read(k);
	scanf("%s", s);
	for (int i = 0; i <= k - 1; i++) {
		if (s[i] == '+') first += power(a, n - i) * power(b, i) % P;
		if (s[i] == '-') first -= power(a, n - i) * power(b, i) % P;
	}
	first = (first % P + P) % P;
	r = power(b * power(a, P - 2) % P, k);
	n = (n + 1) / k;
	if (r == 1) writeln(first * n % P);
	else writeln((first * (power(r, n) - 1) % P) * power(r - 1, P - 2) % P);
	return 0;
}