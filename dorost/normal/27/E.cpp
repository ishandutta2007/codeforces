/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int INF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 2LL;
int pr[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

int tav(int x, int y) {
	int ans = 1;
	for (int i = 0; i < y; i++) {
		if (INF / ans < x) 
			return INF;
		ans *= x;
	}
	return ans;
}

int solve(int x, int i) {
	if (i == 9) {
		return (x == 1 ? 1 : INF);
	}
	int mn = INF;
	for (int j = 1; j <= x; j++) {
		if (x % j)
			continue;
		int f = tav(pr[i], j - 1);
		int s = solve(x / j, i + 1);
		if (INF / s < f)
			continue;
		mn = min(mn, f * s);
	}
	return mn;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	cout << solve(n, 0);
}