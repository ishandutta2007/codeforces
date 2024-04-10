#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int S = 22007, T = 107;

int dp[T][S];
int dp2[T][S];

const int INF = 1e9;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int> > v(n);
	for (auto &x : v) {
		cin >> x.x >> x.y;
		x.x *= 2, x.y *= 2;
	}

	for (int i = 0; i < T; ++i) {
		for (int j = 0; j < S; ++j) {
			dp[i][j] = -INF;
			dp2[i][j] = -INF;
		}
	}

	dp[0][0] = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			for (int e = 0; e <= 200*i; ++e) {
				dp2[j][e] = -INF;
			}
		}

		for (int j = 0; j <= i; ++j) {
			for (int e = 0; e <= 200*i; ++e) {
				dp2[j][e] = max(dp2[j][e], dp[j][e] + v[i].y / 2);
				dp2[j+1][min(S-1, e + v[i].x)] = max(dp2[j+1][min(S-1, e + v[i].x)], dp[j][e] + v[i].y);
			}
		}

		for (int j = 0; j <= (i+1); ++j) {
			for (int e = 0; e <= 200*(i+1); ++e) {
				dp[j][e] = dp2[j][e];
			}
		}
	}

	vector<int> ans(n, -INF);
	for (int j = 1; j <= n; ++j) {
		for (int k = 0; k < S; ++k) {
			ans[j - 1] = max(ans[j - 1], min(k, dp[j][k]));
		}
	}

	cout.precision(14);

	for (auto x : ans) {
		cout << fixed << (db) (x) / 2. << " ";
	}



}