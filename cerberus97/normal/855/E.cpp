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

const int D = 62, B = 12, M = (1 << 10) + 10;

int a[D];
ll dp[D][M][B][2];
bool seen[D][M][B][2] = {0};

ll solve(int b, ll num);
ll dp_equal(int n, int mask, int b, bool is_zero);
ll dp_less(int n, int mask, int b, bool is_zero);

int main() {
	fast_cin();
	int q;
	cin >> q;
	while (q--) {
		int b; ll l, r;
		cin >> b >> l >> r;
		cout << solve(b, r) - solve(b, l - 1) << '\n';
	}
}

ll solve(int b, ll num) {
	int d = 0;
	while (num) {
		a[++d] = num % b;
		num /= b;
	}
	return dp_equal(d, 0, b, true);
}

ll dp_equal(int n, int mask, int b, bool is_zero) {
	if (!n) {
		return !mask;
	}
	ll ans = dp_equal(n - 1, mask ^ (1 << a[n]), b, false);
	for (int i = 0; i < a[n]; ++i) {
		ans += dp_less(n - 1, ((is_zero and !i) ? 0 : (mask ^ (1 << i))), b, !i and is_zero);
	}
	return ans;
}

ll dp_less(int n, int mask, int b, bool is_zero) {
	if (!n) {
		return !mask;
	}
	if (seen[n][mask][b][is_zero]) {
		return dp[n][mask][b][is_zero];
	}
	seen[n][mask][b][is_zero] = true;
	ll ans = 0;
	for (int i = 0; i < b; ++i) {
		ans += dp_less(n - 1, ((is_zero and !i) ? 0 : (mask ^ (1 << i))), b, !i and is_zero);
	}
	dp[n][mask][b][is_zero] = ans;
	return ans;
}