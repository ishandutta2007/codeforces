#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int P = 998244353;
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<ll> x(n), y(n), s(n);
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i] >> s[i];
	vector<ll> ans(n + 1), dp(n + 1), sum(n + 1);
	for (int i = 0; i < n; i++) {
		int p = lower_bound(x.begin(), x.end(), y[i]) - x.begin();
		dp[i + 1] = (x[i] - y[i] + sum[i] - sum[p] + 2 * P) % P;
		sum[i + 1] = (sum[i] + dp[i + 1]) % P;
		ans[i + 1] = (ans[i] + (x[i] - (i > 0 ? x[i - 1] : 0)) + (s[i] ? dp[i + 1] : 0)) % P;
	}
	cout << (ans[n] + 1) % P << endl;
	return 0;
}