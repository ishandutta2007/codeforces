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

char s[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin >> s;
	int n = strlen(s);
	int ans = 1, cur = 0;
	for (int i = 0; i < n + n; i++) {
		if (i >= n) s[i] = s[i - n];
		if (i == 0 || s[i] == s[i - 1]) cur = 0;
		cur++;
		ans = max(ans, cur);
	}
	cout << min(ans, n) << endl;
	return 0;
}