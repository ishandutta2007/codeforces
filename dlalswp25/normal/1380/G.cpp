#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll C[303030];
ll S[303030];
int N;

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

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &C[i]);
	sort(C + 1, C + N + 1);

	for(int i = 1; i <= N; i++) S[i] = S[i - 1] + C[i];

	ll I = inv(N);

	for(int i = 1; i <= N; i++) {
		ll ans = 0;
		for(int j = N - i; j >= 1; j -= i) ans = (ans + S[j]) % MOD;
		printf("%lld ", ans * I % MOD);
	}
	puts("");

	return 0;
}