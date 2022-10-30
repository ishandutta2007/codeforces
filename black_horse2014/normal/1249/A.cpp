#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n; cin >> n;
		vector<int> a(n), chk(n, 0);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (chk[i]) continue;
			int cur = a[i];
			chk[i] = 1;
			for (int j = i + 1; j < n; j++) {
				if (chk[j]) continue;
				if (a[j] - cur == 1) continue;
				chk[j] = 1;
				cur = a[j];
			}
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}