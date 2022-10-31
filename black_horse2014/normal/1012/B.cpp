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

int f[440000];

int find_set(int u) {
	return f[u] == u ? u : f[u] = find_set(f[u]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= n + m; i++) f[i] = i;
	int ans = n + m;
	for (int i = 1; i <= q; i++) {
		int r, c; cin >> r >> c;
		int u = find_set(r);
		int v = find_set(c + n);
		if (u == v) continue;
		f[u] = v;
		ans--;
	}
	cout << ans - 1 << endl;
	return 0;
}