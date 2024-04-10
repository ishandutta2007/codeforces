/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 701;
bool ok[N][N], dp[N][N][2];
int a[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (__gcd(a[i], a[j]) == 1)
				ok[i][j] = false;
			else
				ok[i][j] = true;
		}
	}
	for (int l = n; l >= 0; l--) {
		for (int r = l; r <= n; r++) {
			for (int i = 0; i < 2; i++) {
				if (l == r) {
					dp[l][r][i] = true;
//					cout << l << ' ' << r << ' ';
//					cout << dp[l][r][i] << '\n';
					continue;
				}
				bool f = false;
				for (int k = l; k < r; k++) {
					if ((l == 0 && i == 0) || (r == n && i == 1) || (ok[k][(i == 0 ? l - 1 : r)])) {
//						cout << k << '\n';
						f |= (dp[l][k][1] && dp[k + 1][r][0]);
					}
				}
				dp[l][r][i] = f;
//				cout << l << ' ' << r << ' ' << f << ' ';
//				cout << dp[l][r][i] << '\n';
			}
		}
	}
	cout << (dp[0][n][0] ? "Yes" : "No");
}