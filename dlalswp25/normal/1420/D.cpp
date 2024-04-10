#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 998244353;

int N, K;
vector<pii> evt;

ll F[303030];
ll I[303030];

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

ll ncr(int n, int r) { return F[n] * I[r] % MOD * I[n - r] % MOD; }

int main() {
	scanf("%d%d", &N, &K);

	F[0] = 1;
	for(int i = 1; i <= N; i++) F[i] = F[i - 1] * i % MOD;
	I[N] = inv(F[N]);
	for(int i = N - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	for(int i = 1; i <= N; i++) {
		int l, r; scanf("%d%d", &l, &r);
		evt.emplace_back(l, 1);
		evt.emplace_back(r + 1, -1);
	}

	sort(evt.begin(), evt.end());

	ll ans = 0;
	int cnt = 0;
	for(pii i : evt) {
		if(i.second == -1) { cnt--; continue; }
		if(cnt < K - 1) { cnt++; continue; }
		ans = (ans + ncr(cnt, K - 1)) % MOD;
		cnt++;
		// printf("%d %d / %d %lld\n", i.first, i.second, cnt, ans);
	}
	printf("%lld\n", ans);

	return 0;
}