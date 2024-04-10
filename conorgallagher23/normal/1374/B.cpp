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
		ll n = read(); int cnt2 = 0, cnt3 = 0;
		while (n % 2 == 0) n >>= 1, cnt2++;
		while (n % 3 == 0) n /= 3, cnt3++;
		if (n > 1 || cnt2 > cnt3) printf("-1\n");
		else printf("%d\n", (cnt3 << 1) - cnt2);
	}
	return 0;
}