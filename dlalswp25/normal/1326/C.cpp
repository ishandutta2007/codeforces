#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int P[202020];
int N, K;

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%d", &P[i]);

	int a = N - K + 1, b = N;
	printf("%lld ", (ll)(b + a) * (b - a + 1) / 2);
	ll c = 1;
	int bf = -1;
	for(int i = 1; i <= N; i++) {
		if(a <= P[i] && P[i] <= b) {
			if(bf == -1) { bf = i; continue; }
			c = c * (i - bf) % MOD;
			bf = i;
		}
	}
	printf("%lld\n", c);
	return 0;
}