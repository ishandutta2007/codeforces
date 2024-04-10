#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const ll I2 = 500000004;

int N;
int A[202020];
int cnt[32];
ll pw[202020];

int main() {
	scanf("%d", &N);
	pw[0] = 1;
	for(int i = 1; i <= N; i++) pw[i] = pw[i - 1] * 2 % MOD;
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		int tmp = A[i];
		int c = 0;
		while(tmp) {
			if(tmp & 1) break;
			c++; tmp >>= 1;
		}
		cnt[c]++;
	}

	ll ans = (pw[N] + MOD - 1) % MOD;
	ll no = 0;

	for(int i = 1; i <= 30; i++) {
		if(!cnt[i]) continue;
		int s = 0;
		for(int j = i + 1; j <= 30; j++) s += cnt[j];
		ll t = pw[cnt[i]] * I2 % MOD * pw[s] % MOD;
		no = (no + t) % MOD;
	}
	printf("%lld\n", (ans + MOD - no) % MOD);

	return 0;
}