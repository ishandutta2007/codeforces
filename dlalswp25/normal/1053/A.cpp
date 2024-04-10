#include <stdio.h>

typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	ll n, m, k; scanf("%lld%lld%lld", &n, &m, &k);
	ll x = n * m;
	ll g = gcd(x, k);
	if(k / g > 2) { puts("NO"); return 0; }

	ll g1 = gcd(n, k);
	ll _n = n / g1;
	k /= g1;
	ll g2 = gcd(m, k);
	ll _m = m / g2;
	k /= g2;
	puts("YES");
	printf("0 0\n");
	if(k == 2) {
		printf("%d 0\n", _n);
		printf("0 %d\n", _m);
		return 0;
	}
	if(_n * 2 <= n) {
		printf("%d 0\n", _n * 2);
		printf("0 %d\n", _m);
	}
	else if(_m * 2 <= m) {
		printf("%d 0\n", _n);
		printf("0 %d\n", _m * 2);
	}

	return 0;
}