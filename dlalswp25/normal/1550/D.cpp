#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 200000;
const ll MOD = 1000000007;

int N, L, R;
ll F[202020];
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

ll inv(ll x) { return pw(x, MOD - 2); }

ll ncr(ll n, ll r) {
	if(n < 0 || r < 0 || n < r) return 0;
	return F[n] * I[r] % MOD * I[n - r] % MOD;
}

int main() {
	F[0] = 1;
	for(int i = 1; i <= MX; i++) F[i] = F[i - 1] * i % MOD;
	I[MX] = inv(F[MX]);
	for(int i = MX - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &L, &R);
		ll ans = 0;
		int x = min(1 - L, R - N);
		ans = x * ncr(N, N / 2) % MOD;
		if(N & 1) {
			ans = (ans + x * ncr(N, (N + 1) / 2)) % MOD;
		}

		int l = 1, r = N;
		for(int i = 0; i < N; i++) {
			x++;
			while(r + x > R) r--;
			while(l - x < L) l++;
			int dn = N - r, up = l - 1;
			ans = (ans + ncr(N - dn - up, N / 2 - up)) % MOD;
			if(N & 1) {
				ans = (ans + ncr(N - dn - up, (N + 1) / 2 - up)) % MOD;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}