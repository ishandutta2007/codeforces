#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
const int N = 2000005;

int p[N], mu[N]; bool np[N];
vector<int> ft[N >> 1];
void sieve(int l) {
	mu[1] = 1; int tp = 0;
	for (int i = 2; i <= l; i++) {
		if (!np[i]) p[++tp] = i, mu[i] = -1;
		for (int j = 1; j <= tp && i * p[j] <= l; j++) {
			np[i * p[j]] = true;
			if (i % p[j] == 0) break;
			mu[i * p[j]] = -mu[i];
		}
	}
	for (int i = 1; i <= (l >> 1); i++)
		for (int j = i; j <= (l >> 1); j += i) ft[j].push_back(i);
}
ll calc(int n, int p) {
	ll ret = 0;
	for (auto it : ft[p]) ret += (ll)mu[it] * (n / it);
	return ret;
}

int main() {
	sieve(2e6);
	int T = read();
	while (T--) {
		int x = read(), p = read(), k = read();
		int pe = calc(x, p), pos = x;
		for (int i = 25; i >= 0; i--) {
			int tmp = pos + (1 << i);
			if (calc(tmp, p) - pe < k) pos = tmp;
		}
		printf("%d\n", pos + 1);
	}
	return 0;
}