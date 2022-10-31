#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	unsigned long long pw[40];
	for (int i = 0; i < 40; i++) pw[i] = i == 0 ? 1 : pw[i - 1] * 3;
	int ncase;
	for (cin >> ncase; ncase--; ) {
		long long n; cin >> n;
		unsigned long long ans = ULLONG_MAX;
		unsigned long long cur = 0;
		for (int i = 39; i >= 0; i--) {
			if (cur + pw[i] >= n) {
				ans = min(ans, cur + pw[i]);
			} else {
				cur += pw[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}