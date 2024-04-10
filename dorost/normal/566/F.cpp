/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012345;
int a[N], dp[N], cnt[N];

int ans(int x) {
	if (dp[x] != -1)
		return dp[x];
	int mx = 0;
	for (int i = x * 2; i <= N; i += x) {
		mx = max(mx, ans(i));
	}
	return dp[x] = mx + cnt[x];
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 0; i < N; i++) {
		dp[i] = -1;
	}
	cout << ans(1);
}