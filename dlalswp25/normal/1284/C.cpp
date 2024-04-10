#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N, M;
ll F[252525];

int main() {
	scanf("%lld%lld", &N, &M);
	F[0] = 1; for(int i = 1; i <= 250000; i++) F[i] = F[i - 1] * i % M;
	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		ans = (ans + (ll)(N - i + 1) * (N - i + 1) % M * F[i] % M * F[N - i] % M) % M;
	}
	printf("%lld\n", ans);

	return 0;
}