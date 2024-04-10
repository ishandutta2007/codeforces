#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long y1y, y2, yw, xb, yb, r;

struct node
{
	node(){}
	node(double _x, double _y) : x(_x), y(_y){}
	double x, y;
};

void calc(double &x)
{
	long long a = yw - r - yb, b = y1y - yb;
	long long ax = 2 * a - b, ay = -xb * a + xb * b;
	ay = -ay;
	if (ax == 0)
	{
		printf("-1\n");
		exit(0);
	}
	x = (double)ay / ax;
}

double fabs(double x, double y)
{
	if (x - y < 0)
		return -x + y;
	return x - y;
}

double cross(node a, node b, node c)
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

double dis(node a, node b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dis(node a, node b, node c)
{
	return fabs(cross(a, b, c)) / dis(a, b);
}

int main()
{

	cin >> y1y >> y2 >> yw >> xb >> yb >> r;
	if (y1y > y2 || fabs(yb, yw) < r)
	{
		printf("-1\n");
		return 0;
	} 
	y1y = y1y + r;
	double x;
	calc(x);
	if (x > 0 && x < xb && dis(node(0, y1y), node(x, yw - r), node(0, y2)) > r)
		printf("%.8lf\n", x);
	else
		cout << -1 << endl;
	return 0;
}