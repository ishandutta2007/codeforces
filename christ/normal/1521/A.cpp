#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5+5;
void solve () {
	int a,b; scanf ("%d %d",&a,&b);
	if (b == 1) {
		printf ("NO\n");
		return;
	}
	long long go = (long long)a * b;
	printf ("YES\n%lld %lld %lld\n",go,(long long)a,go+a);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}