/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
int a[N];
pair <int, int> mx[N];
vector <int> v[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		v[i].clear();
		mx[i].F = mx[i].S = 0;
	}
	mx[n].S = mx[n].F = 0;
	for (int i = 0; i < n; i++) {
		v[i].push_back(-1);
	}
	for (int i = 0; i < n; i++) {
		v[a[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		v[i].push_back(n);
	}
	for (int i = 0; i < n; i++) {
		if (v[i].size() == 0)
			continue;
		for (int j = 1; j < v[i].size(); j++) {
			mx[i].F = max(mx[i].F, v[i][j] - v[i][j - 1]);
		}
		mx[i].S = i + 1;
	}
	sort(mx, mx + n);
	int x = INT_MAX;
	for (int k = 1; k <= n; k++) {
		pair <int, int> p = {k, -1};
		pair <int, int> an = (*upper_bound(mx, mx + n, p));
		int ans = an.S;
		int d = an.F;
		int all = (d == k ? (ans == 0 ? INT_MAX : ans) : INT_MAX);
		int b = min(all, x);
		cout << (b == INT_MAX ? -1 : b) << ' ';
		x = b;
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}