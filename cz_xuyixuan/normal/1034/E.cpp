#include<bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 21) + 5;
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
int n, Log, bits[MAXN];
char s[MAXN], t[MAXN];
ll a[MAXN], b[MAXN], c[MAXN], P;
void FWT(ll *a) {
	for (int bit = 1; bit <= Log; bit++)
	for (int i = 0; i < n; i += 1 << bit) {
		for (int j = i, k = i + (1 << (bit - 1)); k < i + (1 << bit); j++, k++) {
			a[k] += a[j];
			if (a[k] >= P) a[k] -= P;
		}
	}
}
void UFWT(ll *a) {
	for (int bit = 1; bit <= Log; bit++)
	for (int i = 0; i < n; i += 1 << bit) {
		for (int j = i, k = i + (1 << (bit - 1)); k < i + (1 << bit); j++, k++) {
			a[k] -= a[j];
			if (a[k] < 0) a[k] += P;
		}
	}
}
int main() {
	read(Log), n = 1 << Log;
	P = 1ll << (2 * Log + 2);
	scanf("\n%s", s);
	scanf("\n%s", t);
	for (int i = 0; i < n; i++) {
		if (i != 0) bits[i] = bits[i - (i & -i)] + 1;
		a[i] = (s[i] - '0' + 0ll) << (bits[i] * 2);
		b[i] = (t[i] - '0' + 0ll) << (bits[i] * 2);
	}
	FWT(a), FWT(b);
	for (int i = 0; i < n; i++) {
		ll tmp = (ld) a[i] * b[i] / P;
		c[i] = ((a[i] * b[i] - tmp * P) % P + P) % P;
	}
	UFWT(c);
	for (int i = 0; i < n; i++) {
		c[i] >>= (bits[i] * 2);
		putchar((c[i] & 3) + '0');
	}
	return 0;
}