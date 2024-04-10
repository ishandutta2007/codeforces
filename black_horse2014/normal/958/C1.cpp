#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int d[N];

int main() {
	int n, p;
	long long l = 0, r = 0, S = 0;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) scanf("%d", d + i), r += d[i];
	for (int i = 0; i < n; i++) {
		l += d[i];
		r -= d[i];
		if (l == 0 || r == 0) continue;
		long long s = l % p + r % p;
		if (S < s) S = s;
	}
	printf("%lld\n", S);
	return 0;
}