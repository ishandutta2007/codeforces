/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234, M = 1000 * 1000 * 1000 + 7;
int a[N], dp[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		vector <int> v;
		for (int j = 1; j * j <= a[i]; j++) {
			if (a[i] % j)
				continue;
			if (j < N) {
				v.push_back(j);
			}
			if (j * j != a[i] && a[i] / j < N) {
				v.push_back(a[i] / j);
			}
		}
		sort(v.begin(), v.end());
		for (int j = v.size() - 1; j >= 0; j--) {
			dp[v[j]] += dp[v[j] - 1];
			dp[v[j]] %= M;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dp[i];
		ans %= M;
	}
	cout << ans << ' ';
}