#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

int main() {
	ll N, M; scanf("%lld%lld", &N, &M);
	printf("%lld\n", pw(pw(2, M) - 1 + MOD, N));
	return 0;
}