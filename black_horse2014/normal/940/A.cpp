#include <bits/stdc++.h>
using namespace std;

int a[111];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, d; cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = n - 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (a[j] - a[i] > d) break;
			ans = min(ans, i - 1 + n - j);
		}
	}
	cout << ans << endl;
	return 0;
}