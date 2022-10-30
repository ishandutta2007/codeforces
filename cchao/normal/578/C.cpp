#include <bits/stdc++.h>
using namespace std;

int n;
double a[200010], s[200010]={};
double f(double x) {
	double mi = 0, mx = 0, ret = 0;
	for(int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i] - x;
		ret = max(ret, fabs(s[i] - mi));
		ret = max(ret, fabs(s[i] - mx));
		mi = min(mi, s[i]);
		mx = max(mx, s[i]);
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for(int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		a[i] = x;
	}
	double l = -1000000, r = 1000000;
	for(int i = 0; i < 100; ++i) {
		double m1 = l + (r - l) * 0.33;
		double m2 = l + (r - l) * 0.67;
		double r1 = f(m1);
		double r2 = f(m2);
		if(r1 > r2) l = m1;
		else r = m2;
	}
	printf("%.12f\n", f((l + r) / 2));
	return 0;
}