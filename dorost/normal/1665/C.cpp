/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int cnt[N], n;

bool is_valid(int x) {
	if (x == 0)
		return false;
	int a = x, r = x - 1;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0)
			continue;
		if (cnt[i] <= a) {
			a--;
			r--;
			continue;
		}
		int m = ((cnt[i] - a) + 1);
		a--;
		r -= m;
	}
	return (r >= 0);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cnt[i] = 0;
	for (int i = 0; i < n - 1; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	sort(cnt + 1, cnt + n + 1);
	reverse(cnt + 1, cnt + n + 1);
	int l = 0, r = n; 
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r << '\n';
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