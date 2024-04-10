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

const int N = 110000;

int a[2*N];

int main() {
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= 2 * n; i++) cin >> a[i];
	sort(a + 1, a + 2 * n + 1);
	int minx = a[1];
	long long ans = 1LL<<60;
	for (int i = n; i < 2 * n; i++) {
		int maxx = a[i];
		int miny = (i == n ? a[i + 1] : a[n]);
		int maxy = a[2 * n];
		ans = min(ans, 1LL * (maxx - minx) * (maxy - miny));
	}
	int maxx = a[2 * n];
	for (int i = 2; i <= n; i++) {
		int miny = a[i];
		int maxy = a[i + n - 1];
		ans = min(ans, 1LL * (maxx - minx) * (maxy - miny));
	}
	cout << ans << endl;
	return 0;
}