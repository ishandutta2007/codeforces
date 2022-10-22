/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 18;
int a[N][(1 << N)];

int ask (int a, int b) {
	cout << "? " << a << ' ' << b << endl;
	int y;
	cin >> y;
	return y;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < (1 << n); i++)
		a[0][i] = i + 1;
	for (int i = 0; i < n; i += 2) {
		int sz = (1 << (n - i));
		if (sz == 2) {
			int y = ask(a[i][0], a[i][1]);
			if (y == 1) 
				a[n][0] = a[i][0];
			else if (y == 2) 
				a[n][0] = a[i][1];
			else
				assert(false);
		} else {
			for (int j = 0; j < sz; j += 4) {
				int y = ask(a[i][j], a[i][j + 2]);
				if (y == 1) {
					int y2 = ask(a[i][j], a[i][j + 3]);
					if (y2 == 1) {
						a[i + 2][j / 4] = a[i][j];
					} else {
						a[i + 2][j / 4] = a[i][j + 3];
					}
				} else if (y == 2) {
					int y2 = ask(a[i][j + 2], a[i][j + 1]);
					if (y2 == 1) {
						a[i + 2][j / 4] = a[i][j + 2];
					} else {
						a[i + 2][j / 4] = a[i][j + 1];
					}
				} else {
					int y2 = ask(a[i][j + 3], a[i][j + 1]);
					if (y2 == 1) {
						a[i + 2][j / 4] = a[i][j + 3];
					} else {
						a[i + 2][j / 4] = a[i][j + 1];
					}
				}
			}
		}
	}
	cout << "! " << a[n][0] << endl;
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