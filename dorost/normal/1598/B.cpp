/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
bool a[N][5];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) 
			cin >> a[i][j];
	}
	for (int k = 0; k < 5; k++) {
		for (int j = 0; j < k; j++) {
			vector <int> v, w;
			for (int i = 0; i < n; i++) {
				if (a[i][k])
					v.push_back(i);
				else
					w.push_back(i);
			}
			int x = 0;
			for (auto y : v) {
				if (a[y][j])
					x++;
			}
			for (auto y : w) {
				if (!a[y][j])
					x = -n;
				else
					x++;
			}
			if (x >= n / 2 && v.size() >= n / 2) {
				cout << "YES ";
				return;
			}
		}
	}
	cout << "NO ";
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