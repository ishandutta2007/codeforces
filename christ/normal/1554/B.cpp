#include <bits/stdc++.h>
using namespace std;
const int MN = 3e5 + 5, MOD = 1e9+7, BIG = 3e7;
int a[MN];
void solve () {
	int n,k; scanf ("%d %d",&n,&k);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	long long ret = -1e18;
	for (int i = 1; i <= n; i++) {
		for (int j = i-1; j >= 1 && (long long)i * j >= (long long)n * n - BIG; j--) {
			ret = max(ret,(long long)i * j - k * (a[i] | a[j]));
		}
	}
	printf ("%lld\n",ret);
}
int main() {
	int t; scanf ("%d",&t);
	while (t--) solve();
    return 0;
}