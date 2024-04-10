/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101;
int a[N][N];

int32_t main() {
	int n, m;
	cin >> n >> m;
	bool f = (n < m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	vector <pair <bool, int>> v;
	if (f) {
		for (int i = 0; i < n; i++) {
			int mn = INT_MAX;
			for (int j = 0; j < m; j++) {
				mn = min(mn, a[i][j]);
			}
			for (int j = 0; j < m; j++)
				a[i][j] -= mn;
			for (int j = 0; j < mn; j++) {
				v.push_back(make_pair(0, i + 1));
			}
		}
	} else {
		for (int i = 0; i < m; i++) {
			int mn = INT_MAX;
			for (int j = 0; j < n; j++) {
				mn = min(mn, a[j][i]);
			}
			for (int j = 0; j < n; j++)
				a[j][i] -= mn;
			for (int j = 0; j < mn; j++) {
				v.push_back(make_pair(1, i + 1));
			}
		}
	}
	if (!f) {
		for (int i = 0; i < n; i++) {
			int mn = INT_MAX;
			for (int j = 0; j < m; j++) {
				mn = min(mn, a[i][j]);
			}
			for (int j = 0; j < m; j++)
				a[i][j] -= mn;
			for (int j = 0; j < mn; j++) {
				v.push_back(make_pair(0, i + 1));
			}
		}
	} else {
		for (int i = 0; i < m; i++) {
			int mn = INT_MAX;
			for (int j = 0; j < n; j++) {
				mn = min(mn, a[j][i]);
			}
			for (int j = 0; j < n; j++)
				a[j][i] -= mn;
			for (int j = 0; j < mn; j++) {
				v.push_back(make_pair(1, i + 1));
			}
		}
	}
	bool f2 = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j])
				f2 = false;
		}
	}
	if (!f2) {
		printf("-1");
		exit(0);
	}
	cout << v.size() << '\n';
	for (auto [x, y] : v) {
		cout << (x ? "col " : "row ") << y << '\n';
	}
}