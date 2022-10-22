/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234, M = 510;
int ans[N], a[M][M];

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return (x > 1);
}

int32_t main() {
	for (int i = 1; i < N; i++) {
		for (int j = i; ; j++) {
			if (is_prime(j)) {
				ans[i] = j - i;
				break;
			}
		}
	}
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int mn = INT_MAX;
	for (int i = 0; i < n; i++) {
		int x = 0;
		for (int j = 0; j < m; j++) {
			x += ans[a[i][j]];
		}
		mn = min(mn, x);
	}
	for (int i = 0; i < m; i++) {
		int x = 0;
		for (int j = 0; j < n; j++) {
			x += ans[a[j][i]];
		}
		mn = min(mn, x);
	}
	cout << mn;
}