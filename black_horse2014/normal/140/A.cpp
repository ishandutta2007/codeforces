#include <bits/stdc++.h>
using namespace std;

int n;
double r, R;
const double eps = 1e-7;

int main() {
	
	scanf("%d%lf%lf", &n, &R, &r);
	if (n == 1) {
		if (r < R + eps) puts("YES");
		else puts("NO");
	} else if (n == 2) {
		if (r < R / 2 + eps) puts("YES");
		else puts("NO");
	} else {
		if (r > R / 2 - eps) puts("NO");
		else {
			double ang = asin(r / (R - r));
			if (ang * n < acos(-1.0) + eps) puts("YES");
			else puts("NO");
		}
	}
	
	return 0;
}