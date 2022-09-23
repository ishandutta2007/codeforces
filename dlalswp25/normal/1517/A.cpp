#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll X[20];

int main() {
	X[0] = 2050;
	for(int i = 1; i < 15; i++) X[i] = X[i - 1] * 10;
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll n; scanf("%lld", &n);
		int ans = 0;
		for(int i = 14; i >= 0; i--) {
			while(n >= X[i]) { ans++; n -= X[i]; }
		}
		if(n) puts("-1");
		else printf("%d\n", ans);
	}
	return 0;
}