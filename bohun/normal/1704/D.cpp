#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;

int n, m;

void solve() {
	cin >> n >> m;
	pair<ll, ll> mn = {1e18, 0};
	pair<ll, ll> mx = {-1e18, 0};
	rep(i, 1, n) {
		ll h = 0;
		rep(j, 1, m) {
			ll x;
			cin >> x;
			h += j * x;
		}
		mn = min(mn, {h, i});
		mx = max(mx, {h, i});
	}
	cout << mx.second << " " << mx.first - mn.first << "\n";
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