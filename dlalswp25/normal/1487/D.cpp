#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		N = 2 * N - 1;
		ll l = 0, r = N;
		while(l <= r) {
			ll m = l + r >> 1;
			if(m * m > N) r = m - 1;
			else l = m + 1;
		}
		printf("%lld\n", (r - 1) / 2);
	}
	return 0;
}