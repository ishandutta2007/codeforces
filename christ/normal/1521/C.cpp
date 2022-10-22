#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5+5;
int ask (int t, int i, int j, int x) {
	printf ("? %d %d %d %d\n",t,i,j,x);
	fflush(stdout);
	int ret; scanf ("%d",&ret);
	return ret;
}
void solve () {
	int n; scanf ("%d",&n);
	vector<int> p(n+1); vector<bool> done(n+1);
	for (int i = 1; i <= n; i += 2) {
		if (i + 1 <= n) {
			int mx = ask(1,i,i+1,n-1), mn = ask(2,i,i+1,1);
			if (mx == n-1) mx = max(mx,ask(1,i+1,i,n-1));
			if (mn == 2) mn = min(mn,ask(2,i+1,i,1));
			assert(mn < n);
			int got = ask(2,i,i+1,mn);
			if (got == mn) p[i] = mn, p[i+1] = mx;
			else p[i+1] = mn, p[i] = mx;
			done[p[i]] = done[p[i+1]] = 1;
		} else {
			for (int j = 1; j <= n; j++) if (!done[j]) p[i] = j;
		}
	}
	printf ("!");
	for (int i = 1; i <= n; i++) printf (" %d",p[i]);
	printf ("\n");
	fflush(stdout);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}