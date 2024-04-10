#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	int s = accumulate(a, a + n, 0);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int c = s;
		for (int k = i; k < n; ++k) {
			c += a[k] ? -1 : 1;
			ans = max(ans, c);
		}
	}
	cout << ans;
	return 0;
}