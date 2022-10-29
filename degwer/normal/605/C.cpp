#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<double, double>pdd;
double p, q;
double get(vector<pdd>v, double med)
{
	double mini = 1.0;
	for (int i = 0; i < v.size(); i++)
	{
		mini = min(mini, (1.0 - v[i].first*med) / v[i].second);
	}
	return mini;
}
int main()
{
	int num;
	scanf("%d%lf%lf", &num, &p, &q);
	vector<pdd>vec;
	for (int i = 0; i < num; i++)
	{
		double za, zb;
		scanf("%lf%lf", &za, &zb);
		vec.push_back(make_pair(za, zb));
	}
	double beg = 0.0, end = 1.0;
	for (int r = 0; r < 100; r++)
	{
		double m1 = (beg + beg + end) / 3.0, m2 = (beg + end + end) / 3.0;
		double mi1 = get(vec, m1), mi2 = get(vec, m2);
		if (mi2 < 0.0)
		{
			end = m2;
		}
		else if (m1*p + mi1*q < m2*p + mi2*q)
		{
			beg = m1;
		}
		else end = m2;
	}
	double mi = get(vec, beg);
	printf("%.10lf\n", beg*p + mi*q);
}