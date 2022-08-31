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

const int N = 5e5 + 10, inf = 1e9 + 42;

int max_ba[N], max_b[N];
int min_ba[N], min_b[N];
vector<int> at[N];

int main() {
	fast_cin();
	int n; cin >> n;
	int l = 0;
	int g_min_a = inf, g_max_a = -inf;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		l = max(l, int(s.length()));
		int a = count(s.begin(), s.end(), 'B');
		int b = count(s.begin(), s.end(), 'N');
		at[a].pb(b);
		g_min_a = min(g_min_a, a);
		g_max_a = max(g_max_a, a);
	}
	int cur_max_ba = -inf, cur_min_b = inf;
	for (int a = 0; a <= l; ++a) {
		for (auto& b : at[a]) {
			cur_max_ba = max(cur_max_ba, b - a);
			cur_min_b = min(cur_min_b, b);
		}
		max_ba[a] = cur_max_ba;
		min_b[a] = cur_min_b;
	}
	int cur_max_b = -inf, cur_min_ba = inf;
	for (int a = l; a >= 0; --a) {
		for (auto& b : at[a]) {
			cur_max_b = max(cur_max_b, b);
			cur_min_ba = min(cur_min_ba, b - a);
		}
		max_b[a] = cur_max_b;
		min_ba[a] = cur_min_ba;
	}
	pii ans = {l, l};
	int lo = 0, hi = 2 * l - 1;
	while (lo <= hi) {
		int d = (lo + hi) / 2;
		bool ok = false;
		for (int a = 0; a <= l; ++a) {
			bool check = (a - d <= g_min_a) and (g_max_a <= a + d);
			int max_l = max(a - d + max_ba[a], max_b[a] - d);
			int min_r = min(min_b[a] + d, a + d + min_ba[a]);
			if (check and max_l <= min_r and (a > 0 or min_r > 0)) {
				ok = true;
				ans = {a, min_r};
				break;
			}
		}
		if (ok) {
			hi = d - 1;
		} else {
			lo = d + 1;
		}
	}
	cout << hi + 1 << '\n';
	cout << string(ans.first, 'B') + string(ans.second, 'N') << '\n';
}