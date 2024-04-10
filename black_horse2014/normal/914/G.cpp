#include <bits/stdc++.h>
using namespace std;

const int N = 1<<17;
const int MOD = 1e9 + 7;

int b[N], c[N], d[N], f[N], a[N], s[N];

template<typename T>
void Trans(T *b, int n, T m) {
	for (int j = 0, k = 1; k < n; k <<= 1, j++) {
		for (int i = 0; i < n; i++) {
			if (~i>>j & 1) {
				T x = (b[i] + b[i+k]) % m, y = (b[i] - b[i+k] + m) % m;
				b[i] = x, b[i+k] = y;
			}
		}
	}
}

template<typename T>
void Untrans(T *b, int n, T m) {
	for (int j = __builtin_ctz(n)-1, k = n/2; j >= 0; k /= 2, j--) {
		for (int i = 0; i < n; i++) {
			if (~i>>j & 1) {
				T x = (b[i] + b[i+k]) % m, y = (b[i] - b[i+k] + m) % m;
				if (x & 1) x += m; if (y & 1) y += m;
				b[i] = x>>1, b[i+k] = y>>1;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		a[x]++;
	}
	for (int i = 0; i < 1<<17; i++) {
		if (i < 2) f[i] = i;
		else f[i] = (f[i-1] + f[i-2]) % MOD;
	}
	for (int i = 0; i < 1<<17; i++) {
		for (int j = i; j >= 0; j = i & (j - 1)) {
			b[i] = (b[i] + 1LL * a[j] * a[i - j]) % MOD;
			if (j == 0) break;
		}
		b[i] = 1LL * f[i] * b[i] % MOD;
	}
	for (int i = 0; i < 1<<17; i++) d[i] = a[i];
	Trans(d, 1<<17, MOD);
	for (int i = 0; i < 1<<17; i++) d[i] = 1LL * d[i] * d[i] % MOD;
	Untrans(d, 1<<17, MOD);
	for (int i = 0; i < 1<<17; i++) d[i] = 1LL * f[i] * d[i] % MOD;
	for (int i = 0; i < 1<<17; i++) c[i] = 1LL * f[i] * a[i] % MOD;
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 1<<17; j++) if (~j >> i & 1) {
			int k = j ^ (1<<i);
			b[j] = (b[j] + b[k]) % MOD;
			c[j] = (c[j] + c[k]) % MOD;
			d[j] = (d[j] + d[k]) % MOD;
		}
	}
	for (int j = 0; j < 1<<17; j++) s[j] = 1LL * b[j] * c[j] % MOD * d[j] % MOD;
	for (int j = 0; j < 1<<17; j++) s[j] = ((__builtin_popcount(j) & 1) ? MOD - s[j] : s[j]);
	for (int j = 0; j < 1<<17; j++) s[j] %= MOD;
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 1<<17; j++) if (~j >> i & 1) {
			int k = j ^ (1<<i);
			s[j] = (s[j] + s[k]) % MOD;
		}
	}
	for (int j = 0; j < 1<<17; j++) if (__builtin_popcount(j) & 1) s[j] = (MOD - s[j]) % MOD;
	int ans = 0;
	for (int j = 0; j < 17; j++) ans = (ans + s[1<<j]) % MOD;
	cout << ans << endl;
	return 0;
}