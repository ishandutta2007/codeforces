#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N;
int A[202020];

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
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		if(A[N] > A[N - 1] + 1) { puts("0"); continue; }

		ll ans = 1;
		for(int i = 1; i <= N; i++) ans = ans * i % MOD;
		if(A[N] != A[N - 1]) {
			int p = N - 1;
			while(p && A[p] == A[N] - 1) p--;
			int t = N - p;
			ans = ans * (t - 1) % MOD * inv(t) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}