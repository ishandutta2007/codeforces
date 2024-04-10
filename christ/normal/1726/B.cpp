#include <bits/stdc++.h>
using namespace std;
const int MN = 4e5 + 5;
void solve() {
	int n,m; scanf ("%d %d",&n,&m);
	if (m < n) {
		printf ("No\n");
		return;
	}
	if (n % 2 == 1) {
		int big = m - n + 1;
		printf ("Yes\n");
		printf ("%d",big);
		for (int i = 1; i < n; i++) printf (" 1");
		printf ("\n");
	} else { //even number of everything
		if (m % 2 == 1) {
			printf ("No\n");
			return;
		}
		printf ("Yes\n");
		for (int i = 0; i < n-2; i++) {
			printf ("1 ");
			m--;
		}
		assert(m % 2 == 0);
		printf ("%d %d\n",m/2,m/2);
	}
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}