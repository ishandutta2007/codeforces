/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];
map <int, vector <int>> cnt;

void solve() {
	cnt.clear();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], cnt[a[i]].push_back(i);
	int mn = INT_MAX;
	for (auto [x, y] : cnt) {
		int ans = y.size() + 1;
		if (y[0] == 0)
			ans--;
		if (y[y.size() - 1] == n - 1)
			ans--;
		for (int i = 1; i < y.size(); i++) {
			if (y[i] == y[i - 1] + 1)
				ans--;
		}
		if (mn > ans)
			mn = ans;
	}
	cout << mn << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}