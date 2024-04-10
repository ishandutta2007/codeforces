/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 25;
int a[N][N];

void solve() {
	int n, m, sum = 0;
	cin >> n >> m;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] < 0)
				v.push_back(a[i][j]);
			sum += abs(a[i][j]);
		}
	}
	if (v.size() % 2 == 0)
		cout << sum << '\n';
	else {
		int mn = INT_MAX;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mn = min(mn, abs(a[i][j]));
			}
		}
		cout << sum - (mn * 2) << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}