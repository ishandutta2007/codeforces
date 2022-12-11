#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXS 310
int pri[MAXS], mu[MAXS], tot;
bool npri[MAXS];
void sieve() {
	mu[1] = 1;
	for (int i = 2; i != MAXS; ++i) {
		if (!npri[i]) mu[pri[++tot] = i] = -1;
		for (int j = 1; j <= tot; ++j) {
			int t = i * pri[j];
			if (t >= MAXS) break;
			npri[t] = true;
			if (i % pri[j] == 0) { mu[t] = 0; break; }
			mu[t] = -mu[i];
		}
	}
}
long long n; int T;
unsigned long long fastpow(unsigned long long a, unsigned long long b) {
	unsigned long long res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}
long long sqrtx(long long x) {
	long long b, res, vb = 0x3f3f3f3f3f3f3f3fLLU;
	unsigned long long tv;
	b = pow((double)n, 1. / x);
	for (long long i = b - 5; i <= b + 5; ++i) {
		if (i <= 0) continue;
		tv = fastpow(i, x);
		if (tv > n) break;
		if (n - tv < vb) vb = n - tv, res = i;
	}
	return res;
}
int main() {
	sieve();
	scanf("%d", &T);
	while (T --> 0) {
		scanf("%lld", &n);
		long long cnt = 0, t;
		for (int i = 2; i <= 300; ++i) {
			t = sqrtx(i) - 1; 
			// cout << n << " " << i << " " << t + 1 << endl;
			if (t == 0) break;
			cnt += t * mu[i];
		}
		printf("%lld\n", n - 1 + cnt);
	}
	return 0;
}