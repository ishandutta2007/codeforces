#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N, M;
int A[3][4] = {
	{0, 1, 2, 3},
	{0, 2, 3, 1},
	{0, 3, 1, 2}
};

int main() {
	int Q; scanf("%d", &Q);
	while(Q--) {
		scanf("%lld", &N);
		M = (N - 1) / 3;

		ll b = 0;
		ll s = 0;
		while(M >= s) {
			s += (1LL << 2 * b);
			b++;
		}
		b--;

		int r = (N + 2) % 3;
		ll ans = 0;

		// printf("%lld %lld\n", M, b);

		for(int i = 0; i < b; i++) M -= (1LL << 2 * i);
		for(int i = 0; i < b; i++) {
			ll t = M >> 2 * i & 3;
			ans += A[r][t] * (1LL << 2 * i);
		}
		printf("%lld\n", ans + A[r][1] * (1LL << 2 * b));
	}
	return 0;
}