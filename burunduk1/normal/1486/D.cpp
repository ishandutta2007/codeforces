/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int64_t solve() {
	int n, k;
	cin >> n >> k;
	int a[n], b[n+1];
	forn(i, n) {
		cin >> a[i];
		assert(1 <= a[i] && a[i] <= n);
	}

	int l = 1, r = n + 1;
	while (r - l > 1) {
		int m = (l + r) / 2, good = 0;
		b[0] = 0;
		forn(i, n)
			b[i + 1] = b[i] + (a[i] >= m);
		auto f = [&](int i) {
			int k1 = b[i], k0 = i - k1;
			// printf("[f(%d)=%d]", i, k1 - k0);
			return k1 - k0;
		};
		int sub = 0;
		for (int i = 0; i + k <= n; i++) {
			sub = min(sub, f(i));
			// printf("[%d]", f(i + k) - sub);
			good |= (f(i + k) - sub > 0);
		}
		// printf(" m=%d\n",m);
		(good ? l : r) = m;
	}
	return l;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cout << solve() << "\n";
}