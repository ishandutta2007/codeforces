#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
void solve () {
	int n;
	scanf ("%d",&n);
	vector<int> a(n+1), b(n+1), c(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	for (int i = 1; i <= n; i++) scanf ("%d",&b[i]);
	for (int i = 1; i <= n; i++) scanf ("%d",&c[i]);
	vector<int> ret(n+1);
	for (int i = 1; i <= n; i++) {
		int lst = ret[i-1];
		for (int j : {a[i],b[i],c[i]}) if (j != lst && j != ret[1]) {
			ret[i] = j;
			break;
		} 
		printf ("%d%c",ret[i]," \n"[i==n]);
	}
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
	return 0;
}