#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll mx = 0, s = 0;
		ll a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
		s = a + b + c;
		mx = max(max(a, b), c);
		if(mx > (s + 1) / 2) puts("No");
		else puts("Yes");
	}
	return 0;
}