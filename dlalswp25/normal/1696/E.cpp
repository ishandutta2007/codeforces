#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MX = 400000;

int N;
ll F[404040];
ll I[404040];

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

ll ncr(int n, int r) {
	return F[n] * I[r] % MOD * I[n - r] % MOD;
}

int main() {
	F[0] = 1;
	for(int i = 1; i <= MX; i++) F[i] = F[i - 1] * i % MOD;
	I[MX] = inv(F[MX]);
	for(int i = MX - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;
	scanf("%d", &N);
	ll ans = 0;
	for(int i = 0; i <= N; i++) {
		int a; scanf("%d", &a);
		if(!a) continue;
		ans = (ans + ncr(i + a, i + 1)) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}