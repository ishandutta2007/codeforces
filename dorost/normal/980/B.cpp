/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
char s[4][N];

void solve() {
	int n, k;
	cin >> n >> k;
	cout << "YES\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j <= n / 2; j++) {
			if (!(i != 0 && i != 3 && j != 0 && j != n - 1)) {
				s[i][j] = '.';
				s[i][n - j - 1] = '.';
			} else if (k && j == n / 2) {
				s[i][j] = '#';
				s[i][n - j - 1] = '#';
				k--;
			} else if (j == n / 2) {
				s[i][j] = '.';
				s[i][n - j - 1] = '.';
			} else if (k >= 2) {
				s[i][j] = '#';
				s[i][n - j - 1] = '#';
				k -= 2;
			} else {
				s[i][j] = '.';
				s[i][n - j - 1] = '.';
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			cout << s[i][j];
		}
		cout << '\n';
	}
}

int32_t main() {
	solve();
}