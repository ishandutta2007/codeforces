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

const int inf = 1e9;
const int N = 5500;

int a[N];
int dp[N][N][2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) dp[i][j][0] = dp[i][j][1] = inf;
		dp[i][0][0] = 0;
	}
	dp[1][1][1] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= (i+1)/2; j++) {
			dp[i][j][1] = min(dp[i-2][j-1][0] + max(0, a[i-1] - (a[i] - 1)), dp[i-2][j-1][1] + max(0, a[i-1] - (min(a[i], a[i-2]) - 1)));
			dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1] + max(0, a[i] - (a[i-1] - 1)));
		}
	}
	for (int i = 1; i <= (n+1)/2; i++) cout << min(dp[n][i][0], dp[n][i][1]) << ' ';
	cout << endl;
	return 0;
}