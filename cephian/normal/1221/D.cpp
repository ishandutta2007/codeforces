#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5+5;
ll dp[N][3];
int a[N], b[N];
ll INF = 1LL<<50;

void solve() {
	int n;
	cin >> n;
	a[0] = -1;
	for(int i = 0; i < 3; ++i)
		dp[0][i] = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		for(int j = 0; j < 3; ++j)
			dp[i][j] = INF;
		for(int j = 0; j < 3; ++j) {
			for(int k = 0; k < 3; ++k) {
				if(a[i-1]+j == a[i]+k) continue;
				dp[i][k] = min(dp[i][k], dp[i-1][j] + b[i]*k);
			}
		}
	}
	ll ans = INF;
	for(int i = 0; i < 3; ++i)
		ans = min(ans, dp[n][i]);
	cout << ans << '\n';
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		solve();
	}
}