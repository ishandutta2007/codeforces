#include <bits/stdc++.h>
using namespace std;
const int MN = 3e3+5;
void solve () {
	int n; scanf ("%d",&n);
	if (n%2==1) {
		printf ("1 ");
		for (int i = 2; i <= n-2; i++) {
			if (i%2) printf ("%d ",i-1);
			else printf ("%d ",i+1);
		}
	} else {
		for (int i = 1; i <= n-2; i++) {
			if (i%2) printf ("%d ",i+1);
			else printf ("%d ",i-1);
		}
	}
	printf ("%d %d\n",n-1,n);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}
//1 2 4 = 1+2+4 = 7
//1 2 4 8 ... =
//1 2 5 = 8
//5
//want n + n-1...
//perm of [n-2] that ends with 0