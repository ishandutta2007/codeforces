#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll x1, x2, y1, y2; scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);

		printf("%lld\n", ((x2 - x1) * (y2 - y1)) + 1);
	}
	return 0;
}