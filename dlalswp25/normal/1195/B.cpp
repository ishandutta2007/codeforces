#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N, K;

int main() {
	scanf("%lld%lld", &N, &K);
	for(ll i = 1; i <= 1000000000; i++) {
		if(i * (i + 1) / 2 - (N - i) == K) {
			printf("%lld\n", N - i);
			return 0;
		}
	}
	return 0;
}