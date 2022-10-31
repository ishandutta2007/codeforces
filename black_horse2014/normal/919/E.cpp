#include <bits/stdc++.h>
using namespace std;

int c[1100000];

int main() {
	int a, b, p; long long n; cin >> a >> b >> p >> n;
	c[0] = 1;
	for (int i = 1; i < p; i++) c[i] = 1LL * c[i - 1] * a % p;
	long long ans = 0;
	for (int i = 0; i < p - 1; i++) {
		int j = 1LL * b * c[p - 1 - i] % p;
		int k = (i - j + p) % p;
		long long st = 1LL * k * (p - 1) + i;
		if (st <= n) ans += (n - st) / p / (p - 1) + 1;
	}
	cout << ans << endl;
	return 0;
}