/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
const int N = 301234;
int a[N], w[N];
bool f[N], g[N];
vector <int> divs[N], pdivs[N];
bool dp[6][N];
int maz[6][N];

int z(int x) {
	return (pdivs[x].size() % 2 == 0 ? 1 : -1);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	for (int i = 0; i < N; i++)
		f[i] = true;
	f[0] = false;
	f[1] = false;
	int gcd = 0;
	for (int i = 2; i < N; i++) {
		if (!f[i])
			continue;
		pdivs[i].push_back(i);
		for (int j = i * 2; j < N; j += i) {
			f[j] = false;
			pdivs[j].push_back(i);
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			divs[j].push_back(i);
		}
	}
	for (int i = 0; i < N; i++) {
		int x = 1, y = i;
		for (int j = 2; j * j <= y; j++) {
			if (y % j == 0) {
				x *= j;
				while (y % j == 0) {
					y /= j;
				}
			}
		}
		if (y != 1)
			x *= y;
		w[i] = x;
		g[x] = true;
	}
	int n;
	cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		gcd = __gcd(a[i], gcd);
		dp[0][w[a[i]]] = true;
	}
	if (gcd != 1) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		if (dp[0][i]) {
			v.push_back(i);
			for (int j = i * 2; j < N; j += i) {
				dp[0][j] = false;
			}
		}
	}
	for (int k = 1; k < 6; k++) {
		for (int i = 1; i < N; i++) {
			for (int j = i; j < N; j += i) {
				maz[k - 1][i] += dp[k - 1][j];
			}
		}
		for (int i = 0; i < N; i++) {
			if (dp[k - 1][i])
				dp[k][i] = true;
		}
		for (auto x : v) {
			for (auto i : divs[x]) {
				if (dp[k][i])
					continue;
				int l = x / i;
				int ans = 0;
				for (auto j : divs[l]) {
					ans += z(j) * maz[k - 1][i * j];
				}
				if (ans != 0) {
					dp[k][i] = true;
				}
			}
		}
	}
	for (int i = 0; i < 6; i++) {
		if (dp[i][1]) {
			cout << i + 1;
			return 0;
		}
	}
	cout << 7;
}