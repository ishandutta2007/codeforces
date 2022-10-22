/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 1023;
pair <int, int> dp[N][N][2][2][2];

int ans(int a, int b, int c, int h, int l) {
	if (a >= N || b >= N || c >= 2) {
		return 0;
	}
	if (a < 0 || b < 0 || c < 0) {
		return 0;
	}
	if (a == 0 && b == 0 && c == 0) {
		return 0;
	}
	if (dp[a][b][c][h][l].F != -1) {
		return dp[a][b][c][h][l].F;
	}
	int mn = INT_MAX;
	mn = min(mn, (2 * a + b + c) - ans(a - 1, b + 1, c, 1 - h, 1));
	mn = min(mn, (2 * a + b + c) - ans(a, b - 1, c,  1 - h, 1));
	mn = min(mn, (2 * a + b + c) - ans(a, b, c - 1, 1 - h, 1));
	if (l != 0 && b != 0) {
		mn = min(mn, (2 * a + b + c) - ans(a, b, c, 1 - h, 0));
	}
	return dp[a][b][c][h][l].F = mn;
}

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int a = 0, b = 0, c = 0;
	if (n % 2 && s[n / 2] == '0')
		c++;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] == '0' && s[n - i - 1] == '0')
			a++;
		else if (s[i] == '0' || s[n - i - 1] == '0')
			b++;
	}
	pair <int, int> x = dp[a][b][c][0][1];
	x.S = (2 * a + b + c) - x.F;
	if (x.F == x.S) {
		cout << "DRAW\n";
	} else {
		cout << (x.F < x.S ? "ALICE\n" : "BOB\n"); 
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					dp[i][j][0][k][l].F = -1;
					dp[i][j][1][k][l].F = -1;
				}
			}
		}
	}
	ans(N - 1, N - 1, 1,  0, 1);
	ans(N - 1, N - 1, 0,  0, 1);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}