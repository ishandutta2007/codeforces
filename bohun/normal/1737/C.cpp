#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	int corner = 0;

	map<int, int> x, y;
	rep(i, 1, 3) {
		int X, Y;
		cin >> X >> Y;
		x[X]++;
		y[Y]++;
		corner += min(X - 1, n - X);
		corner += min(Y - 1, n - Y);
	}

	int xe, ye;
	cin >> xe >> ye;

	if (x[xe] == 2 || y[ye] == 2) {
		cout << "YES\n";
		return;
	}

	if (corner == 2) {
		cout << "NO\n";
		return;
	}

	for (auto [k, v] : x) {
		if (v == 2 && k % 2 == xe % 2) {
			cout << "YES\n";
			return;
		}
	}
	
	for (auto [k, v] : y) {
		if (v == 2 && k % 2 == ye % 2) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) solve();

	return 0;
}