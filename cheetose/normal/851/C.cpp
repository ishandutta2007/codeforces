#include<cstdio>
#include<cmath>
#include<vector>
#define PI 3.14159265358979323
using namespace std;
struct point {
	double a, b, c, d, e;
};
inline double length(point p1, point p2)
{
	return sqrt((p1.a - p2.a)*(p1.a - p2.a) + (p1.b - p2.b)*(p1.b - p2.b) + (p1.c - p2.c)*(p1.c - p2.c) + (p1.d - p2.d)*(p1.d - p2.d) + (p1.e - p2.e)*(p1.e - p2.e));
}
inline double dot(point p1, point p2)
{
	return (p1.a*p2.a) + (p1.b*p2.b) + (p1.c*p2.c) + (p1.d*p2.d) + (p1.e*p2.e);
}
point operator - (point p1, point p2)
{
	point p;
	p.a = p1.a - p2.a, p.b = p1.b - p2.b, p.c = p1.c - p2.c, p.d = p1.d - p2.d, p.e = p1.e - p2.e;
	return p;
}
bool is(point p1, point p2, point p3)
{
	return acos(dot(p2-p1,p3-p1)/length(p2,p1)/length(p3,p1)) < PI / 2;
}
point p[1000];
int main() {
	vector<int> v;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf%lf%lf%lf%lf", &p[i].a, &p[i].b, &p[i].c, &p[i].d, &p[i].e);
	for (int i = 0; i < n; i++)
	{
		bool ok = 1;
		for (int j = 0; j < n; j++)
		{
			if (!ok)break;
			for (int k = 0; k < n; k++)
			{
				if (i == j || j == k || i == k)continue;
				if (is(p[i], p[j], p[k]))
				{
					ok = 0;
					break;
				}
			}
		}
		if (ok) v.push_back(i);
	}
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i] + 1);
}