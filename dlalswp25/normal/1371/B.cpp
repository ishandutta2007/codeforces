#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll N, R; scanf("%lld%lld", &N, &R);
		R = min(R, N);
		if(R == N) printf("%lld\n", R * (R - 1) / 2 + 1);
		else printf("%lld\n", R * (R + 1) / 2);
	}
	return 0;
}