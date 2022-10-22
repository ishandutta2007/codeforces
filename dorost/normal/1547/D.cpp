/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234, M = 31;
bool b[N][M];
int a[N], ans[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < M; j++)
			b[i][j] = 0;
		cin >> a[i];
		ans[i] = 0;
		int x = 0;
		while (a[i]) {
			b[i][x] = (a[i] % 2);
			a[i] /= 2;
			x++;
		}
	}
	for (int j = 0; j < M; j++) {
		int x = N;
		for (int i = 0; i < n; i++) {
			if (b[i][j]) {
				x = i;
				break;
			}
		}
		for (int i = x + 1; i < n; i++) {
			if (!b[i][j])
				ans[i] += (1 << j);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' '; 
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