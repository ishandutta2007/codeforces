/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
vector <int> cnt[N];
int a[N], ans[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= n + 2; i++) {
		cnt[i].clear();
		ans[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cnt[a[i]].push_back(i);
	}
	int x = 0, y = 0;
	vector <int> v;
	for (int i = 0; i <= n; i++) {
		x = min(k, (int)cnt[i].size());
		if (x == 0)
			continue;
		for (int j = 0; j < x; j++) {
			ans[cnt[i][j]] = y + 1;
			v.push_back(cnt[i][j]);
			y++;
			y %= k;
		}
	}
	for (int i = v.size() - 1; i >= v.size() - y; i--) {
		ans[v[i]] = 0;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}