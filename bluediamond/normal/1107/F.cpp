#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

#define int long long

struct T {
	int a, b, k;
};

bool operator < (T f, T s) {
	return f.b > s.b;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	vector<T> v(n);
	for (auto& x : v) {
		cin >> x.a >> x.b >> x.k;
	}
	sort(v.begin(), v.end());

	vector<int> dp(n + 7, 0);
	for (auto& x : v) {
		for (int i = n; i >= 0; i--) {
			dp[i + 1] = max(dp[i + 1], dp[i] + x.a - x.b * i);
			dp[i] = max(dp[i], dp[i] + x.a - x.b * x.k);
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << "\n";
}