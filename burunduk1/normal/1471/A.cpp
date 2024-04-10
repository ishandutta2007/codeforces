/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--) {
		int n, x, a;
		cin >> n >> x;
		int64_t sum_mi = 0, ma = 0, sum = 0;
		auto f = [&](int64_t y) { return (y + x - 1) / x; };
		while (n--) {
			cin >> a;
			sum += a, sum_mi += a;
			if (sum % x != 0)
				ma += f(sum), sum = 0;
		}
		ma += f(sum), sum = 0;
		cout << f(sum_mi) << " " << ma << "\n";
	}
}