#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
void solve () {
	int n,l;
	scanf ("%d %d",&n,&l);
	vector<int> a(n+2); vector<double> pre(n+2), suf(n+2);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	a[0] = 0; a[n+1] = l;
	for (int i = 1; i <= n; i++) {
		double time_taken = (double)(a[i] - a[i-1]) / i;
		pre[i] = pre[i-1] + time_taken;
	}
	for (int i = n; i >= 1; i--) {
		double time_taken = (double)(a[i+1] - a[i]) / (n - i + 1);
		suf[i] = suf[i+1] + time_taken; 
	}
	int lst = 0; 
	for (int i = 1; i <= n; i++) {
		if (pre[i] < suf[i]) lst = i;
	}
	//[lst,lst+1]
	int accel_first = lst + 1, accel_second = n - lst + 1;
	double time_first = pre[lst], time_second = suf[lst+1];
	printf ("%.8f\n",(double)(a[lst+1]-a[lst]+accel_first*time_first+accel_second*time_second) / (accel_first+accel_second));
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
	return 0;
}