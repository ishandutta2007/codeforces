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
		int n, x;
		cin >> n >> x;
		vector<pair<int, int64_t>> a(n);
		for (auto &t : a) cin >> t.first, t.second = 1;
		for (size_t i = 0; i < a.size(); i++) {
			auto [q, cnt] = a[i];
			if (q % x != 0) break;
			a.push_back({q / x, x * cnt});
		}
		int64_t sum = 0;
		for (auto [q, cnt] : a) 
			sum += q * cnt;
		cout << sum << "\n";
	}
}