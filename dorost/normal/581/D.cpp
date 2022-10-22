/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 302;
char c[N][N];

int32_t main() {
	int x[3], y[3];
	cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
	int a = x[0] * y[0] + x[1] * y[1] + x[2] * y[2];
	if (floor(sqrt(a)) * floor(sqrt(a)) != a) {
		cout << -1;
		return 0;
	}
	a = floor(sqrt(a));
	int n = a, m = a;
	bool f[3] = {1, 1, 1};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (!f[j]) 
				continue;
			if (n == x[j]) {
				for (int k = m - 1; k >= m - y[j]; k--) {
					for (int l = 0; l < n; l++) {
						c[l][k] = 'A' + j;
					}
				}
				m -= y[j];
				f[j] = false;
			} else if (m == x[j]) {
				for (int k = n - 1; k >= n - y[j]; k--) {
					for (int l = 0; l < m; l++) {
						c[k][l] = 'A' + j;
					}
				}
				n -= y[j];
				f[j] = false;
			} else if (n == y[j]) {
				for (int k = m - 1; k >= m - x[j]; k--) {
					for (int l = 0; l < n; l++) {
						c[l][k] = 'A' + j;
					}
				}
				m -= x[j];
				f[j] = false;
			} else if (m == y[j]) {
				for (int k = n - 1; k >= n - x[j]; k--) {
					for (int l = 0; l < m; l++) {
						c[k][l] = 'A' + j;
					}
				}
				n -= x[j];
				f[j] = false;
			}
		}
	}
	if (n * m != 0) {
		cout << -1;
		return 0;
	}
	cout << a << endl;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			cout << c[i][j];
		}
		cout << '\n';
	}
}