#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	pair<int, int> a[n];
	for (int i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i + 1;
	sort(a, a + n);
	stack<int> ans;
	for (int i = 0; a[i].first <= k; k -= a[i].first, ++i) {
		ans.push(a[i].second);
	}
	cout << ans.size() << '\n';
	for (; ans.size(); ans.pop()) cout << ans.top() << ' ';
	return 0;
}