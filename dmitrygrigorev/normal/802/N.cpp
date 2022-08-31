#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

pair<ll, int> dp[2500][2500];

pair<ll, int> solve(vector<ll> &a, vector<ll> &b, ll fine) {
	int n = a.size();
	for (int i = 0; i <= n; ++i) for (int j = 0; j <= n; ++j) dp[i][j] = {-1e18, 1e9};
	for (int i = 0; i <= n; ++i) dp[0][i] = {0, 0};
	pair<ll, int> ans = {0, 0};

	for (int i = 0; i < n; ++i) {
		pair<ll, int> tut = {0, 0};

		dp[i+1][0] = dp[i][0];
		for (int j = 0; j < n; ++j) {
			dp[i+1][j+1] = dp[i][j+1];
			if (j >= i) {
				pair<ll, int> var = tut;
				if (a[i] + b[j] + fine > 0) {
					var.first += a[i] + b[j] + fine;
					var.second--;
				}

				dp[i+1][j+1] = max(dp[i+1][j+1], var);
				ans = max(ans, dp[i+1][j+1]);
			}
			tut = max(tut, dp[i][j+1]);
		}
	}


	return ans;
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<ll> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]*=-1;
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		b[i] *= -1;
	}

	ll L = -2000000007, R = 2000000007;
	ll profit = 0;

	while (R-L>1) {
		ll M = (L+R)/2;
		pair<ll, int> ans = solve(a, b, M);
		//cout << M << " " << ans.first << " " << -ans.second << endl;
		if (-ans.second <= k) {
			L = M;
			profit = ans.first;
		}
		else R = M;
	}

	cout << -(profit - L * k);

}