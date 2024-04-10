/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int f[N][N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			f[i][j] = (i % 2 == j % 2 ? 1 : -1);
		}
	}
	if (n % 2 == 0){
		for (int i = 0; i < n; i += 2) {
			f[i][i + 1] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cout << f[i][j] << ' ';
		}
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}