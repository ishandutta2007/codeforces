#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5, M = 2e4 + 5;
void solve () {
	int l,r; long long m;
	scanf ("%d %d %lld",&l,&r,&m);
	int sz = r-l;
	for (int k = l; k <= r; k++) {
		//does there exist a mutiple of k between
		long long low = m - sz, high = m + sz;
		low = max(low,1ll);
		if (high / k > (low - 1) / k) {
			long long mult = high / k * k;
			long long diff = mult - m;
			//c - b == diff
			for (int c = l; c <= r; c++) {
				if (l <= c-diff && c-diff <= r) {
					printf ("%d %lld %d\n",k,c-diff,c);
					return;
				}
			}
		}
	}
	assert(false);
}
//c-b == diff
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}