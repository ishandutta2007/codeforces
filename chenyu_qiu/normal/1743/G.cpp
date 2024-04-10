#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
inline int add(int x, int y) {
	return (x += y) >= P ? (x - P) : x;
}
inline int sub(int x, int y) {
	return (x -= y) < 0 ? (x + P) : x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> f{1, 1};
	while (f.back() <= 3000000) {
		f.push_back(f[f.size() - 2] + f[f.size() - 1]);
	}

	auto get = [&](int x) {
		for (int i = f.size() - 1; i > 1; --i) {
			if (x > f[i]) {
				x -= f[i];
			}
		}
		return x == 2 ? 0 : 1;
	};

	auto check = [&](int x) {
		return *lower_bound(f.begin(), f.end(), x) == x;
	};

	vector<pair<int, int>> dp{{0, 1}};
	int sum = 1;

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		for (auto c : s) {
			int x = c - '0';
			vector<pair<int, int>> ndp;

			int cur = sum;
			for (auto it : dp) {
				int len = it.first + 1;
				int val = it.second;

				if (get(len) == x) {
					ndp.emplace_back(len, val);
					if (check(len)) {
						cur = sub(cur, val);
					}
				} else if (len == 1) {
					cur = sub(cur, val);
				}
			}

			dp = ndp;
			dp.emplace_back(0, cur);
			sum = add(sum, cur);
		}

		for (auto it : dp) {
			if (it.first == 0) {
				cout << it.second << "\n";
			}
		}
	}

	return 0;
}