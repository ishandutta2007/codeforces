#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		ll mx = 0; int mxi = 0;
		ll mn = 1LL << 60;
		for(int i = 1; i <= N; i++) {
			ll t = 0;
			for(int j = 1; j <= M; j++) {
				ll a; scanf("%lld", &a);
				t += a * j;
			}
			if(mx < t) { mx = t; mxi = i; }
			mn = min(mn, t);
		}
		printf("%d %lld\n", mxi, mx - mn);
	}
	return 0;
}