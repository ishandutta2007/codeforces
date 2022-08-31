#include <bits/stdc++.h>
using namespace std;
#define F0R(i, a) for (int i=0; i<a; i++)

int n, s[200000];

double e(double x) {
	double csum = 0, cmin = 0, cmax = 0, ans = 0;
	F0R(i,n) {
		csum += (s[i]-x);
		cmin = min(cmin,csum), cmax = max(cmax,csum);
		ans = max(ans,max(csum-cmin,cmax-csum));
	}
	return ans;
}

int main() {
	cin >> n;
	F0R(i,n) cin >> s[i];
	double l = -10000, r = -l;
	while (r-l > 0.00000000001) {
		double m1 = (l+l+r)/3, m2 = (l+r+r)/3;
   		if (e (m1) < e(m2)) r = m2;
   		else l = m1;
	}
	cout << fixed << setprecision(10) << e((l+r)/2);
}