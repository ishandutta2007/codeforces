#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<int> diffs;
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i - 1])
			diffs.push_back(i);
	}
	if (diffs.size() <= 1)
		return 0;
	return max(diffs.back() - diffs.front() - 1, 1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cout << solve() << "\n";
	}
}