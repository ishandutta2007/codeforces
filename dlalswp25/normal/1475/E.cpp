#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MX = 1000;

ll F[1010];
ll I[1010];
int A[1010];

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}
ll inv(ll a) { return pw(a, MOD - 2); }

ll ncr(ll n, ll r) {
	if(n < r) return 0;
	return F[n] * I[n - r] % MOD * I[r] % MOD;
}

int main() {
	F[0] = 1; for(int i = 1; i <= MX; i++) F[i] = F[i - 1] * i % MOD;
	I[MX] = inv(F[MX]);
	for(int i = MX - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, K; scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		int c = 0;
		for(int i = N; i >= N - K + 1; i--) {
			if(A[i] != A[i + 1]) c = 1;
			else c++;
		}
		int d = 0;
		for(int i = N - K; i >= 1; i--) {
			if(A[i] != A[i + 1]) break;
			d++;
		}
		printf("%lld\n", ncr(c + d, d));
	}
	return 0;
}