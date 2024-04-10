#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 7e3 + 5;
typedef long long ll;
typedef bitset <MAXM> info;
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
info a[MAXN], b[MAXM], getans[MAXM];
int tot, prime[MAXM], f[MAXM], miu[MAXM];
void init(int n) {
	miu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (f[i] == 0) {
			prime[++tot] = f[i] = i;
			miu[i] = -1;
		}
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp > n) break;
			f[tmp] = prime[j];
			if (prime[j] == f[i]) miu[tmp] = 0;
			else miu[tmp] = -miu[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			b[j][i] = 1;
			if (miu[j / i]) getans[i][j] = 1;
		}
	}
}
int main() {
	init(7000);
	int n, m;
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int opt, x, y, z;
		read(opt), read(x), read(y);
		if (opt == 1) a[x] = b[y];
		if (opt == 2) {
			read(z);
			a[x] = a[y] ^ a[z];
		}
		if (opt == 3) {
			read(z);
			a[x] = a[y] & a[z];
		}
		if (opt == 4) putchar('0' + (a[x] & getans[y]).count() % 2);
	}
	return 0;
}