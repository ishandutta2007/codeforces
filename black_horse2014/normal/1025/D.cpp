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

int a[777], b[777][777], ldp[777][777], rdp[777][777];
bitset<777> dp[777][777];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (__gcd(a[i], a[j]) > 1) {
				b[i][j] = b[j][i] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) dp[i][i].set(i), ldp[i][i] = rdp[i][i] = 1;
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n-l+1; i++) {
			int j = i+l-1;
			for (int k = i; !ldp[i][j] && k < j; k++) {
				if (b[j][k] && dp[i][j-1][k]) {
					ldp[i][j] = 1;
					dp[i][j].set(j);
					break;
				}
			}
			for (int k = i+1; !rdp[i][j] && k <= j; k++) {
				if (b[i][k] && dp[i+1][j][k]) {
					rdp[i][j] = 1;
					dp[i][j].set(i);
					break;
				}
			}
			for (int k = i+1; k < j; k++) {
				if (ldp[i][k] && rdp[k][j]) dp[i][j].set(k);
			}
		}
	}
	if (dp[1][n].count()) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}