#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int N, M;
pii A[101010];

ll S[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= M; i++) scanf("%lld%lld", &A[i].first, &A[i].second);
		sort(A + 1, A + M + 1);

		S[M + 1] = 0;
		for(int i = M; i >= 1; i--) S[i] = S[i + 1] + A[i].first;

		// for(int i = 1; i <= M; i++) printf("%lld %lld\n", A[i].first, A[i].second);

		ll ans = S[max(1, M - N + 1)];
		for(int i = 1; i <= M; i++) {
			int idx = lower_bound(A + 1, A + M + 1, pii(A[i].second, 0)) - A;
			// printf("%d %d\n", i, idx);
			ll t;

			if(i >= idx) {
				if(N - (M - idx + 1) < 0) continue;
				t = (N - (M - idx + 1)) * A[i].second + S[idx];
			}
			else {
				if(N - (M - idx + 1) - 1 < 0) continue;
				t = (N - (M - idx + 1) - 1) * A[i].second + A[i].first + S[idx];
			}
			ans = max(ans, t);
		}
		printf("%lld\n", ans);
	}
	return 0;
}