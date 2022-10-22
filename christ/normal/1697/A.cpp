#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 1e9 + 123;
void solve () {
	int n,m; scanf ("%d %d",&n,&m);
	int cur = m, ret = 0;
	for (int i = 0; i < n; i++) {
		int x; scanf ("%d",&x);
		while (cur < x) {
			cur++; ret++;
		}
		cur -= x;
	}
	printf ("%d\n",ret);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}
//