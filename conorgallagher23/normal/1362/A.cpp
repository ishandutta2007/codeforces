#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll read() {
	char c = getchar(); ll x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

map<ll, int> bs;

int main() {
	for (ll i = 0; i <= 60; i++)
		bs[1ll << i] = i;
	int T = read();
	while (T--) {
		ll a = read(), b = read();
		if (a < b) swap(a, b);
		if (a % b != 0) { printf("-1\n"); continue; }
		ll div = a / b, tmp = div & -div;
		if (tmp != div) { printf("-1\n"); continue; }
		tmp = bs[tmp];
		printf("%lld\n", tmp % 3 == 0 ? tmp / 3 : tmp / 3 + 1);
	} 
	return 0;
}