//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;

vector<int> v[1100];

int calc(int m) {
	for (int i = 1; i <= m + 5; i++) v[i].clear();
	for (int i = 1; i <= n; i++) v[(i + m - 1) / m].push_back(i);
	return (n + m - 1) / m + (n < m ? n : m);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin >> n;
	int m = sqrt(n);
	if (calc(m) <= calc(m + 1)) {
		calc(m);
	} else {
		calc(m + 1);
	}
	for (int i = m + 5; i >= 1; i--) {
		if (v[i].empty()) continue;
		for (int x : v[i]) cout << x << ' ';
	}
	cout << endl;
	return 0;
}