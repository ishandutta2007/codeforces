#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using point = pair<double, double>;
const int maxn = 410000;
point P[maxn], u;
inline double angle(point p) {
	return atan2(u.first - p.first, u.second - p.second);
}
inline double dist(point a, point b) {
	double dx = a.first - b.first;
	double dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}
inline point operator+ (point a, point b) {
	return make_pair(a.first + b.first, a.second + b.second);
}
inline point operator- (point a, point b) {
	return make_pair(a.first - b.first, a.second - b.second);
}
inline point operator* (point a, double p) {
	return make_pair(a.first * p, a.second * p);
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, H;
	scanf("%d %d", &n, &H);
	for (int i = 1; i <= n; ++i)
		scanf("%lf %lf", &P[i].first, &P[i].second);
	u.first = P[n].first;
	u.second = P[n].second + H;
	double ans = dist(P[n - 1], P[n]);
	double alpha = angle(P[n - 1]);
	for (int i = n - 1; i >= 2; --i) {
		point a = P[i - 1], b = P[i];
		if (angle(a) > angle(b))
			swap(a, b);
		point vector = b - a;
		double L = 0, R = 1;
		for (int j = 0; j < 50; ++j) {
			double M = (L + R) / 2;
			auto mid = a + vector * M;
			if (angle(mid) < alpha)
				L = M;
			else
				R = M;
		}
		ans += dist(a, b) * (1 - L);
		alpha = max(alpha, angle(b));
	}
	printf("%.12f\n", ans);
	return 0;
}