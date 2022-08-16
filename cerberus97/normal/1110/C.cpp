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

const int N = 4e7 + 10;

set<int> p2;
int mp[N];

int main() {
	fast_cin();
	int q; cin >> q;
	int p = 1;
	while (p < N) {
		p2.insert(p);
		p *= 2;
	}
	while (q--) {
		int a; cin >> a;
		if (!p2.count(a + 1)) {
			int ans = 1;
			while (a) {
				a /= 2;
				ans *= 2;
			}
			cout << ans - 1 << '\n';
		} else if (mp[a] != 0) {
			cout << mp[a] << '\n';
		} else {
			int best = 1, sq = sqrt(a) + 2;
			for (int b = 2; b <= sq; ++b) {
				if (a % b == 0) {
					best = max(best, a / b);
				}
			}
			mp[a] = best;
			cout << best << '\n';
		}
	}
}