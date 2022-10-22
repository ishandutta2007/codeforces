/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 23;
bitset <(1 << N)> ok[N];
bool dp[(1 << N)];
int a[N], w[(1 << (N - 1))];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	for (int i = 0; i < (1 << (N - 1)); i++)
		w[i] = -1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % a[0]) {
			cout << -1;
			return 0;
		}
		if (i != 0)
			a[i] /= a[0];
	}
	a[0] = 1;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	} 
	if (n == 2) {
		cout << -1 + (a[1] == 2) * 2 << '\n';
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > (1 << 22)) {
			cout << -1;
			return 0;
		}
		w[a[i]] = i;
	}
	for (int j = 0; j < n; j++) {
		for (int i = 1; i < (1 << n); i++) {
			int wf = (1 << j) - 1;
			if ((i & wf) != i)
				continue;
			int f = __builtin_ctz(i);
			ok[j][i] = ok[j][i ^ (1 << f)];
			int x = a[j];
			int y = a[f];
			int wef = x - y;
			if (wef < 0 || w[wef] == -1)
				continue;
			if ((i >> w[wef]) & 1) {
				ok[j][i] = true;
			}
		}
	}
	dp[0] = true;
	int ans = N + 1;
	for (int i = 1; i < (1 << n); i++) {
		int lst = -1;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1)
				lst = j;
		}
		if (lst == 0) {
			dp[i] = true;
			continue;
		}
		if ((i >> (lst - 1)) & 1) {
			for (int j = 0; j < lst; j++) {
				int mask = i ^ (1 << lst);
				if (((i >> j) & 1) == 0)
					mask ^= (1 << j);
				dp[i] |= (dp[mask] && ok[lst][mask]);
			}
		} else {
			for (int j = lst - 1; j < lst; j++) {
				int mask = i ^ (1 << lst);
				if (((i >> j) & 1) == 0)
					mask ^= (1 << j);
				dp[i] |= (dp[mask] && ok[lst][mask]);
			}
		}
		if (lst == n - 1 && dp[i]) {
			ans = min(ans, __builtin_popcount(i));
		}
	}
	cout << (ans == 24 ? -1 : ans) << endl;
}