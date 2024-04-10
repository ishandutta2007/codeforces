#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		ll ans = 0;
		for(int i = 3; i <= N; i += 2) {
			ll x = (ll)i * i - (ll)(i - 2) * (i - 2);
			ans += x * (i / 2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}