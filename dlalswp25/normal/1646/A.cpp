#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll N, S; scanf("%lld%lld", &N, &S);
		printf("%lld\n", S / (N * N));
	}
	return 0;
}