/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int ans[N][N];

void solve() {
	int n;
	cin >> n;
	if (n == 2) {
		cout << -1 << '\n';
		return;
	}
	int x = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {	
			if ((i + j) % 2 == 0) {
				ans[i][j] = x;
				x++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {	
			if ((i + j) % 2) {
				ans[i][j] = x;
				x++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {	
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}