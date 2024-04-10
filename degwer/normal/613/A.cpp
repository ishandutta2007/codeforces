#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<double, double>pdd;
int main()
{
	ll num, x, y;
	scanf("%I64d%I64d%I64d", &num, &x, &y);
	double mini = 1000000000000000000.0, maxi = 0.0;
	vector<pdd>v;
	for (int i = 0; i < num; i++)
	{
		ll a, b;
		scanf("%I64d%I64d", &a, &b);
		v.push_back(make_pair(double(a - x), double(b - y)));
	}
	v.push_back(v[0]);
	for (int i = 0; i < num; i++)
	{
		double beg = 0.0, end = 1.0;
		for (int p=0;p<50;p++)
		{
			double m1 = (beg + beg + end) / 3.0, m2 = (beg + end + end) / 3.0;
			double nx1 = v[i].first*m1 + v[i + 1].first*(1.0 - m1);
			double ny1 = v[i].second*m1 + v[i + 1].second*(1.0 - m1);
			double nx2 = v[i].first*m2 + v[i + 1].first*(1.0 - m2);
			double ny2 = v[i].second*m2 + v[i + 1].second*(1.0 - m2);
			if (nx1*nx1 + ny1*ny1 < nx2*nx2 + ny2*ny2)end = m2;
			else beg = m1;
			mini = min(mini, nx1*nx1 + ny1*ny1);
		}
		maxi = max(maxi, v[i].first*v[i].first + v[i].second*v[i].second);
	}
	printf("%.12lf\n", double(maxi - mini)*3.1415926535897932384626433832);
}