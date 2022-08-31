/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 10;

int n, m, q;
int a[N][N], sum[N][N];

ll solve(ll x, ll y, ll nn, ll mm);

int main() {
	fast_cin();
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char c; cin >> c;
			a[i][j] = (c == '1');
			sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll nn = n, mm = m;
		while (nn < x2 or mm < y2) {
			nn *= 2;
			mm *= 2;
		}
		ll ans = solve(x2, y2, nn, mm);
		ans -= solve(x2, y1 - 1, nn, mm);
		ans -= solve(x1 - 1, y2, nn, mm);
		ans += solve(x1 - 1, y1 - 1, nn, mm);
		cout << ans << '\n';
	}
}

ll solve(ll x, ll y, ll nn, ll mm) {
	if (x < 1 or y < 1) {
		return 0;
	} else if (n == nn) {
		return sum[x][y];
	} else if (x == nn or y == mm) {
		return (x * y) / 2;
	}
	nn /= 2; mm /= 2;
	ll ans = solve(min(x, nn), min(y, mm), nn, mm);
	ans += (max(0ll, x - nn) * min(y, mm) - solve(x - nn, min(y, mm), nn, mm));
	ans += (max(0ll, y - mm) * min(x, nn) - solve(min(x, nn), y - mm, nn, mm));
	ans += solve(x - nn, y - mm, nn, mm);
	return ans;
}