#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#pragma warning(disable:4996)

#define all(x) (x).begin(), (x).end()

const ll MOD = 998244353;

ll mul_inv(ll a, ll b = MOD) {
	ll t1 = a, t2 = b, t3;
	ll v1 = 1, v2 = 0, v3;
	while (t2 != 1) {
		ll x = t1 / t2;
		t3 = t1 - x*t2;
		v3 = v1 - x*v2;
		t1 = t2, t2 = t3;
		v1 = v2, v2 = v3;
	}
	return (v2 + b) % b;
}
ll pow(ll a, ll b, ll m = MOD) {
	ll rv = 1;
	while (b) {
		if (b % 2) rv = rv * a % m;
		a = a*a%m;
		b /= 2;
	}
	return (rv + MOD) % MOD;
}

ll F[1000050];
ll Finv[1000050];
int main() {
	ll N, i;
	scanf("%lld", &N);

	F[0] = 1;
	for (i = 1; i <= N; i++) F[i] = F[i - 1] * i % MOD;
	for (i = 0; i <= N; i++) Finv[i] = mul_inv(F[i]);

	ll ans = 0;
	
	for (i = 1; i <= N; i++) {
		ll v = 2 * pow(3, N*N - (N-1)*i);
		v = v * F[N] % MOD;
		v = v * Finv[i] % MOD;
		v = v * Finv[N - i] % MOD;
		if (i % 2 == 0) v *= -1;
		ans += v;
	}
	for (i = 1; i <= N; i++) {
		ll t = pow(3, N - i) - 1;
		t = pow(t, N) - pow(t + 1, N);
		t = t * 3 % MOD;

		t = t * F[N] % MOD;
		t = t * Finv[i] % MOD;
		t = t * Finv[N - i] % MOD;
		if (i % 2) ans += t;
		else ans -= t;
	}
	ans = (ans%MOD + MOD) % MOD;
	return !printf("%lld\n", ans);
}