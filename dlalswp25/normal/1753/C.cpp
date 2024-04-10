#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

ll inv(ll x) { return pw(x, MOD - 2); }

int N;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int c0 = 0;
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			c0 += (A[i] == 0);
		}
		int k = 0;
		for(int i = 1; i <= c0; i++) k += (A[i] == 1);
		ll X = (ll)N * (N - 1) % MOD * ((MOD + 1) / 2) % MOD;
		ll ans = 0;
		for(int i = 1; i <= k; i++) ans = (ans + X * inv(i) % MOD * inv(i)) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}