#include <cstdio>
using namespace std;
typedef long long ll;
const int P = 1e9 + 7;
const int N = 2e6 + 10;
int n, k, pc;
int pw[N], mu[N], p[N], b[N * 2];
bool vis[N];
void sieve();
int pow(int x, int k);
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; ++i)
		pw[i] = pow(i, n);
	sieve();
	for (int x = 1; x <= k; ++x) {
		for (int i = 1; i * x <= k; ++i) {
			b[i * x] = (b[i * x] + (ll)pw[i] * (P + mu[x]) % P) % P;
			b[i * x] = (b[i * x] - (ll)pw[i - 1] * (P + mu[x] % P)) % P;
			if (b[i * x] < 0)
				b[i * x] += P;
		}
	}
	int ans = 0;
	for (int i = 1; i <= k; ++i) {
		b[i] = (b[i] + b[i - 1]) % P;
		ans = (ans + (b[i] ^ i) % P) % P;
	}
	printf("%d\n", ans);
	return 0;
}
void sieve() {
	mu[1] = 1;
	for (int x = 2; x <= k; ++x) {
		if (!vis[x]) {
			p[++pc] = x;
			mu[x] = -1;
		}
		for (int j = 1; x * p[j] <= k; ++j)
			if (x % p[j] == 0) {
				mu[x * p[j]] = 0;
				vis[x * p[j]] = true;
				break;
			} else {
				mu[x * p[j]] = -mu[x];
				vis[x * p[j]] = true;
			}
	}
}
int pow(int x, int k) {
	int ret = 1;
	while (k) {
		if (k & 1)
			ret = (ll)ret * x % P;
		x = (ll)x * x % P;
		k >>= 1;
	}
	return ret;
}