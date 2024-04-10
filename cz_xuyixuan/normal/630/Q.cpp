#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
#define PI	acos(-1)
int main() {
	double a, b, c, tmp, s, h, ans = 0;
	cin >> a >> b >> c;
	s = sqrt(3) / 4 * a * a;
	h = sqrt((double) 2 / 3) * a;
	ans += s * h / 3;
	s = b * b;
	h = sqrt(2) / 2 * b;
	ans += s * h / 3;
	tmp = c / 2 * tan(2 * PI / 360 * 54);
	s = 5 * c * tmp / 2;
	tmp = sqrt(tmp * tmp + c * c / 4);
	h = sqrt(c * c - tmp * tmp);
	ans += s * h / 3;
	printf("%.10lf\n", ans);
	return 0;
}