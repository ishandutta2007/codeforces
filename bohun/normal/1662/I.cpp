#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define cat(x) cout << #x << ": " << x << endl

using ll = long long;
using namespace std;

const int N = 400400;

int n, m; 
ll p[N], a[N];
vector<pair<ll, ll>> v;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	rep(i, 1, n) cin >> p[i];
	rep(i, 1, m) cin >> a[i];
	sort(a + 1, a + m + 1);
	a[0] = -1e18;
	a[m + 1] = 1e18;
	rep(i, 1, n) {
		int P = 100 * (i - 1);
		int y = lower_bound(a + 1, a + m + 1, P) - a;
		ll x = min(a[y] - P, P - a[y - 1]);
		v.push_back({P - x, p[i]});
		v.push_back({P + x, -p[i]});
	}

	sort(v.begin(), v.end());
	
	ll res = 0, s = 0;
	for (auto [x, d] : v) {
		s += d;
		res = max(res, s);
	}
	cout << res << "\n";
	return 0;
}