/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], l[N];
vector <pair <bool, int>> v[N];

int32_t main() {
	int n, m, truth = 0, lie = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) {
			truth++;
		} else {
			lie++;
		}
		v[abs(a[i])].push_back({a[i] < 0, i + 1});
	}
	int x = 0;
	for (int i = 1; i <= n; i++) {
		int t = truth, l1 = lie;
		for (auto [x, y] : v[i]) {
			if (x) {
				t--;
				l1++;
			} else {
				t++;
				l1--;
			}
		}
		if (m == t) {
			x++;
			for (auto [x, y] : v[i]) {
				if (x) {
					if (l[y] == 0) {
						l[y] = 2;
					}
					if (l[y] == 1) {
						l[y] = 3;
					}
				} else {
					if (l[y] == 0) {
						l[y] = 1;
					} 
					if (l[y] == 2) {
						l[y] = 3;
					}
				}
			}
		}
	}
	string ewf[4] = {"", "Truth", "Lie", "Not defined"};
	if (x == 1) {
		for (int i = 1; i <= n; i++) {
			if (l[i] == 0) {
				l[i] = (a[i - 1] > 0) + 1;
			}
			cout << ewf[(l[i])] << '\n';
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (a[i - 1] > 0) {
				if (l[i] == 1) {
					l[i] = 3;
				} else {
					l[i] = 2;
				}
			} else {
				if (l[i] == 2) {
					l[i] = 3;
				} else {
					l[i] = 1;
				}
			}
			cout << ewf[l[i]] << '\n';
		}
	}
}