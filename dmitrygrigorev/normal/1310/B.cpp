#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int dp[1<<17][2][2];
int dp2[1<<17][2][2];

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<bool> used(1<<n);

	for (int i= 0; i < k; ++i) {
		int x;
		cin >> x;
		used[x-1] = true;
	}	

	if (k == 0) {
		cout << 0;
		exit(0);
	}

	for (int i = 0; i < (1<<n); ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
		dp[i][j][k] = -1e9;
	}

	for (int i = 0; i < (1<<n); i += 2) {
		int A = used[i];
		A += used[i+1];

		if (A == 0) {
			dp[i/2][0][0] = 0;
		}
		else if (A==1) {
			dp[i/2][0][1] = 1, dp[i/2][1][0] = 1;
		}
		else {
			dp[i/2][1][1] = 1;
		}

	}

	for (int step = 4; step <= (1<<n); step *= 2) {
		int tut = 0;
		for (int i = 0; i < (1<<n); i += step) {
			for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) dp2[tut][j][k] = -1e9;

			for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) for (int l = 0; l < 2; ++l) for (int m = 0; m < 2; ++m) {
				int cost = (int) (max(j, k) == 1) + (int) (max(l, m) == 1) + dp[2*tut][j][l] + dp[2*tut+1][k][m];

				dp2[tut][j][l] = max(dp2[tut][j][l], cost + (int) (max(l, k) == 1));
				dp2[tut][j][m] = max(dp2[tut][j][m], cost + (int) (max(m, k) == 1));
				dp2[tut][k][l] = max(dp2[tut][k][l], cost + (int) (max(l, j) == 1));
				dp2[tut][k][m] = max(dp2[tut][k][m], cost + (int) (max(m, j) == 1));
				dp2[tut][j][k] = max(dp2[tut][j][k], cost + (int) (max(max(l, m), k) == 1));
				dp2[tut][k][j] = max(dp2[tut][k][j], cost + (int) (max(max(l, m), j) == 1));
			}
			tut++;
		}
		for (int j = 0; j < tut; ++j) for (int e = 0; e < 2; ++e) for (int f=0; f < 2; ++f) dp[j][e][f] = dp2[j][e][f];
	}

	int ans = 0;
	for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) {
		ans = max(ans, dp[0][i][j] + (int) (max(i, j) == 1));
	}

	cout << ans;

}