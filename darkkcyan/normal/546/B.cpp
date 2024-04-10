#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	long long ans = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] < a[i - 1] + 1) {
			ans += a[i - 1] + 1 - a[i];
			a[i] = a[i - 1] + 1;
		}
	}
	cout << ans;
	return 0;
}