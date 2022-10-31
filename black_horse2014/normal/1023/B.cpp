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

int main() {
	ios_base::sync_with_stdio(0);
	long long n, m; cin >> n >> m;
	if (n == 1 || m < 3 || m >= 2 * n) return puts("0"), 0;
	long long ans;
	if (m >= n + 1) {
		ans = n + n - m + 1;
	} else {
		ans = m - 1;
	}
	if (m % 2 == 0) ans--;
	ans /= 2;
	printf("%lld\n", ans);
	return 0;
}