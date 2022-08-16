/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e2 + 10;

bool a[N][3], seen[N][2][2];
int dp[N][2][2];

int solve(int n, bool up, bool dn);

int main() {
	int n;
	for (int i = 1; i <= 2; ++i) {
		string s; cin >> s;
		n = s.length();
		for (int j = 1; j <= n; ++j) {
			a[j][i] = (s[j - 1] == 'X');
		}
	}
	// for (int i = 1; i <= n; ++i) {
	// 	cout << solve(i, 0, 0) << ' ' << solve(i, 1, 0) << ' ' << solve(i, 0, 1) << endl;
	// }
	cout << solve(n, 0, 0);
}

int solve(int n, bool up, bool dn) {
	if (n <= 1) {
		return 0;
	} else if (seen[n][up][dn]) {
		return dp[n][up][dn];
	} else {
		seen[n][up][dn] = true;
		int ans = solve(n - 1, 0, 0);
		if (!up and !dn and !a[n][1] and !a[n][2]) {
			if (!a[n - 1][1]) {
				ans = max(ans, 1 + solve(n - 1, 1, 0));
			}
			if (!a[n - 1][2]) {
				ans = max(ans, 1 + solve(n - 1, 0, 1));
			}
		}
		if (!a[n - 1][1] and !a[n - 1][2]) {
			if ((!up and !a[n][1]) or (!dn and !a[n][2])) {
				ans = max(ans, 1 + solve(n - 2, 0, 0));
			}
		}
		dp[n][up][dn] = ans;
		return ans;
	}
}