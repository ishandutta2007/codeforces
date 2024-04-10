#include<iostream>
#include<algorithm>
using namespace std;
long long n, x[10009], y[10009], v, u, w, minv = 5e18, maxv = -5e18;
int main() {
	cin >> n >> w >> v >> u;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		minv = min(minv, x[i] * u - y[i] * v);
		maxv = max(maxv, x[i] * u - y[i] * v);
	}
	long double ans = 1.0L*w / u; if (minv < 0 && maxv > 0)ans += 1.0L*maxv / (u*v);
	printf("%.25Lf\n", ans);
	return 0;
}