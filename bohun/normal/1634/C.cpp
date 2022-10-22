#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

int t, n, k;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (k >= 2 && n % 2) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		rep(i, 0, n / 2 - 1) {
			rep(j, 1, k) cout << 2 * (k * i + j) << " "; cout << endl;
			rep(j, 1, k) cout << 2 * (k * i + j) - 1 << " "; cout << endl;
		}

		if (k == 1 && n % 2 == 1)
			cout << n << endl;
	}

	return 0;
}