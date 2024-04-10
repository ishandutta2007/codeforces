#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL power(LL x, LL p, LL MOD) {
	LL ans = 1;
	while (p) {
		if (p & 1) ans = ans * x % MOD;
		x = x * x % MOD; p >>= 1;
	}
	return ans;
}

LL calc(LL x, LL y, LL MOD) {
	if (x % MOD) return (power(x, power(2, y, MOD - 1), MOD) + MOD - 1) % MOD;
	return MOD - 1;
}

#define rev(x) (power(x, MOD - 2, MOD))
LL solve(LL K, LL l, LL r, LL MOD) {
	LL x = calc(K, l, MOD);
	if (x) return calc(x + 1, r - l + 1, MOD) * rev(x) % MOD * ((K & 1) ? rev(power(2, r - l, MOD)) : 1) % MOD;
	return ((K & 1) ? 2 : power(2, r - l + 1, MOD)) % MOD;
}

int main() {
	LL T, K, l, r, p;
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld%lld%lld%lld", &K, &l, &r, &p);
		printf("%lld\n", (solve(K, l, r, p) + p) % p);
	}
	return 0;
}