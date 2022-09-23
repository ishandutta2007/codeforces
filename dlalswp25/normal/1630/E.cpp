#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MX = 1000000;

int N;
int cnt[1010101];
ll C[1010101];
ll T[1010101];

ll F[1010101];
ll I[1010101];

int gcd(int a, int b) { while(b) { a %= b; swap(a, b); } return a; }

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
	F[0] = 1;
	for(int i = 1; i <= MX; i++) F[i] = F[i - 1] * i % MOD;
	I[MX] = inv(F[MX]);
	for(int i = MX - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) cnt[i] = C[i] = T[i] = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			cnt[a]++;
		}
		int g = 0;
		for(int i = 1; i <= N; i++) g = gcd(g, cnt[i]);
		if(g == N) { puts("1"); continue; }

		vector<int> v;
		for(int i = 1; i <= N; i++) if(cnt[i]) v.push_back(i);

		for(int i = 1; i <= g; i++) {
			if(g % i) continue;
			ll t = F[N / i];
			for(int j : v) t = t * I[cnt[j] / i] % MOD;
			C[i] = t;
			ll s = 0;
			for(int j : v) {
				if(cnt[j] < 2 * i) continue;
				s = (s + t * I[N / i] % MOD * F[N / i - 2] % MOD * F[cnt[j] / i] % MOD * I[cnt[j] / i - 2]) % MOD;
			}
			T[i] = s * N % MOD;
		}

		// for(int i = 1; i <= g; i++) printf("c%lld ", C[i]); puts("");
		// for(int i = 1; i <= g; i++) printf("t%lld ", T[i]); puts("");

		ll p = 0, q = 0;
		for(int i = g; i >= 1; i--) {
			if(g % i) continue;
			for(int j = i + i; j <= g; j += i) {
				C[i] = (C[i] + MOD - C[j]) % MOD;
				T[i] = (T[i] + MOD - T[j]) % MOD;
			}
			p = (p + T[i] * inv(N / i)) % MOD;
			q = (q + C[i] * inv(N / i)) % MOD;
		}
		printf("%lld\n", (N + MOD - p * inv(q) % MOD) % MOD);
	}
	return 0;
}