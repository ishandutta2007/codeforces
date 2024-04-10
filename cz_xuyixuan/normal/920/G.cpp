#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
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
int tot, prime[MAXN], miu[MAXN], f[MAXN];
int x, p, k, n, d[MAXN];
void init() {
	miu[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		if (f[i] == 0) {
			prime[++tot] = f[i] = i;
			miu[i] = -1;
		}
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp >= MAXN) break;
			f[tmp] = prime[j];
			if (prime[j] == f[i]) miu[tmp] = 0;
			else miu[tmp] = -miu[i];
		}
	}
}
long long calc(long long x) {
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += miu[d[i]] * (x / d[i]);
	return ans;
}
int main() {
	init();
	int T; read(T);
	while (T--) {
		read(x), read(p), read(k); n = 0;
		for (int i = 1; i <= sqrt(p); i++)
			if (p % i == 0) {
				d[++n] = i;
				if (i * i != p) d[++n] = p / i;
			}
		k += calc(x);
		long long l = 1, r = 1e18;
		while (l < r) {
			long long mid = (l + r) / 2;
			if (calc(mid) >= k) r = mid;
			else l = mid + 1;
		}
		writeln(l);
	}
	return 0;
}