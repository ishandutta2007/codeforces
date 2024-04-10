/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 20, INF = 1000 * 1000 * 1000;
int dp[(1 << N)];
int a[N][N];
string s[N];
vector <pair <int, int>> c;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int j = 0; j < m; j++) {
		for (char ch = 'a'; ch <= 'z'; ch++) {
			int mask = 0;
			int sum = 0, mx = 0;
			for (int i = 0; i < n; i++) {
				if (s[i][j] == ch) {
					mask += (1 << i);
					sum += a[i][j];
					mx = max(mx, a[i][j]);
				}
			}
			c.push_back({mask, sum - mx});
		}
		for (int i = 0; i < n; i++) {
			c.push_back({(1 << i), a[i][j]});
		}
	}
	for (int i = 1; i < (1 << n); i++) {
		dp[i] = INF;
		for (pair <int, int> p : c) {
			int wef = p.F;
			wef = ((1 << n) - 1) - wef;
			dp[i] = min(dp[i], dp[i & wef] + p.S);
		}
	}
	cout << dp[(1 << n) - 1];
}