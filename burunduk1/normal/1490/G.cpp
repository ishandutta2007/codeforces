/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	int tn;
	cin >> tn;
	while (tn--) {
		int n, m, x, a;
		cin >> n >> m;
		vector<int64_t> ms(n + 1);
		int64_t sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a, sum += a;
			ms[i + 1] = max(ms[i], sum);
		}
		while (m--) {
			cin >> x;
			if (ms[n] < x && sum <= 0) {
				cout << "-1 ";
				continue;
			}
			int64_t k = 0, l = 0, r = n;
			if (ms[n] < x) {
				k = (x - ms[n] + (sum - 1)) / sum;
				x -= k * sum;
			}
			while (r - l > 1) {
				int64_t m = (l + r) / 2;
				(ms[m] < x ? l : r) = m;
			}
			cout << k * n + r - 1 << "\n";
		}
	}
}