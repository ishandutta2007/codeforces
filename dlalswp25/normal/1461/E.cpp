#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	ll k, l, r, t, x, y;
	scanf("%lld%lld%lld%lld%lld%lld", &k, &l, &r, &t, &x, &y);
	if(x == y) {
		if(k + y > r && k - x < l) puts("No");
		else puts("Yes");
		return 0;
	}
	if(x > y) {
		if(k + y <= r) k += y;
		k -= x;
		if(k < l) { puts("No"); return 0; }
		ll g = k - l;
		if(1 + g / (x - y) >= t) puts("Yes");
		else puts("No");
		return 0;
	}
	if(y % x == 0 || l + y > r) {
		ll g = (k - l);
		ll t0 = g / x;
		k -= x * t0;
		if(k + y <= r) puts("Yes");
		else if(t > t0) puts("No");
		else puts("Yes");
		return 0;
	}

	ll z = r - y;
	ll g = k - z;
	ll t0 = 0;
	if(g > 0) {
		t0 = g / x + !!(g % x);
	}

	k -= x * t0;
	if(k < l) {
		if(k - x * t < l) puts("No");
		else puts("Yes");
		return 0;
	}

	if(r - l >= x + y) { puts("Yes"); return 0; }

	bool ok = true;
	for(int i = 0; i < 2000000; i++) {
		k += y;
		g = k - z;
		t0 += g / x;
		k -= x * (g / x);
		if(t0 >= t) { puts("Yes"); return 0; }
		if(g % x && k - x < l) { ok = false; break; }
		if(g % x) { k -= x; t0++; }
	}

	if(ok) { puts("Yes"); return 0; }
	puts(t0 < t ? "No" : "Yes");

	return 0;
}