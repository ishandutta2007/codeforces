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

const int N = 1e9 + 10, M = 3e5 + 10;
const ll inf = 1e18 + 42;

struct line {
	ll m, c;
};

vector<line> cht;

int main() {
	fast_cin();
	ll n; int m;
	cin >> n >> m;
	ll sum_s = 0, sum_b = 0;
	cht.pb({0, 0});
	for (int i = 1; i <= m; ++i) {
		int t; cin >> t;
		if (t == 1) {
			int k; cin >> k;
			cht.clear();
			sum_b = sum_s = 0;
			cht.pb({0, 0});
			n += k;
		} else if (t == 2) {
			int k; cin >> k;
			line l = {-n, 0};
			int r = cht.size();
			while (r >= 2) {
				line l1 = cht[r - 2];
				line l2 = cht[r - 1];
				l1.c += sum_b + sum_s * l1.m;
				l2.c += sum_b + sum_s * l2.m;
				if ((l1.c - l.c) * ld(l2.m - l1.m) <= (l1.c - l2.c) * ld(l.m - l1.m)) {
					--r;
					cht.pop_back();
				} else {
					break;
				}
			}
			l.c -= sum_b + sum_s * l.m;
			cht.pb(l);
			n += k;
		} else {
			int b, s;
			cin >> b >> s;
			sum_b += b;
			sum_s += -s;
		}
		int r = cht.size();
		while (r >= 2) {
			line l1 = cht[r - 2];
			line l2 = cht[r - 1];
			l1.c += sum_b + sum_s * l1.m;
			l2.c += sum_b + sum_s * l2.m;
			if ((l1.c - l2.c) <= 0) {
				--r;
				cht.pop_back();
			} else {
				break;
			}
		}
		ll ans = cht[r - 1].c + sum_b + cht[r - 1].m * sum_s;
		cout << 1 - cht[r - 1].m << ' ' << ans << '\n';
	}
}