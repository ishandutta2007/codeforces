#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int mx = 0;
		ll ans = 0;
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			ans += a;
		}
		for(int i = 1; i <= N; i++) {
			int b; scanf("%d", &b);
			ans += b;
			mx = max(mx, b);
		}
		printf("%lld\n", ans - mx);
	}
	return 0;
}