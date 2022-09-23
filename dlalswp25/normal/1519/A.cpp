#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll r, b, d; scanf("%lld%lld%lld", &r, &b, &d);
		if(r < b) swap(r, b);
		if(r > b * (1 + d)) puts("NO");
		else puts("YES");
	}
	return 0;
}