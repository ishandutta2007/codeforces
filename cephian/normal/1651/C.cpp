#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+5;
int n;
ll ans;
ll a[N][2];

ll dist(ll x, bool w) {
	ll ans = 2e9;
	for(int i = 0; i < n; ++i)
		ans = min(ans, abs(a[i][w] - x));
	return ans;
}

inline void maybe(ll& ans, ll x) {
	if(x < ans)
		ans = x;
}

void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i][0];
	for(int i = 0; i < n; ++i)
		cin >> a[i][1];

	ll as = a[0][0], ae = a[n-1][0];
	ll bs = a[0][1], be = a[n-1][1];

	ll asd = dist(as, 1);
	ll aed = dist(ae, 1);
	ll bsd = dist(bs, 0);
	ll bed = dist(be, 0);

	ll ans = 1LL<<60;
	maybe(ans, abs(as-bs) + abs(ae-be));
	maybe(ans, abs(as-be) + abs(ae-bs));

	maybe(ans, abs(as-bs) + aed + bed);
	maybe(ans, abs(as-be) + aed + bsd);
	maybe(ans, abs(ae-bs) + asd + bed);
	maybe(ans, abs(ae-be) + asd + bsd);

	maybe(ans, asd + aed + bsd + bed);

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}