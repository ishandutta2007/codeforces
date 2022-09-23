#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int mx = 0;
		ll s = 0;
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			s += a; mx = max(mx, a);
		}

		ll k = (s + N - 2) / (N - 1);
		if(mx > k) printf("%lld\n", (ll)mx * (N - 1) - s);
		else printf("%lld\n", k * (N - 1) - s);
	}
	return 0;
}