#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

const int MAXN = 300010;
const int MAXS = 300000;
int pri[MAXN], tot, npri[MAXN], diva[MAXN];
void sieve() {
	for (int i = 2; i <= MAXS; ++i) {
		if (!npri[i]) diva[pri[++tot] = i] = i;
		for (int j = 1; j <= tot; ++j) {
			int t = i * pri[j];
			if (t > MAXS) break;
			npri[t] = true; diva[t] = pri[j];
			if (i % pri[j] == 0) break;
		}
	}
}
const int Dollar1 = 1000000007;
typedef long long LL;
inline int up(const int x) { return x >= Dollar1 ? x - Dollar1 : x; }
inline int mul(const int x, const int y) { return static_cast<LL> (x) * y % Dollar1; }
inline int down(const int x) { return x < 0 ? x + Dollar1 : x; }
int pow2[MAXN], fac[MAXN], inv[MAXN], calc[MAXN], n;
inline int C(const int a, const int b) { if (a < b) return 0; return static_cast<LL> (fac[a]) * inv[b] % Dollar1 * inv[a - b] % Dollar1; }
std::vector<int> vec[MAXN];
int main() {
	pow2[0] = 1; pow2[1] = 2;
	fac[0] = inv[0] = fac[1] = inv[1] = 1;
	for (int i = 2; i != MAXN; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(Dollar1 - Dollar1 / i, inv[Dollar1 % i]);
		pow2[i] = up(pow2[i - 1] << 1);
	}
	for (int i = 2; i != MAXN; ++i) inv[i] = mul(inv[i], inv[i - 1]);
	scanf("%d", &n);
	sieve();
	int prex = 0;
	for (int i = 0; i != n; ++i) prex = up(prex + C(n - 1, i)), calc[i] = down(-up(pow2[n - 1] + C(n - 1, i)) + up(prex << 1));
	for (int i = 1; i <= n; ++i) {
		int t; scanf("%d", &t);
		while (t != 1) {
			int xt = diva[t], cnt = 0;
			while (t % xt == 0) t /= xt, ++cnt;
			vec[xt].push_back(cnt);
		}
	}
	int ans = 0;
	for (int i = 1; i <= MAXS; ++i) if (vec[i].size()) {
		std::vector<int> & v = vec[i];
		std::sort(v.begin(), v.end());
		const int SZ = v.size();
		const int prec = n - SZ;
		for (int j = 0; j != SZ; ++j)
			ans = up(ans + mul(v[j], calc[j + prec]));
	}
	printf("%d\n", ans);
	return 0;
}