#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N;
int cnt[62];
ll A[505050];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int j = 0; j < 60; j++) cnt[j] = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%lld", &A[i]);
			ll tmp = A[i];
			for(int j = 0; j < 60; j++) {
				if(tmp & 1) cnt[j]++;
				tmp >>= 1;
			}
		}

		ll ans = 0;
		for(int i = 1; i <= N; i++) {
			ll s = A[i] % MOD * N % MOD;
			for(int j = 0; j < 60; j++) {
				if(A[i] & (1LL << j)) continue;
				s = (s + cnt[j] * ((1LL << j) % MOD)) % MOD;
			}
			for(int j = 0; j < 60; j++) {
				if(~A[i] & (1LL << j)) continue;
				ans = (ans + (cnt[j] * ((1LL << j) % MOD)) % MOD * s) % MOD;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}