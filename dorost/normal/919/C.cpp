/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2012;
int a[N], b[N][N];

int find(int n, int k) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			continue;
		}
		int x = n;
		for (int j = i; j < n; j++) {
			if (a[j] == 1) {
				x = j;
				break;
			}
		}
		ans += max(0, (x - i) - k + 1);
		i = x - 1;
	}
	return ans;
}

int32_t main() {
	int n, m, k;
	cin >> n >> m >> k;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			b[i][j] = (c == '*');
			a[j] = b[i][j];
		}
		ans += find(m, k);
	}
	if (k == 1) {
		cout << ans;
		return 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[j] = b[j][i];
		}
		ans += find(n, k);
	}
	cout << ans;
}