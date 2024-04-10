#include <bits/stdc++.h>
using namespace std;

long long a[55];
bool pd[55][55];

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
	long long ans = 0;
	for (int i = 59; i >= 0; i--) {
		memset(pd, 0, sizeof pd);
		pd[0][0] = 1;
		for (int k = 1; k <= n; k++) {
			for (int kk = 0; kk < k; kk++) {
				long long temp = a[k] - a[kk];
				if (~temp >> i & 1) continue;
				if ((temp & ans) < ans) continue;
				for (int l = 1; l <= k && l <= m; l++) if (pd[kk][l - 1]) {
					pd[k][l] = 1;
				}
			}
		}
		if (pd[n][m]) ans ^= 1LL<<i;
	}
	cout << ans << endl;
	return 0;
}