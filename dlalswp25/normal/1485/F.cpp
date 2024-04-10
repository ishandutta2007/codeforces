#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N;
int A[202020];
ll D[202020][2];
ll pw[202020];
map<ll, ll> mp;

int main() {
	pw[0] = 1; for(int i = 1; i <= 200000; i++) pw[i] = pw[i - 1] * 2 % MOD;

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		mp.clear();
		mp[0]++;

		ll s = A[1];
		D[1][0] = 0; D[1][1] = 1;
		for(int i = 2; i <= N; i++) {
			D[i][0] = (D[i - 1][0] + D[i - 1][1]) % MOD;
			D[i][1] = D[i][0];
			D[i][1] = (D[i][1] + mp[s]) % MOD;
			mp[s] += (pw[i - 1] + MOD - D[i][1]) % MOD;
			s += A[i];
			// printf("%lld %lld\n", D[i][0], D[i][1]);
		}
		printf("%lld\n", (pw[N] + MOD + MOD - (D[N][0] + D[N][1])) % MOD);
	}
	return 0;
}