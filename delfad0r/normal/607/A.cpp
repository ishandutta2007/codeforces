#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int N;
ii X[100100];
int dp[100100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for(int n = 0; n < N; ++n)
		cin >> X[n].first >> X[n].second;
	
	sort(X, X + N);
	for(int n = 1; n < N; ++n) {
		int p = lower_bound(X, X + n, ii(X[n].first - X[n].second, 0)) - X - 1;
		dp[n] = n - p - 1;
		if(p >= 0) dp[n] += dp[p];
	}
	
	int ans = N;
	for(int n = 0; n < N; ++n)
		ans = min(ans, N - 1 - n + dp[n]);
	cout << ans << '\n';
}