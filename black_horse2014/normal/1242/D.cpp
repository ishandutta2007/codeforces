#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		long long n, m; cin >> n >> m;
		auto get = [&](long long n, long long m) {
		    long long ret = (n + m * (m - 1) / 2) / m;
		    if (ret * m < n + m * (m - 1) / 2) ret++;
		    return ret;
		};
		function<pair<long long, long long>(long long, long long)> solve = [&](long long n, long long m) {
			if (n < 1LL * m * (m + 1) / 2) {
				return make_pair(0LL, 0LL);
			}
			long long x = get(n, m);
			auto cur = solve(x, m);
			long long y = cur.first, z = cur.second;
			long long turns = (y - z + m - 1) / m;
			long long last_cnt = turns * m - (y - z);
			long long first = y - (m - last_cnt);
			long long last = y + last_cnt - (last_cnt == 0);
			long long sum = (first + first + m) * (m + 1) / 2 - y;
			pair<long long, long long> ret = {0, 0};
			if (sum > n) {
				first -= m;
				last = first + m - 1;
				sum = (first + first + m - 1) * m / 2;
				turns--;
				return make_pair(sum, turns);
			}
			if (sum <= n) {
				ret = max(ret, make_pair(sum, turns));
			}
			first += m + 1;
			last = first + m - 1;
			turns++;
			sum = (first + first + m - 1) * m / 2;
			if (sum <= n) {
				ret = max(ret, make_pair(sum, turns));
			}
			if (x > last) {
				long long nturns = (x - 1 - last) / m;
				first += nturns * m;
				last += nturns * m;
				turns += nturns;
				sum += m * m * nturns;
				ret = max(ret, make_pair(sum, turns));
			}
			first += m;
			last += m;
			turns++;
			sum += m * m;
			if (sum <= n) {
				ret = max(ret, make_pair(sum, turns));
			}
			return ret;
		};
		auto ret = solve(n, m);
		if (ret.first == n) {
			cout << ret.second * (m + 1) << "\n";
		} else {
			if ((n - ret.second) % m == 0) {
				cout << ((n - ret.second) / m - 1) * (m + 1) + m << "\n";
			} else {
				cout << (n - ret.second) / m * (m + 1) + (n - ret.second) % m << "\n";
			}
		}
	}
	return 0;
}