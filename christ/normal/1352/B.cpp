#include <bits/stdc++.h>
using namespace std;
void solve () {
	int n, k;
	scanf ("%d %d", &n, &k);
	if (n - 2 * (k - 1) > 0 && n % 2 == 0) {
		printf ("YES\n");
		for (int i = 0; i < k-1; i++) printf ("2 ");
		printf ("%d\n",n - 2 * (k-1));
	} else if (n - (k - 1) > 0 && (n - (k - 1)) % 2 == 1) {
		printf ("YES\n");
		for (int i = 0; i < k-1; i++) printf ("1 ");
		printf ("%d\n",n-(k-1));
	} else {
		printf ("NO\n");
	}
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
	return 0;
}
//2 2 2 2 2 2 n-(2 * (k-1))

//1 1 1 1 1 1 n-(k - 1)