/* 	* In the name of GOD 
 	* Thanks God */
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 1012, M = 1000 * 1000 * 1000 + 7;
int a[26], dp[N], psdp[N], b[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < 26; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int mn = INT_MAX, x = i;
		for (int j = i; j < n; j++) {
			mn = min(mn, a[s[j] - 'a']);
			if (j >= i + mn) {
				x = j - 1;
				break;
			}
			x = j;
		}
		b[i] = x - i + 1;
	}
	dp[n + 1] = 0;
	psdp[n + 1] = 0;
	dp[n] = 1;
	psdp[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		dp[i] = (psdp[i + 1] - psdp[i + b[i] + 1]) % M;
		if (dp[i] < 0)
			dp[i] += M;
		dp[i] %= M;
		psdp[i] = psdp[i + 1] + dp[i];
		psdp[i] %= M;
	}
	int x = 0, y = 0;
	while (x != n) {
		x = x + b[x];
		y++;
	}
	cout << dp[0] << '\n' << *max_element(b, b + n) << '\n' << y;
}