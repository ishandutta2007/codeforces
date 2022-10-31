#include <bits/stdc++.h>
using namespace std;

long long b[70];

long long get(int p, long long x) {
	if (p == 1) return 3 - x;
	if (x & 1) return b[p] - x / 2;
	return get(p - 1, x / 2);
}

int main() {
	b[0] = 1;
	for (int i = 1; i < 70; i++) b[i] = b[i - 1] * 2;
	long long n; scanf("%lld", &n);
	
	long long y = 1;
	int p = 0;
	while (y < n) y *= 2, p++;
	int q;
	y /= 2;
	p--;
	for (scanf("%d", &q); q--; ) {
		long long x; scanf("%lld", &x);
		long long rem = n - y;
		if (x <= 2 * rem) {
			if (x & 1) printf("%lld\n", x / 2 + 1);
			else printf("%lld\n", n + 1 - get(p, y - rem + x / 2));
		}
		else printf("%lld\n", n + 1 - get(p, x - 2 * rem));
	}
	return 0;
}