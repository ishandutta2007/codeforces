#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll H, W; scanf("%lld%lld", &W, &H);
		ll ans = 0;
		for(int i = 0; i < 2; i++) {
			int k; scanf("%d", &k);
			int l = W, r = 0;
			for(int j = 1; j <= k; j++) {
				int x; scanf("%d", &x);
				l = min(l, x);
				r = max(r, x);
			}
			ans = max(ans, (r - l) * H);
		}
		for(int i = 0; i < 2; i++) {
			int k; scanf("%d", &k);
			int l = H, r = 0;
			for(int j = 1; j <= k; j++) {
				int x; scanf("%d", &x);
				l = min(l, x);
				r = max(r, x);
			}
			ans = max(ans, (r - l) * W);
		}
		printf("%lld\n", ans);
	}
	return 0;
}