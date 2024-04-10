#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, K; scanf("%d%d", &N, &K);
		K--;
		if(!K) { puts("1"); continue; }
		if(N & 1) {
			ll q = K / (N / 2);
			ll r = K % (N / 2);
			ll t = q * (N + 1) / 2 % N;
			t += r;
			printf("%lld\n", t % N + 1);
		}
		else {
			printf("%d\n", K % N + 1);
		}
	}
	return 0;
}