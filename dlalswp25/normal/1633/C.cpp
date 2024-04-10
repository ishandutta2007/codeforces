#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll hc, dc, hm, dm;
		ll k, w, a;
		scanf("%lld%lld%lld%lld%lld%lld%lld", &hc, &dc, &hm, &dm, &k, &w, &a);
		bool ok = false;
		for(int i = 0; i <= k; i++) {
			ll h = hc + i * a;
			ll d = dc + (k - i) * w;
			ll t1 = (hm + d - 1) / d;
			ll t2 = (h + dm - 1) / dm;
			if(t1 <= t2) ok = true;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}