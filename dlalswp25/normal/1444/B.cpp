#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N;
ll A[303030];

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
	scanf("%d", &N);
	for(int i = 1; i <= 2 * N; i++) scanf("%lld", &A[i]);
	sort(A + 1, A + 2 * N + 1);
	
	ll S = 0;
	for(int i = 1; i <= N; i++) S -= A[i];
	for(int i = N + 1; i <= 2 * N; i++) S += A[i];
	while(S < 0) S += MOD;
	S %= MOD;

	ll T = 1;
	for(int i = 1; i <= 2 * N; i++) T = T * i % MOD;
	ll U = 1;
	for(int i = 1; i <= N; i++) U = U * i % MOD;
	U = inv(U);
	printf("%lld\n", S * T % MOD * U % MOD * U % MOD);
	return 0;
}