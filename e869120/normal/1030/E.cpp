#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long n, a[300009], c[300009], cc[300009], g[300009], ans;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 63; j++) { if ((a[i] / (1LL << j)) % 2 == 1) c[i]++; }
	}
	for (int i = 1; i <= n; i++) { cc[i] = (cc[i - 1] + c[i]) % 2; }
	for (int i = 0; i <= n; i++) { g[cc[i]]++; }

	for (int i = 1; i <= n; i++) {
		g[cc[i - 1]]--; ans += g[cc[i - 1]];
		long long S = 0, maxn = 0;
		for (int j = i; j <= i + 120; j++) {
			if (j > n) break;
			S += c[j]; maxn = max(maxn, c[j]);
			if (S < maxn * 2 && cc[j] == cc[i - 1]) { ans--; }
		}
	}
	cout << ans << endl;
	return 0;
}