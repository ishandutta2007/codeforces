#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int a = 0, b = 0;
		int N; scanf("%d", &N);
		int x = 1;
		for(int d = 0; ; d++) {
			if(!N) break;
			int t = N % 10;
			if(~d & 1) a += x * t;
			else b += x * t;
			if(d & 1) x *= 10;
			N /= 10;
		}
		ll ans = (ll)(a + 1) * (b + 1) - 2;
		printf("%lld\n", ans);
	}
	return 0;
}