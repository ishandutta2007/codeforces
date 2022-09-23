#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll n; scanf("%lld", &n);
		printf("%lld %lld\n", -n + 1, n);
	}
	return 0;
}