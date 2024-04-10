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

int s[1100];

int main() {
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		s[i] = a + b + c + d;
	}
	int ans = 1;
	for (int i = 1; i < n; i++) if (s[i] > s[0]) ans++;
	cout << ans << endl;
	return 0;
}