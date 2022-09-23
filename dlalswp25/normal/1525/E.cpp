#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, M;
int D[25][50505];

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
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) scanf("%d", &D[i][j]);

	ll I = 1;
	for(int i = 1; i <= N; i++) I = I * inv(i) % MOD;

	ll ans = 0;
	for(int j = 1; j <= M; j++) {
		vector<int> v;
		for(int i = 1; i <= N; i++) v.push_back(D[i][j]);
		sort(v.begin(), v.end());
		ll x = 1;
		for(int i = 0; i < N; i++) {
			x = x * max(v[i] - i - 1, 0) % MOD;
		}
		x = x * I % MOD;
		x = (1 + MOD - x) % MOD;
		ans = (ans + x) % MOD;
		// printf("%d %lld\n", j, ans);
	}
	printf("%lld\n", ans);

	return 0;
}