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

const int N = 220000;

char s[N], t[N];

int main() {
	ios_base::sync_with_stdio(0);
	int n, m; cin >> n >> m >> s >> t;
	int p = -1;
	for (int i = 0; i < n; i++) if (s[i] == '*') p = i;
	if (p >= 0) {
		if (n - 1 > m) {
			return puts("NO"), 0;
		}
	} else {
	    if (n != m) return puts("NO"), 0;
	}
	for (int i = 0; i < p; i++) if (i >= m || s[i] != t[i]) return puts("NO"), 0;
	for (int i = n - 1; i > p; i--) if (m - n + i < 0 || t[m - n + i] != s[i]) return puts("NO"), 0;
	puts("YES");
	return 0;
}