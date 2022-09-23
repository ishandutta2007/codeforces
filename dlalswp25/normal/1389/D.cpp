#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int N;
ll K;
pll A, B;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%lld", &N, &K);
		scanf("%lld%lld%lld%lld", &A.first, &A.second, &B.first, &B.second);

		if(A.first > B.first) swap(A, B);
		if(A.second < B.first) {
			ll ans = 1LL << 60;
			for(int i = 1; i <= N; i++) {
				ll t = (B.first - A.second) * i;
				ll L = (B.second - A.first);
				if(L * i > K) ans = min(ans, t + K);
				else ans = min(ans, t + L * i + (K - L * i) * 2);
			}
			printf("%lld\n", ans);
		}
		else {
			ll X = (A.second < B.second ? A.second - B.first : B.second - B.first);
			if(X * N >= K) { puts("0"); continue; }
			K -= X * N;
			ll L = (B.first - A.first) + abs(B.second - A.second);
			if(L * N > K) printf("%lld\n", K);
			else printf("%lld\n", L * N + 2 * (K - L * N));
		}
	}
	return 0;
}