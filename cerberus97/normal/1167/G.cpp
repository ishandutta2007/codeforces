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
#include <bitset>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10, D = 2 * 7e3 + 10;

ll a[N];
bitset<D> to_left, to_right;

int main() {
	fast_cin();
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int m; cin >> m;
	int x = 0, r = 0, p = 1;
	while (m--) {
		int nx; cin >> nx;
		while (x < nx) {
			if (p <= n and nx > a[p]) {
				int shift = a[p] + 1 - x;
				x += shift;
				to_right >>= shift;
				to_left <<= shift;
				to_left[0] = 1;
				to_left[1] = 1;
				++p;
				to_right[0] = (p <= n and a[p] == x);
			} else {
				int shift = nx - x;
				x += shift;
				to_right >>= shift;
				to_left <<= shift;
			}
		}
		while (r + 1 <= n) {
			if (a[r + 1] < x) {
				++r;
				continue;
			} else if (a[r + 1] - x < D - 1) {
				to_right[a[r + 1] - x] = 1;
				to_right[a[r + 1] - x + 1] = 1;
				++r;
			} else {
				break;
			}
		}
		int cand = min(to_left._Find_first(), to_right._Find_first());
		ld ans = atan2(1, cand);
		cand = (to_left & to_right)._Find_first();
		// cand = min(cand, int((to_left & (to_right << 1))._Find_first()));
		// cand = min(cand, int(((to_left << 1) & to_right)._Find_first()));
		ans = max(ans, ld(2 * atan2(1, cand)));
		cout << fixed << setprecision(15) << ans << '\n';
	}
}