#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[303030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);	
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int mx = *max_element(A + 1, A + N + 1);
		ll ans = 1LL << 60;
		for(int z = 0; z < 2; z++) {
			ll goal = mx + z;
			ll s = 0, o = 0;
			for(int i = 1; i <= N; i++) {
				s += goal - A[i];
				o += (goal - A[i]) & 1;
			}
			ll l = 2 * o - 1, r = 2 * s - 1;
			while(l <= r) {
				ll m = l + r >> 1;
				ll t = (m + 1) / 2;
				if(2 * ((s - t + 1) / 2) > m) l = m + 1;
				else r = m - 1;
			}
			ans = min(ans, l);
		}
		printf("%lld\n", ans);
	}
	return 0;
}