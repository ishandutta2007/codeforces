#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
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
int tot, prime[MAXN], f[MAXN];
int cnt[MAXN];
int main() {
	for (int i = 2; i < MAXN; i++) {
		if (f[i] == 0) prime[++tot] = f[i] = i;
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = i * prime[j];
			if (tmp >= MAXN) break;
			f[tmp] = prime[j];
		}
	}
	int x, y; read(x);
	for (int i = 1; i <= tot; i++)
		if (x % prime[i] == 0 && x != prime[i]) y = x - prime[i] + 1;
	int ans = x;
	for (int i = 1; i <= tot; i++)
	for (int j = 2 * prime[i]; j <= x; j += prime[i]) {
		if (j < y) continue;
		chkmin(ans, j - prime[i] + 1);
	}
	writeln(ans);
	return 0;
}