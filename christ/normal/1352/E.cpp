#include <bits/stdc++.h>
using namespace std;
void solve () {
	int n;
	scanf ("%d",&n);
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	vector<bool> exists(n+1);
	for (int l = 1; l <= n; l++) {
		int sum = 0;
		for (int r = l; r <= n; r++) {
			sum += a[r];
			if (r > l && sum <= n) exists[sum] = true; 
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) if (exists[a[i]]) ++ans;
	printf ("%d\n",ans); 
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
	return 0;
}