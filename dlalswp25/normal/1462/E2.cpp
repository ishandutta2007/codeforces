#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll F[202020];
ll I[202020];
int A[202020];
int N, M, K;

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

ll ncr(int n, int r) {
	if(n < r) return 0;
	return F[n] * I[r] % MOD * I[n - r] % MOD;
}

int main() {
	F[0] = 1;
	for(int i = 1; i <= 200000; i++) F[i] = F[i - 1] * i % MOD;
	I[200000] = pw(F[200000], MOD - 2);
	for(int i = 199999; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &M, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		int r = 1;
		ll ans = 0;
		for(int i = 1; i <= N; i++) {
			while(r <= N && A[r] <= A[i] + K) r++;
			ans = (ans + ncr(r - i - 1, M - 1)) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}