/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 207;
int r[N], g[N], b[N], dp[N][N][N];

void solve() {
	int nr, ng, nb;
	cin >> nr >> ng >> nb;
	for (int i = 0; i < nr; i++)
		cin >> r[i];
	for (int i = 0; i < ng; i++)
		cin >> g[i];
	for (int i = 0; i < nb; i++)
		cin >> b[i];
	sort(r, r + nr);
	sort(g, g + ng);
	sort(b, b + nb);
	for (int i = 0; i <= nr; i++) {
		for (int j = 0; j <= ng; j++) {
			for (int k = 0; k <= nb; k++) {
				int dpans = 0;
				if (i && j)
					dpans = max(dp[i - 1][j - 1][k] + (r[i - 1] * g[j - 1]), dpans);
				if (j && k)
					dpans = max(dp[i][j - 1][k - 1] + (g[j - 1] * b[k - 1]), dpans);
				if (i && k)
					dpans = max(dp[i - 1][j][k - 1] + (r[i - 1] * b[k - 1]), dpans);
				dp[i][j][k] = dpans;
			}
		}
	}
	cout << dp[nr][ng][nb];
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}