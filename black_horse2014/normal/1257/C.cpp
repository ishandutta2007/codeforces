#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n; cin >> n;
		map<int, int> H;
		int ans = n + 1;
		for (int j = 0, i = 1; i <= n; i++) {
			int x; cin >> x;
			if (H.count(x)) {
				ans = min(ans, i - H[x] + 1);
			}
			H[x] = i;
		}
		if (ans == n + 1) {
			cout << -1 << '\n';
		} else {
			cout << ans << '\n';
		}
	}
	return 0;
}