#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	long long ans = 0;
	long long not_yet_multiplied = 0;
	long long yet_multiplied_but_currently_not = 0;
	long long currently_multiplied = 0;
	for (int i = 0; i < n; i++) {
		long long x; cin >> x;
		yet_multiplied_but_currently_not = max(max(yet_multiplied_but_currently_not, currently_multiplied) + x, 0LL);
		currently_multiplied = max(max(currently_multiplied, not_yet_multiplied) + m * x, 0LL);
		not_yet_multiplied = max(not_yet_multiplied + x, 0LL);
		ans = max(ans, not_yet_multiplied);
		ans = max(ans, yet_multiplied_but_currently_not);
		ans = max(ans, currently_multiplied);
	}
	cout << ans << endl;
	return 0;
}