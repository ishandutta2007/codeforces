/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, k;
	cin >> n >> k;
	int fst = -1, lst = -1;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			if (i == 0)
				ans += 10;
			else if (i == n - 1)
				ans++;
			else
				ans += 11;
			if (fst == -1)
				fst = i;
			lst = i;
		}
	}
	if (fst != -1) {
		if (fst == lst) {
			if (lst != n - 1 && (n - 1) - lst <= k) {
				if (lst == 0) {
					ans++;
				}
				ans -= 10;
			} else if (fst != 0 && fst != n - 1 && fst <= k) {
				ans--;			
			}
		} else {
			if (lst != n - 1 && (n - 1) - lst <= k) {
				ans -= 10;
				k -= (n - 1) - lst;
			}
			if (fst != 0 && fst <= k) {
				ans--;
			}
		}
	}
	cout << ans << '\n';
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