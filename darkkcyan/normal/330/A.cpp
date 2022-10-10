#include <iostream>
using namespace std;

int main() {
	int m, n; cin >> m >> n;
	int a[m] = {0};
	int b[n] = {0};
	for (int i = 0; i < m; ++i) {
		for (int f = 0; f < n; ++f) {
			char s; cin >> ws >> s;
			if (s == 'S') a[i] = 1, b[f] = 1;
		}
	}
	int ans = 0;
	int t = m;
	for (int i = 0; i < m; ++i) ans += !a[i] * n, t -= !a[i];
	for (int i = 0; i < n; ++i) ans += !b[i] * t;
	cout << ans;
	return 0;
}