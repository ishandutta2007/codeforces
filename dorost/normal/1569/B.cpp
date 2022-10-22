/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 55;
char c[N][N];
bool f[N];

void solve() {
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < N; i++) {
		f[i] = false;
		for (int j = 0; j < N; j++) {
			c[i][j] = 'X';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (s[i] == '1' || s[j] == '1') {
				c[i][j] = '=';
				c[j][i] = '=';
			} else {
				if (f[i]) {
					c[i][j] = '-';
					c[j][i] = '+';
					f[j] = true;
				} else {
					c[i][j] = '+';
					c[j][i] = '-';
					f[i] = true;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '2' && !f[i]) {
			cout << "NO ";
			return;
		}
	}
	cout << "YES ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << c[i][j];
		}
		cout << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}