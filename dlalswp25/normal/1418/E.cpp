#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, M;
ll D[202020];
ll S[202020];
ll I[202020];

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%lld", &D[i]);
	sort(D + 1, D + N + 1);
	for(int i = 1; i <= N; i++) S[i] = (S[i - 1] + D[i]) % MOD;
	for(int i = 1; i <= N + 1; i++) I[i] = pw(i, MOD - 2);

	while(M--) {
		int a, b; scanf("%d%d", &a, &b);
		int t = lower_bound(D + 1, D + N + 1, b) - D;
		t--;
		if(N - t < a) { puts("0"); continue; }
		ll ans = S[t] * (N - t + 1 - a) % MOD * I[N - t + 1] % MOD;
		ans = (ans + (S[N] + MOD - S[t]) * (N - t - a) % MOD * I[N - t] % MOD) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}