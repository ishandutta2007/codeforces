#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, B, X, Y; scanf("%d%d%d%d", &N, &B, &X, &Y);
		int cur = 0;
		ll ans = 0;
		for(int i = 1; i <= N; i++) {
			if(cur + X <= B) cur += X;
			else cur -= Y;
			ans += cur;
		}
		printf("%lld\n", ans);
	}
	return 0;
}