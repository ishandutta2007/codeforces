#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5, SUB = 5e3 + 1;
void solve () {
	int n; scanf ("%d",&n); int ret = 0;
	for (int dig = 1; dig <= 9; dig++) {
		long long go = 0;
		for (int cnt = 1; cnt <= 10; cnt++) {
			go = go * 10 + dig;
			if (go <= n) ++ret;
		}
	}
	printf ("%d\n",ret);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}