/* 	* In the name of GOD  */

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

typedef tree<
pair <int, int>,
null_type,
less<pair <int, int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int N = 201234;
int ps[N];
ordered_set p[3];

void solve() {
	int n;
	string s;
	cin >> n >> s;
	p[0].clear();
	p[1].clear();
	p[2].clear();
	p[0].insert(make_pair(0, -1));
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ps[i] = (i == 0 ? 0 : ps[i - 1]) + (s[i] == '+' ? -1 : +1);
		int k = ((ps[i] % 3) + 3) % 3;
		int in = p[k].order_of_key(make_pair(ps[i] + 1, -2));
		sum += in;
		p[k].insert(make_pair(ps[i], i));
	}
	cout << sum << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}