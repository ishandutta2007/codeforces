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

const int N = 1e5 + 10, A = 105;

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	vector<int> f(A, 0), mx_at(n + 1, 0);
	vector<vector<int>> ids(A), where_mx(A);
	int mv = 1, ans = 0;
	for (int i = 1; i <= n; ++i) {
		++f[a[i]];
		mv = (f[a[i]] > f[mv] ? a[i] : mv);
		mx_at[i] = mv;
		where_mx[mv].pb(i);
		ids[a[i]].pb(i);
	}
	for (int v = 1; v < A; ++v) {
		ids[v].pb(n + 1);
	}
	for (int v = 1; v < A; ++v) {
		for (int x = 1; x < A; ++x) {
			if (x == v) {
				continue;
			}
			vector<pii> stk = {{0, 0}};
			int p1 = 0, p2 = 0, cur = 0;
			for (auto& r : where_mx[v]) {
				while (min(ids[v][p1], ids[x][p2]) <= r) {
					int id = min(ids[v][p1], ids[x][p2]);
					if (ids[v][p1] <= ids[x][p2]) {
						++cur;
						++p1;
					} else {
						--cur;
						++p2;
					}
					if (cur > stk.back().first) {
						stk.pb({cur, id});
					}
				}
				auto it = lower_bound(stk.begin(), stk.end(), make_pair(cur, -1));
				if (it != stk.end()) {
					ans = max(ans, r - it->second);
				}
			}
		}
	}
	cout << ans << '\n';
}