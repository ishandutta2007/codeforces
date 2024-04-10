#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	vector<int> a(n, 0);
	int cnt = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int cur = min(cnt, a[i] / 2);
		a[i] -= 2 * cur;
		ans += cur;
		cnt -= cur;
		ans += a[i] / 3;
		a[i] %= 3;
		cnt += a[i];
	}
	cout << ans << endl;
	return 0;
}