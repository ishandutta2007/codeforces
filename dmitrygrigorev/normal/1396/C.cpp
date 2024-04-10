#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1000007;
int dp[N][4];

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	vector<int> v(n);
	for (auto &x : v) cin >> x;

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < 4; ++j) dp[i][j] = 1e18;
	}

	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		int full_cost = v[i] * a + c;
		int only_boss = min(b, v[i] * a + a) + a;

		int R = 1e18;
		if (i > 0) R = d;

		int Q = 0;
		if (i > 0) Q = d;

		dp[i + 1][0] = min(dp[i+1][0], dp[i][0] + full_cost + Q);
		dp[i + 1][1] = min(dp[i+1][1], dp[i][0] + only_boss + (2*d * (i+1 == n)) + Q);
		dp[i + 1][0] = min(dp[i+1][0], dp[i][0] + only_boss + Q + 2*R);

		dp[i + 1][2] = min(dp[i+1][2], min(dp[i][1], dp[i][2]) + min(full_cost, only_boss + (2*d * (i+1 == n))) + Q + 2*R);
		dp[i + 1][3] = min(dp[i+1][3], min(dp[i][1], dp[i][3]) + min(full_cost, only_boss + (2*d * (i+1 == n))) + Q + R);
		dp[i + 1][0] = min(dp[i+1][0], dp[i][1] + Q + only_boss + 2*R);

		dp[i+1][0] = min(dp[i+1][0], dp[i+1][2]);

		//cout << full_cost << " " << only_boss << endl;
		//cout << dp[i+1][0] << " " << dp[i+1][1] << " " << dp[i+1][2] << " " << dp[i+1][3] << endl;

	}

	cout << min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]});

}