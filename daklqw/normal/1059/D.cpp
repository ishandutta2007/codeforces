#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
const long double eps = 1e-8;
const int MAXN = 100010;
int n, xs[MAXN], ys[MAXN];
inline long double absx(long double x) { return x < 0 ? -x : x; }
inline long double pows(long double x) { return x * x; }
long double calc(long double x) {
	long double res = 0;
	for (int i = 1; i <= n; ++i) {
		const long double dis = absx(x - xs[i]);
		res = max(res, (pows(dis) + pows(static_cast<long double> (ys[i]))) / absx(ys[i]) / 2);
	}
	return res;
}
int main() {
	scanf("%d", &n);
	bool flagz = true, flagf = true;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &xs[i], &ys[i]);
		flagz &= ys[i] > 0;
		flagf &= ys[i] < 0;
	}
	if (!flagz && !flagf) {
		puts("-1");
		return 0;
	}
	long double l = -1e8, r = 1e8;
	while (absx(r - l) > eps) {
		const long double delta = (r - l) / 3, t1 = l + delta, t2 = t1 + delta;
		const long double v1 = calc(t1), v2 = calc(t2);
		if (v1 + eps > v2) l = t1; else r = t2;
	}
	cout << fixed << setprecision(6) << calc(l) << endl;
	return 0;
}