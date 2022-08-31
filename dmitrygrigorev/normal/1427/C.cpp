#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int STEP = 1007;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int r, n;
	cin >> r >> n;

	vector<tuple<int, int, int> > arr(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> get<0>(arr[i]) >> get<1>(arr[i]) >> get<2>(arr[i]);
	}

	arr[0] = make_tuple(0, 1, 1);

	vector<int> dp(n + 1);
	dp[0] = 0;

	int cur_mx = -1e9;

	for (int i = 1; i <= n; ++i) {
		if (i - STEP >= 0) cur_mx = max(cur_mx, dp[i - STEP]);
		dp[i] = cur_mx + 1;

		for (int j = 1; j < STEP; ++j) {
			if (i - j >= 0) {
				int need = abs(get<2>(arr[i]) - get<2>(arr[i - j])) + abs(get<1>(arr[i]) - get<1>(arr[i - j]));
				int req = abs(get<0>(arr[i]) - get<0>(arr[i - j]));

				if (need <= req) {
					dp[i] = max(dp[i], dp[i - j] + 1);
				}

			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]);

	cout << ans;

}