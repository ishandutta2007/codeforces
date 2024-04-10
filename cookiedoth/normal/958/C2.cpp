/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;

const int INF = 1e9;
const int mx1 = 2e4 + 228;
const int mx2 = 55;
const int mx3 = 105;
int n, k, p, a[mx1], dp[mx1][mx2 + 1], max_dp[mx2 + 1][mx3], pref[mx1];

int main() {
	cin >> n >> k >> p;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	pref[0] = a[0] % p;
	for (int i = 1; i < n; ++i) {
		pref[i] = (pref[i - 1] + a[i]) % p;
	}
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j < p; ++j) {
			max_dp[i][j] = -INF;
		}
	}
	max_dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[i][j] = -INF;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int x = 0; x < p; ++x) {
			int add = (pref[i] - x + p) % p;
			for (int j = 1; j <= k; ++j) {
				dp[i][j] = max(dp[i][j], max_dp[j - 1][x] + add);
			}
		}
		for (int j = 0; j <= k; ++j) {
			max_dp[j][pref[i]] = max(max_dp[j][pref[i]], dp[i][j]);
		}
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dp[n - 1][k] << endl;
}