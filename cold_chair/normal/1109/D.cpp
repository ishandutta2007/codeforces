#include<cstdio>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const int mo = 1e9 + 7;

ll ksm(ll x, ll y) {
	ll s = 1;
	if(y < 0) x = ksm(x, mo - 2), y = -y;
	for(; y; y /= 2, x = x * x % mo)
		if(y & 1) s = s * x % mo;
	return s;
}

const int N = 1e6 + 5;

int n, m, a, b;
ll fac[N], nf[N], ans;

ll P(int n, int m) {
	if(n < m) return 0;
	return fac[n] * nf[n - m] % mo;
}

ll C(int n, int m) {
	if(n < m) return 0;
	return fac[n] * nf[m] % mo * nf[n - m] % mo;
}

int main() {
	n = 1e6;
	fac[0] = 1; fo(i, 1, n) fac[i] = fac[i - 1] * i % mo;
	nf[n] = ksm(fac[n], mo - 2); fd(i, n, 1) nf[i - 1] = nf[i] * i % mo;
	scanf("%d %d %d %d", &n, &m, &a, &b);
	fo(x, 1, n - 1) ans += P(n - 2, x - 1) * C(m - 1, x - 1) % mo * ksm(m, n - 1 - x) % mo * ksm(n, n - 1 - (x + 1)) % mo * (x + 1) % mo;
	printf("%I64d", ans % mo);
}