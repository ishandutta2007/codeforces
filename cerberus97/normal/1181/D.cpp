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

const int N = 5e5 + 10;

pll f[N], qry[N];
ll ans[N];

int main() {
	fast_cin();
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		++f[x].first;
	}
	for (int i = 1; i <= m; ++i) {
		f[i].second = i;
	}
	sort(f + 1, f + 1 + m);
	for (int i = 1; i <= q; ++i) {
		cin >> qry[i].first;
		qry[i].second = i;
	}
	sort(qry + 1, qry + 1 + q);
	ll done = n; int p = 1;
	ordered_set<int> s;
	s.insert(f[1].second);
	for (int i = 1; i <= q; ++i) {
		ll t = qry[i].first - 1;
		while (p < m and (t - done) >= (f[p + 1].first - f[p].first) * p) {
			done += (f[p + 1].first - f[p].first) * p;
			++p;
			s.insert(f[p].second);
		}
		ans[qry[i].second] = *s.find_by_order((t - done) % s.size());
	}
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << '\n';
	}
}