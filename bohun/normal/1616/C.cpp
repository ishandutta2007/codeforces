#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &x : a)
			cin >> x;

		int res = n - 1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int good = 0;
				for (int k = 0; k < n; k++)
					good += a[k] == (a[i] + (double)(k - i) * (a[j] - a[i]) / (j - i));
				res = min(res, n - good);
			}
		}

		cout << res << '\n';
	}
	return 0;
}