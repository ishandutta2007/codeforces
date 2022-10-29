#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
double pi = 3.14159265358979323;
double get(double t)
{
	double beg = 0.0, end = pi;
	for (int p = 0; p < 100; p++)
	{
		double med = (beg + end) / 2.0;
		if (sin(med) + med < t)beg = med;
		else end = med;
	}
	return beg;
}
int main()
{
	int n;
	double r, v;
	scanf("%d%lf%lf", &n, &r, &v);
	for (int i = 0; i < n; i++)
	{
		double a, b;
		scanf("%lf%lf", &a, &b);
		double l = b - a;
		double ans = (l - fmod(l, 2.0*pi*r));
		printf("%.10lf\n", (ans + get((l - ans) / (2.0*r))*2.0*r) / v);
	}
}