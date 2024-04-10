#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll a, b, x, y;
		scanf("%lld%lld", &x, &y);
		scanf("%lld%lld", &a, &b);
		if(x > y) swap(x, y);
		if(2 * a <= b) {
			printf("%lld\n", (x + y) * a);
		}
		else {
			printf("%lld\n", x * b + (y - x) * a);
		}
	}
	return 0;
}