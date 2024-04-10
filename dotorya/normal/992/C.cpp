#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define all(x) (x).begin(), (x).end()

const int INF = 0x3f3f3f3f;
const int MAXN = 10000;
const int MOD = 1000000007;

typedef long long ll;

ll mymul(ll a, ll b) {
	return (a%MOD) * (b%MOD) % MOD;
}
ll mypow(ll a, ll b) {
	a %= MOD;

	ll rv = 1;
	while (b) {
		if (b % 2) rv = rv*a%MOD;
		a = a*a%MOD;
		b /= 2;
	}
	return rv;
}

int main() {
	ll X, K, i, j;
	scanf("%lld %lld", &X, &K);

	if (X == 0) return !printf("0\n");

	ll ans = mymul(X, mypow(2, K + 1)) - mypow(2, K) + 1;
	ans = (ans%MOD + MOD) % MOD;
	return !printf("%lld\n", ans);
}