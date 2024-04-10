#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N;
ll A[20];
bool chk[20];
ll D[17171];
ll W[20][20];

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

ll win(ll a, ll b) {
	return W[a][b];
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%lld", &A[i]);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(i == j) continue;
			W[i][j] = A[i] * inv(A[i] + A[j]) % MOD;
		}
	}

	ll ans = 0;
	for(int i = 1; i < 1 << N; i++) {
		int bit = 0;
		for(int j = 0; j < N; j++) chk[j] = false;
		for(int j = 0; j < N; j++) {
			if(i & 1 << j) { bit++; chk[j] = true; }
		}
		ll prob = 1;
		for(int j = 0; j < N; j++) {
			if(!chk[j]) continue;
			for(int k = 0; k < N; k++) {
				if(chk[k]) continue;
				prob = prob * win(j, k) % MOD;
			}
		}

		for(int t = i; t; t = (t - 1) & i) {
			ll x = D[t];
			for(int j = 0; j < N; j++) {
				if(!chk[j]) continue;
				if(t & 1 << j) continue;
				for(int k = 0; k < N; k++) {
					if(chk[k]) continue;
					x = x * win(j, k) % MOD;
				}
			}
			prob = (prob + MOD - x) % MOD;
		}
		D[i] = prob;
		ans = (ans + D[i] * bit) % MOD;
	}

	printf("%lld\n", ans);

	return 0;
}