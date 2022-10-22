#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << ": " << x << endl

using ll = long long;
using namespace std;

const int N = 1 << 20;
const int P = 998244353;

int n, k, p[N], vis[N];

void solve() {
	cin >> n >> k;
	rep(i, 1, n) cin >> p[i];
	rep(i, 1, n) vis[i] = 0;
	rep(i, 1, n) {
		if (p[i] > 0 && (i + k > n || p[i] + k >= i + k)) {
			cout << 0 << endl;
			return;
		}
		if (p[i] > 0) vis[i + k] = 1;
	}
	ll res = 1;
	rep(i, 1, n) {
		if (p[i] == 0) {
			if (i + k <= n) {
				vis[i + k] = 1;
				res = res * (k + 1) % P;
			}
		}
	}
	rep(i, 1, n) if (!vis[i]) res = res * i % P;
	cout << res << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}