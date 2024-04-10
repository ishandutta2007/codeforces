/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 3012;
int a[N], mn[N][N], b[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] -= i;
		b[i] = a[i];
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int dp;
			if (i == 0) {
				dp = abs(a[i] - b[j]);
			} else {
				dp = abs(a[i] - b[j]) + mn[i - 1][j];
			}
			mn[i][j] = (j == 0 ? dp : min(dp, mn[i][j - 1]));
		}
	}
	cout << mn[n - 1][n - 1];
}