#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll x, y;
ll C[6];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%lld%lld", &x, &y);
		for(int i = 0; i < 6; i++) scanf("%lld", &C[i]);
		swap(x, y);

		ll ans = 1LL << 61;
		for(int i = 0; i < 6; i += 3) {
			for(int j = 1; j < 6; j += 3) {
				for(int k = 2; k < 6; k += 3) {
					ll mn = 0, mx = (1LL << 60);
					int cj = 1, ck = 1;

					ll a = C[i];
					if(j == (i + 1) % 6) { a -= C[j]; mx = min(mx, x); cj = -1; }
					else { a += C[j]; mn = max(mn, x); }
					if(k == (i + 5) % 6) { a -= C[k]; mx = min(mx, y); ck = -1; }
					else { a += C[k]; mn = max(mn, y); }

					// printf("%d %d %d %lld %lld\n", i, j, k, mn, mx);

					if(mn > mx) continue;

					// printf("%d %d %d %lld %lld %lld %d %d\n", i, j, k, a, mn, mx, cj, ck);

					ll ni, nj, nk;
					if(a >= 0) ni = mn;
					else ni = mx;
					nj = (ni - x) * cj;
					nk = (ni - y) * ck;
					ans = min(ans, ni * C[i] + nj * C[j] + nk * C[k]);
				}
			}
			x *= -1; y *= -1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}