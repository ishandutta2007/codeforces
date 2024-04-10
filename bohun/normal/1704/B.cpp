#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;

int n, x, a[200200];

void solve() {
	cin >> n >> x;
	rep(i, 1, n) cin >> a[i];
	int res = 1;
	int mx = -1e9, mn = 1e9;
	rep(i, 1, n) {
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
		if (mx - mn > 2 * x) {
			res++;
			mx = mn = a[i];
		}
	}
	cout << res - 1 << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}