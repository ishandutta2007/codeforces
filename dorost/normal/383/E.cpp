/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = (1 << 24);
int32_t dp[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int a = (1 << 24) - 1;
		for (int j = 0; j < 3; j++) {
			int wef = (1 << (s[j] - 'a'));
			wef = ((1 << 24) - 1) - wef;
			a &= wef;
		}
		dp[a]++;
	}
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < (1 << 24); j++) {
			if (!((j >> i) & 1)) {
				dp[j] += dp[j + (1 << i)];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << 24); i++) {
		dp[i] = n - dp[i];
		int wef = dp[i];
		wef = wef * wef;
		ans ^= wef;
	}
	cout << ans;
}