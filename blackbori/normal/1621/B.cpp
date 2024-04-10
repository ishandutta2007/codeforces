#include <bits/stdc++.h>

using namespace std;

void tc() {
	int n, i, l, r, c, x, y, xa, ya, za;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> l >> r >> c;
		if (i == 0) x = l, y = r, xa = c, ya = c, za = c;
		else {
			if (x > l) x = l, xa = c, za = 21e8;
			else if (x == l && xa > c) x = l, xa = c;
			if (y < r) y = r, ya = c, za = 21e8;
			else if (y == r && ya > c) y = r, ya = c;
			if (x == l && y == r && za > c) za = c;
		}
		cout << min(xa + ya, za) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	
	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}