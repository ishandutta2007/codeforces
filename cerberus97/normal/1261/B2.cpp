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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

template<typename has_less>
using ordered_set =
tree<has_less,
	null_type,
	less<has_less>,
	rb_tree_tag,
	tree_order_statistics_node_update>;

const int N = 2e5 + 10;

pii a[N];
vector<pii> queries[N];
int ans[N], at[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = -i;
		at[i] = a[i].first;
	}
	sort(a + 1, a + 1 + n, greater<pii>());
	int m; cin >> m;
	for (int i = 1; i <= m; ++i) {
		int k, pos;
		cin >> k >> pos;
		queries[k].pb({pos, i});
	}
	ordered_set<int> indices;
	for (int i = 1; i <= n; ++i) {
		indices.insert(-a[i].second);
		for (auto &q : queries[i]) {
			int pos = q.first, idx = q.second;
			ans[idx] = at[(*indices.find_by_order(pos - 1))];
		}
	}
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << '\n';
	}
}