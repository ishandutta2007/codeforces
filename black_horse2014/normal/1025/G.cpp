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

const int P = 1e9 + 7;

int sz[555], b[555];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x == -1) sz[i]++;
		else sz[x]++;
	}
	for (int i = 0; i <= n; i++) b[i] = (i == 0 ? 1 : b[i - 1] * 2 % P);
	int ans = 0;
	for (int i = 1; i <= n; i++) if (sz[i]) ans = (ans + b[sz[i] - 1] - 1) % P;
	ans %= P;
	ans = ((b[n - 1] - 1 - ans) % P + P) % P;
	cout << ans << endl;
	return 0;
}