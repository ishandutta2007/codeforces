#include <bits/stdc++.h>
using namespace std;
const int MN = 505, MOD = 1e8;
void solve () {
	int n; scanf ("%d",&n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf ("%d",&a[i]);
	long long ret = 0;
	for (int i = 0; i + 1 < n; i++) {
		ret = max(ret,(long long)a[i] * a[i+1]);
	}
	printf ("%lld\n",ret);
}
int main() {
	int t; scanf ("%d",&t);
	while (t--) solve();
    return 0;
}