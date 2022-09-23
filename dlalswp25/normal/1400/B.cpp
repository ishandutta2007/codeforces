#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll p, f;
ll cs, cw;
ll s, w;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%lld%lld%lld%lld%lld%lld", &p, &f, &cs, &cw, &s, &w);
		ll ans = 0;
		for(int i = 0; i <= cs; i++) {
			if(i * s > p) continue;
			ll j = min(cw, (p - i * s) / w);
			ll t = i + j;
			if(s < w) {
				if(f <= (cs - i) * s) {
					t += f / s;
				}
				else {
					t += cs - i;
					t += min(cw - j, (f - (cs - i) * s) / w);
				}
			}
			else {
				if(f <= (cw - j) * w) {
					t += f / w;
				}
				else {
					t += cw - j;
					t += min(cs - i, (f - (cw - j) * w) / s);
				}
			}
			ans = max(ans, t);
		}
		printf("%lld\n", ans);
	}
	return 0;
}