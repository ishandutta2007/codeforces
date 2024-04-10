/* 	* In the name of GOD 
 * Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 105;
int a[N][N], b[N][N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = a[i][j], y = a[i][m - j - 1], z = a[n - i - 1][j], v = a[n - i - 1][m - j - 1], mia = INT_MAX, mn = INT_MAX;
			int sum = (x + y + z + v) / 4;
			for (int k = sum - 20; k <= sum + 20; k++) {
				int fas = abs(x - k) + abs(y - k) + abs(z - k) + abs(v - k);
				if (fas <= mn) {
					mn = fas;
					mia = k;
				}
			}
			sum = x;
			for (int k = sum - 20; k <= sum + 20; k++) {
				int fas = abs(x - k) + abs(y - k) + abs(z - k) + abs(v - k);
				if (fas <= mn) {
					mn = fas;
					mia = k;
				}
			}
			sum = y;
			for (int k = sum - 20; k <= sum + 20; k++) {
				int fas = abs(x - k) + abs(y - k) + abs(z - k) + abs(v - k);
				if (fas <= mn) {
					mn = fas;
					mia = k;
				}
			}
			sum = z;
			for (int k = sum - 20; k <= sum + 20; k++) {
				int fas = abs(x - k) + abs(y - k) + abs(z - k) + abs(v - k);
				if (fas <= mn) {
					mn = fas;
					mia = k;
				}
			}
			sum = v;
			for (int k = sum - 20; k <= sum + 20; k++) {
				int fas = abs(x - k) + abs(y - k) + abs(z - k) + abs(v - k);
				if (fas <= mn) {
					mn = fas;
					mia = k;
				}
			}
			b[i][j] = mia;
			b[i][m - j - 1] = mia;
			b[n - i - 1][j] = mia;
			b[n - i - 1][m - j - 1] = mia;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += (abs(b[i][j] - a[i][j]));
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}