#include <bits/stdc++.h>
using namespace std;
const int MN = 3e3+5;
void solve () {
	int n; scanf ("%d",&n);
	int mx = -1, w = -1;
	for (int i = 1; i <= n; i++) {
		int x; scanf ("%d",&x);
		if (x>mx)mx=x,w=i;
	}
	printf ("%d\n",w);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}