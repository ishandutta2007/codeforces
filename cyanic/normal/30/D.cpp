#include<bits/stdc++.h>
using namespace std;

const int maxn = 100009;
double a[maxn], cur, x, y, res;
int n, K;

double dist(double x, double y) {
	return sqrt(x*x + y*y);
}

int main() {
	scanf("%d%d", &n, &K);
	for (int i=1; i<=n; i++) scanf("%lf", &a[i]);
	cur = a[K]; sort(a+1, a+n+1);
	scanf("%lf%lf", &x, &y);
	if (K == n+1) {
		printf("%.20lf\n", min(dist(x-a[1], y), dist(x-a[n], y)) + a[n] - a[1]);
		return 0;
	}
	if (n == 1) {
		printf("%.20lf\n", dist(x-a[1], y));
		return 0;
	}
	for (int i=1; i<=n; i++) if (fabs(a[i] - cur) < 1e-6) { K = i; break; }
	res = 1e99;
	for (int i=1; i<=n; i++) {
		res = min(res, 	min(fabs(a[K] - a[i]) + fabs(a[i] - a[n]) + dist(a[n]-x, y),
							fabs(a[K] - a[n]) + fabs(a[i] - a[n]) + dist(a[i]-x, y)) +
						(i == 1 ? 0 : (min(dist(a[i-1]-x, y), dist(a[1]-x, y)) + fabs(a[i-1] - a[1]))));
		res = min(res, 	min(fabs(a[K] - a[i]) + fabs(a[i] - a[1]) + dist(a[1]-x, y),
							fabs(a[K] - a[1]) + fabs(a[i] - a[1]) + dist(a[i]-x, y)) +
						(i == n ? 0 : (min(dist(a[i+1]-x, y), dist(a[n]-x, y)) + fabs(a[i+1] - a[n]))));
	}
	printf("%.20lf\n", res);
	return 0;
}