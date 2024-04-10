/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 1001, M = 998244353;
int dp[N][N * 2][4];
int n, m;

int ans(int i, int k, int h) {
	if (i > n)
		return 0;
	if (i == n && k == m) {
		return 1;
	}
	if (i == n)
		return 0;
	if (k > m) {
		return 0;
	}
	if (i != 0 && dp[i][k][h] != -1)
		return dp[i][k][h];
	int x = h / 2, y = h % 2;
	if (h == -1)
		x = -1, y = -1;
	int num = 0;
	for (int l = 0; l < 4; l++) {
		int v = l / 2, h2 = l % 2, a = 0;
		if (v == h2 && x == y && x != v && v == 1) {
			a++;
		} else if (((v == 1 && x != 1) || (y != 1 && h2 == 1)) && (v != h2)) {
			a++;
		}
//		cout << x << ' ' << y << ' ' << v << ' ' << h << ' ';
		v = 1 - v;
		h2 = 1 - h2;
		x = 1 - x;
		y = 1 - y;
		if (v == h2 && x == y && x != v && v == 1) {
			a++;
		} else if (((v == 1 && x != 1) || (y != 1 && h2 == 1)) && (v != h2)) {
			a++;
		}
		x = 1 - x;
		y = 1 - y;
		v = 1 - v;
		h2 = 1 - h2;
//		cout << a << '\n';
		num += ans(i + 1, k + a, l);
//		if (i == 1) {
//			cout << l << ' ' << k << ' ' << h << ' ' << num << '\n';
//			cout << x << ' ' << y << ' ' << v << ' ' << h2 << ' ' << a << '\n';
//		}
		num %= M;
	}
//	if (i == 1)
//		cout << '\n';
	return dp[i][k][h] = num;
}

int32_t main() {
	cin >> n >> m;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2; j++) {
			for (int k = 0; k < 4; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	cout << ans(0, 0, -1);

}