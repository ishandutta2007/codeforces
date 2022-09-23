#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K, Z;
ll A[101010];
ll S[101010];
ll M[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &K, &Z);
		for(int i = 1; i <= N; i++) {
			scanf("%lld", &A[i]);
			S[i] = S[i - 1] + A[i];
		}

		for(int i = 1; i <= N; i++) {
			M[i] = max(M[i - 1], A[i] + A[i + 1]);
		}

		ll ans = 0;
		for(int i = 0; i <= Z; i++) {
			int r = K + 1 - 2 * i;
			if(r <= 0) continue;
			if(!i) ans = max(ans, S[r] + M[r - 1] * i);
			else ans = max(ans, S[r] + M[r] * i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}