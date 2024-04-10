#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int dp[107][107][107][2];

int main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);

	int a = n/2, b = n - n/2;
	for (int i = 0; i < n; ++i) cin >> v[i];
	for (int i = 0; i < n; ++i) {
		if (v[i] == 0) continue;
		if (v[i] % 2 == 0) a--;
		else b--;
	}

	for (int i = 0; i < 107; ++i) for (int j = 0; j < 107; ++j) for (int k = 0; k < 107; ++k) for (int e = 0; e < 2; ++e) dp[i][j][k][e] = 1e9;
	dp[0][a][b][0] = 0;
	dp[0][a][b][1] = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 107; ++j) for (int k = 0; k < 107; ++k) for (int e = 0; e < 2; ++e) {
			if (v[i] != 0) {
				dp[i+1][j][k][v[i]%2] = min(dp[i+1][j][k][v[i]%2], dp[i][j][k][e] + (e != (v[i]%2)));
			}
			else{
				if (j > 0) {
					dp[i+1][j-1][k][0] = min(dp[i+1][j-1][k][0], dp[i][j][k][e] + (e != 0));
				}
				if (k > 0) {
					dp[i+1][j][k-1][1] = min(dp[i+1][j][k-1][1], dp[i][j][k][e] + (e != 1));
				}
			}
		}
	}

	cout << min(dp[n][0][0][0], dp[n][0][0][1]);



}