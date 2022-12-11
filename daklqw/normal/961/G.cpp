#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 200010
#define PRE_RUN 1000010
inline long long LL(int x) { return static_cast<long long> (x); }
namespace MOD_BASE {
const int Dollar1 = 1000000007;
inline int up(int x) { return x >= Dollar1 ? x - Dollar1 : x; }
inline int down(int x) { return x < 0 ? x + Dollar1 : x ; }
inline int & add(int & x, const int y) { x += y; if (x >= Dollar1) x -= Dollar1; return x; }
inline int & dec(int & x, const int y) { x -= y; if (x < 0) x += Dollar1; return x; }
inline int mul(int x, int y) { return LL(x) * y % Dollar1; }
inline int fastpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = LL(res) * a % Dollar1;
        a = LL(a) * a % Dollar1;
        b >>= 1;
    }
    return res;
}
inline int INV(int x) { return fastpow(x, Dollar1 - 2); }
#ifdef PRE_RUN
int fac[PRE_RUN], inv[PRE_RUN], invfac[PRE_RUN];
inline int C(int a, int b) { if (a < 0 || b < 0 || b > a) return 0; return LL(fac[a]) * invfac[b] % Dollar1 * invfac[a - b] % Dollar1; }
inline int lucas(int a, int b) { if (a < Dollar1 && b < Dollar1) return C(a, b); return LL(lucas(a % Dollar1, b % Dollar1)) * lucas(a / Dollar1, b / Dollar1) % Dollar1; }
int RUN_INIT() {
    invfac[0] = invfac[1] = inv[0] = inv[1] = fac[0] = fac[1] = 1;
    for (int i = 2; i != PRE_RUN; ++i) {
        fac[i] = LL(fac[i - 1]) * i % Dollar1;
        inv[i] = LL(inv[Dollar1 % i]) * (Dollar1 - Dollar1 / i) % Dollar1;
    }
    for (int i = 2; i != PRE_RUN; ++i) invfac[i] = mul(invfac[i - 1], inv[i]);
    return 0;
}
int FIRSTRUN = RUN_INIT();
#endif
}
using namespace MOD_BASE;

int S(int n, int m) {
	int res = 0;
	for (int i = 0, t = 1; i <= m; ++i, t = -t)
		add(res, down(t * mul(fastpow(m - i, n), C(m, i))));
	return mul(res, invfac[m]);
}
int n, k, w[MAXN], cnt[MAXN];
int main() {
	scanf("%d%d", &n, &k);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) scanf("%d", &w[i]), add(cnt, w[i]);
	printf("%d\n", mul(cnt, up(S(n, k) + mul(n - 1, S(n - 1, k)))));
	return 0;
}