#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5, MOD = 1e9+7, BIG = 2e7;
int a[MN];
void solve () {
	int n; scanf ("%d",&n);
	if (n == 1) {
	    printf ("z\n");
	    return;
	}
	if (n % 2 == 1) {
		printf ("c");
		--n;
	}
	for (int i = 0; i < n/2; i++) printf ("a");
	printf ("b");
	for (int i = 0; i < n/2-1; i++) printf ("a");
	printf ("\n");
}
int main() {
	int t; scanf ("%d",&t);
	while (t--) solve();
    return 0;
}