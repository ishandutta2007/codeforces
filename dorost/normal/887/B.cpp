/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1000;
int a[3][6];
bool is[N];
vector <vector <int>> v = {{1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}, {2, 1}, {3, 1}, {3, 2}, {3, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}};

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> a[i][j];
		}
	}
	for (auto x : v) {
		if (*max_element(x.begin(), x.end()) > n) {
			continue;
		}
		for (int i = 0; i < pow(6, x.size()); i++) {
			int aa[x.size()] = {};
			int y = i;
			for (int j = 0; j < x.size(); j++) {
				aa[j] = y % 6;
				y /= 6;
			}
			string s;
			for (int j = 0; j < x.size(); j++) {
				s += (a[x[j] - 1][aa[j]] + '0');
			}
			is[stoi(s)] = 1;
		}
	}
	int ans = 999;
	for (int i = 1; i <= 999; i++) {
		if (!is[i]) {
			ans = i - 1;
			break;
		}
	}
	cout << ans;
}