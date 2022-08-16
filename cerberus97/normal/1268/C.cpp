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

int p[N], loc[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		loc[p[i]] = i;
	}
	ll cost = 0;
	ordered_set<int> pos;
	for (int k = 0; k < n; ++k) {
		int x = loc[k + 1];
		int i = pos.order_of_key(x);
		cost += k - i;
		cost -= min(i, k - i);
		int j = k / 2 + 1;
		if (j <= i) {
			cost += (x - *pos.find_by_order(j - 1) - 1 - i + j);
		}
		j = (k + 1) / 2;
		if (j > i) {
			cost += (*pos.find_by_order(j - 1) - x - j + i);
		}
		pos.insert(x);
		cout << cost << ' ';
	}
	cout << endl;
}