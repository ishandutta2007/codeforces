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

const int N = 2e5 + 10, inf = 1e9 + 42;

int a[N], max_pwr[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			max_pwr[i] = 0;
		}
		max_pwr[n + 1] = 0;
		int m; cin >> m;
		for (int i = 1; i <= m; ++i) {
			int p, s;
			cin >> p >> s;
			max_pwr[s] = max(max_pwr[s], p);
		}
		for (int s = n - 1; s >= 1; --s) {
			max_pwr[s] = max(max_pwr[s], max_pwr[s + 1]);
		}
		int p = 1, ans = 0;
		a[n + 1] = inf;
		while (p <= n) {
			++ans;
			int need_pwr = 0, nxt = p;
			for (int i = p; i <= n + 1; ++i) {
				need_pwr = max(need_pwr, a[i]);
				if (need_pwr > max_pwr[i - p + 1]) {
					nxt = i;
					break;
				}
			}
			if (nxt == p) {
				ans = -1;
				break;
			}
			p = nxt;
		}
		cout << ans << '\n';
	}
}