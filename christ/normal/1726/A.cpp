#include <bits/stdc++.h>
using namespace std;
const int MN = 4e5 + 5;
void solve() {
	int n; scanf ("%d",&n);
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	int ret = a[n] - a[1];
	//just change n
	for (int i = 2; i <= n; i++) ret = max(ret,a[i] - a[1]);
	for (int i = 1; i < n; i++) ret = max(ret,a[n] - a[i]);
	for (int i = 2; i <= n; i++) {
		ret = max(ret,a[i-1] - a[i]);
	}
	printf ("%d\n",ret);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}