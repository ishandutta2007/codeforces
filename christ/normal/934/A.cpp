#include <bits/stdc++.h>
using namespace std;
const int MN = 5e3 + 5, MOD = 1e9 + 7;
int main () {
	int n,m; scanf ("%d %d",&n,&m);
	vector<int> a(n+1), b(m+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	for (int i = 1; i <= m; i++) scanf ("%d",&b[i]);
	long long ans = 2e18;
	for (int i = 1; i <= n; i++) {
		long long ret = -2e18;
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= n; k++) if (i != k) {
				ret = max(ret,(long long)a[k]*b[j]);
			}
		}
		ans = min(ans,ret);
	}
	printf ("%lld\n",ans);
	return 0;
}