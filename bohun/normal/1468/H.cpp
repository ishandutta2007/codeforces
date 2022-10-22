#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int n, k, m, b[200200];

void solve() {
	cin >> n >> k >> m;
	k = (k - 1) / 2;

	fill(b, b + n + 1, 0);
	rep(i, 0, m) {
		int a;
		cin >> a;
		b[a] = 1;
	}

	rep(i, 1, n)
		b[i] = !b[i] + b[i - 1];

	int cnt = n - m;

	if (cnt % (2 * k)) {
		cout << "NO\n";
		return;
	}

	rep(i, 1, n)
		if (b[i - 1] == b[i]) {
			if (cnt == 2 * k) {
				if (b[i] == k) {
					cout << "YES\n";
					return;
				}
			}
			else {
				if (b[i] >= k && cnt - b[i] >= k) {
					cout << "YES\n";
					return;
				}
			}
		}
	cout << "NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}