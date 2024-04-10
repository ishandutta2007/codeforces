/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int M = 1000 * 1000 * 1000 + 7, N = 201234;
int x[N][10];

void solve() {
	string n;
	int m, ans = 0;
	cin >> n >> m;
	for (auto c: n) {
		int h = c - '0';
		for (int i = 0; i < 10; i++) {
			ans += x[max(0LL, m - (9 - h))][i];
			ans %= M;
		}
	}
	cout << ans << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	x[0][9]++;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			int a = j - 1;
			if (a < 0)
				a = 9;
			x[i][j] += x[i - 1][a];
			x[i][j] %= M;
		}
		x[i][1] += x[i - 1][9];
		x[i][1] %= M;
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}