#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
double pi = 3.14159265358979323;
double v1x, v1y, v2x, v2y;
double v, t;
double l;
double getv(double v1, double v2, double d1, double d2)
{
	double beg = 0.0, end = v + v;
	double zl = sqrt(d1*d1 + d2*d2);
	for (int p=0;p<=100;p++)
	{
		double med = (beg + end) / 2.0;
		if (sqrt((med*d1 / zl - v1)*(med*d1 / zl - v1) + (med*d2 / zl - v2)*(med*d2 / zl - v2)) < v)beg = med;
		else end = med;
	}
	return beg;
}
double get(double d)
{
	double v1 = getv(v1x, v1y, cos(d), sin(d));
	double rx = l - v1*cos(d)*t;
	double ry = -v1*sin(d)*t;
	double v2 = getv(v2x, v2y, rx, ry);
	return t + sqrt(rx*rx + ry*ry) / v2;
}
int main()
{
	double zx1, zy1, zx2, zy2;
	scanf("%lf%lf%lf%lf", &zx1, &zy1, &zx2, &zy2);
	double dx = zx2 - zx1, dy = zy2 - zy1;
	l = sqrt(dx*dx + dy*dy);
	scanf("%lf%lf", &v, &t);
	double zv1x, zv1y, zv2x, zv2y;
	scanf("%lf%lf%lf%lf", &zv1x, &zv1y, &zv2x, &zv2y);
	v1x = (zv1x*dx + zv1y*dy) / l;
	v1y = (-zv1x*dy + zv1y*dx) / l;
	v2x = (zv2x*dx + zv2y*dy) / l;
	v2y = (-zv2x*dy + zv2y*dx) / l;
	if (l < (1e-12))
	{
		printf("0\n");
		return 0;
	}
	if (getv(v1x, v1y, l, 0)*t >= l)
	{
		printf("%lf\n", l / getv(v1x, v1y, l, 0));
		return 0;
	}
	double beg = -pi/2, end = pi/2;
	for (int p = 0; p <= 100; p++)
	{
		double m1 = (beg + beg + end) / 3.0, m2 = (beg + end + end) / 3.0;
		double r1 = get(m1), r2 = get(m2);
		if (r1 < r2)end = m2;
		else beg = m1;
	}
	printf("%.10lf\n", get(beg));
}