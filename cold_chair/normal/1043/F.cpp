#include<cstdio>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const int mo = 998244353;

ll ksm(ll x, ll y) {
	ll s = 1;
	for(; y; y /= 2, x = x * x % mo)
		if(y & 1) s = s * x % mo;
	return s;
}

const int N = 3e5 + 5;
int n, k, x, s[N];
int bz[N], p[N], mu[N];
ll fac[N], nf[N], a2[N];

int sieve(int n) {
	mu[1] = 1;
	fo(i, 2, n) {
		if(!bz[i]) p[++ p[0]] = i, mu[i] = -1;
		for(int j = 1; i * p[j] <= n; j ++) {
			int k = i * p[j]; bz[k] = 1;
			if(i % p[j] == 0) {
				mu[k] = 0;
				break;
			}
			mu[k] = -mu[i];
		}
	}
}

ll C(ll x, ll y) {
	if(x < y) return 0;
	return fac[x] * nf[y] % mo * nf[x - y] % mo;
}

ll ans;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) scanf("%d", &x), s[x] ++;
	sieve(300000);
	fac[0] = a2[0] = 1;
	fo(i, 1, n) a2[i] = a2[i - 1] * 2 % mo, fac[i] = fac[i - 1] * i % mo;
	nf[n] = ksm(fac[n], mo - 2); fd(i, n - 1, 0) nf[i] = nf[i + 1] * (i + 1) % mo;
	for(k = 1; k <= 7; k ++) {
		fo(i, 1, 3e5) if(mu[i]) {
			int t = 0;
			for(int j = i; j <= 3e5; j += i) t += s[j];
			ans += C(t, k) * mu[i];
		}
		ans %= mo;
		if(ans) {
			printf("%d\n", k); return 0;
		}
	}
	printf("-1");
}