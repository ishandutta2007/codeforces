#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n];
	long long s = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s += a[i];
	}
	long long ans = s;
	sort(a, a + n);
	for (int i = 0; i < n - 1; ++i) {
		s -= a[i];
		ans += a[i] + s;
	}
	cout << ans;
	return 0;
}