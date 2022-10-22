#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
void solve () {
	int n,k;
	scanf ("%d %d",&n,&k); --k;
	vector<int> a(n+1); int cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		cnt += i > 1 && a[i] != a[i-1];
	}
	if (!k) return (void)printf ("%d\n",cnt ? -1 : 1);
	printf ("%d\n",max(1,(cnt + k - 1) / k));
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
	return 0;
}