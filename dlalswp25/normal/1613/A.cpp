#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll x1, p1, x2, p2; scanf("%lld%lld%lld%lld", &x1, &p1, &x2, &p2);
		ll t = min(p1, p2);
		p1 -= t; p2 -= t;
		if(p1 > 6) { puts(">"); continue; }
		if(p2 > 6) { puts("<"); continue; }
		for(int i = 0; i < p1; i++) x1 *= 10;
		for(int i = 0; i < p2; i++) x2 *= 10;
		if(x1 == x2) puts("=");
		else if(x1 > x2) puts(">");
		else puts("<");
	}
	return 0;
}