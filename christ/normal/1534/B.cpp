#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5;
void solve () {
	int n; scanf ("%d",&n);
	vector<int> a(n+2);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	long long ret = 0;
	for (int i = 1; i <= n+1; i++) ret += abs(a[i]-a[i-1]);
	for (int i = 1; i <= n; i++) {
		if (a[i] > a[i-1] && a[i] > a[i+1]) {
			int go = min(a[i] - a[i-1],a[i] - a[i+1]);
			ret -= go;
		}
	}
	printf ("%lld\n",ret);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}
//aba aba
//012 345

//ab a ba
//01 2 34