/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	map <int, int> cnt;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for (auto x : cnt) {
		if (cnt[x.F] < 2)
			continue;
		cnt[x.F + 1] += (cnt[x.F] / 2);
		cnt[x.F] -= (cnt[x.F] / 2) * 2;
	}
	int mx = 0, cnt2 = 0;
	for (auto x : cnt) {
		mx = max(mx, x.F);
		if (cnt[x.F])
			cnt2++;
	}
	cout << mx - cnt2 + 1;
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}