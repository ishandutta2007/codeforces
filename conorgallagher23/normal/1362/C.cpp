#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll read() {
	char c = getchar(); ll x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int main() {
	int T = read();
	while (T--) {
		ll n = read();
		ll ans = 0;
		n++;
		for (ll i = 0; i <= 60; i++) {
			ll tmp = (1ll << i);
			if (tmp > n) break;
			if (n % tmp == 0) tmp = n / tmp; else tmp = n / tmp + 1;
			ans += (ll)tmp - 1;
		}
		printf("%lld\n", ans);
	} 
	return 0;
}