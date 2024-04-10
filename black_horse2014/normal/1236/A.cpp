#include <bits/stdc++.h>
using namespace std;

int main() {
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int a, b, c; cin >> a >> b >> c;
		int ans = 0;
		for (int i = 0; i <= a && i <= b / 2; i++) {
			ans = max(ans, i + min(b - 2 * i, c / 2));
		}
		cout << ans * 3 << endl;
	}
	return 0;
}