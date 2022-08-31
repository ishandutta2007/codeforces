/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 55, B = 56;

bool seen[N][N], dp[N][N];
ll a[N];

bool check(int i, int j, ll mask);

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	ll ans = 0;
	// cout << check(2, 1, 2) << endl;
	for (int b = B; b >= 0; --b) {
		memset(seen, 0, sizeof(seen));
		if (check(n, k, ans | (1ll << b))) {
			ans |= (1ll << b);
		}
	}
	cout << ans;
}

bool check(int i, int j, ll mask) {
	if (j > i) {
		return false;
	} else if (i == 0) {
		return (j == 0);
	} else if (seen[i][j]) {
		return dp[i][j];
	} else {
		seen[i][j] = true;
		dp[i][j] = false;
		ll sum = 0;
		for (int k = i; k >= 1; --k) {
			sum += a[k];
			// cout << sum << ' ' << mask << ' ' << (sum & mask) << endl;
			if ((sum & mask) == mask and check(k - 1, j - 1, mask)) {
				dp[i][j] = true;
				break;
			}
		}
		return dp[i][j];
	}
}