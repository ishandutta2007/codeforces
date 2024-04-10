/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 505;
int a[N], ans[N][N];
int n;

bool ok(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	if (ans[x][y])
		return false;
	return true;
}

int32_t main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		ans[i][i] = a[i];
		int x = i, y = i;
		for (int j = 1; j < a[i]; j++) {
			if (ok(x, y - 1)) {
				y--;
				ans[x][y] = a[i];
			} else if (ok(x + 1, y)) {
				x++;
				ans[x][y] = a[i];
			} else {
				cout << -1;
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}