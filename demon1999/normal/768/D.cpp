#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const int MAXN = 5 * 100 * 1000,/* ma = 128 * 1024,*/ mod = 1000 * 1000 * 1000 + 7;

int n, k, q;

double dp[20001][1001];

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	dp[0][0] = 2000;
	cin >> k >> q;
	for (int i = 1; i <= 8000; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j] * (double(j) / double(k)) + dp[i - 1][j - 1] * double((k - (j - 1LL))) / double(k);
			//cout << dp[i][j] << " ";
		}
		/*
		if (dp[i][k] > double(1) - 1e-7)
			break;*/
		//cout << "\n";
	}
	forn (i, q) {
		int p;
		cin >> p;
		forn (j, 8001)
			if (dp[j][k] > double(p) - 1e-7) {
				cout << j << "\n";
				break;
			}
	}
}