#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N;
ll X = (MOD + 1) / 2;

int main() {
	scanf("%d", &N);
	if(N == 1) { printf("%lld\n", X); return 0; }
	ll a = X, b = 1;
	ll t;
	for(int i = 2; i <= N; i++) {
		t = a * X % MOD;
		b = (t + b * X % MOD * X) % MOD;
		swap(a, b);
	}
	printf("%lld\n", t);
	return 0;
}