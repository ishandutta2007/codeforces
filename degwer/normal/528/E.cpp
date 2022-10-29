#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef pair<double, double>pdd;
typedef pair<pdd, double>pd3;
#define SIZE 4096
class BIT
{
public:
	double bit[SIZE + 1];
	void init()
	{
		fill(bit, bit + SIZE + 1, 0.0);
	}
	void add(int a, double b)
	{
		a++;
		for (;;)
		{
			if (a > SIZE)return;
			bit[a] += b;
			a += a&-a;
		}
	}
	double get(int a)
	{
		a++;
		double ret = 0.0;
		for (;;)
		{
			if (a == 0)return ret;
			ret += bit[a];
			a -= a&-a;
		}
	}
};
BIT bi1, bi2;
double pi = 3.1415926535897932384626433832;
double calc(vector<pd3>dat, pd3 lin)
{
	double a = lin.first.first, b = lin.first.second, c = lin.second;
	double vx = a / sqrt(a*a + b*b), vy = b / sqrt(a*a + b*b);
	vector<pdd>vec;
	vector<double>zat;
	//printf("%lf %lf\n", vx, vy);
	for (int i = 0; i < dat.size(); i++)
	{
		double za = dat[i].first.first, zb = dat[i].first.second, zc = dat[i].second;
		double arg = atan2(a, b) - atan2(za, zb);
		if (arg > pi)arg -= pi;
		if (arg > pi)arg -= pi;
		if (arg < 0)arg += pi;
		if (arg < 0)arg += pi;
		double x = (zb*c - b*zc) / (a*zb - b*za), y = (c*za - a*zc) / (b*za - a*zb);
		//printf(" %lf %lf %lf\n", x, y, arg);
		vec.push_back(make_pair(arg, x*vy - y*vx));
		zat.push_back(x*vy - y*vx);
	}
	sort(vec.begin(), vec.end());
	sort(zat.begin(), zat.end());
	bi1.init();
	bi2.init();
	double d = c / sqrt(a*a + b*b);
	double ret = 0;
	for (int i = 0; i < dat.size(); i++)
	{
		//printf("  %lf %lf\n", vec[i].first, vec[i].second);
		int low = lower_bound(zat.begin(), zat.end(), vec[i].second) - zat.begin();
		ret -= bi2.get(low)*vec[i].second - bi1.get(low);
		ret += (bi1.get(SIZE - 1) - bi1.get(low)) - (bi2.get(SIZE - 1) - bi2.get(low))*vec[i].second;
		bi1.add(low, vec[i].second);
		bi2.add(low, 1.0);
	}
	//printf("%lf %lf\n\n", ret, d);
	return ret*d / 2.0;
}
int main()
{
	int num;
	scanf("%d", &num);
	vector<pd3>vec;
	for (int i = 0; i < num; i++)
	{
		double za, zb, zc;
		scanf("%lf%lf%lf", &za, &zb, &zc);
		vec.push_back(make_pair(make_pair(za, zb), zc));
	}
	double ans = 0.0;
	for (int i = 0; i < num; i++)
	{
		vector<pd3>z;
		for (int j = 0; j < num; j++)
		{
			if (j != i)z.push_back(vec[j]);
		}
		ans += calc(z, vec[i]);
	}
	ans *= 6.0;
	ans /= num;
	ans /= (num - 1);
	ans /= (num - 2);
	printf("%lf\n", ans);
}