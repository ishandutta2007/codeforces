#include <bits/stdc++.h>
using namespace std;
const int MN = 3e3 + 5;
void solve () {
	int r,b,d; scanf ("%d %d %d",&r,&b,&d);
	if ((long long)(d + 1) * r < b || (long long)(d+1) * b < r) {
		printf ("No\n");
	} else {
		printf ("Yes\n");
	}
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}