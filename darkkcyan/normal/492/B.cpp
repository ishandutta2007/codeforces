#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, l; cin >> n >> l;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	float ans = max(a[0], l - a[n - 1]);
	for (int i = 1; i < n; ++i) ans = max(ans, (a[i] - a[i - 1]) / 2.0f);
	cout << fixed << ans;
	return 0;
}