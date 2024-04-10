#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll N; scanf("%lld", &N);
		if(N & 1 || N <= 2) { puts("-1"); continue; }
		N /= 2;
		ll mx = N / 2;
		ll mn = (N + 2) / 3;
		printf("%lld %lld\n", mn, mx);
	}
	return 0;
}