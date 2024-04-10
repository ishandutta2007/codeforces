#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	int x = min_element(a, a + n) - a;
	int y = max_element(a, a + n) - a;
	if (x == 0 or y == 0 or x == n - 1 or y == n - 1) return cout << (n - 1), 0;
	vector<int> ans {x, y, n - x - 1, n - y - 1};
	cout << *max_element(ans.begin(), ans.end());
	return 0;
}