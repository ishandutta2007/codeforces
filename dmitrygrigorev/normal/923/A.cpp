#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e6 + 10;
int prim[MAXN];

signed main() {
	ios_base::sync_with_stdio(false);

	for (int i = 2; i < MAXN; i++) {
		if (prim[i] == 0) {
			for (int j = i * 2; j < MAXN; j += i) {
				// if (prim[j] == 0)
					prim[j] = i;
			}
		}
	}
	int ans = 1e9;
	int n;
	cin >> n;
	// cout << n - prim[n] + 1 << endl;
	// for (int i = 2; i <= n; i++) {
	// 	if (prim[i] == 0 && n % i == 0) {
	// 		ans = min(ans, prim)
	// 	}
	// }
	int max_div = prim[n];
	// for (int i = 1; i * i <= n; i++) {
	// 	max
	// }
	for (int i = n - max_div + 1; i <= n; i++) {
		// if (prim[i] != 0)
			ans = min(ans, i - prim[i] + 1);
	}
	cout << ans << endl;


	return 0;
}