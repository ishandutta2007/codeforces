#include <bits/stdc++.h>
using namespace std;

#define long long long
#define ve vector
#define ii pair<int, int>
#define ll pair<long, long>
#define sz(v) ((int) (v).size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define xx first
#define yy second
#define pb push_back

#define maxm 111
#define maxs 999
int dp[maxm][maxs] = {0};

int main() {
	int m, s; cin >> m >> s;
	if (s == 0) {
		if (m == 1) cout << "0 0";
		else cout << "-1 -1";
		return 0;
	}
	if (m * 9 < s) {
		cout << "-1 -1";
		return 0;
	}
	
	for (int i = 0; i < 10; ++i) dp[1][i] |= 1 << i;
	for (int i = 2; i <= m; ++i) {
		for (int k = 0; k <= s; ++k) {
			for (int f = 0; f < 10; ++f) {
				if (k - f < 0) continue;
				if (dp[i - 1][k - f] > 0) dp[i][k] |= 1 << f;
			}
		}
	}
	
	int i;
	for (i = 1; i < 10 and !((dp[m][s] >>i) & 1); ++i);
	cout << i;
	for (int n = m - 1, x = s - i; n; --n, x -= i) {
		for (i = 0; i < 10 and !((dp[n][x] >> i) & 1); ++i);
		cout << i;
	}
	cout << ' ';
	for (int n = m, x = s; n; --n, x -= i) {
		for (i = 9; i >= 0 and !((dp[n][x] >> i) & 1); --i);
		cout << i;
	}
	
	return 0;
}