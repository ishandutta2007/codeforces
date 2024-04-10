/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int dp[N];
vector <int> a[26];

void solve() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		s[i] -= 'a';
	for (int i = 0; i < 26; i++)
		a[i].clear();
	for (int i = 0; i < s.size(); i++) {
		a[s[i]].push_back(i);
	}
	dp[0] = 0;
	for (int i = 1; i < (int)s.size(); i++) {
		dp[i] = dp[i - 1];
		int in = lower_bound(a[s[i]].begin(), a[s[i]].end(), i) - a[s[i]].begin() - 1;
		if (in == -1)
			continue;
		dp[i] = max(dp[i], (a[s[i]][in] == 0 ? 0 : dp[a[s[i]][in] - 1]) + 2);
	}
	cout << (int)s.size() - dp[(int)s.size() - 1] << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}