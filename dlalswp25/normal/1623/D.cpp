#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

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
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, M, x1, y1, x2, y2;
		ll p;
		scanf("%d%d%d%d%d%d%lld", &N, &M, &x1, &y1, &x2, &y2, &p);
		p = p * inv(100) % MOD;

		vector<ll> v;
		if(x1 > x2) {
			for(int i = 0; i < M - 1; i++) {
				v.emplace_back((ll)i * 2 * (N - 1) + N + N - x2 - x1);
				v.emplace_back((ll)i * 2 * (N - 1) + (N + N - 2) - (x1 - x2));
			}
		}
		else {
			for(int i = 0; i < M - 1; i++) {
				v.emplace_back((ll)i * 2 * (N - 1) + x2 - x1);
				v.emplace_back((ll)i * 2 * (N - 1) + N + N - x2 - x1);
			}
		}

		if(y1 > y2) {
			for(int i = 0; i < N - 1; i++) {
				v.emplace_back((ll)i * 2 * (M - 1) + M + M - y2 - y1);
				v.emplace_back((ll)i * 2 * (M - 1) + (M + M - 2) - (y1 - y2));
			}
		}
		else {
			for(int i = 0; i < N - 1; i++) {
				v.emplace_back((ll)i * 2 * (M - 1) + y2 - y1);
				v.emplace_back((ll)i * 2 * (M - 1) + M + M - y2 - y1);
			}
		}

		for(ll& i : v) if(i == 2LL * (N - 1) * (M - 1)) i = 0;

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		ll q = 1;
		ll ans = 0;
		for(ll i : v) {
			ans = (ans + i * q % MOD * p) % MOD;
			q = q * (1 + MOD - p) % MOD;
		}
		printf("%lld\n", (ans + 2LL * (N - 1) * (M - 1) % MOD * q) % MOD * inv((1 + MOD - q) % MOD) % MOD);
	}
	return 0;
}