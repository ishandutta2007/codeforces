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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int h, g;
		cin >> h >> g;
		int n = (1 << h) - 1, m = (1 << g) - 1;
		vector<int> a(n + 1);
		ll sum = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		vector<int> ans;
		ans.reserve(n - m);
		for (int i = 1; i <= n;) {
			if (a[i] == 0) {
				++i;
				continue;
			}
			int j = i;
			while (true) {
				int lc = 2 * j, rc = lc + 1;
				if (lc > n) {
					break;
				} else if (!a[lc] and !a[rc]) {
					break;
				} else {
					j = ((a[lc] > a[rc]) ? lc : rc);
				}
			}
			assert(a[j]);
			if (j > m) {
				ans.pb(i);
				sum -= a[i];
				j = i;
				while (true) {
					int lc = 2 * j, rc = lc + 1;
					if (lc > n) {
						break;
					} else if (!a[lc] and !a[rc]) {
						break;
					} else {
						j = ((a[lc] > a[rc]) ? lc : rc);
						a[j / 2] = a[j];
					}
				}
				a[j] = 0;
			} else {
				++i;
			}
		}
		cout << sum << '\n';
		for (auto& i : ans) {
			cout << i << ' ';
		}
		cout << endl;
	}
}