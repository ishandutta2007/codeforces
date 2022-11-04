#include<cstdio>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const int mo = 1e9 + 7;

ll ksm(ll x, ll y) {
	ll s = 1;
	for(; y; y /= 2, x = x * x % mo)
		if(y & 1) s = s * x % mo;
	return s;
}

const int N = 32000000;

bool bz[N + 1]; int p[N + 1];

ll n; int k;

void sieve(int n) {
	fo(i, 2, n) {
		if(!bz[i]) p[++ p[0]] = i;
		for(int j = 1; i * p[j] <= n; j ++) {
			bz[i * p[j]] = 1;
			if(i % p[j] == 0) break;
		}
	}
}

ll u[100], v[100]; int u0;
ll ni[101];

int tot;

const int M = 2e5 + 5;

ll f[2][100], ans, o;

int main() {
	sieve(N);
	scanf("%I64d %d", &n, &k);
	for(int i = 1; (ll) p[i] * p[i] <= n; i ++) if(n % p[i] == 0) {
		u[++ u0] = p[i] % mo;
		while(n % p[i] == 0) n /= p[i], v[u0] ++;
	}
	if(n > 1) u[++ u0] = n, v[u0] = 1;
	fo(i, 1, 100) ni[i] = ksm(i, mo - 2);
	ans = 1;
	fo(i, 1, u0) {
		fo(j, 0, v[i]) f[o][j] = 0;
		f[o][v[i]] = 1;
		fo(ii, 1, k) {
			fo(j, 0, v[i]) f[!o][j] = 0;
			fo(k, 0, v[i]) fo(j, 0, k)
				f[!o][j] = (f[!o][j] + f[o][k] * ni[k + 1]) % mo;
			o = !o;
		}
		ll s = 1, sum = 0;
		fo(j, 0, v[i]) {
			sum = (sum + s * f[o][j]) % mo;
			s = s * u[i] % mo;
		}
		ans = ans * sum % mo;
	}
	printf("%I64d", ans);
}