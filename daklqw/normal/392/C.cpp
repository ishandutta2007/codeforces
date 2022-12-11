#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;
const int MAXK = 50;
const int Dollar1 = 1000000007;
int fac[MAXK], inv[MAXK], pow2[MAXK], k;
LL n;
inline int mul(const int a, const int b) { return static_cast<LL> (a) * b % Dollar1; }
inline void add(int & x, const int y) { x += y; if (x >= Dollar1) x -= Dollar1; }
inline int up(const int x) { return x >= Dollar1 ? x - Dollar1 : x; }
struct Mat {
	int a[110][110];
	Mat() { memset(a, 0, sizeof a); }
	inline friend Mat operator * (const Mat & a, const Mat & b) {
		Mat res;
		const int UP = (k + 1) * 2 + 1;
		for (int i = 0; i != UP; ++i)
			for (int j = 0; j != UP; ++j) {
				int t = 0;
				for (int k = 0; k != UP; ++k)
					add(t, mul(a.a[i][k], b.a[k][j]));
				res.a[i][j] = t;
			}
		return res;
	}
} a, res;
inline int getPos(int x, int y) { return x * (k + 1) + y; }
inline int C(int a, int b) { return static_cast<LL> (fac[a]) * inv[b] % Dollar1 * inv[a - b] % Dollar1; }
int main() {
	fac[0] = fac[1] = inv[0] = inv[1] = pow2[0] = 1; pow2[1] = 2;
	for (int i = 2; i != MAXK; ++i)
		fac[i] = mul(fac[i - 1], i),
		inv[i] = mul(Dollar1 - Dollar1 / i, inv[Dollar1 % i]),
		pow2[i] = up(pow2[i - 1] << 1);
	for (int i = 2; i != MAXK; ++i) inv[i] = mul(inv[i], inv[i - 1]);
	scanf("%lld%d", &n, &k);
	for (int i = 0; i <= k; ++i) {
		a.a[getPos(1, i)][getPos(0, i)] = 1;
		for (int j = 0; j <= i; ++j) {
			a.a[getPos(0, j)][getPos(1, i)] = mul(C(i, j), pow2[i - j]);
			a.a[getPos(1, j)][getPos(1, i)] = C(i, j);
		}
		a.a[getPos(2, 0)][getPos(1, i)] = up(pow2[i] + 1);
	}
	res.a[0][getPos(2, 0)] = a.a[getPos(2, 0)][getPos(2, 0)] = 1;
	for (int i = 0; i <= k; ++i) {
		res.a[0][getPos(1, i)] = up(1 + pow2[i + 1]);
		res.a[0][getPos(0, i)] = 1; 
	}
	if (n == 1) { puts("1"); return 0; }
	n -= 2;
	while (n) {
		if (n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	printf("%d\n", res.a[0][getPos(1, k)]);
	return 0;
}