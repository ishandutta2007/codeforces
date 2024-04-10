#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5, MOD = 1e9+7, BIG = 2e7;
int a[MN];
void solve () {
	int n,m; scanf ("%d %d",&n,&m);
	if (m < n) {
		printf ("0\n");
		return;
	}
	int cur = n;
	for (int i = 29; i >= 0; i--) {
		//do we have to set this bit?
		if ((cur | ((1 << i) - 1)) > m) {
			//no
		} else {
			cur |= (1 << i);
		}
	}
	printf ("%d\n",cur ^ n);
}
int main() {
	int t; scanf ("%d",&t);
	while (t--) solve();
    return 0;
}