#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << ": " << x << endl

using ll = long long;
using namespace std;

const int N = 1 << 20;
int n, a[N], b[N], vis[N];

void solve() {
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) {
		int x;
		cin >> x;
		b[x] = i;
	}
	rep(i, 1, n) vis[i] = 0;
	int odd = 0;
	rep(i, 1, n) {
		if (vis[i]) continue;
		int x = i;
		int sz = 0;
		while (vis[x] == 0) {
			vis[x] = 1;
			sz++;
			x = b[a[x]];
		}
		if (sz % 2) odd++;
	}
	ll res = 0;
	rep(i, 1, (n - odd) / 2) {
		res += 2 * (n - i + 1 - i);
	}
	cout << res << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}