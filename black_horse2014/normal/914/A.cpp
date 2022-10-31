#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	int ans = -1e7;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		if (x < 0) ans = max(ans, x);
		else {
			int y = sqrt(x);
			if (y * y != x) ans = max(ans, x);
		}
	}
	cout << ans << endl;
	return 0;
}