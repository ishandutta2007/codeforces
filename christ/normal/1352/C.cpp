#include <bits/stdc++.h>
using namespace std;
void solve () {
	int n, k;
	scanf ("%d %d", &n, &k);
	long long low = 1, high = 1e18, mid, ans = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (mid - mid / n < k) low = (ans = mid) + 1;
		else high = mid - 1; 
	}
	printf ("%lld\n",ans + 1);
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
	return 0;
}