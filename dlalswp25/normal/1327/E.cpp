#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N;

ll pw(ll a, ll b) {
	if(b < 0) return 0;
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		if(i == N) { puts("10"); break; }
		ll t = 0;
		t = (t + 2 * 9 * pw(10, N - 1 - i)) % MOD;
		t = (t + (N - i - 1) * 9 * 9 % MOD * pw(10, N - 2 - i));
		printf("%lld ", t * 10 % MOD);
	}
	return 0;
}