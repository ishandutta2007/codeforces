#include <bits/stdc++.h>
using namespace std;
int main () {
	int n,m;
	scanf ("%d %d",&n,&m);
	vector<int> a(n+1), b(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	for (int i = 1; i <= n; i++) scanf ("%d",&b[i]);
	auto check = [&](double curFuel) {
		curFuel -= (curFuel + m) / a[1];
		if (curFuel <= 0) return false;
		for (int i = 2; i <= n; i++) {
			curFuel -= (curFuel + m) / b[i];
			if (curFuel <= 0) return false;
			curFuel -= (curFuel + m) / a[i];
			if (curFuel <= 0) return false;
		}
		curFuel -= (curFuel + m) / b[1];
		return curFuel >= 0;
	};
	double low = 0, high = 1e18, mid;
	for (int ITER = 0; ITER < 10000; ITER++) {
		mid = (low + high) / 2;
		if (check(mid)) high = mid;
		else low = mid;
	}
	if (low > 1e17) printf ("-1\n");
	else printf ("%.15f\n",(low + high) / 2);
	return 0;
}