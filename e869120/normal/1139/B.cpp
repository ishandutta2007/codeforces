#include <bits/stdc++.h>
using namespace std;

long long n, x[1 << 19];

int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
	long long s = 0, c = (1LL << 30);
	for (int i = n; i >= 1; i--) {
		c = min(c - 1LL, x[i]); if (c < 0) c = 0;
		s += c;
	}
	cout << s << endl;
	return 0;
}