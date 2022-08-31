/*
Cerberus97
Hanit Banga
*/


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;

typedef long double ld;
// typedef long long ll;
typedef pair <int, int> pii;
// typedef pair <ll, ll> pll;

template<typename has_less>
using ordered_set =
tree<has_less,
	null_type,
	less<has_less>,
	rb_tree_tag,
	tree_order_statistics_node_update>;

const int N = 2e5 + 10;

ordered_set<int> pos[3];
map<char, int> mp = {{'R', 0}, {'P', 1}, {'S', 2}};

int n, q;

int query(int R, int P, int S);
int query2(int R, int l, int r);

int main() {
	cin >> n >> q;
	string s; cin >> s;
	for (int i = 0; i < n; ++i) {
		pos[mp[s[i]]].insert(i + 1);
	}
	int ans = 0;
	ans += query(0, 1, 2);
	ans += query(1, 2, 0);
	ans += query(2, 0, 1);
	cout << ans << '\n';
	while (q--) {
		int i; char c;
		cin >> i >> c;
		char cur = s[i - 1];
		pos[mp[cur]].erase(i);
		pos[mp[c]].insert(i);
		s[i - 1] = c;
		ans = 0;
		ans += query(0, 1, 2);
		ans += query(1, 2, 0);
		ans += query(2, 0, 1);
		cout << ans << '\n';
	}
}

int query(int R, int P, int S) {
	if (pos[P].empty()) {
		return pos[R].size();
	}
	int l = *(pos[P].begin());
	int r = *(pos[P].rbegin());
	if (pos[S].empty()) {
		// return query2(R, 1, l - 1) + query2(R, r + 1, n);
		return 0;
	}
	int ll = *(pos[S].begin());
	int rr = *(pos[S].rbegin());
	int ans = query2(R, ll + 1, rr - 1);
	ans += query2(R, 1, min(l - 1, ll - 1));
	ans += query2(R, max(r + 1, rr + 1), n);
	return ans;
}

int query2(int R, int l, int r) {
	if (l > r) {
		return 0;
	}
	if (pos[R].empty()) {
		return 0;
	}
	auto i1 = pos[R].lower_bound(l);
	auto i2 = pos[R].upper_bound(r);
	--i2;
	if (i1 == pos[R].end() or i2 == pos[R].end()) {
		return 0;
	}
	int v1 = *i1;
	int v2 = *i2;
	if (v1 < l or v1 > r or v2 < l or v2 > r) {
		return 0;
	}
	return pos[R].order_of_key(v2) - pos[R].order_of_key(v1) + 1;
}