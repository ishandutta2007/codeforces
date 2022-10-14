#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n);
		for (int ii = 0, i = n - 1 >> 1, j = i + 1; ii < n; ++ii)
			cout << (ii & 1 ? a[j++] : a[i--]) << ' ';
		cout << '\n';
	}
}