#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
typedef long long ll;
using namespace std;
int t, n;
ll a[200005];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int res = 0;
		map<ll, int> dp;
		dp[0] = 0;
		for (int i = 0; i + 1 < n; i++) {
			ll x = abs(a[i] - a[i + 1]);
			map<ll, int> ndp;
			ndp[x] = 1;
			for (auto [a, b] : dp) {
				ll g = __gcd(a, x);
				ndp[g] = max(ndp[g], b + 1);
			}
			dp = ndp;
			for (auto [a, b] : dp)
				if (a > 1)
					res = max(res, b);
		}
		cout << res + 1 << endl;
	}
	return 0;
}