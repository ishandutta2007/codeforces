#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	pair<int, int> a[n];
	for (int i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i + 1;
	sort(a, a + n);
	for (int i = 0, f = n - 1; i < f; ++i, --f) {
		cout << a[i].second << ' ' << a[f].second << endl;
	}
	return 0;
}